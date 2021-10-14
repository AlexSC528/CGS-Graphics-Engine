#pragma once
#include "RasterDefines.h"

VertexStruct VecMult3(VertexStruct _vec, Matrix3 _mat3)
{
	float entryX = (_vec.X * _mat3.index[0][0]) 
				 + (_vec.Y * _mat3.index[1][0]) 
				 + (_vec.Z * _mat3.index[2][0]);

	float entryY = (_vec.X * _mat3.index[0][1]) 
				 + (_vec.Y * _mat3.index[1][1]) 
				 + (_vec.Z * _mat3.index[2][1]);

	float entryZ = (_vec.X * _mat3.index[0][2]) 
				 + (_vec.Y * _mat3.index[1][2]) 
				 + (_vec.Z * _mat3.index[2][2]);

	return { entryX, entryY, entryZ, _vec.W, _vec.color };
}

VertexStruct VecMult4(VertexStruct _vec, Matrix4 _mat4)
{
	float entryX = (_vec.X * _mat4.index[0][0]) 
				 + (_vec.Y * _mat4.index[1][0]) 
				 + (_vec.Z * _mat4.index[2][0]) 
				 + (_vec.W * _mat4.index[3][0]);

	float entryY = (_vec.X * _mat4.index[0][1]) 
				 + (_vec.Y * _mat4.index[1][1]) 
				 + (_vec.Z * _mat4.index[2][1]) 
				 + (_vec.W * _mat4.index[3][1]);

	float entryZ = (_vec.X * _mat4.index[0][2]) 
				 + (_vec.Y * _mat4.index[1][2]) 
				 + (_vec.Z * _mat4.index[2][2]) 
				 + (_vec.W * _mat4.index[3][2]);

	float entryW = (_vec.X * _mat4.index[0][3]) 
				 + (_vec.Y * _mat4.index[1][3]) 
				 + (_vec.Z * _mat4.index[2][3]) 
				 + (_vec.W * _mat4.index[3][3]);

	return { entryX, entryY, entryZ, entryW, _vec.color };
}

Matrix3 Matrix3Mult(Matrix3 matA, Matrix3 matB)
{
	Matrix3 results;
	results.index[0][0] = (matA.index[0][0] * matB.index[0][0]) + (matA.index[0][1] * matB.index[1][0]) + (matA.index[0][2] * matB.index[2][0]);
	results.index[0][1] = (matA.index[0][0] * matB.index[0][1]) + (matA.index[0][1] * matB.index[1][1]) + (matA.index[0][2] * matB.index[2][1]);
	results.index[0][2] = (matA.index[0][0] * matB.index[0][2]) + (matA.index[0][1] * matB.index[1][2]) + (matA.index[0][2] * matB.index[2][2]);

	results.index[1][0] = (matA.index[1][0] * matB.index[0][0]) + (matA.index[1][1] * matB.index[1][0]) + (matA.index[1][2] * matB.index[2][0]);
	results.index[1][1] = (matA.index[1][0] * matB.index[0][1]) + (matA.index[1][1] * matB.index[1][1]) + (matA.index[1][2] * matB.index[2][1]);
	results.index[1][2] = (matA.index[1][0] * matB.index[0][2]) + (matA.index[1][1] * matB.index[1][2]) + (matA.index[1][2] * matB.index[2][2]);

	results.index[2][0] = (matA.index[2][0] * matB.index[0][0]) + (matA.index[2][1] * matB.index[1][0]) + (matA.index[2][2] * matB.index[2][0]);
	results.index[2][1] = (matA.index[2][0] * matB.index[0][1]) + (matA.index[2][1] * matB.index[1][1]) + (matA.index[2][2] * matB.index[2][1]);
	results.index[2][2] = (matA.index[2][0] * matB.index[0][2]) + (matA.index[2][1] * matB.index[1][2]) + (matA.index[2][2] * matB.index[2][2]);
	return results;
}

