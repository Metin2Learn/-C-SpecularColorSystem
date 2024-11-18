// Inlocuieste CGrannyMaterial::SetSpecularInfo
// Cu

#ifdef ENABLE_SPECULAR_SYSTEM
void CGrannyMaterial::SetSpecularInfo(BOOL bFlag, float fPower, BYTE uSphereMapIndex, bool bIsColor)
#else
void CGrannyMaterial::SetSpecularInfo(BOOL bFlag, float fPower, BYTE uSphereMapIndex)
#endif

// Mai jos inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
		if (bIsColor)
			m_pfnApplyRenderState = &CGrannyMaterial::__ApplySpecularColorRenderState;
		else
			m_pfnApplyRenderState = &CGrannyMaterial::__ApplySpecularRenderState;
#else
		m_pfnApplyRenderState = &CGrannyMaterial::__ApplySpecularRenderState;
#endif


// Deasupra bool CGrannyMaterial::IsEqual(granny_material* pgrnMaterial) const
// Adauga 

#ifdef ENABLE_SPECULAR_SYSTEM
void CGrannyMaterial::SetSpecularColor(float fSpecular, float fColorR, float fColorG, float fColorB)
{
	m_fSpecularPower = fSpecular;
	m_fSpecularColorR = fColorR;
	m_fSpecularColorG = fColorG;
	m_fSpecularColorB = fColorB;
}
#endif

// Sub float CGrannyMaterial::__GetSpecularPower() const
// Adauga

#ifdef ENABLE_SPECULAR_SYSTEM
float CGrannyMaterial::__GetSpecularColorR() const
{
	return m_fSpecularColorR;
}

float CGrannyMaterial::__GetSpecularColorG() const
{
	return m_fSpecularColorG;
}

float CGrannyMaterial::__GetSpecularColorB() const
{
	return m_fSpecularColorB;
}
#endif


// Inauntrul void CGrannyMaterial::Initialize()
// Adauga 

#ifdef ENABLE_SPECULAR_SYSTEM
	m_fSpecularColorR = 0.0f;
	m_fSpecularColorG = 0.0f;
	m_fSpecularColorB = 0.0f;
#endif


// Inauntrul functiei void CGrannyMaterial::__ApplySpecularRenderState()
// Cauta linia:

	STATEMANAGER.SetRenderState(D3DRS_TEXTUREFACTOR, D3DXCOLOR(g_fSpecularColor.r, g_fSpecularColor.g, g_fSpecularColor.b, __GetSpecularPower()));

// Inlocuieste-o cu:

	STATEMANAGER.SetRenderState(D3DRS_TEXTUREFACTOR, D3DXCOLOR(__GetSpecularColorR(), __GetSpecularColorG(), __GetSpecularColorB(), __GetSpecularPower()));



// Sub toata functia, adauga:


