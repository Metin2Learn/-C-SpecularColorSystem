// Sub CWindow * CWindowManager::RegisterBox(PyObject * po, const char * c_szLayer)

// Adauga 

	CWindow* CWindowManager::RegisterRenderTarget(PyObject* po, const char* c_szLayer)
	{
		assert(m_LayerWindowMap.end() != m_LayerWindowMap.find(c_szLayer));

		CWindow* pWin = new CUiRenderTarget(po);
		m_LayerWindowMap[c_szLayer]->AddChild(pWin);

#ifdef __WINDOW_LEAK_CHECK__
		gs_kSet_pkWnd.insert(pWin);
#endif
		return pWin;
	}