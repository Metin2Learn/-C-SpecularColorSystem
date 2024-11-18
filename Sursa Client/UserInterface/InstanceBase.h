#include "GameType.h"

// Sub m_stName adauga

#ifdef ENABLE_SPECULAR_SYSTEM
			BYTE	m_bSpecularColor[SPECULAR_WEAR_MAX_NUM];
#endif

// Cauta si inlocuieste DWORD	__AttachEffect(UINT eEftType); cu:

#if defined(ENABLE_SPECULAR_SYSTEM) && defined(ENABLE_EFFECT_COLOR_SYSTEM)
		DWORD	__AttachEffect(UINT eEftType, const D3DXCOLOR & pColor = (1.0, 1.0, 1.0, 1.0));
#else
		DWORD	__AttachEffect(UINT eEftType);
#endif


// Sub SetPartyMemberFlag(bool bFlag); adauga:

		DWORD					GetArmor();
		DWORD					GetHair();
		DWORD					GetWeapon();
		
// Cauta si inlocuieste toate functiile astea:

#ifdef ENABLE_SPECULAR_SYSTEM
		void					SetShape(DWORD eShape, float fSpecular = 0.0f, bool bIsColor = false, BYTE r = 0, BYTE g = 0, BYTE b = 0, BYTE a = 0);
		void					SetArmor(DWORD dwArmor, BYTE r = 0, BYTE g = 0, BYTE b = 0, BYTE a = 0, bool bUpdate = false, bool bEffect = true);
		void					SetHair(DWORD eHair, BYTE r = 0, BYTE g = 0, BYTE b = 0, BYTE a = 0, bool bUpdate = false);
		bool					SetWeapon(DWORD eWeapon, BYTE r = 0, BYTE g = 0, BYTE b = 0, BYTE a = 0, bool bUpdate = false);
		bool					ChangeArmor(DWORD dwArmor, BYTE r = 0, BYTE g = 0, BYTE b = 0, BYTE a = 0, bool bUpdate = false);
		void					ChangeWeapon(DWORD eWeapon, BYTE r = 0, BYTE g = 0, BYTE b = 0, BYTE a = 0);
		void					ChangeHair(DWORD eHair, BYTE r = 0, BYTE g = 0, BYTE b = 0, BYTE a = 0);
#else
		void					SetShape(DWORD eShape, float fSpecular = 0.0f);
		void					SetArmor(DWORD dwArmor);
		void					SetHair(DWORD eHair);
		bool					SetWeapon(DWORD eWeapon);
		bool					ChangeArmor(DWORD dwArmor);
		void					ChangeWeapon(DWORD eWeapon);
		void					ChangeHair(DWORD eHair);
#endif


// Sub m_dwEmoticonTime adauga:

	protected:
		bool m_IsAlwaysRender;
	public:
		bool IsAlwaysRender();
		void SetAlwaysRender(bool val);
#ifdef ENABLE_SPECULAR_SYSTEM
	public:
		void SetSpecularColor(BYTE bIndex, BYTE bColor);
		void UpdateSpecularColor(BYTE bPart, BYTE r = 0, BYTE g = 0, BYTE b = 0, BYTE a = 0, bool bIsEquip = false, bool bIsClose = false, bool bIsDefault = false);
#ifdef ENABLE_EFFECT_COLOR_SYSTEM
		void UpdateEffectColor(UINT eEftType, BYTE r = 255, BYTE g = 255, BYTE b = 255, BYTE a = 0);
		void RefreshEffect();
		void RegisterEffectColor();
#endif
	protected:
		BYTE m_bSpecularColor[SPECULAR_WEAR_MAX_NUM];
		bool m_bRefresh;
		DWORD m_dwArmor;
#endif