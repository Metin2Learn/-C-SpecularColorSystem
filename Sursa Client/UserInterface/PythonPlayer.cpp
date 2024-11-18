// Deasupra void CPythonPlayer::SetItemMetinSocket(TItemPos Cell, DWORD dwMetinSocketIndex, DWORD dwMetinNumber)
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
void CPythonPlayer::SetSpecularColor(TItemPos Cell, BYTE* bColors)
{
	if (!Cell.IsValidCell())
		return;

	memcpy((const_cast <TItemData*>(GetItemData(Cell)))->bSpecularColor, bColors, sizeof((const_cast <TItemData*>(GetItemData(Cell)))->bSpecularColor));
	PyCallClassMemberFunc(m_ppyGameWindow, "RefreshInventory", Py_BuildValue("()"));
}

BYTE* CPythonPlayer::GetSpecularColor(TItemPos Cell)
{
	if (Cell.IsValidCell())
		return (const_cast <TItemData*>(GetItemData(Cell)))->bSpecularColor;

	return 0;
}
#endif