// Inauntrul bool CInstanceBase::Create(const SCreateData& c_rkCreateData)
// Cauta SetArmor(c_rkCreateData.m_dwArmor);
// Inlocuieste cu:

#ifdef ENABLE_SPECULAR_SYSTEM
	for (int i = 0; i < SPECULAR_WEAR_MAX_NUM; i++)
		SetSpecularColor(i, c_rkCreateData.m_bSpecularColor[i]);

	SetArmor(c_rkCreateData.m_dwArmor, c_rkCreateData.m_bSpecularColor[0], c_rkCreateData.m_bSpecularColor[1], c_rkCreateData.m_bSpecularColor[2], c_rkCreateData.m_bSpecularColor[3]);
#else
	SetArmor(c_rkCreateData.m_dwArmor);
#endif


// Mai jos, cauta si inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
		SetHair(c_rkCreateData.m_dwHair, c_rkCreateData.m_bSpecularColor[8], c_rkCreateData.m_bSpecularColor[9], c_rkCreateData.m_bSpecularColor[10], c_rkCreateData.m_bSpecularColor[11]);
		SetWeapon(c_rkCreateData.m_dwWeapon, c_rkCreateData.m_bSpecularColor[4], c_rkCreateData.m_bSpecularColor[5], c_rkCreateData.m_bSpecularColor[6], c_rkCreateData.m_bSpecularColor[7]);
#else
		SetHair(c_rkCreateData.m_dwHair);
		SetWeapon(c_rkCreateData.m_dwWeapon);
#endif

// Inauntrul bool CInstanceBase::__CanRender()
// Adauga:

	if (IsAlwaysRender())
	{
		return true;
	}
	
	
// Cauta CInstanceBase::SetHair si inlocuieste cu:

#ifdef ENABLE_SPECULAR_SYSTEM
void CInstanceBase::SetHair(DWORD eHair, BYTE r, BYTE g, BYTE b, BYTE a, bool bUpdate)
#else
void CInstanceBase::SetHair(DWORD eHair)
#endif

// Mai jos, cauta m_GraphicThingInstance.SetHair(eHair); si inlocuieste cu:

#ifdef ENABLE_SPECULAR_SYSTEM
	float fSpecularPower = 0.0f;
	bool bIsColor = false;

	CItemData* pItemData;
	if (CItemManager::Instance().GetItemDataPointer(eHair, &pItemData))
	{
		if (pItemData->IsSpecularColorItem() && (r > 0 || g > 0 || b > 0 || a > 0) || (bUpdate))
			bIsColor = true;

		fSpecularPower = pItemData->GetSpecularPowerf(bIsColor);
	}

	if (eHair >= 1005 && eHair <= 1012 || eHair >= 2001 && eHair <= 2012 || /*war ninja */
		eHair >= 3005 && eHair <= 3012 ||
		eHair >= 60030 && eHair <= 60035 || /*sura shaman */
		eHair >= 60090 && eHair <= 60094 || /*sura shaman */
		eHair >= 4005 && eHair <= 4009 || /*sura shaman */
		eHair >= 4010 && eHair <= 4012) /*sura shaman */
	{
		fSpecularPower = 0.001f;

		if ((r > 0 || g > 0 || b > 0 || a > 0) || (bUpdate))
			bIsColor = true;
	}
	if (eHair == 60111) /*sura shaman */
	{
		fSpecularPower = 0.0f;
	}

	m_GraphicThingInstance.SetHair(eHair, fSpecularPower, bIsColor, float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, float(a) / 255.0);
#else
	m_GraphicThingInstance.SetHair(eHair);
#endif


// Mai jos, inlocuieste ChangeHair cu
#ifdef ENABLE_SPECULAR_SYSTEM
void CInstanceBase::ChangeHair(DWORD eHair, BYTE r, BYTE g, BYTE b, BYTE a)
#else
void CInstanceBase::ChangeHair(DWORD eHair)
#endif


// Mai jos, cauta:

	SetHair(eHair);
	
// Inlocuieste cu:

#ifdef ENABLE_SPECULAR_SYSTEM
	SetHair(eHair, r, g, b, a);
#else
	SetHair(eHair);
#endif


// Mai jos, inlocuieste SetArmor cu