Matrix4 Matrix4Mult(Matrix4 matA, Matrix4 matB)
{
	//help me :(

	Matrix4 results;

	results.index[0][0] = (matA.index[0][0] * matB.index[0][0]) + (matA.index[0][1] * matB.index[1][0]) + (matA.index[0][2] * matB.index[2][0]) + (matA.index[0][3] * matB.index[3][0]);
	results.index[0][1] = (matA.index[0][0] * matB.index[0][1]) + (matA.index[0][1] * matB.index[1][1]) + (matA.index[0][2] * matB.index[2][1]) + (matA.index[0][3] * matB.index[3][1]);
	results.index[0][2] = (matA.index[0][0] * matB.index[0][2]) + (matA.index[0][1] * matB.index[1][2]) + (matA.index[0][2] * matB.index[2][2]) + (matA.index[0][3] * matB.index[3][2]);
	results.index[0][3] = (matA.index[0][0] * matB.index[0][3]) + (matA.index[0][1] * matB.index[1][3]) + (matA.index[0][2] * matB.index[2][3]) + (matA.index[0][3] * matB.index[3][3]);

	results.index[1][0] = (matA.index[1][0] * matB.index[0][0]) + (matA.index[1][1] * matB.index[1][0]) + (matA.index[1][2] * matB.index[2][0]) + (matA.index[1][3] * matB.index[3][0]);
	results.index[1][1] = (matA.index[1][0] * matB.index[0][1]) + (matA.index[1][1] * matB.index[1][1]) + (matA.index[1][2] * matB.index[2][1]) + (matA.index[1][3] * matB.index[3][1]);
	results.index[1][2] = (matA.index[1][0] * matB.index[0][2]) + (matA.index[1][1] * matB.index[1][2]) + (matA.index[1][2] * matB.index[2][2]) + (matA.index[1][3] * matB.index[3][2]);
	results.index[1][3] = (matA.index[1][0] * matB.index[0][3]) + (matA.index[1][1] * matB.index[1][3]) + (matA.index[1][2] * matB.index[2][3]) + (matA.index[1][3] * matB.index[3][3]);

	results.index[2][0] = (matA.index[2][0] * matB.index[0][0]) + (matA.index[2][1] * matB.index[1][0]) + (matA.index[2][2] * matB.index[2][0]) + (matA.index[2][3] * matB.index[3][0]);
	results.index[2][1] = (matA.index[2][0] * matB.index[0][1]) + (matA.index[2][1] * matB.index[1][1]) + (matA.index[2][2] * matB.index[2][1]) + (matA.index[2][3] * matB.index[3][1]);
	results.index[2][2] = (matA.index[2][0] * matB.index[0][2]) + (matA.index[2][1] * matB.index[1][2]) + (matA.index[2][2] * matB.index[2][2]) + (matA.index[2][3] * matB.index[3][2]);
	results.index[2][3] = (matA.index[2][0] * matB.index[0][3]) + (matA.index[2][1] * matB.index[1][3]) + (matA.index[2][2] * matB.index[2][3]) + (matA.index[2][3] * matB.index[3][3]);

	results.index[3][0] = (matA.index[3][0] * matB.index[0][0]) + (matA.index[3][1] * matB.index[1][0]) + (matA.index[3][2] * matB.index[2][0]) + (matA.index[3][3] * matB.index[3][0]);
	results.index[3][1] = (matA.index[3][0] * matB.index[0][1]) + (matA.index[3][1] * matB.index[1][1]) + (matA.index[3][2] * matB.index[2][1]) + (matA.index[3][3] * matB.index[3][1]);
	results.index[3][2] = (matA.index[3][0] * matB.index[0][2]) + (matA.index[3][1] * matB.index[1][2]) + (matA.index[3][2] * matB.index[2][2]) + (matA.index[3][3] * matB.index[3][2]);
	results.index[3][3] = (matA.index[3][0] * matB.index[0][3]) + (matA.index[3][1] * matB.index[1][3]) + (matA.index[3][2] * matB.index[2][3]) + (matA.index[3][3] * matB.index[3][3]);

	return results;
}


