#pragma once
#include <DX3D/Core/Logger.h>

//Выяснить почему значения в макросе(присваемые, в частности) нужно брать в скобки
namespace dx3d
{
#define DX3DGraphicsLogErrorAndThrow(hr, message)\
	{\
	auto res = (hr);\
	if (FAILED(res))\
		DX3DLogErrorAndThrow(message);\
	}
}