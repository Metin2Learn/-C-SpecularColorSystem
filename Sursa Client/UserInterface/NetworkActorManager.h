// Sub m_dwLevel adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	BYTE	m_bSpecularColor[SPECULAR_WEAR_MAX_NUM];
#endif

// Sub m_dwMountVnum adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	BYTE	m_bSpecularColor[SPECULAR_WEAR_MAX_NUM];
#endif

// Sub m_dwStateFlags=0; adauga

#ifdef ENABLE_SPECULAR_SYSTEM
		memset(m_bSpecularColor, 0, sizeof(m_bSpecularColor));
#endif