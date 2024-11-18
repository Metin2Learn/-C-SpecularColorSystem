// Inauntrul PyObject * chrSetHair(PyObject* poSelf, PyObject* poArgs)
// Inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
	bool bSelect;
	if (!PyTuple_GetBoolean(poArgs, 1, &bSelect))
		bSelect = false;

	pkInst->SetHair(iRace, 0, 0, 0, 0, bSelect);
#else
	pkInst->SetHair(iRace);
#endif

// Inauntrul PyObject * chrSetArmor(PyObject* poSelf, PyObject* poArgs)
// Inlocuieste:

#ifdef ENABLE_SPECULAR_SYSTEM
	bool bSelect;
	if (!PyTuple_GetBoolean(poArgs, 1, &bSelect))
		bSelect = false;

	pkInst->SetArmor(iForm, 0, 0, 0, 0, bSelect);
#else
	pkInst->SetArmor(iForm);
#endif

// Dupa functie, adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
PyObject* chrUpdateSpecularColor(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bType;
	if (!PyTuple_GetByte(poArgs, 0, &bType))
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

	CInstanceBase* pkInst = CPythonCharacterManager::Instance().GetSelectedInstancePtr();
	if (!pkInst)
		return Py_BuildNone();

	pkInst->UpdateSpecularColor(bType, r, g, b, a);
	return Py_BuildNone();
}
#endif

PyObject* chrGetHair(PyObject* poSelf, PyObject* poArgs)
{
	CInstanceBase* pkInst = CPythonCharacterManager::Instance().GetSelectedInstancePtr();
	if (!pkInst)
		return Py_BuildValue("i", 0);

	return Py_BuildValue("i", pkInst->GetHair());
}

// Inauntrul initchr() adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
		{ "UpdateSpecularColor", 			chrUpdateSpecularColor,				METH_VARARGS },
#endif
		{ "GetHair", 						chrGetHair, 						METH_VARARGS },
		
	
// Sub PyModule_AddIntConstant(poModule, "PART_WEAPON_LEFT
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
	PyModule_AddIntConstant(poModule, "PART_MAIN", CRaceData::PART_MAIN);
	PyModule_AddIntConstant(poModule, "PART_HAIR", CRaceData::PART_HAIR);
#endif