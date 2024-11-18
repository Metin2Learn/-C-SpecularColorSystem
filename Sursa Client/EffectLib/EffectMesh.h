// Adauga-ti Locale_inc.h la inceput de fisier

// Sub CDynamicPool<CEffectMeshScript>
// Adauga 

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
	public:
		void SetEffectColor(float fColorR = 1.0f, float fColorG = 1.0f, float fColorB = 1.0f, float fAlpha = 1.0f);
		void SetEffectColor(const D3DXCOLOR & pColor = (1.0, 1.0, 1.0, 1.0));
		bool GetEffectColor(DWORD dwMeshIndex, D3DXCOLOR * pColor);
		bool m_bNewColor;
	protected:
		D3DXCOLOR	m_pColor;
#endif