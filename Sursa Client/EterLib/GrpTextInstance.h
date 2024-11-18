#include "Locale_inc.h"
#include "GrpImageInstance.h"

// Sub struct SHyperlink
// Adauga 

		struct SEmoji
		{
			short x;
			CGraphicImageInstance* pInstance;

			SEmoji() : x(0)
			{
				pInstance = NULL;
			}
		};
		
// Sub std::vector<SHyperlink> m_hyperlinkVector;
// Adauga

std::vector<SEmoji> m_emojiVector;