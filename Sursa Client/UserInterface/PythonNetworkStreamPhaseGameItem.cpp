// Inauntrul bool CPythonNetworkStream::RecvSafeBoxSetPacket()
// Sub kItemData.flags = kItemSet.flags;


#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(kItemData.bSpecularColor, kItemSet.bSpecularColor, sizeof(kItemData.bSpecularColor));
#endif


// Inauntrul bool CPythonNetworkStream::RecvMallItemSetPacket()
// Sub kItemData.flags = kItemSet.flags;
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(kItemData.bSpecularColor, kItemSet.bSpecularColor, sizeof(kItemData.bSpecularColor));
#endif

// Inauntrul bool CPythonNetworkStream::RecvItemSetPacket()
// Sub kItemData.count	= packet_item_set.count;
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(kItemData.bSpecularColor, packet_item_set.bSpecularColor, sizeof(kItemData.bSpecularColor));
#endif

// Inauntrul bool CPythonNetworkStream::RecvItemSetPacket2()
// Sub kItemData.flags = packet_item_set.flags;
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(kItemData.bSpecularColor, packet_item_set.bSpecularColor, sizeof(kItemData.bSpecularColor));
#endif

// Inauntrul bool CPythonNetworkStream::RecvItemUpdatePacket()
// Sub rkPlayer.SetItemCount(packet_item_update.Cell, packet_item_update.count);
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	rkPlayer.SetSpecularColor(packet_item_update.Cell, packet_item_update.bSpecularColor);
#endif