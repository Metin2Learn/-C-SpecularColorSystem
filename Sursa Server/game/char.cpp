// Sub addPacket.bEmpire = m_bEmpire;
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
		for (int i = 0; i < 4; ++i)
		{
			if (GetWear(WEAR_COSTUME_BODY))
				addPacket.bSpecularColor[i] = GetWear(WEAR_COSTUME_BODY) ? GetWear(WEAR_COSTUME_BODY)->GetSpecularColorSingle(i) : 0;
			else
				addPacket.bSpecularColor[i] = GetWear(WEAR_BODY) ? GetWear(WEAR_BODY)->GetSpecularColorSingle(i) : 0;
		
			addPacket.bSpecularColor[i+4] = GetWear(WEAR_WEAPON) ? GetWear(WEAR_WEAPON)->GetSpecularColorSingle(i) : 0;
			addPacket.bSpecularColor[i+8] = GetWear(WEAR_COSTUME_HAIR) ? GetWear(WEAR_COSTUME_HAIR)->GetSpecularColorSingle(i) : 0;
		}
#endif

// Cauta si inlocuieste void CHARACTER::UpdatePacket()

#ifdef ENABLE_SPECULAR_SYSTEM
void CHARACTER::UpdatePacket(bool bUnequip)
#else
void CHARACTER::UpdatePacket()
#endif

// Sub pack.bPKMode	= m_bPKMode; adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	for (int i = 0; i < 4; ++i)
	{
		if (GetWear(WEAR_COSTUME_BODY) && !bUnequip)
			pack.bSpecularColor[i] = GetWear(WEAR_COSTUME_BODY) ? GetWear(WEAR_COSTUME_BODY)->GetSpecularColorSingle(i) : 0;
		else
			pack.bSpecularColor[i] = GetWear(WEAR_BODY) ? GetWear(WEAR_BODY)->GetSpecularColorSingle(i) : 0;

		pack.bSpecularColor[i+4] = GetWear(WEAR_WEAPON) ? GetWear(WEAR_WEAPON)->GetSpecularColorSingle(i) : 0;
		pack.bSpecularColor[i+8] = GetWear(WEAR_COSTUME_HAIR) ? GetWear(WEAR_COSTUME_HAIR)->GetSpecularColorSingle(i) : 0;
	}
#endif

// Sub item->SetAttributes(pItems->aAttr); adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
			item->SetSpecularColor(pItems->bSpecularColor);
#endif

// Sub al 2-lea item->SetAttributes(pItems->aAttr); adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
			item->SetSpecularColor(pItems->bSpecularColor);
#endif