// Sub HEADER_CG_CLIENT_VERSION
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
		case HEADER_CG_SPECULAR_COLOR:
			SpecularColor(ch, c_pData);
			break;
#endif

// La sfarsit de functie, adauga:

// Am pus sabia de lv 1 +9, ca item default, sa nu primesti crash la server. Il inlocuiesti tu cu ce vnum vrei pentru Specular Color Ticket

#ifdef ENABLE_SPECULAR_SYSTEM
void CInputMain::SpecularColor(LPCHARACTER ch, const char* c_pData)
{
	if (!ch)
		return;
	
	quest::PC * pPC = quest::CQuestManager::instance().GetPCForce(ch->GetPlayerID());
	
	if (pPC->IsRunning())
		return;

	TPacketCGSpecularColor * packet = (TPacketCGSpecularColor*) c_pData;
	
	if (!packet)
		return;
	
	LPITEM item = ch->GetInventoryItem(packet->dwPos);
	
	if (!item)
		return;
	
	if (!ch->IsGM())
	{
		LPITEM needItem = ch->FindSpecifyItem(19);
		if (!needItem)
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "You don't have Specular Ticket.");
			return;
		}
		needItem->SetCount(needItem->GetCount() - 1);
	}
	
	item->SetSpecularColor(packet->bColor);
	ch->UpdatePacket();
}
#endif