// Sub byyPlacedItemSize
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
				CGraphicImageInstance* pInstanceSpecular;
#endif

// Sub SetSlotStyle
// Adauga 

#ifdef ENABLE_SPECULAR_SYSTEM
			void SetSlotSpecularImage(DWORD dwIndex, CGraphicImage* specularImage, D3DXCOLOR& diffuseColor);
#endif