// Dupa functia for (int j = 0; j < ITEM_ATTRIBUTE_MAX_NUM; j++)
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
		for (int i = 0; i < 4; ++i)
			str_to_number(item.bSpecularColor[i], row[cur++]);
#endif

// Deasupra "FROM item%s WHERE owner_id=%d AND (window < %d or window = %d)",
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
					", specular_color0, specular_color1, specular_color2, specular_color3 "
#endif

// Deasupra urmatorului "FROM item%s WHERE owner_id=%d AND (window < %d or window = %d)",
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
				", specular_color0, specular_color1, specular_color2, specular_color3 "
#endif