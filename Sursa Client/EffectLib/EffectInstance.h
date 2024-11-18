// Adauga-ti Locale_inc.h la inceput de fisier

// Cauta SetEffectDataPointer 
// Adauga la sfarsitul parantezei:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
			, const D3DXCOLOR & pColor = (1.0, 1.0, 1.0, 1.0)
#endif

// Sub ms_iRenderingEffectCount
// Adauga

	protected:
		bool m_ignoreFrustum;

		struct FEffectFrustum
		{
			bool ignoreFrustum;
			FEffectFrustum(bool igno)
				: ignoreFrustum(igno)
			{
			}
			void operator () (CEffectElementBaseInstance * pInstance)
			{
				pInstance->SetIgnoreFrustum(ignoreFrustum);
			}
		};

	public:
		void SetIgnoreFrustum(bool frustum)
		{
			m_ignoreFrustum = frustum;
			FEffectFrustum f2(m_ignoreFrustum);
			std::for_each(m_ParticleInstanceVector.begin(), m_ParticleInstanceVector.end(), f2);
			std::for_each(m_MeshInstanceVector.begin(), m_MeshInstanceVector.end(), f2);
			std::for_each(m_LightInstanceVector.begin(), m_LightInstanceVector.end(), f2);
		}

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
	public:
		void SetEffectColor(CEffectData * pEffectData, float fColorR = 1.0f, float fColorG = 1.0f, float fColorB = 1.0f, float fAlpha = 1.0f);
#endif