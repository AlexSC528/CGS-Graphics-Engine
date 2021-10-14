
#include "../ConvertToRaster.h"


int main()
{

	timer.Restart();
	VertexStruct testLine[2] = { {-0.2f, 0.0f, 0.0f,0.0f, 0xffff0000}, {0.2, 0, 0.3f,0, 0xffff0000} };

	quad gridPerimeter = { {0.5f, 0.0f, 0.5f,1, 0xffff0000}, {0.5f, 0.0f, -0.5f,1, 0xffff0000}, {-0.5f, 0.0f, -0.5f,1, 0xffff0000}, {-0.5f, 0.0f, 0.5f,1, 0xffff0000} };

	VertexStruct gridLine[2] = { {0.4f, 0.0f, 0.5f,1, 0xffff0000}, {0.4f, 0.0f, -0.5f,1, 0xffff0000} };
	VertexStruct gridLine1[2] = { {0.3f, 0.0f, 0.5f,1, 0xffff0000}, {0.3f, 0.0f, -0.5f,1, 0xffff0000} };
	VertexStruct gridLine2[2] = { {0.2f, 0.0f, 0.5f,1, 0xffff0000}, {0.2f, 0.0f, -0.5f,1, 0xffff0000} };
	VertexStruct gridLine3[2] = { {0.1f, 0.0f, 0.5f,1, 0xffff0000}, {0.1f, 0.0f, -0.5f,1, 0xffff0000} };
	VertexStruct gridLine4[2] = { {0.0f, 0.0f, 0.5f,1, 0xffff0000}, {0.0f, 0.0f, -0.5f,1, 0xffff0000} };
	VertexStruct gridLine5[2] = { {-0.1f, 0.0f, 0.5f,1, 0xffff0000}, {-0.1f, 0.0f, -0.5f,1, 0xffff0000} };
	VertexStruct gridLine6[2] = { {-0.2f, 0.0f, 0.5f,1, 0xffff0000}, {-0.2f, 0.0f, -0.5f,1, 0xffff0000} };
	VertexStruct gridLine7[2] = { {-0.3f, 0.0f, 0.5f,1, 0xffff0000}, {-0.3f, 0.0f, -0.5f,1, 0xffff0000} };
	VertexStruct gridLine8[2] = { {-0.4f, 0.0f, 0.5f,1, 0xffff0000}, {-0.4f, 0.0f, -0.5f,1, 0xffff0000} };

	VertexStruct gridLine9[2] = { {0.5f, 0.0f, 0.4f,1, 0xffff0000}, {-0.5f, 0.0f, 0.4f,1, 0xffff0000} };
	VertexStruct gridLine10[2] = { {0.5f, 0.0f, 0.3f,1, 0xffff0000}, {-0.5f, 0.0f, 0.3f,1, 0xffff0000}};		
	VertexStruct gridLine11[2] = { {0.5f, 0.0f, 0.2f,1, 0xffff0000}, {-0.5f, 0.0f, 0.2f,1, 0xffff0000}};		
	VertexStruct gridLine12[2] = { {0.5f, 0.0f, 0.1f,1, 0xffff0000}, {-0.5f, 0.0f, 0.1f,1, 0xffff0000}};		
	VertexStruct gridLine13[2] = { {0.5f, 0.0f, 0.0f,1, 0xffff0000}, {-0.5f, 0.0f, 0.0f,1, 0xffff0000}};		
	VertexStruct gridLine14[2] = {{0.5f, 0.0f, -0.1f,1, 0xffff0000}, {-0.5f, 0.0f, -0.1f,1, 0xffff0000} };		
	VertexStruct gridLine15[2] = {{0.5f, 0.0f, -0.2f,1, 0xffff0000}, {-0.5f, 0.0f, -0.2f,1, 0xffff0000} };		
	VertexStruct gridLine16[2] = {{0.5f, 0.0f, -0.3f,1, 0xffff0000}, {-0.5f, 0.0f, -0.3f,1, 0xffff0000} };		
	VertexStruct gridLine17[2] = {{0.5f, 0.0f, -0.4f,1, 0xffff0000}, {-0.5f, 0.0f, -0.4f,1, 0xffff0000} };		


	//the "W" value is used when translating
	quad faceA = { {-0.25f, -0.25f, 0.25f,1, 0xffff0000}, {-0.25f, 0.25f, 0.25f,1, 0xffff0000}, {0.25f, 0.25f, 0.25f,1, 0xffff0000}, {0.25f, -0.25f, 0.25f,1, 0xffff0000} };
	quad faceB = { {-0.25f, -0.25f, -0.25f,1, 0xffff0000}, {-0.25f, 0.25f, -0.25f,1, 0xffff0000}, {0.25f, 0.25f, -0.25f,1, 0xffff0000}, {0.25f, -0.25f, -0.25f,1, 0xffff0000} };
	quad faceC = { {0.25f, 0.25f, 0.25f,1, 0xffff0000}, {0.25f, 0.25f, -0.25f,1, 0xffff0000}, {-0.25f, 0.25f, -0.25f,1, 0xffff0000}, {-0.25f, 0.25f, 0.25f,1, 0xffff0000} };
	quad faceD = { {0.25f, -0.25f, 0.25f,1, 0xffff0000}, {0.25f, -0.25f, -0.25f,1, 0xffff0000}, {-0.25f, -0.25f, -0.25f,1, 0xffff0000}, {-0.25f, -0.25f, 0.25f,1, 0xffff0000} };
	quad faceE = { {0.25f, -0.25f, -0.25f,1, 0xffff0000}, {0.25f, -0.25f, 0.25f,1, 0xffff0000}, {0.25f, 0.25f, 0.25f,1, 0xffff0000}, {0.25f, 0.25f, -0.25f,1, 0xffff0000} };
	quad faceF = { {-0.25f, -0.25f, -0.25f,1, 0xffff0000}, {-0.25f, -0.25f, 0.25f,1, 0xffff0000}, {-0.25f, 0.25f, 0.25f,1, 0xffff0000}, {-0.25f, 0.25f, -0.25f,1, 0xffff0000} };

	Matrix4 GridMatrix = SV_WorldMatrix;

	Matrix4 CubeMatrix = SV_WorldMatrix;

	RS_Initialize(RASTER_WIDTH, RASTER_HEIGHT);

	while (RS_Update(rasterSurface, RASTER_AREA))
	{
		timer.Signal();
		ClearWindow(0x00000000, rasterSurface);
		if ((GetAsyncKeyState(VK_ESCAPE) & 0x1)) //to close the program
		{
			break;
		}

		VertexShader = VS_Perspective;

		PixelShader = PS_White;

		//SV_WorldMatrix = Matrix4Mult(SV_WorldMatrix, viewMatrix);

		SV_WorldMatrix = { {{1, 0,  0, 0},
						   {0, 1,  0, 0},
						   {0, 0,  1, 0},
						   {0, 0,0, 1}} };

		DrawLine(gridLine[0], gridLine[1]);
		DrawLine(gridLine1[0], gridLine1[1]);
		DrawLine(gridLine2[0], gridLine2[1]);
		DrawLine(gridLine3[0], gridLine3[1]);
		DrawLine(gridLine4[0], gridLine4[1]);
		DrawLine(gridLine5[0], gridLine5[1]);
		DrawLine(gridLine6[0], gridLine6[1]);
		DrawLine(gridLine7[0], gridLine7[1]);
		DrawLine(gridLine8[0], gridLine8[1]);
		DrawLine(gridLine9[0], gridLine9[1]);

		DrawLine(gridLine10[0], gridLine10[1]);
		DrawLine(gridLine11[0], gridLine11[1]);
		DrawLine(gridLine12[0], gridLine12[1]);
		DrawLine(gridLine13[0], gridLine13[1]);
		DrawLine(gridLine14[0], gridLine14[1]);
		DrawLine(gridLine15[0], gridLine15[1]);
		DrawLine(gridLine16[0], gridLine16[1]);
		DrawLine(gridLine17[0], gridLine17[1]);

		DrawQuad(gridPerimeter);


	
		SV_WorldMatrix = { {{1, 0,  0, 0},
						   {0, 1,  0, 0},
						   {0, 0,  1, 0},
						   {0, 0.25,0, 1}} }; //translate the cube upwards

		SV_WorldMatrix = Matrix4Mult(SV_WorldMatrix, RotationY(timer.TotalTime()*50.0f));

		//testLineCopy

		//NDCToScreen(testLineCopyA)

		//DrawLine(testLine[0], testLine[1]);

		//cameraLocation = Matrix4Mult(cameraLocation, RotationZ(timer.TotalTime()));

		PixelShader = PS_Green;

		//DrawTri({ faceA._pA, faceA._pB, faceA._pC });
		FillTri({ faceA._pA, faceA._pB, faceA._pC });
		DrawQuad(faceA);
		DrawQuad(faceB);
		DrawQuad(faceC);
		DrawQuad(faceD);
		DrawQuad(faceE);
		DrawQuad(faceF);
	}
	RS_Shutdown();
	return 0;
}