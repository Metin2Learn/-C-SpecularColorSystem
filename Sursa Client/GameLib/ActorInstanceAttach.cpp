#include "../EterLib/ResourceManager.h"


// Mai jos, inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
void CActorInstance::AttachWeapon(DWORD dwItemIndex, DWORD dwParentPartIndex, DWORD dwPartIndex, bool bIsColor, float fSpecular, float fColorR, float fColorG, float fColorB)
#else
void CActorInstance::AttachWeapon(DWORD dwItemIndex, DWORD dwParentPartIndex, DWORD dwPartIndex)
#endif

// Mai jos, inlocuieste:

if (__IsRightHandWeapon(pItemData->GetWeaponType()))
		AttachWeapon(dwParentPartIndex, CRaceData::PART_WEAPON, pItemData);
if (__IsLeftHandWeapon(pItemData->GetWeaponType()))
	AttachWeapon(dwParentPartIndex, CRaceData::PART_WEAPON_LEFT, pItemData);

// Cu asta:

#ifdef ENABLE_SPECULAR_SYSTEM
	if (pItemData->GetType() != CItemData::ITEM_TYPE_COSTUME)
	{
		if (__IsRightHandWeapon(pItemData->GetWeaponType()))
			AttachWeapon(dwParentPartIndex, CRaceData::PART_WEAPON, pItemData, bIsColor, fSpecular, fColorR, fColorG, fColorB);

		if (__IsLeftHandWeapon(pItemData->GetWeaponType()))
			AttachWeapon(dwParentPartIndex, CRaceData::PART_WEAPON_LEFT, pItemData, bIsColor, fSpecular, fColorR, fColorG, fColorB);
	}
	else
	{
		DWORD typeDec = pItemData->GetValue(3);
		if (__IsRightHandWeapon(typeDec))
			AttachWeapon(dwParentPartIndex, CRaceData::PART_WEAPON, pItemData, bIsColor, fSpecular, fColorR, fColorG, fColorB);

		if (__IsLeftHandWeapon(typeDec))
			AttachWeapon(dwParentPartIndex, CRaceData::PART_WEAPON_LEFT, pItemData, bIsColor, fSpecular, fColorR, fColorG, fColorB);
	}
#else
	if (pItemData->GetType() != CItemData::ITEM_TYPE_COSTUME)
	{
		if (__IsRightHandWeapon(pItemData->GetWeaponType()))
			AttachWeapon(dwParentPartIndex, CRaceData::PART_WEAPON, pItemData);

		if (__IsLeftHandWeapon(pItemData->GetWeaponType()))
			AttachWeapon(dwParentPartIndex, CRaceData::PART_WEAPON_LEFT, pItemData);
	}
	else
	{
		DWORD typeDec = pItemData->GetValue(3);
		if (__IsRightHandWeapon(typeDec))
			AttachWeapon(dwParentPartIndex, CRaceData::PART_WEAPON, pItemData);

		if (__IsLeftHandWeapon(typeDec))
			AttachWeapon(dwParentPartIndex, CRaceData::PART_WEAPON_LEFT, pItemData);
	}
#endif


// Mai jos, inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
void CActorInstance::AttachWeapon(DWORD dwParentPartIndex, DWORD dwPartIndex, CItemData * pItemData, bool bIsColor, float fSpecular, float fColorR, float fColorG, float fColorB)
#else
void CActorInstance::AttachWeapon(DWORD dwParentPartIndex, DWORD dwPartIndex, CItemData * pItemData)
#endif


// Inauntrul ei, inlocuieste:

	if (CRaceData::PART_WEAPON_LEFT == dwPartIndex)
	{
		RegisterModelThing(dwPartIndex, pItemData->GetSubModelThing());
	}
	else
	{
		RegisterModelThing(dwPartIndex, pItemData->GetModelThing());
	}
	
// Cu :