#ifdef ENABLE_SPECULAR_SYSTEM
void CGrannyMaterial::__ApplySpecularColorRenderState()
{
	if (TRUE == STATEMANAGER.GetRenderState(D3DRS_ALPHABLENDENABLE))
	{
		__ApplyDiffuseRenderState();
		return;
	}

	CGraphicTexture* pkTexture=ms_akSphereMapInstance[m_bSphereMapIndex].GetTexturePointer();

	STATEMANAGER.SetTexture(0, GetD3DTexture(0));

	if (pkTexture)
		STATEMANAGER.SetTexture(1, pkTexture->GetD3DTexture());
	else
		STATEMANAGER.SetTexture(1, NULL);

	STATEMANAGER.SetRenderState(D3DRS_TEXTUREFACTOR, D3DXCOLOR(__GetSpecularColorR(), __GetSpecularColorG(), __GetSpecularColorB(), __GetSpecularPower()));
	STATEMANAGER.SaveTextureStageState(1, D3DTSS_TEXCOORDINDEX, D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR);
	STATEMANAGER.SaveTextureStageState(0, D3DTSS_COLORARG1,	D3DTA_TEXTURE);
	STATEMANAGER.SaveTextureStageState(0, D3DTSS_COLORARG2,	D3DTA_DIFFUSE);
	STATEMANAGER.SaveTextureStageState(0, D3DTSS_COLOROP,	D3DTOP_MODULATE);
	STATEMANAGER.SaveTextureStageState(0, D3DTSS_ALPHAARG1,	D3DTA_TEXTURE);
	STATEMANAGER.SaveTextureStageState(0, D3DTSS_ALPHAARG2,	D3DTA_TFACTOR);
	BYTE bIntensity[4] = 
	{
		{	0					},
		{	D3DTOP_MODULATE		},
		{	D3DTOP_MODULATE2X	},
		{	D3DTOP_MODULATE4X	},
	};
	STATEMANAGER.SaveTextureStageState(0, D3DTSS_ALPHAOP,	bIntensity[SET_ALPHACHANNEL_INTENSITY]);
	STATEMANAGER.SetTextureStageState(1, D3DTSS_COLORARG1,	D3DTA_CURRENT);
	STATEMANAGER.SetTextureStageState(1, D3DTSS_COLORARG2,	D3DTA_TFACTOR);
	STATEMANAGER.SetTextureStageState(1, D3DTSS_COLOROP,	D3DTOP_MODULATEALPHA_ADDCOLOR);
	STATEMANAGER.SetTextureStageState(1, D3DTSS_ALPHAARG1,	D3DTA_CURRENT);
	STATEMANAGER.SetTextureStageState(1, D3DTSS_ALPHAOP,	D3DTOP_SELECTARG1);
	STATEMANAGER.SetTransform(D3DTS_TEXTURE1, &ms_matSpecular);
	STATEMANAGER.SaveTextureStageState(1, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2);
	STATEMANAGER.SaveTextureStageState(1, D3DTSS_ADDRESSU, D3DTADDRESS_WRAP);
	STATEMANAGER.SaveTextureStageState(1, D3DTSS_ADDRESSV, D3DTADDRESS_WRAP);
}
#endif


// Inauntrul CGrannyMaterialPalette::SetMaterialData
// Inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
				pkNewMtrl->SetSpecularInfo(c_rkMaterialData.isSpecularEnable, c_rkMaterialData.fSpecularPower, c_rkMaterialData.bSphereMapIndex, c_rkMaterialData.bSpecularColor);
#else
				pkNewMtrl->SetSpecularInfo(c_rkMaterialData.isSpecularEnable, c_rkMaterialData.fSpecularPower, c_rkMaterialData.bSphereMapIndex);
#endif


// Mai jos sub CGrannyMaterial::TRef& roMtrl=*i;
// Inlocuieste 

#ifdef ENABLE_SPECULAR_SYSTEM
			roMtrl->SetSpecularInfo(c_rkMaterialData.isSpecularEnable, c_rkMaterialData.fSpecularPower, c_rkMaterialData.bSphereMapIndex, c_rkMaterialData.bSpecularColor);
#else
			roMtrl->SetSpecularInfo(c_rkMaterialData.isSpecularEnable, c_rkMaterialData.fSpecularPower, c_rkMaterialData.bSphereMapIndex);
#endif


// Mai jos inlocuieste CGrannyMaterialPalette::SetSpecularInfo cu 

#ifdef ENABLE_SPECULAR_SYSTEM
void CGrannyMaterialPalette::SetSpecularInfo(const char* c_szMtrlName, BOOL bEnable, float fPower, bool bIsColor)
#else
void CGrannyMaterialPalette::SetSpecularInfo(const char* c_szMtrlName, BOOL bEnable, float fPower)
#endif

// Mai jos inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
				roMtrl->SetSpecularInfo(bEnable, fPower, 0, bIsColor);
#else
				roMtrl->SetSpecularInfo(bEnable, fPower, 0);
#endif


// Si mai jos, inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
			roMtrl->SetSpecularInfo(bEnable, fPower, 0, bIsColor);
#else
			roMtrl->SetSpecularInfo(bEnable, fPower, 0);
#endif


// Sub functie, adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
void CGrannyMaterialPalette::SetSpecularColor(float fSpecular, float fColorR, float fColorG, float fColorB)
{
	DWORD size=m_mtrlVector.size();
	DWORD i;

	for (i=0; i<size; ++i)
	{
		CGrannyMaterial::TRef& roMtrl=m_mtrlVector[i];
		roMtrl->SetSpecularColor(fSpecular, fColorR, fColorG, fColorB);
	}
}
#endif