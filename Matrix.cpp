#include "Matrix.h"

#define _USE_MATH_DEFINES
#include <math.h>



Matrix4::Matrix4(){
	m11 = 1.0; m21 = 0.0; m31 = 0.0; m41 = 0.0;
	m12 = 0.0; m22 = 1.0; m32 = 0.0; m42 = 0.0;
	m13 = 0.0; m23 = 0.0; m33 = 1.0; m43 = 0.0;
	m14 = 0.0; m24 = 0.0; m34 = 0.0; m44 = 1.0;
}

Matrix4::Matrix4(float p11, float p21, float p31, float p41,
				 float p12, float p22, float p32, float p42,
				 float p13, float p23, float p33, float p43,
				 float p14, float p24, float p34, float p44)
{
	m11 = p11;
	m21 = p21;
	m31 = p31;
	m41 = p41;

	m12 = p12;
	m22 = p22;
	m32 = p32;
	m42 = p42;

	m13 = p13;
	m23 = p23;
	m33 = p33;
	m43 = p43;

	m14 = p14;
	m24 = p24;
	m34 = p34;
	m44 = p44;
}

Vector4 Matrix4::operator*(Vector4 other){
	float vx = (other.x * m11) + (other.y * m21) + (other.z * m31) + (other.w * m41);
	float vy = (other.x * m12) + (other.y * m22) + (other.z * m32) + (other.w * m42);
	float vz = (other.x * m13) + (other.y * m23) + (other.z * m33) + (other.w * m43);
	float vw = (other.x * m14) + (other.y * m24) + (other.z * m34) + (other.w * m44);
	return Vector4(vx, vy, vz, vw);
}

Matrix4 Matrix4::operator*(Matrix4 p){
	float new11 = (p.m11 * m11) + (p.m12 * m21) + (p.m13 * m31) + (p.m14 * m41);
	float new12 = (p.m11 * m12) + (p.m12 * m22) + (p.m13 * m32) + (p.m14 * m42);
	float new13 = (p.m11 * m13) + (p.m12 * m23) + (p.m13 * m33) + (p.m14 * m43);
	float new14 = (p.m11 * m14) + (p.m12 * m24) + (p.m13 * m34) + (p.m14 * m44);

	float new21 = (p.m21 * m11) + (p.m22 * m21) + (p.m23 * m31) + (p.m24 * m41);
	float new22 = (p.m21 * m12) + (p.m22 * m22) + (p.m23 * m32) + (p.m24 * m42);
	float new23 = (p.m21 * m13) + (p.m22 * m23) + (p.m23 * m33) + (p.m24 * m43);
	float new24 = (p.m21 * m14) + (p.m22 * m24) + (p.m23 * m34) + (p.m24 * m44);

	float new31 = (p.m31 * m11) + (p.m32 * m21) + (p.m33 * m31) + (p.m34 * m41);
	float new32 = (p.m31 * m12) + (p.m32 * m22) + (p.m33 * m32) + (p.m34 * m42);
	float new33 = (p.m31 * m13) + (p.m32 * m23) + (p.m33 * m33) + (p.m34 * m43);
	float new34 = (p.m31 * m14) + (p.m32 * m24) + (p.m33 * m34) + (p.m34 * m44);

	float new41 = (p.m41 * m11) + (p.m42 * m21) + (p.m43 * m31) + (p.m44 * m41);
	float new42 = (p.m41 * m12) + (p.m42 * m22) + (p.m43 * m32) + (p.m44 * m42);
	float new43 = (p.m41 * m13) + (p.m42 * m23) + (p.m43 * m33) + (p.m44 * m43);
	float new44 = (p.m41 * m14) + (p.m42 * m24) + (p.m43 * m34) + (p.m44 * m44);

	Matrix4 m = { new11, new21, new31, new41,
		new12, new22, new32, new42,
		new13, new23, new33, new43,
		new14, new24, new34, new44 };

	return m;

}