float Determinant4(Matrix4 a)
{

	float invertMeD; // |A|

	invertMeD = (a.index[0][0] * a.index[1][1] * a.index[2][2] * a.index[3][3])
		      + (a.index[0][0] * a.index[1][2] * a.index[2][3] * a.index[3][1])
		      + (a.index[0][0] * a.index[1][3] * a.index[2][1] * a.index[3][2])
		      
		      - (a.index[0][0] * a.index[1][3] * a.index[2][2] * a.index[3][1])
		      - (a.index[0][0] * a.index[1][2] * a.index[2][1] * a.index[3][3])
		      - (a.index[0][0] * a.index[1][1] * a.index[2][3] * a.index[3][2])
		      
		      - (a.index[0][1] * a.index[1][0] * a.index[2][2] * a.index[3][3])
		      - (a.index[0][2] * a.index[1][0] * a.index[2][3] * a.index[3][1])
		      - (a.index[0][3] * a.index[1][0] * a.index[2][1] * a.index[3][2])
		      
		      + (a.index[0][3] * a.index[1][0] * a.index[2][2] * a.index[3][1])
		      + (a.index[0][2] * a.index[1][0] * a.index[2][1] * a.index[3][3])
		      + (a.index[0][1] * a.index[1][0] * a.index[2][3] * a.index[3][2])
		      
		      + (a.index[0][1] * a.index[1][2] * a.index[2][0] * a.index[3][3])
		      + (a.index[0][2] * a.index[1][3] * a.index[2][0] * a.index[3][1])
		      + (a.index[0][3] * a.index[1][1] * a.index[2][0] * a.index[3][2])
		      
		      - (a.index[0][3] * a.index[1][2] * a.index[2][0] * a.index[3][1])
		      - (a.index[0][2] * a.index[1][1] * a.index[2][0] * a.index[3][3])
		      - (a.index[0][1] * a.index[1][3] * a.index[2][0] * a.index[3][2])
		      
		      - (a.index[0][1] * a.index[1][2] * a.index[2][3] * a.index[3][0])
		      - (a.index[0][2] * a.index[1][3] * a.index[2][1] * a.index[3][0])
		      - (a.index[0][3] * a.index[1][1] * a.index[2][2] * a.index[3][0])

		+ (a.index[0][3] * a.index[1][2] * a.index[2][1] * a.index[3][0])
		+ (a.index[0][2] * a.index[1][1] * a.index[2][3] * a.index[3][0])
		+ (a.index[0][1] * a.index[1][3] * a.index[2][2] * a.index[3][0]);

	return invertMeD;
}


