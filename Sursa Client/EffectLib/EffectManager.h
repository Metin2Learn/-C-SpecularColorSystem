// Adauga-ti Locale_inc.h la inceput de fisier

// Sub void Render();
// Adauga:

void RenderOne(DWORD id);


// Mai jos cauta void CreateEffectInstance(DWORD dwInstanceIndex, DWORD dwID);
// Adauga la sfarsitul parantezei:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
			, const D3DXCOLOR & pColor = (1.0, 1.0, 1.0, 1.0)
#endif

// Sub m_pSelectedEffectInstance
// Adauga

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
	public:
		void SetEffectColor(DWORD dwEffectID, float fColorR = 1.0f, float fColorG = 1.0f, float fColorB = 1.0f, float fAlpha = 0.0f);
#endif