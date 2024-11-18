#include "../EterLib/CRenderTargetManager.h"

// Inauntrul void CPythonApplication::RenderGame()

// Sub float fAspect=m_kWndMgr.GetAspect(); adauga:

m_kRenderTargetManager.RenderBackgrounds();

// Sub m_kEftMgr.Update(); adauga: 

m_kRenderTargetManager.DeformModels();

// Sub m_kChrMgr.Render(); adauga:

m_kRenderTargetManager.RenderModels();

// Sub TPixelPosition kPPosMainActor; adauga:

m_kRenderTargetManager.UpdateModels();

// Deasupra if (m_pyGraphic.RestoreDevice()) adauga:

CRenderTargetManager::Instance().ReleaseRenderTargetTextures();

// Deasupra rkBG.CreateCharacterShadowTexture(); adauga:

CRenderTargetManager::Instance().CreateRenderTargetTextures();