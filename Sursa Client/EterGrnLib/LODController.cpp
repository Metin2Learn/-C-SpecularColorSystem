// Deasupra CGrannyLODController::CGrannyLODController() :
// Adauga

#ifdef ENABLE_SPECULAR_SYSTEM
void CGrannyLODController::SetSpecularColor(float fSpecular, float fColorR, float fColorG, float fColorB)
{
	std::deque<CGrannyModelInstance *>::iterator i;
	for (i=m_que_pkModelInst.begin(); i!=m_que_pkModelInst.end(); ++i)
	{
		CGrannyModelInstance* pkModelInst=(*i);
		pkModelInst->SetSpecularColor(fSpecular, fColorR, fColorG, fColorB);
	}
}
#endif