Matrix4 Matrix4InverseOA(Matrix4 a)
{
	//in order to create the view matrix we need to use this function
	//on the Camera matrix, which is a type of world matrix

	//any world matrix can be the "Camera"
	//what makes it a view matrix is when we take its inverse

	//if the camera was a cube, 
	//we would tilt it down and move it back in the world space

	//the camera is a combination of two matrices

	float determinantA = Determinant4(a);

	Matrix4 aNegate; //~A

	aNegate.index[0][0] = (a.index[1][1] * a.index[2][2] * a.index[3][3]) + (a.index[1][2] * a.index[2][3] * a.index[3][1]) + (a.index[1][3] * a.index[2][1] * a.index[3][2])
		- (a.index[1][3] * a.index[2][2] * a.index[3][1]) - (a.index[1][2] * a.index[2][1] * a.index[3][3]) - (a.index[1][1] * a.index[2][3] * a.index[3][2]);

	aNegate.index[0][1] = (-(a.index[0][1] * a.index[2][2] * a.index[3][3])) - (a.index[0][2] * a.index[2][3] * a.index[3][1]) - (a.index[0][3] * a.index[2][1] * a.index[3][2])
		+ (a.index[0][3] * a.index[2][2] * a.index[3][1]) + (a.index[0][2] * a.index[2][1] * a.index[3][3]) + (a.index[0][1] * a.index[2][3] * a.index[3][2]);

	aNegate.index[0][2] = (a.index[0][1] * a.index[1][2] * a.index[3][3]) + (a.index[0][2] * a.index[1][3] * a.index[3][1]) + (a.index[0][3] * a.index[1][1] * a.index[3][2])
		- (a.index[0][3] * a.index[1][2] * a.index[3][1]) - (a.index[0][2] * a.index[1][1] * a.index[3][3]) - (a.index[0][1] * a.index[1][3] * a.index[3][2]);

	aNegate.index[0][3] = (-(a.index[0][1] * a.index[1][2] * a.index[2][3])) - (a.index[0][2] * a.index[1][3] * a.index[2][1]) - (a.index[0][3] * a.index[1][1] * a.index[2][2])
		+ (a.index[0][3] * a.index[1][2] * a.index[2][1]) + (a.index[0][2] * a.index[1][1] * a.index[2][3]) + (a.index[0][1] * a.index[1][3] * a.index[2][2]);


	aNegate.index[1][0] = (-(a.index[1][0] * a.index[2][2] * a.index[3][3])) - (a.index[1][2] * a.index[2][3] * a.index[3][0]) - (a.index[1][3] * a.index[2][0] * a.index[3][2])
		+ (a.index[1][3] * a.index[2][2] * a.index[3][0]) + (a.index[1][2] * a.index[2][0] * a.index[3][3]) + (a.index[1][0] * a.index[2][3] * a.index[3][2]);

	aNegate.index[1][1] = (a.index[0][0] * a.index[2][2] * a.index[3][3]) + (a.index[0][2] * a.index[2][3] * a.index[3][0]) + (a.index[0][3] * a.index[2][0] * a.index[3][2])
		- (a.index[0][3] * a.index[2][2] * a.index[3][0]) - (a.index[0][2] * a.index[2][0] * a.index[3][3]) - (a.index[0][0] * a.index[2][3] * a.index[3][2]);
	
	aNegate.index[1][2] = (-(a.index[0][0] * a.index[1][2] * a.index[3][3])) - (a.index[0][2] * a.index[1][3] * a.index[3][0]) - (a.index[0][3] * a.index[1][0] * a.index[3][2])
		+ (a.index[1][3] * a.index[1][2] * a.index[3][0]) + (a.index[0][2] * a.index[1][0] * a.index[3][3]) + (a.index[0][0] * a.index[1][3] * a.index[3][2]);

	aNegate.index[1][3] = (a.index[0][0] * a.index[1][2] * a.index[2][3]) + (a.index[0][2] * a.index[1][3] * a.index[2][0]) + (a.index[0][3] * a.index[1][0] * a.index[2][2])
		- (a.index[0][3] * a.index[1][2] * a.index[2][0]) - (a.index[0][2] * a.index[1][0] * a.index[2][3]) - (a.index[0][0] * a.index[1][3] * a.index[2][2]);


	aNegate.index[2][0] = (a.index[1][0] * a.index[2][1] * a.index[3][3]) + (a.index[1][1] * a.index[2][3] * a.index[3][0]) + (a.index[1][3] * a.index[2][0] * a.index[3][1])
		- (a.index[0][3] * a.index[2][1] * a.index[3][0]) - (a.index[1][1] * a.index[2][0] * a.index[3][3]) - (a.index[1][0] * a.index[2][3] * a.index[3][1]);

	aNegate.index[2][1] = (-(a.index[0][0] * a.index[2][1] * a.index[3][3])) - (a.index[0][1] * a.index[2][3] * a.index[3][0]) - (a.index[0][3] * a.index[2][0] * a.index[3][1])
		+ (a.index[0][3] * a.index[2][1] * a.index[3][0]) + (a.index[0][1] * a.index[2][0] * a.index[3][3]) + (a.index[0][0] * a.index[2][3] * a.index[3][1]);

	aNegate.index[2][2] = (a.index[0][0] * a.index[1][1] * a.index[3][3]) + (a.index[0][1] * a.index[1][3] * a.index[3][0]) + (a.index[0][3] * a.index[1][0] * a.index[3][1])
		- (a.index[0][3] * a.index[1][1] * a.index[3][1]) - (a.index[0][1] * a.index[1][0] * a.index[3][3]) - (a.index[0][0] * a.index[1][3] * a.index[3][1]);

	aNegate.index[2][3] = (-(a.index[0][0] * a.index[1][1] * a.index[2][3])) - (a.index[0][1] * a.index[1][3] * a.index[2][0]) - (a.index[0][3] * a.index[1][0] * a.index[2][1])
		+ (a.index[0][3] * a.index[1][1] * a.index[2][0]) + (a.index[0][1] * a.index[1][0] * a.index[2][3]) + (a.index[0][0] * a.index[1][3] * a.index[2][1]);


	aNegate.index[3][0] = (-(a.index[1][0] * a.index[2][1] * a.index[3][2])) - (a.index[1][1] * a.index[2][2] * a.index[3][0]) - (a.index[1][2] * a.index[2][0] * a.index[3][1])
		+ (a.index[1][2] * a.index[2][1] * a.index[3][0]) + (a.index[1][1] * a.index[2][0] * a.index[3][2]) + (a.index[1][0] * a.index[2][2] * a.index[3][1]);

	aNegate.index[3][1] = (a.index[0][0] * a.index[2][1] * a.index[3][2]) + (a.index[0][1] * a.index[2][2] * a.index[3][0]) + (a.index[0][2] * a.index[2][0] * a.index[3][1])
		- (a.index[0][2] * a.index[2][1] * a.index[3][0]) - (a.index[0][1] * a.index[2][0] * a.index[3][2]) - (a.index[0][0] * a.index[2][2] * a.index[3][1]);

	aNegate.index[3][2] = (-(a.index[0][0] * a.index[1][1] * a.index[3][2])) - (a.index[0][1] * a.index[1][2] * a.index[3][0]) - (a.index[0][2] * a.index[1][0] * a.index[3][1])
		+ (a.index[0][2] * a.index[1][1] * a.index[3][0]) + (a.index[0][1] * a.index[1][0] * a.index[3][2]) + (a.index[0][0] * a.index[1][2] * a.index[3][1]);

	aNegate.index[3][3] = (a.index[0][0] * a.index[1][1] * a.index[2][2]) + (a.index[0][1] * a.index[1][2] * a.index[2][0]) + (a.index[0][2] * a.index[1][0] * a.index[2][1])
		- (a.index[0][2] * a.index[1][1] * a.index[2][0]) - (a.index[0][1] * a.index[1][0] * a.index[2][2]) - (a.index[0][0] * a.index[1][2] * a.index[2][1]);

	Matrix4 results;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			results.index[i][j] = (aNegate.index[i][j] * (1.0f / determinantA));
		}
	}

	return results;
}

