#pragma once
#include"SuperShaders.h"
#include <Windows.h>

void ClearWindow()
{
	for (int i = 0; i < RASTER_AREA; i++)
	{
		rasterSurface[i] = 0xff000000;
		zBuffer[i] = 0.0f;
	}
}

void DrawPixel(unsigned int _newColor, VertexStruct point, unsigned int* _raster)
{
	if (point.X >= 0 && point.X < RASTER_WIDTH && point.Y >= 0 && point.Y < RASTER_HEIGHT)
	{
		if (point.Z >= zBuffer[indexConversion(static_cast<int>(point.X), static_cast<int>(point.Y), RASTER_WIDTH)])
		{
			_raster[indexConversion(static_cast<int>(point.X), static_cast<int>(point.Y), RASTER_WIDTH)] = _newColor;
			zBuffer[indexConversion(static_cast<int>(point.X), static_cast<int>(point.Y), RASTER_WIDTH)] = point.Z;
		}
	}
}


void NDCToScreen(VertexStruct& cartesian)
{
	// if your coordinates are 0-1 instead of -1 to 1
	//multiply the x coordinate by your screen width

	//view and projection matrix accounts for the "Z" axis
	int screenX = ((cartesian.X / 2) * RASTER_WIDTH) +(RASTER_WIDTH * 0.5f);
	int screenY = (RASTER_HEIGHT * (cartesian.Y/2)) + (RASTER_WIDTH * 0.5f);

	cartesian.X = screenX;// = { static_cast<float>(screenX), static_cast<float>(screenY), cartesian.Z, 0, cartesian.color }; //old code. THank you Dan!
	cartesian.Y = screenY;
}
/*VertexStruct NDCtoScreen(VertexStruct _convertMe) //watch the video
{
	VertexStruct results;

	return results;
}*/



void ParametricLine(unsigned int* _raster, VertexStruct pointA, VertexStruct pointB)
{
	/*if (PixelShader)
	{
		PixelShader(pointA.color);
		PixelShader(pointB.color);
	}*/
	float deltaX = pointB.X - pointA.X;
	float deltaY = pointB.Y - pointA.Y;
	float total = (fabsf(deltaX) > fabsf(deltaY)) ? fabsf(deltaX) : fabsf(deltaY);

	for (int i = 0; i < total; i++)
	{
		float ratio = i / total;
		float currx = LerpNum(pointA.X, pointB.X, ratio);
		float curry = LerpNum(pointA.Y, pointB.Y, ratio);
		VertexStruct plotPixel = { currx, curry, 0, 0, interpolateColorParametric(pointA.color, pointB.color, ratio) };
		DrawPixel(plotPixel.color, plotPixel, rasterSurface);
	}
}

void DrawLine(const VertexStruct &A, const VertexStruct &B) //we use the const reference to get the memory address instead of making a copy directly
{
	VertexStruct copyA = A;
	VertexStruct copyB = B;

	if (VertexShader)
	{
		VertexShader(copyA);
		VertexShader(copyB);
	}

	//convert to Screen here

	NDCToScreen(copyA);
	NDCToScreen(copyB);
	ParametricLine(rasterSurface, copyA, copyB);
}

void DrawTri(tri triToDraw)
{
	/*StartX = MIN(X1, X2, X3)
		StartY = MIN(Y1, Y2, Y3)
		EndX = MAX(X1, X2, X3)
		EndY = MAX(Y1, Y2, Y3)*/
	/*ParametricLine(rasterSurface, triToDraw._pA, triToDraw._pB, 0xffffffff);
	ParametricLine(rasterSurface, triToDraw._pB, triToDraw._pC, 0xffffffff);
	ParametricLine(rasterSurface, triToDraw._pC, triToDraw._pA, 0xffffffff);*/

	DrawLine(triToDraw._pA, triToDraw._pB);
	DrawLine(triToDraw._pB, triToDraw._pC);
	DrawLine(triToDraw._pC, triToDraw._pA);

}

void DrawQuad(quad quadToDraw)
{
	DrawLine(quadToDraw._pA, quadToDraw._pB);
	DrawLine(quadToDraw._pB, quadToDraw._pC);
	DrawLine(quadToDraw._pC, quadToDraw._pD);
	DrawLine(quadToDraw._pD, quadToDraw._pA);
}

//void DrawGridXZ(quad gridPerimeter)
//{
//	for (int i = 0; i <= 10; i++)
//	{
//		float ratio = static_cast<float>(i) / 5.0f;
//		VertexStruct a = { (gridPerimeter._pA.X * ratio ) - gridPerimeter._pA.X, gridPerimeter._pA.Y, (gridPerimeter._pA.Z) };
//		VertexStruct b = { (gridPerimeter._pB.X * ratio) - gridPerimeter._pB.X, gridPerimeter._pB.Y, (gridPerimeter._pB.Z) };
//
//		VertexStruct c = { (gridPerimeter._pB.X), gridPerimeter._pB.Y, (gridPerimeter._pB.Z * ratio) - gridPerimeter._pB.Z };
//		VertexStruct d = { (gridPerimeter._pC.X), gridPerimeter._pC.Y, (gridPerimeter._pC.Z * ratio) - gridPerimeter._pC.Z };
//		DrawLine(a, b);
//		DrawLine(c, d);
//	}
//	DrawQuad(gridPerimeter);
//}

void FillTri(tri triToDraw)
{
	VertexStruct copyA = triToDraw._pA;
	VertexStruct copyB = triToDraw._pB;
	VertexStruct copyC = triToDraw._pC;

	if (VertexShader)
	{
		VertexShader(copyA);
		VertexShader(copyB);
		VertexShader(copyC);
	}

	//float copyAZ = copyA.Z;
	//float copyBZ = copyB.Z;
	//float copyCZ = copyC.Z;

	NDCToScreen(copyA); //this completely erases the Z value //Not anymore! Thanks Dan!
	NDCToScreen(copyB);
	NDCToScreen(copyC);

	int StartX = min(min(copyA.X, copyB.X), copyC.X);
	int StartY = min(min(copyA.Y, copyB.Y), copyC.Y);

	int EndX = max(max(copyA.X, copyB.X), copyC.X);
	int EndY = max(max(copyA.Y, copyB.Y), copyC.Y);

	for (int y = StartY; y < EndY; y++)
	{
		for (int x = StartX; x < EndX; x++)
		{
			//this is not actually a point in space, the vertex struct is just being used to store the data
			VertexStruct bya = baryRatios(copyA, copyB, copyC, { static_cast<float>(x),  static_cast<float>(y), 0, 0, 0 });
			//fill
			/*IF 	b >= 0 && b <= 1 &&
				y >= 0 && y <= 1 &&
				a >= 0 && a <= 1*/
			if (bya.X >= 0 && bya.X <= 1 && bya.Y >= 0 && bya.Y <= 1 && bya.Z >= 0 && bya.Z <= 1)
			{
				float berpZ = Berp(copyA.Z, copyB.Z, copyC.Z, bya);

				float berpU = Berp(copyA.U, copyB.U, copyC.U, bya);
				float berpV = Berp(copyA.V, copyB.V, copyC.V, bya);
				if (PixelShader)
				{
					PixelShader(copyA.color, berpU, berpV);
					PixelShader(copyB.color, berpU, berpV);
					PixelShader(copyC.color, berpU, berpV);
				}
				//plug bary lerp in here
				VertexStruct pointToDraw{ static_cast<float>(x),  static_cast<float>(y), berpZ, 0 };
				DrawPixel(baryColor(copyA, copyB, copyC, bya), pointToDraw, rasterSurface);
			}
		}
	}
}
