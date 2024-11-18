// Inauntrul bool CPythonNetworkStream::RecvCharacterAppendPacket()
// Sub kNetActorData.m_dwMountVnum=0;
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memset(kNetActorData.m_bSpecularColor, 0, sizeof(kNetActorData.m_bSpecularColor));
#endif


// Inauntrul bool CPythonNetworkStream::RecvCharacterAdditionalInfo()
// Sub kNetActorData.m_dwMountVnum=chrInfoPacket.dwMountVnum;
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
		memcpy(kNetActorData.m_bSpecularColor, chrInfoPacket.bSpecularColor, sizeof(kNetActorData.m_bSpecularColor));
#endif

// Inauntrul bool CPythonNetworkStream::RecvCharacterUpdatePacket()
// Sub kNetUpdateActorData.m_dwMountVnum=chrUpdatePacket.dwMountVnum;
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(kNetUpdateActorData.m_bSpecularColor, chrUpdatePacket.bSpecularColor, sizeof(kNetUpdateActorData.m_bSpecularColor));
#endif

// Inauntrul bool CPythonNetworkStream::RecvCharacterUpdatePacketNew()
// Sub kNetUpdateActorData.m_dwMountVnum=chrUpdatePacket.dwMountVnum;
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(kNetUpdateActorData.m_bSpecularColor, chrUpdatePacket.bSpecularColor, sizeof(kNetUpdateActorData.m_bSpecularColor));
#endif