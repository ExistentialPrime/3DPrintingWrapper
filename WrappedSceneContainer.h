// WrappedSceneContainer.h
//--------------------------------------------------------------------------------
// Interop wrapped version of Microsoft's SceneContainer class for 3D Printing
//--------------------------------------------------------------------------------

#pragma once
#include <functional>
//#include "SceneObject.h" // Not wrapped as of 5/18
//#include "SliceRenderableShape.h" // Not wrapped as of 5/18
//#include "SelectionContainer.h" // Not wrapped as of 5/18
//#include "Camera.h" // Not wrapped as of 5/18

//using namespace RenderTools;
//using namespace System;
//using std::string;

namespace WrappedRenderTools {

	class WrappedSceneContainer
	{

		public:
			WrappedSceneContainer();

			HRESULT ClearScene();
			bool IsSceneEmpty();

		private:
			int testint;
			//SmartPtr<SceneObject> m_spRootObject;
			//std::vector<SmartPtr<SceneObject>> m_objects;
			//std::vector<SmartPtr<ISelectionChangedHandler>> m_callbacks;
			//SmartQIPtr<ISelectionContainer> m_selection;

			//SmartPtr<SceneObject> m_spFocusedObject;
	};
}