#ifdef ENABLE_SPECULAR_SYSTEM
void CInstanceBase::SetArmor(DWORD dwArmor, BYTE r, BYTE g, BYTE b, BYTE a, bool bUpdate, bool bEffect)
#else
void CInstanceBase::SetArmor(DWORD dwArmor)
#endif

// Mai jos cauta:

			float fSpecularPower=pItemData->GetSpecularPowerf();
			SetShape(dwShape, fSpecularPower);
			__GetRefinedEffect(pItemData);
			
			
// Inlocuieste cu :

#ifdef ENABLE_SPECULAR_SYSTEM
			m_dwArmor = dwArmor;
			bool bIsColor = false;

			if (pItemData->IsSpecularColorItem() && (r > 0 || g > 0 || b > 0 || a > 0) || (bUpdate))
				bIsColor = true;

			float fSpecularPower = pItemData->GetSpecularPowerf(bIsColor);
			SetShape(dwShape, fSpecularPower, bIsColor, r, g, b, a);

			if (bEffect)
				__GetRefinedEffect(pItemData);
#else
			float fSpecularPower = pItemData->GetSpecularPowerf();
			SetShape(dwShape, fSpecularPower);
			__GetRefinedEffect(pItemData);
#endif



// Dupa functie, adauga:

DWORD CInstanceBase::GetArmor()
{
	return GetPart(CRaceData::PART_MAIN);
}

DWORD CInstanceBase::GetHair()
{
	return GetPart(CRaceData::PART_HAIR);
}

DWORD CInstanceBase::GetWeapon()
{
	return GetPart(CRaceData::PART_WEAPON);
}

bool CInstanceBase::IsAlwaysRender()
{
	return m_IsAlwaysRender;
}

void CInstanceBase::SetAlwaysRender(bool val)
{
	m_IsAlwaysRender = val;
}

// Cauta si inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
void CInstanceBase::SetShape(DWORD eShape, float fSpecular, bool bIsColor, BYTE r, BYTE g, BYTE b, BYTE a)
#else
void CInstanceBase::SetShape(DWORD eShape, float fSpecular)
#endif

// In functie, cauta :

m_GraphicThingInstance.SetShape(eShape, fSpecular);

// Inlocuieste cu :

#ifdef ENABLE_SPECULAR_SYSTEM
		m_GraphicThingInstance.SetShape(eShape, fSpecular, bIsColor, float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, float(a) / 255.0);
#else
		m_GraphicThingInstance.SetShape(eShape, fSpecular);
#endif

// Cauta si inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
bool CInstanceBase::SetWeapon(DWORD eWeapon, BYTE r, BYTE g, BYTE b, BYTE a, bool bUpdate)
#else
bool CInstanceBase::SetWeapon(DWORD eWeapon)
#endif

// In functie, sub:

m_GraphicThingInstance.AttachWeapon(eWeapon);

// Inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
	bool bIsColor = false;

	if (CItemManager::Instance().GetItemDataPointer(eWeapon, &pItemData))
	{
		if (pItemData->IsSpecularColorItem() && (r > 0 || g > 0 || b > 0 || a > 0) || (bUpdate))
			bIsColor = true;
	}

	m_GraphicThingInstance.AttachWeapon(eWeapon, CRaceData::PART_MAIN, CRaceData::PART_WEAPON, bIsColor, float(a) / 255.0, float(r) / 255.0, float(g) / 255.0, float(b) / 255.0);
#else
	m_GraphicThingInstance.AttachWeapon(eWeapon);
#endif


// O sa primesti eroare la " pItemData ". Muta :


	CItemData* pItemData;
// Deasupra functiei cu Specular



// Cauta si inlocuieste:


#ifdef ENABLE_SPECULAR_SYSTEM
void CInstanceBase::ChangeWeapon(DWORD eWeapon, BYTE r, BYTE g, BYTE b, BYTE a)
#else
void CInstanceBase::ChangeWeapon(DWORD eWeapon)
#endif
	
// Mai jos, inlocuieste asta:

#ifdef ENABLE_SPECULAR_SYSTEM
	if (SetWeapon(eWeapon, r, g, b, a))
#else
	if (SetWeapon(eWeapon))
#endif


