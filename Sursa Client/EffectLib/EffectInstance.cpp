// Cauta CEffectInstance::SetEffectDataPointer
// Adauga la sfarsitul parantezei:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
	, const D3DXCOLOR & pColor
#endif

//Sub CParticleSystemData * pParticle = pEffectData->GetParticlePointer(i);
// Adauga

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
		if (pColor.r > 0 && pColor.g > 0 && pColor.b > 0)
		{
			CParticleProperty * prob = pParticle->GetParticlePropertyPointer();
			D3DXCOLOR c;
			D3DXCOLOR d;
			c = D3DXCOLOR(pColor);

			for (TTimeEventTableColor::iterator it = prob->m_TimeEventColor.begin(); it != prob->m_TimeEventColor.end(); ++it)
			{
				d = D3DXCOLOR(it->m_Value.m_dwColor);
				c.a = d.a;
				it->m_Value.m_dwColor = (DWORD)c;
			}
		}
#endif


// Mai jos, sub CEffectMeshScript * pMesh = pEffectData->GetMeshPointer(i);

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
		if (pColor.r > 0 && pColor.g > 0 && pColor.b > 0)
			pMesh->SetEffectColor(pColor);
#endif

// Inauntrul  void CEffectInstance::__Initialize() adauga:

m_ignoreFrustum = false;


// Adauga la sfarsit:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
void CEffectInstance::SetEffectColor(CEffectData * pEffectData, float fColorR, float fColorG, float fColorB, float fAlpha)
{
	DWORD i;
	for (i = 0; i < pEffectData->GetParticleCount(); ++i)
	{
		CParticleSystemData * pParticle = pEffectData->GetParticlePointer(i);
		CParticleProperty * prob = pParticle->GetParticlePropertyPointer();
		D3DXCOLOR c = D3DXCOLOR(fColorR, fColorG, fColorB, fAlpha);
		D3DXCOLOR d;

		for (TTimeEventTableColor::iterator it = prob->m_TimeEventColor.begin(); it != prob->m_TimeEventColor.end(); ++it)
		{
			d = D3DXCOLOR(it->m_Value.m_dwColor);
			c.a = d.a;
			it->m_Value.m_dwColor = (DWORD)c;
		}
	}
	
	for (i = 0; i < pEffectData->GetMeshCount(); ++i)
	{
		CEffectMeshScript * pMesh = pEffectData->GetMeshPointer(i);
		pMesh->SetEffectColor(fColorR, fColorG, fColorB, fAlpha);
	}
}
#endif