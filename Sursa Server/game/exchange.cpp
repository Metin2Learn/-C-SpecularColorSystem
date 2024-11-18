// Sub thecore_memcpy(&pack_exchg.aAttr, ((LPITEM) pvData)->GetAttributes(), sizeof(pack_exchg.aAttr));
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
		memcpy(pack_exchg.bSpecularColor, ((LPITEM) pvData)->GetSpecularColor(), sizeof(pack_exchg.bSpecularColor));
#endif

// Sub memset(&pack_exchg.aAttr, 0, sizeof(pack_exchg.aAttr));
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
		memset(pack_exchg.bSpecularColor, 0, sizeof(pack_exchg.bSpecularColor));
#endif