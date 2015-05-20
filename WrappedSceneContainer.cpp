
#include "stdafx.h"
//#include "..\MeshTools\Mesh.h"
//#include "..\MeshTools\SliceGeometry.h"
#include "WrappedSceneContainer.h"
//#include "MeshRenderableShape.h"
//#include "SliceRenderableShape.h"

using namespace WrappedRenderTools;

WrappedSceneContainer::WrappedSceneContainer()
{
	ClearScene();
}

HRESULT WrappedSceneContainer::ClearScene()
{
	//m_objects.clear();

	//ClearSelection();
	//m_selection = nullptr;

	//m_spRootObject = SmartObject<SceneObject>::CreateInstance();
	//if (m_spRootObject == nullptr)
		//return E_OUTOFMEMORY;

	return S_OK;
}

bool WrappedSceneContainer::IsSceneEmpty()
{
	//return m_spRootObject->GetChildObjectCount() == 0;
	return false;
}