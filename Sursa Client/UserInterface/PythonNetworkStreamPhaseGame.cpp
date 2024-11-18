// Cauta case EXCHANGE_SUBHEADER_GC_ITEM_ADD:
// Inauntrul if-ului, adauga

#ifdef ENABLE_SPECULAR_SYSTEM
				CPythonExchange::Instance().SetSpecularColor(iSlotIndex, exchange_packet.bSpecularColor, true);
#endif

// Mai jos, inauntrul "else" adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
				CPythonExchange::Instance().SetSpecularColor(iSlotIndex, exchange_packet.bSpecularColor, false);
#endif

// La sfarsit de fisier, adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
bool CPythonNetworkStream::SendSpecularColorPacket(DWORD dwPos, BYTE bColorR, BYTE bColorG, BYTE bColorB, BYTE bColorA)
{
	TPacketCGSpecularColor packet;
	packet.header = HEADER_CG_SPECULAR_COLOR;
	packet.dwPos = dwPos;
	packet.bColor[0] = bColorR;
	packet.bColor[1] = bColorG;
	packet.bColor[2] = bColorB;
	packet.bColor[3] = bColorA;

	if (!Send(sizeof(packet), &packet))
	{
		Tracen("CPythonNetworkStream::SendSpecularColorPacket - ERROR");
		return false;
	}

	return true;
}
#endif