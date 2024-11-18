// #include "ResourceManager.h"

// Inauntrul void CGraphicTextInstance::Update()
// Sub m_hyperlinkVector.clear();
// Adauga


	if (m_emojiVector.size() != 0)
	{
		for (std::vector<SEmoji>::iterator itor = m_emojiVector.begin(); itor != m_emojiVector.end(); ++itor)
		{
			SEmoji& rEmo = *itor;
			if (rEmo.pInstance)
			{
				CGraphicImageInstance::Delete(rEmo.pInstance);
				rEmo.pInstance = NULL;
			}
		}
	}
	m_emojiVector.clear();
	
// Mai jos cauta asta:

			else	// ¾Æ¶ø¿Ü ´Ù¸¥ Áö¿ª.
			{
				int x = 0;
				int len;				
				int hyperlinkStep = 0;
				SHyperlink kHyperlink;
				std::wstring hyperlinkBuffer;
				
				
// Sub ea, adauga asta:

				SEmoji kEmoji;
				int emojiStep = 0;
				std::wstring emojiBuffer;
				
				
// Mai jos, sub hyperlinkBuffer.append(1, wText[i]); adauga

						else if (emojiStep == 1)
							emojiBuffer.append(1, wText[i]);
						
						
// Sub toata functia " else if (ret == TEXT_TAG_HYPERLINK_END) "
// Adauga 

						else if (ret == TEXT_TAG_EMOJI_START)
						{
							emojiStep = 1;
							emojiBuffer = L"";
						}
						else if (ret == TEXT_TAG_EMOJI_END)
						{
							kEmoji.x = x;

							char retBuf[1024];
							int retLen = Ymir_WideCharToMultiByte(GetDefaultCodePage(), 0, emojiBuffer.c_str(), emojiBuffer.length(), retBuf, sizeof(retBuf) - 1, NULL, NULL);
							retBuf[retLen] = '\0';

							char szPath[255];
							snprintf(szPath, sizeof(szPath), "icon/%s.tga", retBuf);
							if (CResourceManager::Instance().IsFileExist(szPath))
							{
								CGraphicImage* pImage = (CGraphicImage*)CResourceManager::Instance().GetResourcePointer(szPath);
								kEmoji.pInstance = CGraphicImageInstance::New();
								kEmoji.pInstance->SetImagePointer(pImage);
								m_emojiVector.push_back(kEmoji);
								memset(&kEmoji, 0, sizeof(SEmoji));
								for (int i = 0; i < pImage->GetWidth() / (pSpaceInfo->width - 1); ++i)
									x += __DrawCharacter(pFontTexture, dataCodePage, ' ', dwColor);
								if (pImage->GetWidth() % (pSpaceInfo->width - 1) > 1)
									x += __DrawCharacter(pFontTexture, dataCodePage, ' ', dwColor);
							}
							else {
								TraceError("No res %s", szPath);
							}
							emojiStep = 0;
							emojiBuffer = L"";
						}
						
						
/// La sfarsitul functiei Render, gasesti if-ul asta: if (m_hyperlinkVector.size() != 0)
// Sub intreg if-ul ala, adauga:

	if (!m_emojiVector.empty())
	{
		for (auto& rEmo : m_emojiVector)
		{
			if (rEmo.pInstance)
			{
				rEmo.pInstance->SetPosition(fStanX + rEmo.x, (fStanY + 7.0) - (rEmo.pInstance->GetHeight() / 2));
				rEmo.pInstance->Render();
			}
		}
	}
	
// Inauntrul void CGraphicTextInstance::Destroy()
// Adauga 

	if (m_emojiVector.size() != 0)
	{
		for (std::vector<SEmoji>::iterator itor = m_emojiVector.begin(); itor != m_emojiVector.end(); ++itor)
		{
			SEmoji& rEmo = *itor;
			if (rEmo.pInstance)
			{
				CGraphicImageInstance::Delete(rEmo.pInstance);
				rEmo.pInstance = NULL;
			}
		}
	}
	m_emojiVector.clear();