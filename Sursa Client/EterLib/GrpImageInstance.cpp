// Inauntrul void CGraphicImageInstance::OnRender()
// Inlocuieste:

	CGraphicImage * pImage = m_roImage.GetPointer();
	CGraphicTexture * pTexture = pImage->GetTexturePointer();

	float fimgWidth = pImage->GetWidth();
	float fimgHeight = pImage->GetHeight();

	const RECT& c_rRect = pImage->GetRectReference();
	float texReverseWidth = 1.0f / float(pTexture->GetWidth());
	float texReverseHeight = 1.0f / float(pTexture->GetHeight());
	
// Cu asta:

	CGraphicTexture* graphicTexture = m_roImage->GetTexturePointer();

	float fimgWidth = m_roImage->GetWidth() * m_v2Scale.x;
	float fimgHeight = m_roImage->GetHeight() * m_v2Scale.y;

	const RECT& c_rRect = m_roImage->GetRectReference();
	float texReverseWidth = 1.0f / float(graphicTexture->GetWidth());
	float texReverseHeight = 1.0f / float(graphicTexture->GetHeight());
	
	
// Mai jos, inlocuieste STATEMANAGER.SetTexture(0, pTexture->GetD3DTexture());
// Cu 

STATEMANAGER.SetTexture(0, graphicTexture->GetD3DTexture());


// Sub void CGraphicImageInstance::SetPosition(float fx, float fy)
// Adauga

void CGraphicImageInstance::SetScale(float fx, float fy)
{
	m_v2Scale.x = fx;
	m_v2Scale.y = fy;
}


// Inauntrul  CGraphicImageInstance::Initialize()
// Adauga 
m_v2Scale.x = m_v2Scale.y = 1.0f;