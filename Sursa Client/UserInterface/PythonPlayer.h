// Deasupra SetItemMetinSocket(TItemPos Cell, DWORD dwMetinSocketIndex, DWORD dwMetinNumber);
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
		void	SetSpecularColor(TItemPos itemPos, BYTE* bColors);
		BYTE* GetSpecularColor(TItemPos itemPos);
#endif