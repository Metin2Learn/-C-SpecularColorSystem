// Deasupra initTrade() adauga:


#ifdef ENABLE_SPECULAR_SYSTEM
PyObject* exchangeGetSpecularColor(PyObject* poTarget, PyObject* poArgs)
{
	int iPos;
	if (!PyTuple_GetInteger(poArgs, 0, &iPos))
		return Py_BuildException();

	bool bSelf;
	if (!PyTuple_GetBoolean(poArgs, 1, &bSelf))
		return Py_BadArgument();

	BYTE* bColors = CPythonExchange::Instance().GetSpecularColor(iPos, bSelf);
	return Py_BuildValue("iiii", bColors[0], bColors[1], bColors[2], bColors[3]);
}
#endif

// Inauntrul initTrade() adauga

#ifdef ENABLE_SPECULAR_SYSTEM
		{"GetSpecularColor",			exchangeGetSpecularColor,			METH_VARARGS},
#endif