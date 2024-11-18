// Sub int iLen = snprintf(szColumns, sizeof(szColumns), "id, owner_id, window, pos, count, vnum");

// Adauga


#ifdef ENABLE_SPECULAR_SYSTEM
		for (int i = 0; i < 4; ++i)
			iLen += snprintf(szColumns + iLen, sizeof(szColumns) - iLen, ", specular_color%d", i);
#endif

// Sub int iValueLen = snprintf(szValues, sizeof(szValues), "%u, %u, %d, %d, %u, %u", p->id, p->owner, p->window, p->pos, p->count, p->vnum);

// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
		for (int i = 0; i < 4; ++i)
			iValueLen += snprintf(szValues + iValueLen, sizeof(szValues) - iValueLen, ", '%u'", p->bSpecularColor[i]);
#endif


// Sub int iUpdateLen = snprintf(szUpdate, sizeof(szUpdate), "owner_id=%u, window=%d, pos=%d, count=%u, vnum=%u", p->owner, p->window, p->pos, p->count, p->vnum);


#ifdef ENABLE_SPECULAR_SYSTEM
		for (int i = 0; i < 4; ++i)
			iUpdateLen += snprintf(szUpdate + iUpdateLen, sizeof(szUpdate) - iUpdateLen, ", specular_color%d='%u'", i, p->bSpecularColor[i]);
#endif