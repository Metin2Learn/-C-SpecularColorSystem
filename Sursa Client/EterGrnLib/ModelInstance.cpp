// Sub CGrannyModelInstance::SetSpecularInfo
// Adauga

#ifdef ENABLE_SPECULAR_SYSTEM
void CGrannyModelInstance::SetSpecularColor(float fSpecular, float fColorR, float fColorG, float fColorB)
{
	m_kMtrlPal.SetSpecularColor(fSpecular, fColorR, fColorG, fColorB);
}
#endif