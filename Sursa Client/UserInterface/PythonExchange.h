// Deasupra } TExchangeData;
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
			BYTE					bSpecularColor[EXCHANGE_ITEM_MAX_NUM][4 + 1];
#endif

// Sub GetItemAttributeFromSelf
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
		void			SetSpecularColor(int iPos, BYTE* bColors, bool bSelf);
		BYTE* GetSpecularColor(int iPos, bool bSelf);
#endif