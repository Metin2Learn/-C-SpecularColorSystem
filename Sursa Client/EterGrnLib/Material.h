// Inlocuieste SetSpecularInfo
// Cu 

#ifdef ENABLE_SPECULAR_SYSTEM
		void					SetSpecularInfo(BOOL bFlag, float fPower, BYTE uSphereMapIndex, bool bIsColor = false);
		void					SetSpecularColor(float fSpecular = 0.0f, float fColorR = 0.0f, float fColorG = 0.0f, float fColorB = 0.0f);
#else
		void					SetSpecularInfo(BOOL bFlag, float fPower, BYTE uSphereMapIndex);
#endif


// Sub __GetSpecularPower() const;
// Adauga 

#ifdef ENABLE_SPECULAR_SYSTEM
		float					__GetSpecularColorR() const;
		float					__GetSpecularColorG() const;
		float					__GetSpecularColorB() const;
#endif


// Sub __ApplySpecularRenderState();
// Adauga 

#ifdef ENABLE_SPECULAR_SYSTEM
		void					__ApplySpecularColorRenderState();
#endif

// Sub m_fSpecularPower
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
		float					m_fSpecularColorR;
		float					m_fSpecularColorG;
		float					m_fSpecularColorB;
#endif


// Mai jos ai iar SetSpecularInfo
// Inlocuieste-l cu:

#ifdef ENABLE_SPECULAR_SYSTEM
		void	SetSpecularInfo(const char* c_szMtrlName, BOOL bEnable, float fPower, bool bIsColor = false);
		void	SetSpecularColor(float fSpecular = 0.0f, float fColorR = 0.0f, float fColorG = 0.0f, float fColorB = 0.0f);
#else
		void	SetSpecularInfo(const char* c_szMtrlName, BOOL bEnable, float fPower);
#endif