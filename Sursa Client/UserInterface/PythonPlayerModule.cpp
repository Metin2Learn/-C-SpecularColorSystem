// Deasupra void initPlayer() adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
PyObject* playerUpdateSpecularColor(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bPart;
	if (!PyTuple_GetByte(poArgs, 0, &bPart))
		return Py_BadArgument();

	BYTE r, g, b, a = 255;
	if (!PyTuple_GetByte(poArgs, 1, &r))
		return Py_BadArgument();
	if (!PyTuple_GetByte(poArgs, 2, &g))
		return Py_BadArgument();
	if (!PyTuple_GetByte(poArgs, 3, &b))
		return Py_BadArgument();
	if (!PyTuple_GetByte(poArgs, 4, &a))
		return Py_BadArgument();

	bool bIsEquip;
	if (!PyTuple_GetBoolean(poArgs, 5, &bIsEquip))
		bIsEquip = false;

	bool bIsClose;
	if (!PyTuple_GetBoolean(poArgs, 6, &bIsClose))
		bIsClose = false;

	bool bIsDefault;
	if (!PyTuple_GetBoolean(poArgs, 7, &bIsDefault))
		bIsDefault = false;

	CInstanceBase* pInstance = CPythonPlayer::Instance().NEW_GetMainActorPtr();
	if (!pInstance)
		return false;

	pInstance->UpdateSpecularColor(bPart, r, g, b, a, bIsEquip, bIsClose, bIsDefault);
	return Py_BuildNone();
}

PyObject* playerGetSpecularColor(PyObject* poSelf, PyObject* poArgs)
{
	switch (PyTuple_Size(poArgs))
	{
	case 1:
	{
		int iSlotIndex;
		if (!PyTuple_GetInteger(poArgs, 0, &iSlotIndex))
			return Py_BuildException();

		BYTE* bColors = CPythonPlayer::Instance().GetSpecularColor(TItemPos(INVENTORY, iSlotIndex));
		return Py_BuildValue("iiii", bColors[0], bColors[1], bColors[2], bColors[3]);
	}
	case 2:
	{
		TItemPos Cell;
		if (!PyTuple_GetByte(poArgs, 0, &Cell.window_type))
			return Py_BuildException();

		if (!PyTuple_GetInteger(poArgs, 1, &Cell.cell))
			return Py_BuildException();

		BYTE* bColors = CPythonPlayer::Instance().GetSpecularColor(Cell);
		return Py_BuildValue("iiii", bColors[0], bColors[1], bColors[2], bColors[3]);
	}
	default:
		return Py_BuildException();
	}
}

#ifdef ENABLE_EFFECT_COLOR_SYSTEM
PyObject* playerUpdateEffectColor(PyObject* poSelf, PyObject* poArgs)
{
	BYTE r, g, b, a = 255;
	if (!PyTuple_GetByte(poArgs, 0, &r))
		return Py_BadArgument();
	if (!PyTuple_GetByte(poArgs, 1, &g))
		return Py_BadArgument();
	if (!PyTuple_GetByte(poArgs, 2, &b))
		return Py_BadArgument();
	if (!PyTuple_GetByte(poArgs, 3, &a))
		return Py_BadArgument();

	CInstanceBase* pInstance = CPythonPlayer::Instance().NEW_GetMainActorPtr();
	if (!pInstance)
		return false;

	pInstance->UpdateEffectColor(587, r, g, b, a);
	return Py_BuildNone();
}

PyObject* playerRefreshEffect(PyObject* poSelf, PyObject* poArgs)
{
	CInstanceBase* pInstance = CPythonPlayer::Instance().NEW_GetMainActorPtr();
	if (!pInstance)
		return false;

	pInstance->RefreshEffect();
	return Py_BuildNone();
}
#endif
#endif

// Inauntrul initPlayer() adauga

#ifdef ENABLE_SPECULAR_SYSTEM
		{ "UpdateSpecularColor",		playerUpdateSpecularColor,			METH_VARARGS },
		{ "GetSpecularColor",			playerGetSpecularColor,				METH_VARARGS },
#ifdef ENABLE_EFFECT_COLOR_SYSTEM
		{ "UpdateEffectColor",			playerUpdateEffectColor,			METH_VARARGS },
		{ "RefreshEffect",				playerRefreshEffect,				METH_VARARGS },
#endif
#endif