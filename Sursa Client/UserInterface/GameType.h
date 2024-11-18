/// Sub #pragma pack(1) adauga

#ifdef ENABLE_SPECULAR_SYSTEM
enum SpecularOption
{
	SPECULAR_WEAR_MAX_NUM = 12 + 1
};
#endif


// Cauta } TItemData; si adauga deasupra:

#ifdef ENABLE_SPECULAR_SYSTEM
	BYTE		bSpecularColor[4 + 1];
#endif


// Cauta } TShopItemData; si adauga deasupra:

#ifdef ENABLE_SPECULAR_SYSTEM
	BYTE		bSpecularColor[4 + 1];
#endif