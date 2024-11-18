// Sub pack.flags	= pkItem->GetFlag(); adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(pack.bSpecularColor, pkItem->GetSpecularColor(), sizeof(pack.bSpecularColor));
#endif