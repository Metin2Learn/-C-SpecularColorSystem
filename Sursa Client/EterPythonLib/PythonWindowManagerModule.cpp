// Sub PyObject * wndMgrRegister(PyObject * poSelf, PyObject * poArgs)
// Adauga:

#ifdef ENABLE_SPECULAR_SYSTEM
PyObject* wndMgrSetSlotSpecularImage(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();

	int iSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 1, &iSlotIndex))
		return Py_BuildException();

	char* szImagePath;
	if (!PyTuple_GetString(poArgs, 2, &szImagePath))
		return Py_BuildException();

	D3DXCOLOR diffuseColor;
	PyObject* pTuple;
	if (!PyTuple_GetObject(poArgs, 3, &pTuple))
		diffuseColor = D3DXCOLOR(1.0, 1.0, 1.0, 1.0);
	else
	{
		if (PyTuple_Size(pTuple) != 4)
			return Py_BuildException();
		if (!PyTuple_GetFloat(pTuple, 0, &diffuseColor.r))
			return Py_BuildException();
		if (!PyTuple_GetFloat(pTuple, 1, &diffuseColor.g))
			return Py_BuildException();
		if (!PyTuple_GetFloat(pTuple, 2, &diffuseColor.b))
			return Py_BuildException();
		if (!PyTuple_GetFloat(pTuple, 3, &diffuseColor.a))
			return Py_BuildException();
	}

	if (!pWin->IsType(UI::CSlotWindow::Type()))
		return Py_BuildException();

	UI::CSlotWindow* pSlotWin = (UI::CSlotWindow*)pWin;
	CGraphicImage* pImage = (CGraphicImage*)CResourceManager::Instance().GetResourcePointer(szImagePath);
	if (!pImage)
		return Py_BuildException();
	pSlotWin->SetSlotSpecularImage(iSlotIndex, pImage, diffuseColor);
	return Py_BuildNone();
}
#endif

PyObject* wndMgrRegisterRenderTarget(PyObject* poSelf, PyObject* poArgs)
{
	PyObject* po;
	if (!PyTuple_GetObject(poArgs, 0, &po))
		return Py_BuildException();
	char* szLayer;
	if (!PyTuple_GetString(poArgs, 1, &szLayer))
		return Py_BuildException();

	UI::CWindow* pWindow = UI::CWindowManager::Instance().RegisterRenderTarget(po, szLayer);
	return Py_BuildValue("i", pWindow);
}


PyObject* wndRenderTargetSetRenderTarget(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWindow;
	if (!PyTuple_GetWindow(poArgs, 0, &pWindow))
		return Py_BuildException();
	int index;
	if (!PyTuple_GetInteger(poArgs, 1, &index))
		return Py_BuildException();

	if (pWindow->IsType(UI::CUiRenderTarget::Type()))
	{
		((UI::CUiRenderTarget*)pWindow)->SetRenderTarget(index);
	}
	return Py_BuildNone();
}



// Inauntrul initwndMgr()


		{ "RegisterRenderTarget",		wndMgrRegisterRenderTarget,			METH_VARARGS },
		{ "SetRenderTarget",			wndRenderTargetSetRenderTarget,		METH_VARARGS },
#ifdef ENABLE_SPECULAR_SYSTEM
		{ "SetSlotSpecularImage",		wndMgrSetSlotSpecularImage,			METH_VARARGS },
#endif