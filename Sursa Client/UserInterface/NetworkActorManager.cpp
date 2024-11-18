// Sub m_stName = src.m_stName; adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(m_bSpecularColor, src.m_bSpecularColor, sizeof(m_bSpecularColor));
#endif

// Sub m_stName=""; adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	memset(m_bSpecularColor, 0, sizeof(m_bSpecularColor));
#endif

// Inauntrul CInstanceBase* CNetworkActorManager::__AppendCharacterManagerActor(SNetworkActorData& rkNetActorData)
// Sub kCreateData.m_isMain=__IsMainActorVID(dwVID);
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(kCreateData.m_bSpecularColor, rkNetActorData.m_bSpecularColor, sizeof(kCreateData.m_bSpecularColor));
#endif

// Inauntrul void CNetworkActorManager::UpdateActor(const SNetworkUpdateActorData& c_rkNetUpdateActorData)
// Inlocuieste astea:

#ifdef ENABLE_SPECULAR_SYSTEM
		for (int i = 0; i < SPECULAR_WEAR_MAX_NUM; i++)
			pkInstFind->SetSpecularColor(i, c_rkNetUpdateActorData.m_bSpecularColor[i]);

		pkInstFind->ChangeArmor(c_rkNetUpdateActorData.m_dwArmor, c_rkNetUpdateActorData.m_bSpecularColor[0], c_rkNetUpdateActorData.m_bSpecularColor[1], c_rkNetUpdateActorData.m_bSpecularColor[2], c_rkNetUpdateActorData.m_bSpecularColor[3]);
		pkInstFind->ChangeWeapon(c_rkNetUpdateActorData.m_dwWeapon, c_rkNetUpdateActorData.m_bSpecularColor[4], c_rkNetUpdateActorData.m_bSpecularColor[5], c_rkNetUpdateActorData.m_bSpecularColor[6], c_rkNetUpdateActorData.m_bSpecularColor[7]);
		pkInstFind->ChangeHair(c_rkNetUpdateActorData.m_dwHair, c_rkNetUpdateActorData.m_bSpecularColor[8], c_rkNetUpdateActorData.m_bSpecularColor[9], c_rkNetUpdateActorData.m_bSpecularColor[10], c_rkNetUpdateActorData.m_bSpecularColor[11]);
#else
		pkInstFind->ChangeArmor(c_rkNetUpdateActorData.m_dwArmor);
		pkInstFind->ChangeWeapon(c_rkNetUpdateActorData.m_dwWeapon);
		pkInstFind->ChangeHair(c_rkNetUpdateActorData.m_dwHair);
#endif	

// Mai jos, cauta:

rkNetActorData.m_byPKMode=c_rkNetUpdateActorData.m_byPKMode;

// Adauga sub:

#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(rkNetActorData.m_bSpecularColor, c_rkNetUpdateActorData.m_bSpecularColor, sizeof(rkNetActorData.m_bSpecularColor));
#endif