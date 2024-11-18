// Sub functia DWORD	GetSIGVnum() const
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	public:
		void		SetSpecularColor(BYTE* bColors);
		BYTE*		GetSpecularColor();
		BYTE		GetSpecularColorSingle(BYTE index);
		void		SaveSpecularColor(bool bClear = false, bool bUnequip = false);
	private:
		BYTE		m_bSpecularColor[4 + 1];
#endif