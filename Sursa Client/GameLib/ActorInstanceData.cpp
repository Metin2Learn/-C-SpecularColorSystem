// Cauta SetHair si inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
void CActorInstance::SetHair(DWORD eHair, float fSpecular, bool bIsColor, float fColorR, float fColorG, float fColorB, float fColorA)
#else
void CActorInstance::SetHair(DWORD eHair)
#endif


// Mai jos ai 
SetMaterialImagePointer(CRaceData::PART_HAIR, c_rkSkinItem.m_stSrcFileName.c_str(), static_cast<CGraphicImage*>(pkRes));

// Inlocuieste-l cu 

#ifdef ENABLE_SPECULAR_SYSTEM
			if (pkRes)
			{
				if (fSpecular > 0.0f)
				{
					SMaterialData kMaterialData;
					kMaterialData.pImage = static_cast<CGraphicImage*>(pkRes);
					kMaterialData.isSpecularEnable = TRUE;
					kMaterialData.fSpecularPower = fSpecular;
					kMaterialData.bSphereMapIndex = 0;
					kMaterialData.bSpecularColor = bIsColor;
					SetMaterialData(CRaceData::PART_HAIR, c_rkSkinItem.m_stSrcFileName.c_str(), kMaterialData);

					if (fColorR > 0.0f || fColorG > 0.0f || fColorB > 0.0f || fColorA > 0.0f)
						SetSpecularColor(CRaceData::PART_HAIR, fColorA, fColorR, fColorG, fColorB);
				}
				else
					SetMaterialImagePointer(CRaceData::PART_HAIR, c_rkSkinItem.m_stSrcFileName.c_str(), static_cast<CGraphicImage*>(pkRes));
			}
#else
			if (pkRes)
				SetMaterialImagePointer(CRaceData::PART_HAIR, c_rkSkinItem.m_stSrcFileName.c_str(), static_cast<CGraphicImage*>(pkRes));
#endif


// Cauta si inlocuieste CActorInstance::SetShape cu 

#ifdef ENABLE_SPECULAR_SYSTEM
void CActorInstance::SetShape(DWORD eShape, float fSpecular, bool bIsColor, float fColorR, float fColorG, float fColorB, float fColorA)
#else
void CActorInstance::SetShape(DWORD eShape, float fSpecular)
#endif

// Sub kMaterialData.bSphereMapIndex = 0;
// Adauga

#ifdef ENABLE_SPECULAR_SYSTEM
					kMaterialData.bSpecularColor = bIsColor;
#endif

// Sub SetMaterialData(c_rkSkinItem.m_ePart, c_rkSkinItem.m_stSrcFileName.c_str(), kMaterialData);
// Adauga

#ifdef ENABLE_SPECULAR_SYSTEM
					if (fColorR > 0.0f || fColorG > 0.0f || fColorB > 0.0f || fColorA > 0.0f)
						SetSpecularColor(c_rkSkinItem.m_ePart, fColorA, fColorR, fColorG, fColorB);
#endif


// La sfarsit de fisier, adauga:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
D3DXCOLOR CActorInstance::GetEffectColor()
{
	return m_pColor;
}
#endif