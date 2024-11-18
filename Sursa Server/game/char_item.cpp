// Sub pack.count = pItem->GetCount();
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
			memcpy(pack.bSpecularColor, pItem->GetSpecularColor(), sizeof(pack.bSpecularColor));
#endif

// Sub pack.count = 0;
// Adauga

#ifdef ENABLE_SPECULAR_SYSTEM
			memset(pack.bSpecularColor, 0, sizeof(pack.bSpecularColor));
#endif