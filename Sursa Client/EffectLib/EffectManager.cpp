// Deasupra BOOL CEffectManager::RegisterEffect(const char * c_szFileName,bool isExistDelete,bool isNeedCache)
// Adauga:

void CEffectManager::RenderOne(DWORD id)
{
	STATEMANAGER.SetTexture(0, NULL);
	STATEMANAGER.SetTexture(1, NULL);

	
	const auto& pEffectInstance = m_kEftInstMap.find(id);

	if (pEffectInstance != m_kEftInstMap.end())
	{
		pEffectInstance->second->SetIgnoreFrustum(true);
		pEffectInstance->second->Show();
		pEffectInstance->second->Render();
	}
	else
		TraceError("!RenderOne, not found");
}

// Cauta CEffectManager::CreateEffectInstance
// Adauga asta la sfarsitul parantezei:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
	, const D3DXCOLOR & pColor
#endif


// Mai jos gasesti pEffectInstance->SetEffectDataPointer
// Adauga asta, la fel, la sfarsitul parantezei:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
		, pColor
#endif


// Adauga asta la sfarsitul fisierului:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
void CEffectManager::SetEffectColor(DWORD dwEffectID, float fColorR, float fColorG, float fColorB, float fAlpha)
{
	if (!dwEffectID)
		return;

	CEffectData * pEffect;
	if (!GetEffectData(dwEffectID, &pEffect))
	{
		TraceError("CEffectManager::SetEffectColor - NO DATA :%d\n", dwEffectID); 
		return;
	}
	
	CEffectInstance * pEffectInstance = CEffectInstance::New();	
	pEffectInstance->SetEffectColor(pEffect, fColorR, fColorG, fColorB, fAlpha);
}
#endif