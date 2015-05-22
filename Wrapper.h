// Wrapper.h

#pragma once
#include "SmartPtr.h"
#include "Lib3Mf.h"
//#include "CameraTool.h" // not wrapped yet as of 5/18 -- 406 lines of code to wrap. FML
//#include "Renderer.h"  // not wrapped yet as of 5/18  -- 1193 lines of code to wrap. FML
#include "WrappedSceneContainer.h" // not wrapped yet as of 5/18 -- 402 lines of code to wrap

using namespace WrappedRenderTools;
using namespace System;
using std::string;

namespace Wrapper {


	public ref class Model{
	public:
		String^ GetText();

	};

	public ref class TestWrapper // supposed to be the starting point to emulate the entire appcore, maybe call it the Application Wrapper
	{
	public:
		TestWrapper();
		void InitTheApp();
		void CloseTheApp();
		HRESULT Initialize(_In_ HWND hWnd);

		int GetIntTestMethod();
		
		void ErrorMessage(DWORD dwError);

		Model^ ImportModel3MF(_In_z_ String^ lpstrFileName);

		void RenderTheFrame();

	private:
		bool m_geometryValid;

		//WrappedSceneContainer m_sceneContainer;
		//Camera m_camera;
		//Renderer m_renderer;
		//CCameraTool m_cameraTool;
	};



}