Matrix3 RotationX3(float degrees)
{
	float radian = ((degrees * M_PI) / 180); //convert the degrees to radians
	Matrix3 xRotation;
	xRotation.index[0][0] = 1; xRotation.index[0][1] = 0;			xRotation.index[0][2] = 0;
	xRotation.index[1][0] = 0; xRotation.index[1][1] = cos(radian); xRotation.index[1][2] = (sin(radian) * -1);
	xRotation.index[2][0] = 0; xRotation.index[2][1] = sin(radian);	xRotation.index[2][2] = cos(radian);

	return xRotation;
}
Matrix3 RotationY3(float degrees)
{
	float radian = ((degrees * M_PI) / 180); //convert the degrees to radians
	Matrix3 yRotation;
	yRotation.index[0][0] = cos(radian);		yRotation.index[0][1] = 0; yRotation.index[0][2] = sin(radian);
	yRotation.index[1][0] = 0;					yRotation.index[1][1] = 1; yRotation.index[1][2] = 0;
	yRotation.index[2][0] = (sin(radian) * -1); yRotation.index[2][1] = 0; yRotation.index[2][2] = cos(radian);

	return yRotation;
}

Matrix3 RotationZ3(float degrees)
{
	float radian = ((degrees * M_PI) / 180); //convert the degrees to radians
	Matrix3 zRotation;
	zRotation.index[0][0] = cos(radian); zRotation.index[0][1] = (sin(radian) * -1);  zRotation.index[0][2] = 0;
	zRotation.index[1][0] = sin(radian); zRotation.index[1][1] = cos(radian);		 zRotation.index[1][2] = 0;
	zRotation.index[2][0] = 0;			 zRotation.index[2][1] = 0;					 zRotation.index[2][2] = 1;

	return zRotation;
}
Matrix4 RotationX(float degrees)
{
	float radian = degrees * (M_PI / 180); //convert the degrees to radians
	Matrix4 xRotation;

	float cosRad = cos(radian);
	float sinRad = sin(radian);

	xRotation.index[0][0] = 1; xRotation.index[0][1] = 0;  xRotation.index[0][2] = 0;							xRotation.index[0][3] = 0;
	xRotation.index[1][0] = 0; xRotation.index[1][1] = cosRad; xRotation.index[1][2] = -sinRad;		xRotation.index[1][3] = 0;
	xRotation.index[2][0] = 0; xRotation.index[2][1] = sinRad; xRotation.index[2][2] = cosRad;		xRotation.index[2][3] = 0;
	xRotation.index[3][0] = 0; xRotation.index[3][1] = 0;			xRotation.index[3][2] = 0;					xRotation.index[3][3] = 1;

	return xRotation;
}
Matrix4 RotationY(float degrees)
{
	float radian = degrees * (M_PI / 180); //convert the degrees to radians
	Matrix4 yRotation;

	float cosRad = cos(radian);
	float sinRad = sin(radian);

	//it keeps returning zero for all cos and sin functions despite working PERFECTLY FINE in lab 3
	yRotation.index[0][0] = cosRad;		yRotation.index[0][1] = 0; yRotation.index[0][2] = sinRad;	yRotation.index[0][3] = 0;
	yRotation.index[1][0] = 0;					yRotation.index[1][1] = 1; yRotation.index[1][2] = 0; yRotation.index[1][3] = 0;
	yRotation.index[2][0] = -sinRad;		yRotation.index[2][1] = 0; yRotation.index[2][2] = cosRad;	yRotation.index[2][3] = 0;
	yRotation.index[3][0] = 0;					yRotation.index[3][1] = 0; yRotation.index[3][2] = 0;	yRotation.index[3][3] = 1;

	return yRotation;
}

