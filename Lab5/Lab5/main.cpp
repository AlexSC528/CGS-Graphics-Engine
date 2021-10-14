#include "../../Math/ConvertToRaster.h"


int main()
{

	timer.Restart();
	VertexStruct testLine[2] = { {-0.2f, 0.0f, 0.0f,0.0f, 0xffff0000}, {0.2, 0, 0.3f,0, 0xffff0000} };

	quad gridPerimeter = { {0.5f, 0.0f, 0.5f,1, 0xffffffff}, {0.5f, 0.0f, -0.5f,1, 0xffffffff}, {-0.5f, 0.0f, -0.5f,1, 0xffffffff}, {-0.5f, 0.0f, 0.5f,1, 0xffffffff} };

	VertexStruct gridLine[2] = { {0.4f, 0.0f, 0.5f,1, 0xffffffff}, {0.4f, 0.0f, -0.5f,1, 0xffffffff} };
	VertexStruct gridLine1[2] = { {0.3f, 0.0f, 0.5f,1, 0xffffffff}, {0.3f, 0.0f, -0.5f,1, 0xffffffff} };
	VertexStruct gridLine2[2] = { {0.2f, 0.0f, 0.5f,1, 0xffffffff}, {0.2f, 0.0f, -0.5f,1, 0xffffffff} };
	VertexStruct gridLine3[2] = { {0.1f, 0.0f, 0.5f,1, 0xffffffff}, {0.1f, 0.0f, -0.5f,1, 0xffffffff} };
	VertexStruct gridLine4[2] = { {0.0f, 0.0f, 0.5f,1, 0xffffffff}, {0.0f, 0.0f, -0.5f,1, 0xffffffff} };
	VertexStruct gridLine5[2] = { {-0.1f, 0.0f, 0.5f,1, 0xffffffff}, {-0.1f, 0.0f, -0.5f,1, 0xffffffff} };
	VertexStruct gridLine6[2] = { {-0.2f, 0.0f, 0.5f,1, 0xffffffff}, {-0.2f, 0.0f, -0.5f,1, 0xffffffff} };
	VertexStruct gridLine7[2] = { {-0.3f, 0.0f, 0.5f,1, 0xffffffff}, {-0.3f, 0.0f, -0.5f,1, 0xffffffff} };
	VertexStruct gridLine8[2] = { {-0.4f, 0.0f, 0.5f,1, 0xffffffff}, {-0.4f, 0.0f, -0.5f,1, 0xffffffff} };

	VertexStruct gridLine9[2] = { {0.5f, 0.0f, 0.4f,1, 0xffffffff}, {-0.5f, 0.0f, 0.4f,1, 0xffffffff} };
	VertexStruct gridLine10[2] = { {0.5f, 0.0f, 0.3f,1, 0xffffffff}, {-0.5f, 0.0f, 0.3f,1, 0xffffffff} };
	VertexStruct gridLine11[2] = { {0.5f, 0.0f, 0.2f,1, 0xffffffff}, {-0.5f, 0.0f, 0.2f,1, 0xffffffff} };
	VertexStruct gridLine12[2] = { {0.5f, 0.0f, 0.1f,1, 0xffffffff}, {-0.5f, 0.0f, 0.1f,1, 0xffffffff} };
	VertexStruct gridLine13[2] = { {0.5f, 0.0f, 0.0f,1, 0xffffffff}, {-0.5f, 0.0f, 0.0f,1, 0xffffffff} };
	VertexStruct gridLine14[2] = { {0.5f, 0.0f, -0.1f,1, 0xffffffff}, {-0.5f, 0.0f, -0.1f,1, 0xffffffff} };
	VertexStruct gridLine15[2] = { {0.5f, 0.0f, -0.2f,1, 0xffffffff}, {-0.5f, 0.0f, -0.2f,1, 0xffffffff} };
	VertexStruct gridLine16[2] = { {0.5f, 0.0f, -0.3f,1, 0xffffffff}, {-0.5f, 0.0f, -0.3f,1, 0xffffffff} };
	VertexStruct gridLine17[2] = { {0.5f, 0.0f, -0.4f,1, 0xffffffff}, {-0.5f, 0.0f, -0.4f,1, 0xffffffff} };

	//the "W" value is used when translating
	quad faceA = { {-0.25f, -0.25f, 0.25f,1, 0xffff0000, 1.0f, 1.0f}, {-0.25f, 0.25f, 0.25f,1, 0xffff0000, 1.0f, 0.0f}, {0.25f, 0.25f, 0.25f,1, 0xffff0000, 0.0f, 0.0f}, {0.25f, -0.25f, 0.25f,1, 0xffff0000, 0.0f, 1.0f} };
	quad faceB = { {-0.25f, -0.25f, -0.25f,1, 0xffff0000, 0.0f, 1.0f}, {-0.25f, 0.25f, -0.25f,1, 0xffff0000, 0.0f, 0.0f}, {0.25f, 0.25f, -0.25f,1, 0xffff0000, 1.0f, 0.0f}, {0.25f, -0.25f, -0.25f,1, 0xffff0000, 1.0f, 1.0f} };
	quad faceC = { {0.25f, 0.25f, 0.25f,1, 0xffff0000, 0.0f, 1.0f}, {0.25f, 0.25f, -0.25f,1, 0xffff0000, 0.0f, 0.0f}, {-0.25f, 0.25f, -0.25f,1, 0xffff0000, 1.0f, 0.0f}, {-0.25f, 0.25f, 0.25f,1, 0xffff0000, 1.0f, 1.0f} };
	quad faceD = { {0.25f, -0.25f, 0.25f,1, 0xffff0000, 0.0f, 0.0f}, {0.25f, -0.25f, -0.25f,1, 0xffff0000, 0.0f, 1.0f}, {-0.25f, -0.25f, -0.25f,1, 0xffff0000, 1.0f, 1.0f}, {-0.25f, -0.25f, 0.25f,1, 0xffff0000, 1.0f, 0.0f} };
	quad faceE = { {0.25f, -0.25f, -0.25f,1, 0xffff0000, 0.0f, 1.0f}, {0.25f, -0.25f, 0.25f,1, 0xffff0000, 1.0f, 1.0f}, {0.25f, 0.25f, 0.25f,1, 0xffff0000, 1.0f, 0.0f}, {0.25f, 0.25f, -0.25f,1, 0xffff0000, 0.0f, 0.0f} };
	quad faceF = { {-0.25f, -0.25f, -0.25f,1, 0xffff0000, 1.0f, 1.0f}, {-0.25f, -0.25f, 0.25f,1, 0xffff0000, 0.0f, 1.0f}, {-0.25f, 0.25f, 0.25f,1, 0xffff0000, 0.0f, 0.0f}, {-0.25f, 0.25f, -0.25f,1, 0xffff0000, 1.0f, 0.0f} };

	Matrix4 GridMatrix = SV_WorldMatrix;

	Matrix4 CubeMatrix = SV_WorldMatrix;

	RS_Initialize(RASTER_WIDTH, RASTER_HEIGHT);

	while (RS_Update(rasterSurface, RASTER_AREA))
	{
		timer.Signal();
		ClearWindow();

		if ((GetAsyncKeyState(VK_ESCAPE) & 0x1)) //to close the program
		{
			break;
		}

		//move that camera! ! ! :Daaaaaaaaa
		if ((GetAsyncKeyState('W'))) //Forwards
		{
			cameraMovement.index[3][2] -= (1.0f * timer.Delta());
		}
		if ((GetAsyncKeyState('S'))) //Backwards
		{
			cameraMovement.index[3][2] += (1.0f * timer.Delta());
		}
		if ((GetAsyncKeyState('A'))) //Left
		{
			cameraMovement.index[3][0] += (1.0f * timer.Delta());
		}
		if ((GetAsyncKeyState('D'))) //Right
		{
			cameraMovement.index[3][0] -= (1.0f * timer.Delta());
		}
		if ((GetAsyncKeyState('Q'))) //Up
		{
			cameraMovement.index[3][1] += (1.0f * timer.Delta());
		}
		if ((GetAsyncKeyState('E'))) //Down
		{
			cameraMovement.index[3][1] -= (1.0f * timer.Delta());
		}
		if ((GetAsyncKeyState('R'))) //Reset
		{
			cameraMovement.index[3][0] = 0.0f;
			cameraMovement.index[3][1] = 0.0f;
			cameraMovement.index[3][2] = 1.0f;
		}

		cameraLocation = Matrix4Mult(cameraMovement, tiltDown);
		viewMatrix = Matrix4InverseOA(cameraLocation);

		VertexShader = VS_Perspective;

		//PixelShader = PS_White;

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

		SV_WorldMatrix = Matrix4Mult(SV_WorldMatrix, RotationY(timer.TotalTime() * 50.0f));

		//testLineCopy

		//NDCToScreen(testLineCopyA)

		//DrawLine(testLine[0], testLine[1]);

		//cameraLocation = Matrix4Mult(cameraLocation, RotationZ(timer.TotalTime()));



		//DrawTri({ faceA._pA, faceA._pB, faceA._pC });
		PixelShader = PS_Texture;

		DrawPixel(0xffffff00, faceA._pB, rasterSurface);
		FillTri({ faceA._pB, faceA._pD, faceA._pC });
		FillTri({ faceA._pA, faceA._pB, faceA._pD });

		//PixelShader = PS_Green;
		FillTri({ faceB._pB, faceB._pD, faceB._pC });
		FillTri({ faceB._pA, faceB._pB, faceB._pD });

		//PixelShader = PS_Yellow;
		FillTri({ faceC._pB, faceC._pD, faceC._pC });
		FillTri({ faceC._pA, faceC._pB, faceC._pD });
		
		//PixelShader = PS_Yellow;
		FillTri({ faceD._pB, faceD._pD, faceD._pC });
		FillTri({ faceD._pA, faceD._pB, faceD._pD });

		//PixelShader = PS_Blue;
		FillTri({ faceE._pB, faceE._pD, faceE._pC });
		FillTri({ faceE._pA, faceE._pB, faceE._pD });

		////PixelShader = PS_Magenta;
		FillTri({ faceF._pB, faceF._pD, faceF._pC });
		FillTri({ faceF._pA, faceF._pB, faceF._pD });
		/*DrawQuad(faceA);
		DrawQuad(faceB);
		DrawQuad(faceC);
		DrawQuad(faceD);
		DrawQuad(faceE);
		DrawQuad(faceF);*/
	}
	RS_Shutdown();
	return 0;
}