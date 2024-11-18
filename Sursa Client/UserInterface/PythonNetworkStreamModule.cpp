// Deasupra void initnet() adauga


#ifdef ENABLE_SPECULAR_SYSTEM
PyObject* netSendSpecularColorPacket(PyObject* poSelf, PyObject* poArgs)
{
	int dwPos;
	if (!PyTuple_GetInteger(poArgs, 0, &dwPos))
		return Py_BuildException();

	BYTE bColorR, bColorG, bColorB, bColorA;
	if (!PyTuple_GetInteger(poArgs, 1, &bColorR))
		return Py_BuildException();
	if (!PyTuple_GetInteger(poArgs, 2, &bColorG))
		return Py_BuildException();
	if (!PyTuple_GetInteger(poArgs, 3, &bColorB))
		return Py_BuildException();
	if (!PyTuple_GetInteger(poArgs, 4, &bColorA))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream = CPythonNetworkStream::Instance();
	rkNetStream.SendSpecularColorPacket(dwPos, bColorR, bColorG, bColorB, bColorA);
	return Py_BuildNone();
}
#endif

// Inauntrul void initnet() adauga

#ifdef ENABLE_SPECULAR_SYSTEM
		{ "SendSpecularColorPacket",				netSendSpecularColorPacket,					METH_VARARGS },
#endif