Matrix4 RotationZ(float degrees)
{
	float radian = degrees * (M_PI / 180); //convert the degrees to radians

	float cosRad = cos(radian);
	float sinRad = sin(radian);
	Matrix4 zRotation;
	zRotation.index[0][0] = cosRad; zRotation.index[0][1] = -sinRad; zRotation.index[0][2] = 0; zRotation.index[0][3] = 0;
	zRotation.index[1][0] = sinRad; zRotation.index[1][1] = cosRad;  zRotation.index[1][2] = 0; zRotation.index[1][3] = 0;
	zRotation.index[2][0] = 0;			 zRotation.index[2][1] = 0;			   zRotation.index[2][2] = 1; zRotation.index[2][3] = 0;
	zRotation.index[3][0] = 0;			 zRotation.index[3][1] = 0;			   zRotation.index[3][2] = 0; zRotation.index[3][3] = 1;

	return zRotation;

}

int indexConversion(int _x, int _y, int width) //convert 2d to 1d
{
	return (_y * width) +_x;
}


int interpolateColorParametric(int colorA, int colorB, float ratio)
{
	//same as lab1, though the ratio is already pre determined by the location on the parametric line
	//separation of channels
	unsigned int   alphaA = (colorA & 0xff000000) >> 24; //A
	unsigned int   alphaB = (colorB & 0xff000000) >> 24;

	unsigned int   rA = (colorA & 0x00ff0000) >> 16; // R
	unsigned int   rB = (colorB & 0x00ff0000) >> 16;

	unsigned int   gA = (colorA & 0x0000ff00) >> 8; // G
	unsigned int   gB = (colorB & 0x0000ff00) >> 8;

	unsigned int   bA = (colorA & 0x000000ff); // B
	unsigned int   bB = (colorB & 0x000000ff);

	//(B - A) * R + A calculations to produce results "r"
	unsigned int rAlpha = ((static_cast<int>(alphaB) - static_cast<int>(alphaA)) * ratio + alphaA);
	unsigned int rRed = (((static_cast<int>(rB) - static_cast<int>(rA)) * ratio + rA));
	unsigned int rGreen = (((static_cast<int>(gB) - static_cast<int>(gA)) * ratio + gA));
	unsigned int rBlue = (((static_cast<int>(bB) - static_cast<int>(bA)) * ratio + bA));

	int result = (rAlpha << 24) | (rRed << 16) | (rGreen << 8) | rBlue;
	return result;
}
//unsigned int BaryinterpolateColor(VertexStruct baryRatios, tri Triangle)
//{
	//same as lab1, though the ratio is already pre determined by the location on the parametric line
	//separation of channels
	//USE ORIGINAL TRIANGLE POINTS

//}