#ifdef ENABLE_SPECULAR_SYSTEM
	CGraphicThing* pModelThing;

	if (CRaceData::PART_WEAPON_LEFT == dwPartIndex)
		pModelThing = pItemData->GetSubModelThing();
	else
		pModelThing = pItemData->GetModelThing();

	RegisterModelThing(dwPartIndex, pModelThing);
#else
	if (CRaceData::PART_WEAPON_LEFT == dwPartIndex)
		RegisterModelThing(dwPartIndex, pItemData->GetSubModelThing());
	else
		RegisterModelThing(dwPartIndex, pItemData->GetModelThing());
#endif


// Mai jos, inlocuieste liniile astea:

#ifdef ENABLE_SPECULAR_SYSTEM
		if (pModelThing && pModelThing->GetTextureCount() > 0)
		{
			for (int i = 0; i < pModelThing->GetTextureCount(); i++)
			{
				CResource* pkRes = CResourceManager::Instance().GetResourcePointer(pModelThing->GetTexturePath(i));
				if (!pkRes)
					return;

				SMaterialData kMaterialData;
				kMaterialData.pImage = static_cast<CGraphicImage*>(pkRes);
				kMaterialData.isSpecularEnable = TRUE;
				kMaterialData.fSpecularPower = pItemData->GetSpecularPowerf();
				kMaterialData.bSphereMapIndex = 1;
				kMaterialData.bSpecularColor = bIsColor;
				SetMaterialData(dwPartIndex, pModelThing->GetTexturePath(i), kMaterialData);

				if (fColorR > 0.0f || fColorG > 0.0f || fColorB > 0.0f || fSpecular > 0.0f)
					SetSpecularColor(dwPartIndex, fSpecular, fColorR, fColorG, fColorB);
			}
		}
#else
		SMaterialData kMaterialData;
		kMaterialData.pImage = NULL;
		kMaterialData.isSpecularEnable = TRUE;
		kMaterialData.fSpecularPower = pItemData->GetSpecularPowerf();
		kMaterialData.bSphereMapIndex = 1;
		SetMaterialData(dwPartIndex, NULL, kMaterialData);
#endif


// Mai jos, cauta CActorInstance::AttachEffectByID
// Adauga la sfarsitul parantezei:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
	, const D3DXCOLOR& pColor
#endif

// Inauntrul ei, cauta rkEftMgr.CreateEffectInstance
// Adauga la sfarsitul parantezei:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
		, pColor
#endif

// Adauga la sfarsit de fisier:

void CActorInstance::RenderAllAttachingEffect()
{
	for (const auto& it : m_AttachingEffectList)
		CEffectManager::Instance().RenderOne(it.dwEffectIndex);
}

#ifdef ENABLE_SPECULAR_SYSTEM
void CActorInstance::SetSpecularColorAttach(BYTE bType, float fSpecular, float fColorR, float fColorG, float fColorB)
{
	if (bType < 0 || bType > CRaceData::PART_MAX_NUM)
		return;

	if (bType == CRaceData::PART_WEAPON_LEFT)
	{
		SetSpecularColor(CRaceData::PART_WEAPON, fSpecular, fColorR, fColorG, fColorB);
		SetSpecularColor(CRaceData::PART_WEAPON_LEFT, fSpecular, fColorR, fColorG, fColorB);
	}
	else
		SetSpecularColor(bType, fSpecular, fColorR, fColorG, fColorB);
}

#ifdef ENABLE_EFFECT_COLOR_SYSTEM
void CActorInstance::SetEffectColor(DWORD dwEffectID, float fColorR, float fColorG, float fColorB, float fAlpha)
{
	if (fColorR == 0.0f && fColorG == 0.0f && fColorB == 0.0f) {
		fColorR = 1.0f, fColorG = 1.0f, fColorB = 1.0f;
	}

	CEffectManager& rkEftMgr = CEffectManager::Instance();
	rkEftMgr.SetEffectColor(dwEffectID, fColorR, fColorG, fColorB, fAlpha);
}
#endif
#endif