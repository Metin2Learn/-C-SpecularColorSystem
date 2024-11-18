// Cauta si inlocuieste CItemData::GetSpecularPowerf
#ifdef ENABLE_SPECULAR_SYSTEM
float CItemData::GetSpecularPowerf(bool bIsColor) const
#else
float CItemData::GetSpecularPowerf() const
#endif

// Apoi adauga asta, in functie:

#ifdef ENABLE_SPECULAR_SYSTEM
	if (bIsColor && IsSpecularColorItem())
		return 0.1f;
#endif

// Mai jos, adauga functia asta:

#ifdef ENABLE_SPECULAR_SYSTEM
bool CItemData::IsSpecularColorItem() const
{
	// if (IsFlag(ITEM_FLAG_COLOR))
	if (
		(GetType() == ITEM_TYPE_ARMOR && GetSubType() == ARMOR_BODY)
		|| (GetType() == ITEM_TYPE_WEAPON && (GetSubType() <= WEAPON_FAN))
		|| (GetType() == ITEM_TYPE_COSTUME && GetSubType() == COSTUME_BODY)
		|| (GetType() == ITEM_TYPE_COSTUME && GetSubType() == COSTUME_HAIR)
		)
	{
		return true;
	}

	return false;
}
#endif