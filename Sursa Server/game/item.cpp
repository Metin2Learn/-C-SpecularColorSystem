// Sub memset( &m_aAttr, 0, sizeof(m_aAttr) ); adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memset(m_bSpecularColor, 0, sizeof(m_bSpecularColor));
#endif

// Sub m_dwLastOwnerPID = 0; adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memset(m_bSpecularColor, 0, sizeof(m_bSpecularColor));
#endif

// Sub pack.count	= m_dwCount; din UpdatePacket adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	memcpy(pack.bSpecularColor, m_bSpecularColor, sizeof(pack.bSpecularColor));
#endif

// Inauntrul case ITEM_COSTUME: adauga sub toSetPart:


#ifdef ENABLE_SPECULAR_SYSTEM
				bool bUnequip = false;
#endif

// Inauntrul if (GetSubType() == COSTUME_BODY), sub if (false == bAdd):

#ifdef ENABLE_SPECULAR_SYSTEM
						bUnequip = true;
#endif

// Inlocuieste m_pOwner->UpdatePacket(); cu

#ifdef ENABLE_SPECULAR_SYSTEM
					m_pOwner->UpdatePacket(bUnequip);
#else
					m_pOwner->UpdatePacket();
#endif

// Sub ch->BuffOnAttr_AddBuffsFromItem(this); adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	SaveSpecularColor();
#endif


// Sub m_pOwner->SetWear(GetCell() - INVENTORY_MAX_NUM, NULL); adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	SaveSpecularColor(false, true);
#endif

// La sfarsit de fisier adauga

#ifdef ENABLE_SPECULAR_SYSTEM
void CItem::SetSpecularColor(BYTE* bColors)
{
	memcpy(m_bSpecularColor, bColors, sizeof(m_bSpecularColor));
	UpdatePacket();
	Save();
}

BYTE * CItem::GetSpecularColor()
{
	return const_cast<BYTE*>(m_bSpecularColor);
}

BYTE CItem::GetSpecularColorSingle(BYTE index)
{
	assert(index < 4);
	return m_bSpecularColor[index];
}

void CItem::SaveSpecularColor(bool bClear, bool bUnequip)
{
	BYTE bType = 0;

	if (GetType() == ITEM_WEAPON)
		bType = 1;
	else if ((GetType() == ITEM_ARMOR && GetSubType() == ARMOR_BODY) or (GetType() == ITEM_COSTUME && GetSubType() == COSTUME_BODY))
		bType = 2;
	else if (GetType() == ITEM_COSTUME && GetSubType() == COSTUME_HAIR)
		bType = 3;

#ifdef __ACCE_SYSTEM__
	if (GetType() == ITEM_COSTUME && GetSubType() == COSTUME_ACCE)
		bType = 4;
#endif

	LPCHARACTER ch = GetOwner();
	if (!ch)
		return;

	BYTE bColorR = GetSpecularColorSingle(0);
	BYTE bColorG = GetSpecularColorSingle(1);
	BYTE bColorB = GetSpecularColorSingle(2);
	BYTE bColorA = GetSpecularColorSingle(3);

	if (bUnequip)
	{
		if (GetType() == ITEM_COSTUME && GetSubType() == COSTUME_BODY)
		{
			LPITEM alreadyArmorEquip = ch->GetWear(WEAR_BODY);

			if (alreadyArmorEquip)
			{
				bColorR = alreadyArmorEquip->GetSpecularColorSingle(0);
				bColorG = alreadyArmorEquip->GetSpecularColorSingle(1);
				bColorB = alreadyArmorEquip->GetSpecularColorSingle(2);
				bColorA = alreadyArmorEquip->GetSpecularColorSingle(3);
			}
		}

#ifdef __WEAPON_COSTUME_SYSTEM__
		if (GetType() == ITEM_COSTUME && GetSubType() == COSTUME_WEAPON)
		{
			LPITEM alreadyWeaponEquip = ch->GetWear(WEAR_WEAPON);

			if (alreadyWeaponEquip)
			{
				bColorR = alreadyWeaponEquip->GetSpecularColorSingle(0);
				bColorG = alreadyWeaponEquip->GetSpecularColorSingle(1);
				bColorB = alreadyWeaponEquip->GetSpecularColorSingle(2);
				bColorA = alreadyWeaponEquip->GetSpecularColorSingle(3);
			}
		}
#endif
	}
	
	if (bType != 0)
	{
		if (bClear)
			ch->ChatPacket(CHAT_TYPE_COMMAND, "SaveSpecularColor %d %s 0 0 0 0", bType, ch->GetName());
		else
			ch->ChatPacket(CHAT_TYPE_COMMAND, "SaveSpecularColor %d %s %d %d %d %d", bType, ch->GetName(), bColorR, bColorG, bColorB, bColorA);
	}
}
#endif