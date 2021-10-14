#pragma once
#include "MathbyMe.h"

void (*VertexShader)(VertexStruct&) = 0;

//void (*PixelShader)(unsigned int&) = 0;

void (*PixelShader)(unsigned int&, float&, float&) = 0;

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

	_multiplyVert.U = _multiplyVert.U;
	_multiplyVert.V = _multiplyVert.V;
}

void PS_White(unsigned int &_changeColor)
{
	_changeColor = 0xffffffff;
}

void PS_Red(unsigned int& _changeColor)
{
	_changeColor = 0x0fff0000;
}

void PS_Green(unsigned int& _changeColor)
{
	_changeColor = 0x0f00ff00;
}

void PS_Blue(unsigned int& _changeColor)
{
	_changeColor = 0x0f0000ff;
}

void PS_Yellow(unsigned int& _changeColor)
{
	_changeColor = 0xffffff00;
}

void PS_Magenta(unsigned int& _changeColor)
{
	_changeColor = 0xffff00ff;
}

void PS_Texture(unsigned int& _color, float& u, float& v) //use bary U and Bary V
{
	//texu = bary U * texwidth
	int texu = u * celestial_width;

	//texv = bary V & texheight
	int texv = v * celestial_height;

	_color = BGRAtoARGB(celestial_pixels[indexConversion(texu, texv, celestial_width)]);
}