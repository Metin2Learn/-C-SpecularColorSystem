// Sub t.vnum = item->GetOriginalVnum(); adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(t.bSpecularColor, item->GetSpecularColor(), sizeof(t.bSpecularColor));
#endif