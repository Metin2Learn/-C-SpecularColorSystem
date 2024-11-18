// Deasupra initshop()

#ifdef ENABLE_SPECULAR_SYSTEM
PyObject* shopGetSpecularColor(PyObject* poSelf, PyObject* poArgs)
{
	int iIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iIndex))
		return Py_BuildException();

	const TShopItemData* c_pItemData;

	if (CPythonShop::Instance().GetItemData(iIndex, &c_pItemData))
		return Py_BuildValue("iiii", c_pItemData->bSpecularColor[0], c_pItemData->bSpecularColor[1], c_pItemData->bSpecularColor[2], c_pItemData->bSpecularColor[3]);

	return Py_BuildValue("i", 0);
}
#endif

// Inauntrul initshop()

#ifdef ENABLE_SPECULAR_SYSTEM
		{ "GetSpecularColor",			shopGetSpecularColor,			METH_VARARGS },
#endif