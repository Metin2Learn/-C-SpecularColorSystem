// Deasupra initsafebox()

#ifdef ENABLE_SPECULAR_SYSTEM
PyObject* safeboxGetSpecularColor(PyObject* poSelf, PyObject* poArgs)
{
	int iPos;
	if (!PyTuple_GetInteger(poArgs, 0, &iPos))
		return Py_BadArgument();

	TItemData* pInstance;
	if (!CPythonSafeBox::Instance().GetItemDataPtr(iPos, &pInstance))
		return Py_BuildException();

	return Py_BuildValue("iiii", pInstance->bSpecularColor[0], pInstance->bSpecularColor[1], pInstance->bSpecularColor[2], pInstance->bSpecularColor[3]);
}

PyObject* safeboxGetMallSpecularColor(PyObject* poSelf, PyObject* poArgs)
{
	int iPos;
	if (!PyTuple_GetInteger(poArgs, 0, &iPos))
		return Py_BadArgument();

	TItemData* pInstance;
	if (!CPythonSafeBox::Instance().GetMallItemDataPtr(iPos, &pInstance))
		return Py_BuildException();

	return Py_BuildValue("iiii", pInstance->bSpecularColor[0], pInstance->bSpecularColor[1], pInstance->bSpecularColor[2], pInstance->bSpecularColor[3]);
}
#endif

// Inauntrul initsafebox()

#ifdef ENABLE_SPECULAR_SYSTEM
		{ "GetSpecularColor",			safeboxGetSpecularColor,				METH_VARARGS },
		{ "GetMallSpecularColor",		safeboxGetMallSpecularColor,			METH_VARARGS },
#endif