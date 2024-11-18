// Deasupra CEffectMeshScript::GetTimeTableAlphaPointer
// Adauga 

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
void CEffectMeshScript::SetEffectColor(float fColorR, float fColorG, float fColorB, float fAlpha)
{
	m_pColor = D3DXCOLOR(fColorR, fColorG, fColorB, fAlpha);
	m_bNewColor = true;
}

void CEffectMeshScript::SetEffectColor(const D3DXCOLOR & pColor)
{
	m_pColor = D3DXCOLOR(pColor);
	m_bNewColor = true;
}

bool CEffectMeshScript::GetEffectColor(DWORD dwMeshIndex, D3DXCOLOR * pColor)
{
	if (!CheckMeshIndex(dwMeshIndex))
		return false;

	*pColor = m_pColor;
	return true;
}
#endif

// Inauntrul CEffectMeshScript::OnClear()
// Adauga 


#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
	m_pColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_bNewColor = false;
#endif


// Inauntrul CEffectMeshScript::CEffectMeshScript()
// Adauga

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
	m_pColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_bNewColor = false;
#endif