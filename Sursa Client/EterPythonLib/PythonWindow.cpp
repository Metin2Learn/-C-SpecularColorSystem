#include "../EterLib/CRenderTargetManager.h"

// Sub functia CWindow * CWindow::PickTopWindow(long x, long y)
// Adauga:

	CUiRenderTarget::CUiRenderTarget(PyObject* ppyObject) : CWindow(ppyObject)
	{
		m_dwIndex = -1;
	}
	CUiRenderTarget::~CUiRenderTarget() = default;

	bool CUiRenderTarget::SetRenderTarget(uint8_t index)
	{
		if (!CRenderTargetManager::Instance().GetRenderTarget(index))
		{
			if (!CRenderTargetManager::Instance().CreateRenderTarget(index, GetWidth(), GetHeight()))
			{
				TraceError("CRenderTargetManager could not create the texture. w %d h %d", GetWidth(), GetHeight());
				return false;
			}
		}
		m_dwIndex = index;

		UpdateRect();
		return true;
	}

	void CUiRenderTarget::OnRender()
	{
		auto target = CRenderTargetManager::Instance().GetRenderTarget(m_dwIndex);
		if (!target)
		{
			TraceError("SetRenderingRect -> target empty!");
			return;
		}

		target->SetRenderingRect(&m_rect);

		target->RenderTexture();
	}