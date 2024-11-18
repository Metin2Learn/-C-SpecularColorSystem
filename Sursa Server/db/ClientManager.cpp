// Cauta "FROM item%s WHERE owner_id=%d AND window='%s'",

// Adauga deasupra:

#ifdef ENABLE_SPECULAR_SYSTEM
				", specular_color0, specular_color1, specular_color2, specular_color3 "
#endif


// Inauntrul void CClientManager::QUERY_ITEM_SAVE(CPeer * pkPeer, const char * c_pData)
// Dupa asta:

	if (p->window == SAFEBOX || p->window == MALL)
	{
		CItemCache * c = GetItemCache(p->id);

		if (c)
		{
			TItemCacheSetPtrMap::iterator it = m_map_pkItemCacheSetPtr.find(c->Get()->owner);

			if (it != m_map_pkItemCacheSetPtr.end())
			{
				if (g_test_server)
					sys_log(0, "ITEM_CACHE: safebox owner %u id %u", c->Get()->owner, c->Get()->id);

				it->second->erase(c);
			}

			m_map_itemCache.erase(p->id);

			delete c;
		}
		
// Adauga:

		char szColumns[QUERY_MAX_LEN];
		char szValues[QUERY_MAX_LEN];
		
		int iLen = snprintf(szColumns, sizeof(szColumns), "id, owner_id, window, pos, count, vnum");

#ifdef ENABLE_SPECULAR_SYSTEM
		for (int i = 0; i < 4; ++i)
			iLen += snprintf(szColumns + iLen, sizeof(szColumns) - iLen, ", specular_color%d", i);
#endif

		int iValueLen = snprintf(szValues, sizeof(szValues), "%u, %u, %d, %d, %u, %u", p->id, p->owner, p->window, p->pos, p->count, p->vnum);

#ifdef ENABLE_SPECULAR_SYSTEM
		for (int i = 0; i < 4; ++i)
			iValueLen += snprintf(szValues + iValueLen, sizeof(szValues) - iValueLen, ", '%u'", p->bSpecularColor[i]);
#endif