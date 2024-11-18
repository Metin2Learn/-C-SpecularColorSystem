// Cauta si inlocuieste: CInstanceBase::__AttachEffect(UINT eEftType) cu

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
DWORD CInstanceBase::__AttachEffect(UINT eEftType, const D3DXCOLOR& pColor)
#else
DWORD CInstanceBase::__AttachEffect(UINT eEftType)
#endif


// Mai jos, cauta return m_GraphicThingInstance.AttachEffectByID(0, NULL, ms_adwCRCAffectEffect[eEftType]
// Adauga in ea:

, NULL
#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
			, pColor
#endif

// Mai jos, cauta return m_GraphicThingInstance.AttachEffectByID(0, c_szBoneName, ms_adwCRCAffectEffect[eEftType]

// Adauga in ea:

, NULL
#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
					, pColor
#endif


// Mai jos, caua return m_GraphicThingInstance.AttachEffectByID(0, c_szBoneName, ms_adwCRCAffectEffect[eEftType]

// Adauga in ea:

, NULL
#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
					, pColor
#endif

// Mai jos, cauta return m_GraphicThingInstance.AttachEffectByID(0, rstrBoneName.c_str(), ms_adwCRCAffectEffect[eEftType]

// Adauga in ea:

, NULL
#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
				, pColor
#endif