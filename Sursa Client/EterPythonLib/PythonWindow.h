#include <cstdint> // Daca nu-l ai

//Sub functia class CLayer : public CWindow
//Adauga:

	class CUiRenderTarget : public CWindow
	{
	public:
		CUiRenderTarget(PyObject* ppyObject);
		virtual ~CUiRenderTarget();

		bool SetRenderTarget(uint8_t index);

	protected:
		DWORD m_dwIndex;
		void OnRender();
	};
