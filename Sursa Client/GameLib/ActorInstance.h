// Inlocuieste SetHair cu

#ifdef ENABLE_SPECULAR_SYSTEM
		void SetHair(DWORD eHair, float fSpecular = 0.0f, bool bIsColor = false, float fColorR = 0.0f, float fColorG = 0.0f, float fColorB = 0.0f, float fColorA = 0.0f);
#else
		void SetHair(DWORD eHair);
#endif

// Inlocuieste SetShape cu

#ifdef ENABLE_SPECULAR_SYSTEM
		void SetShape(DWORD eShape, float fSpecular = 0.0f, bool bIsColor = false, float fColorR = 0.0f, float fColorG = 0.0f, float fColorB = 0.0f, float fColorA = 0.0f);
#else
		void SetShape(DWORD eShape, float fSpecular = 0.0f);
#endif

// Inlocuieste cele 2 AttachWeapon cu

#ifdef ENABLE_SPECULAR_SYSTEM
		void AttachWeapon(DWORD dwItemIndex, DWORD dwParentPartIndex = CRaceData::PART_MAIN, DWORD dwPartIndex = CRaceData::PART_WEAPON, bool bIsColor = false, float fSpecular = 0.0f, float fColorR = 0.0f, float fColorG = 0.0f, float fColorB = 0.0f);
		void AttachWeapon(DWORD dwParentPartIndex, DWORD dwPartIndex, CItemData* pItemData, bool bIsColor = false, float fSpecular = 0.0f, float fColorR = 0.0f, float fColorG = 0.0f, float fColorB = 0.0f);
#else
		void AttachWeapon(DWORD dwItemIndex, DWORD dwParentPartIndex = CRaceData::PART_MAIN, DWORD dwPartIndex = CRaceData::PART_WEAPON);
		void AttachWeapon(DWORD dwParentPartIndex, DWORD dwPartIndex, CItemData* pItemData);
#endif

// Mai jos, inauntrul AttachEffectByID, adauga la sfarsitul parantezei:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
			, const D3DXCOLOR& pColor = (1.0, 1.0, 1.0, 1.0)
#endif

// Sub IntersectDefendingSphere
// Adauga 

void		RenderAllAttachingEffect();

// sub ms_isDirLine
// Adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	public:
		void SetSpecularColorAttach(BYTE bType, float fSpecular = 0.0f, float fColorR = 1.0f, float fColorG = 1.0f, float fColorB = 1.0f);
#ifdef ENABLE_EFFECT_COLOR_SYSTEM
		void SetEffectColor(DWORD dwEffectID, float fColorR = 1.0f, float fColorG = 1.0f, float fColorB = 1.0f, float fAlpha = 1.0f);
		void RegisterEffectColor(const D3DXCOLOR& pColor);
		D3DXCOLOR GetEffectColor();
	protected:
		D3DXCOLOR	m_pColor;
#endif
#endif