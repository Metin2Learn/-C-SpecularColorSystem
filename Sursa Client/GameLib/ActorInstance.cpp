// Inauntrul void CActorInstance::__Initialize()
// Adauga 

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
	m_pColor = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
#endif


// Adauga la sfarsit de fisier:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
void CActorInstance::RegisterEffectColor(const D3DXCOLOR& pColor)
{
	m_pColor = pColor;
}
#endif