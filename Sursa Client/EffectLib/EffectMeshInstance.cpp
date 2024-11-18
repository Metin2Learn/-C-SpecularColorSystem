// Sub m_pMeshScript->GetColorFactor(i, &Color);

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
		D3DXCOLOR newColor(1.0f, 1.0f, 1.0f, 1.0f);
		m_pMeshScript->GetEffectColor(i, &newColor);
		
		if (m_pMeshScript->m_bNewColor)
			Color = newColor;
#endif