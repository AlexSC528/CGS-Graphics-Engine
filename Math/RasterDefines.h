#pragma once
#include"../Ulitities/RasterSurface.h"
#include"../Ulitities/XTime.h"
#include"../Lab5/celestial.h"
#include <cmath>
#include<math.h>
#include <Windows.h>
#include<iostream>
#include<vector>

#define RASTER_WIDTH 800
#define RASTER_HEIGHT 600
#define RASTER_AREA (RASTER_WIDTH * RASTER_HEIGHT)
#define M_PI 3.14159265358979323846

unsigned int rasterSurface[RASTER_AREA];
float zBuffer[RASTER_AREA];

XTime timer;

struct VertexStruct
{
	float X;
	float Y;
	float Z;
	float W;

	unsigned int color;

	float U;
	float V;
};

struct Matrix3
{
	float index[3][3];
};

struct Matrix4
{
	float index[4][4];
};

struct tri
{
	VertexStruct _pA;
	VertexStruct _pB;
	VertexStruct _pC;
};

struct quad
{
	VertexStruct _pA;
	VertexStruct _pB;
	VertexStruct _pC;
	VertexStruct _pD;
};

