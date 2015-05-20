// Copyright (C) Microsoft Corporation. All rights reserved.
// stdafx.h : include file for standard system include files, 
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

//#define WIN32_LEAN_AND_MEAN             // Exclude rarely - used stuff from Windows headers

// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <crtdbg.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <malloc.h>
#include <memory.h>
#include <memory>
#include <tchar.h>
#include <atlbase.h>

#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <d2d1_1.h>
#include <dwrite_1.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
using namespace DirectX;

#include <new>
#include <Objidl.h>

#include "define.h"
#include "PlatformVsCommon.h"
#include "Guards.h"
#include "SmartObject.h"
#include "SmartPtr.h"
#include "Utils.h"
#include "ProgressHandler.h"

#include "UILib.h"

// Mesh tools
#include "Mesh.h"
#include "GeometryBuilder.h"
using namespace MeshTools;

//3MF
#include "XmlReaderNode.h"

//This define enables advanced features as settings options in 3DViewer
//To disable these features, comment next row
#define _ADVANCED_FEATURE

#define DEFAULT_VOLUME_SIZE 6.0f;