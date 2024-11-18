// Deasupra } TPacketGCCharacterAdditionalInfo; adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	BYTE	bSpecularColor[SPECULAR_WEAR_MAX_NUM];
#endif


// Deasupra } TPacketGCCharacterUpdate; adauga:


#ifdef ENABLE_SPECULAR_SYSTEM
	BYTE		bSpecularColor[SPECULAR_WEAR_MAX_NUM];
#endif

// Deasupra } TPacketGCCharacterUpdate2; adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	BYTE		bSpecularColor[SPECULAR_WEAR_MAX_NUM];
#endif


// Deasupra } TPacketGCItemSet; adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	BYTE		bSpecularColor[4 + 1];
#endif

// Deasupra } TPacketGCItemSet2; adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	BYTE		bSpecularColor[4 + 1];
#endif

// Deasupra } TPacketGCItemUpdate; adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	BYTE		bSpecularColor[4 + 1];
#endif

// Deasupra } TPacketGCExchange; adauga

#ifdef ENABLE_SPECULAR_SYSTEM
	BYTE		bSpecularColor[4 + 1];
#endif


// La sfarsit de fisier, adauga:


#ifdef ENABLE_SPECULAR_SYSTEM
enum ESpecularColorHeader
{
	HEADER_CG_SPECULAR_COLOR = 224,
};

typedef struct SPacketCGSpecularColor
{
	BYTE	header;
	DWORD	dwPos;
	BYTE	bColor[4 + 1];
} TPacketCGSpecularColor;
#endif