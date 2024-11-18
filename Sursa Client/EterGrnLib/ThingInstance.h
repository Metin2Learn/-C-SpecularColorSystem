// Include-ti Locale_inc.h

// Sub SetMotionAtEnd(); adauga

		void		SetSkipLod(bool value) { m_bSkipLod = value; }
		bool		GetSkipLod() { return m_bSkipLod; }
		
// Sub SetSpecularInfo
// Adauga 

#ifdef ENABLE_SPECULAR_SYSTEM
		void		SetSpecularColor(UINT ePart, float fSpecular = 1.0f, float fColorR = 1.0f, float fColorG = 1.0f, float fColorB = 1.0f);
#endif


// Sub m_roMotionThingMap
// Adauga 

bool									m_bSkipLod;