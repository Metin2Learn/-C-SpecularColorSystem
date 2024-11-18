// Adauga printre void-uri:


#ifdef ENABLE_SPECULAR_SYSTEM
void CPythonExchange::SetSpecularColor(int iPos, BYTE* bColors, bool bSelf)
{
	if (iPos >= EXCHANGE_ITEM_MAX_NUM)
		return;

	if (bSelf)
		memcpy(m_self.bSpecularColor[iPos], bColors, sizeof(m_self.bSpecularColor[iPos]));
	else
		memcpy(m_victim.bSpecularColor[iPos], bColors, sizeof(m_victim.bSpecularColor[iPos]));
}

BYTE* CPythonExchange::GetSpecularColor(int iPos, bool bSelf)
{
	if (iPos >= EXCHANGE_ITEM_MAX_NUM)
		return 0;

	BYTE* bColors = bSelf == true ? m_self.bSpecularColor[iPos] : m_victim.bSpecularColor[iPos];
	return bColors;
}
#endif