float LerpNum(int numberA, int numberB, float ratio)
{
	//I had to separate the equation into its separate parts because it 
	//kept adding numberB and numberA together and I have no idea why or how but this works
	float result = ((static_cast<int>(numberB) - (static_cast<int>(numberA))));
	result = result * ratio;
	result = result += numberA;
	return result;
}

float ImplicitLineEquation(float xA, float yA, float xB, float yB, float xM, float yM)
{
	//(Y1 – Y2)x + (X2 – X1)y + X1Y2 – Y1X2 = 0


	return ((yA - yB) * xM) + ((xB - xA) * yM) + (xA * yB) - (yA * xB);
}

VertexStruct baryRatios(VertexStruct _pA, VertexStruct _pB, VertexStruct _pC, VertexStruct _test)
{
	float b = ImplicitLineEquation(_pA.X, _pA.Y, _pC.X, _pC.Y, _test.X, _test.Y);
	float _B = ImplicitLineEquation(_pA.X, _pA.Y, _pC.X, _pC.Y, _pB.X, _pB.Y);

	float y = ImplicitLineEquation(_pB.X, _pB.Y, _pA.X, _pA.Y, _test.X, _test.Y);
	float _Y = ImplicitLineEquation(_pB.X, _pB.Y, _pA.X, _pA.Y, _pC.X, _pC.Y);

	float a = ImplicitLineEquation(_pC.X, _pC.Y, _pB.X, _pB.Y, _test.X, _test.Y);
	float _A = ImplicitLineEquation(_pC.X, _pC.Y, _pB.X, _pB.Y, _pA.X, _pA.Y);

	return { (b / _B), (y / _Y), (a / _A) };
}
unsigned int baryColor(VertexStruct _pA, VertexStruct _pB, VertexStruct _pC, VertexStruct ratios)
{
	unsigned int   alphaA = (_pA.color & 0xff000000) >> 24; //A
	unsigned int   alphaB = (_pB.color & 0xff000000) >> 24;
	unsigned int   alphaC = (_pC.color & 0xff000000) >> 24;

	unsigned int   rA = (_pA.color & 0x00ff0000) >> 16; // R
	unsigned int   rB = (_pB.color & 0x00ff0000) >> 16;
	unsigned int   rC = (_pC.color & 0x00ff0000) >> 16;

	unsigned int   gA = (_pA.color & 0x0000ff00) >> 8; // G
	unsigned int   gB = (_pB.color & 0x0000ff00) >> 8;
	unsigned int   gC = (_pC.color & 0x0000ff00) >> 8;

	unsigned int   bA = (_pA.color & 0x000000ff); // B
	unsigned int   bB = (_pB.color & 0x000000ff);
	unsigned int   bC = (_pC.color & 0x000000ff);

	unsigned int   rAlpha = (alphaA * ratios.Z) + (alphaB * ratios.X) + (alphaC * ratios.Y);
	unsigned int   rRed = (rA * ratios.Z) + (rB * ratios.X) + (rC * ratios.Y);
	unsigned int   rGreen = (gA * ratios.Z) + (gB * ratios.X) + (gC * ratios.Y);
	unsigned int   rBlue = (bA * ratios.Z) + (bB * ratios.X) + (bC * ratios.Y);


	int results = (rAlpha << 24) | (rRed << 16) | (rGreen << 8) | rBlue;
	return results;
}


// variables
float radians = (M_PI / 180) * (90 / 2);
float yScale = 1 / tan(radians);
float xScale = yScale / ( static_cast<float>(RASTER_WIDTH) / static_cast<float>(RASTER_HEIGHT));
float zFar = 10.0f;
float zNear = 0.1f;

Matrix4 PerspectiveMat = { {{xScale, 0, 0, 0},
						   {0, yScale, 0, 0},
						   {0, 0, zFar/ (zFar-zNear), 1},
						   {0, 0,(-(zFar*zNear)) / (zFar-zNear), 0}} };


//we combine these by multiplying them
Matrix4 tiltDown = RotationX(18.0f);
Matrix4 moveBack = { {{1,0,0,0},
					   {0,1,0,0},
					   {0,  0,1,0},
					   {0, 0, 1,1}} };

//there is a special order required for this
Matrix4 cameraLocation = Matrix4Mult(moveBack, tiltDown);

Matrix4 viewMatrix = Matrix4InverseOA(cameraLocation);
