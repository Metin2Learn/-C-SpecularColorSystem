#include "../eterPythonLib/StdAfx.h"
#include "../ScriptLib/StdAfx.h"
#include "../UserInterface/PythonSystem.h"

// Deasupra la bool CGraphicThingInstance::SetMotion(DWORD dwMotionKey, float blendTime, int loopCount, float speedRatio)
// Adauga 

#ifdef ENABLE_SPECULAR_SYSTEM
void CGraphicThingInstance::SetSpecularColor(UINT ePart, float fSpecular, float fColorR, float fColorG, float fColorB)
{
	if (ePart >= m_LODControllerVector.size())
	{
		TraceError("CGraphicThingInstance::SetSpecularColor(ePart(%d)<uPartCount(%d)) - ePart OUT OF RANGE", ePart, m_LODControllerVector.size());
		return;
	}

	if (!m_LODControllerVector[ePart])
	{
		TraceError("CGraphicThingInstance::SetSpecularColor(ePart(%d)) - ePart Data is NULL", ePart, m_LODControllerVector.size());
		return;
	}

	m_LODControllerVector[ePart]->SetSpecularColor(fSpecular, fColorR, fColorG, fColorB);
}
#endif

// Inauntrul void CGraphicThingInstance::UpdateLODLevel()
// Adauga 

	if (m_bSkipLod)
		return;
	
// Inauntrul void CGraphicThingInstance::OnInitialize()
// Adauga 

m_bSkipLod = false;