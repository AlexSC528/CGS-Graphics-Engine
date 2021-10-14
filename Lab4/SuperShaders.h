#pragma once
#include "MathbyMe.h"

void (*VertexShader)(VertexStruct&) = 0;

void (*PixelShader)(unsigned int&) = 0;

Matrix3 SV_WorldMatrix3 = { {{ 0, 0, 0 },
							{ 0, 0, 0 },
							{ 0, 0, 0 }} };

Matrix4 SV_WorldMatrix = { {{ 1, 0, 0, 0 }, 
							{ 0, 1, 0, 0 }, 
							{ 0, 0, 1, 0 },
							{ 0, 0, 0, 1 },} };

void VS_World3(VertexStruct& _multiplyVert)
{
	_multiplyVert = VecMult3(_multiplyVert, SV_WorldMatrix3);
}

void VS_World(VertexStruct &_multiplyVert)
{
	_multiplyVert = VecMult4(_multiplyVert, SV_WorldMatrix);
}

void VS_Perspective(VertexStruct& _multiplyVert)
{
	_multiplyVert = VecMult4(_multiplyVert, SV_WorldMatrix);

	_multiplyVert = VecMult4(_multiplyVert, viewMatrix);

	_multiplyVert = VecMult4(_multiplyVert, PerspectiveMat);

	_multiplyVert.X = _multiplyVert.X / _multiplyVert.W;
	_multiplyVert.Y = _multiplyVert.Y / _multiplyVert.W;
	_multiplyVert.Z = _multiplyVert.Z / _multiplyVert.W;
	 
	/*_multiplyVert.X = _multiplyVert.X / _multiplyVert.W;
	_multiplyVert.X = _multiplyVert.Y / _multiplyVert.W;
	_multiplyVert.X = _multiplyVert.Z / _multiplyVert.W;
	_multiplyVert.X = _multiplyVert.W / _multiplyVert.W;*/
}

void PS_White(unsigned int &_changeColor)
{
	_changeColor = 0xffffffff;
}

void PS_Green(unsigned int& _changeColor)
{
	_changeColor = 0xff00ff00;
}