// Dupa functie, cauta si inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
bool CInstanceBase::ChangeArmor(DWORD dwArmor, BYTE r, BYTE g, BYTE b, BYTE a, bool bUpdate)
#else
bool CInstanceBase::ChangeArmor(DWORD dwArmor)
#endif
	
	
// Mai jos, inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
	//m_dwArmor = dwArmor;
	SetArmor(dwArmor, r, g, b, a, bUpdate);
	SetHair(eHair, m_bSpecularColor[8], m_bSpecularColor[9], m_bSpecularColor[10], m_bSpecularColor[11]);
	SetWeapon(eWeapon, m_bSpecularColor[4], m_bSpecularColor[5], m_bSpecularColor[6], m_bSpecularColor[7]);
#else
	SetArmor(dwArmor);
	SetHair(eHair);
	SetWeapon(eWeapon);
#endif



// Inauntrul void CInstanceBase::__Initialize()
// Adauga:

	m_IsAlwaysRender = false;
#ifdef ENABLE_SPECULAR_SYSTEM
	memset(m_bSpecularColor, 0, sizeof(m_bSpecularColor));
	m_bRefresh = false;
#endif


// La sfarsitul fisierului, adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
void CInstanceBase::SetSpecularColor(BYTE bIndex, BYTE bColor)
{
	assert(bIndex < SPECULAR_WEAR_MAX_NUM);
	m_bSpecularColor[bIndex] = bColor;
}

void CInstanceBase::UpdateSpecularColor(BYTE bPart, BYTE r, BYTE g, BYTE b, BYTE a, bool bIsEquip, bool bIsClose, bool bIsDefault)
{
	bool bUpdate = true;

	if (bIsDefault)
	{
		r = 0;
		g = 0;
		b = 0;
		a = 0;
		bUpdate = false;
	}

	if ((bIsEquip && !m_bRefresh) || (bIsDefault))
	{
		if (bPart == CRaceData::PART_MAIN)
		{
			SetArmor(m_dwArmor, r, g, b, a, bUpdate, false);
			__AttachHorseSaddle();
		}
		else if (bPart == CRaceData::PART_WEAPON || bPart == CRaceData::PART_WEAPON_LEFT)
			SetWeapon(GetWeapon(), r, g, b, a, bUpdate);
		else if (bPart == CRaceData::PART_HAIR)
			SetHair(GetHair(), r, g, b, a, bUpdate);
#ifdef ENABLE_ACCE_SYSTEM
		else if (bPart == CRaceData::PART_ACCE)
			SetAcce(GetSash() - 85000, r, g, b, a, bUpdate);
#endif

		m_bRefresh = true;
		RefreshState(CRaceMotionData::NAME_WAIT, true);
	}

	if (bIsClose)
		m_bRefresh = false;

	if (!bIsDefault)
		m_GraphicThingInstance.SetSpecularColorAttach(bPart, float(a) / 255.0, float(r) / 255.0, float(g) / 255.0, float(b) / 255.0);
}

#ifdef ENABLE_EFFECT_COLOR_SYSTEM
void CInstanceBase::UpdateEffectColor(UINT eEftType, BYTE r, BYTE g, BYTE b, BYTE a)
{
	if (eEftType >= EFFECT_NUM)
		return;

	m_GraphicThingInstance.SetEffectColor(ms_adwCRCAffectEffect[eEftType], float(r) / 255.0, float(g) / 255.0, float(b) / 255.0, float(a) / 255.0);
}

void CInstanceBase::RefreshEffect()
{
	// #ifdef ENABLE_SHINING_SYSTEM
		// if (!AttachShiningEffect(m_awPart[CRaceData::PART_WEAPON]))
			// TraceError("Error with shining refresh");
	// #endif
}

void CInstanceBase::RegisterEffectColor()
{
	// DWORD effect[ESkillColorLength::MAX_EFFECT_COUNT];
	// memcpy(effect, m_bSpecularColor, sizeof(effect));
	// effect[p->skill][0] = p->col1;
	m_GraphicThingInstance.RegisterEffectColor(D3DXCOLOR(float(m_bSpecularColor[20]) / 255.0, float(m_bSpecularColor[21]) / 255.0, float(m_bSpecularColor[22]) / 255.0, float(m_bSpecularColor[23]) / 255.0));
}
#endif
#endif