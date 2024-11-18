// Sub ITEM_FLAG_APPLICABLE, adauga 

#ifdef ENABLE_SPECULAR_SYSTEM
			ITEM_FLAG_COLOR = (1 << 15),
#endif

// Nu trebuie neaparat sa ai 15, pune urmatorul nr dupa ultimul

// Cauta si inlocuieste GetSpecularPowerf
#ifdef ENABLE_SPECULAR_SYSTEM
		float	GetSpecularPowerf(bool bIsColor = false) const;
#else
		float	GetSpecularPowerf() const;
#endif


// Sub CDynamicPool<CItemData> adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	public:
		bool IsSpecularColorItem() const;
#endif