// Adauga la sfarsitul fisierului:

#ifdef ENABLE_SPECULAR_SYSTEM
		virtual void	SetSpecularColor(TItemPos itemPos, BYTE* bColors) = 0;
		virtual BYTE* GetSpecularColor(TItemPos itemPos) = 0;
#endif