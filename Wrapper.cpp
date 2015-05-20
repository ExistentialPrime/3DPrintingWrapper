// This is the main DLL file.

#include "stdafx.h"

#include "ObjParser.h"
#include "StlParser.h"
#include "Lib3mf.h"

#include "GeometryBuilder.h"
#include "MaterialUtils.h"

#include "LoadImage.h"

#include "MeshRenderableShape.h"
#include "SliceRenderableShape.h"
#include "TextureManager.h"

#include "VerifierLib.h"

#include "Wrapper.h"
#include <sstream>

using namespace RenderTools;

using namespace Wrapper;
using namespace System::Runtime::InteropServices;
using std::string;

#if _MSC_VER > 1499 // Visual C++ 2008 only
#include <msclr/marshal.h>
using namespace msclr::interop;
#endif 

TestWrapper::TestWrapper(){

}

int TestWrapper::GetIntTestMethod(){

	return 44;
}

void TestWrapper::ErrorMessage(DWORD dwError)
{
	LPVOID pText = 0;

	::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, dwError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&pText, 0, NULL);
	MessageBox(NULL, (LPCWSTR)pText, 0, MB_OK);
	LocalFree(pText);
}

Model^ TestWrapper::ImportModel3MF(_In_z_ String^ lpstrFileName)
{
	HRESULT hr;

	LPCTSTR fileName = LPCTSTR(Marshal::StringToHGlobalUni(lpstrFileName).ToPointer());
	
	MessageBox(NULL, (LPCWSTR)fileName, 0, MB_OK); // Not needed anymore

	SmartPtr<IStream> spFileStream;
	if (SUCCEEDED(hr = SHCreateStreamOnFile(fileName, STGM_READ, &spFileStream)))
	{
		
		SmartPtr<IPackage3mf> package;
		hr = CreatePackage3mf(&package);
		
		if (SUCCEEDED(hr))
			hr = package->Read(spFileStream);

		SmartPtr<IStream> spModelStream;
		if (SUCCEEDED(hr))
		{
			hr = package->GetModelStream(&spModelStream);
		}

		if (SUCCEEDED(hr) && (spModelStream != nullptr))
		{
			SmartPtr<IModelReader3mf> reader;
			if (SUCCEEDED(hr))
			{
				hr = CreateModelReader3mf(&reader);
			}

			UINT descCnt = 0;
			hr = package->GetTextureStreamDescCount(&descCnt);
			if (SUCCEEDED(hr))
				hr = reader->SetTextureStreamDescCount(descCnt);

			for (UINT i = 0; SUCCEEDED(hr) && i < descCnt; ++i)
			{
				SmartPtr<ITextureStreamDesc3mf> desc;
				hr = package->GetTextureStreamDesc(i, &desc);
				if (SUCCEEDED(hr))
					hr = reader->SetTextureStreamDesc(i, desc);
			}

			if (SUCCEEDED(hr))
				hr = reader->ReadModel(spModelStream);

			if (SUCCEEDED(hr))
			{
//				std::vector<SmartPtr<MeshTools::Geometry>> geometries;
//				hr = ProcessImportOutput3mf(reader, &geometries);

				ModelUnit3mf unit;
				if (SUCCEEDED(hr))
					hr = reader->GetUnit(&unit);

//				if (SUCCEEDED(hr))
//					hr = OnModelImported(geometries, (ModelUnit)unit, reader, true);
			}
		}
	}
	//return SUCCEEDED(hr) ? true : false;


	ErrorMessage(hr);

	return gcnew Model();
}

void TestWrapper::InitTheApp()
{

	m_geometryValid = false; //this just determines if the model is loaded/valid. this would be a great candidate for moving to the C# class parent
	TextureManager::Create();
}
void TestWrapper::CloseTheApp()
{
	TextureManager::Destroy();
}

HRESULT TestWrapper::Initialize(_In_ HWND hWnd)
{
	HRESULT hr; // = m_renderer.Initialize(hWnd, 4, true);

	if (SUCCEEDED(hr))
	{
		//hr = m_renderer.CreateWindowSizeDependentResources();
	}

	if (SUCCEEDED(hr))
	{
		//hr = SetPrinterVolume(PrinterVolume::GetSizeX(), PrinterVolume::GetSizeY(), PrinterVolume::GetSizeZ());
	}

	if (SUCCEEDED(hr))
	{
		//TextureManager::GetInstance()->SetDevice(m_renderer.GetDevice());
	}

	return hr;
}

void TestWrapper::RenderTheFrame()
{
	//m_cameraTool.UpdateAttachedCamera();
	//std::vector<RenderableObject*> objects = m_sceneContainer.GetRenderableObjects(nullptr);
	//m_renderer.SetObjects(&objects);
	//m_renderer.Render();
	//m_renderer.Present();
}




// ------------- MODEL entity classes --------------------------
// Maybe we should put these in their own seperate file for housekeeping
String^ Model::GetText(){

	return "Text!!";

}

// ------------- end MODEL entity classes --------------------------