Matrix4 Translate3D(float tx, float ty, float tz){
	return Matrix4(1.0, 0.0, 0.0, tx,
				   0.0, 1.0, 0.0, ty,
		           0.0, 0.0, 1.0, tz,
				   0.0, 0.0, 0.0, 1.0);
}


Matrix4 Scale3D(float sx, float sy, float sz){
	return Matrix4(sx, 0.0, 0.0, 0.0,
				   0.0, sy, 0.0, 0.0,
				   0.0, 0.0, sz, 0.0,
				   0.0, 0.0, 0.0, 1.0);
}

Matrix4 RotateX3D(float degrees){
	float radians = degrees * (M_PI / 180.0);
	float cosT = cosf(radians);
	float sinT = sinf(radians);
	Matrix4 m = { 1.0, 0.0, 0.0, 0.0,
		          0.0, cosT, sinT, 0.0,
		          0.0, -sinT, cosT, 0.0,
	              0.0, 0.0, 0.0, 1.0 };

	return m;
}


Matrix4 RotateY3D(float degrees){
	float radians = degrees * (M_PI / 180.0);
	float cosT = cosf(radians);
	float sinT = sinf(radians);
	Matrix4 m = { cosT, 0.0, -sinT, 0.0,
		           0.0, 1.0, 0.0, 0.0,
		          sinT, 0.0, cosT, 0.0,
	 	           0.0, 0.0, 0.0, 1.0 };
	return m;
}


Matrix4 RotateZ3D(float degrees){
	float radians = degrees * (M_PI / 180.0);
	float cosT = cosf(radians);
	float sinT = sinf(radians);
	Matrix4 m = { cosT, sinT, 0.0, 0.0,
		         -sinT, cosT, 0.0, 0.0,
		           0.0, 0.0, 1.0, 0.0,
		           0.0, 0.0, 0.0, 1.0 };
	return m;
}


Matrix4 Rotate3D(float degreesX, float degreesY, float degreesZ){
	Matrix4 m = RotateX3D(degreesX) * RotateY3D(degreesY) * RotateZ3D(degreesZ);
	return m;
}

Matrix4 Rotate3D(float degrees, Vector4 vec){
	float alpha = atanf(vec.x / vec.z);
	float beta = acosf(vec.y / vec.Magnitude());

	Matrix4 m = RotateY3D(-alpha) * RotateX3D(-beta) * RotateY3D(degrees) * RotateX3D(beta) * RotateY3D(alpha);
	return m;
}

Matrix4 LookAt(Vector4 eye, Vector4 spot, Vector4 up){
	Vector4 look = (spot - eye).Normalize();
	Vector4 right = look.Cross(up).Normalize();
	up = up.Normalize();
	Matrix4 move(1,0,0,-eye.x,
				 0,1,0,-eye.y,
				 0,0,1,-eye.z,
				 0,0,0,1);
	Matrix4 map(right.x, right.y, right.z, 0,
				up.x, up.y, up.z, 0,
				-look.x, -look.y, -look.z, 0,
				0,0,0,1);
	return map*move;
}
Matrix4 Orthographic(float minX, float maxX,
					 float minY, float maxY,
					 float minZ, float maxZ){
	Matrix4 trans = Translate3D(-(minX+maxX)/2,
							   -(minY+maxY)/2,
							   -(minZ+maxZ)/2);
	Matrix4 scale = Scale3D(2/(maxX-minX),
							2/(maxY-minY),
							2/(maxZ-minZ));
	return scale*trans;
}

Matrix4 Perspective(float fovY, float aspect, float nearZ, float farZ){
	float rad = fovY * M_PI / 180.0;
	float f = 1/(tan(rad/2));
	Matrix4 result(f/aspect, 0, 0, 0,
					   0, f, 0, 0,
					   0, 0, (farZ+nearZ)/(nearZ-farZ), 2*nearZ*farZ/(nearZ-farZ),
					   0, 0, -1, 0);
	return result;
}

Matrix4 Viewport(float x, float y, float width, float height){
	return Translate3D(x,y,0)*Scale3D(width,height,1)
		   *Scale3D(0.5,0.5,0.5)*Translate3D(1,1,-1);
}
