// Sub thecore_memcpy(pack2.items[i].aAttr, item.pkItem->GetAttributes(), sizeof(pack2.items[i].aAttr)); adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
			memcpy(pack2.items[i].bSpecularColor, item.pkItem->GetSpecularColor(), sizeof(pack2.items[i].bSpecularColor));
#endif

// Mai jos cauta thecore_memcpy(pack2.item.aAttr, m_itemVector[pos].pkItem->GetAttributes(), sizeof(pack2.item.aAttr));

// Adauga sub:

#ifdef ENABLE_SPECULAR_SYSTEM
			memcpy(pack2.item.bSpecularColor, m_itemVector[pos].pkItem->GetSpecularColor(), sizeof(pack2.item.bSpecularColor));
#endif

// Mai jos, cauta memset(pack2.item.aAttr, 0, sizeof(pack2.item.aAttr));
// Adauga sub:

#ifdef ENABLE_SPECULAR_SYSTEM
			memset(pack2.item.bSpecularColor, 0, sizeof(pack2.item.bSpecularColor));
#endif