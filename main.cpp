#include <iostream>
#include "Color.h"
#include "Raster.h"
#include "Vector2.h"
#include "Matrix.h"
#include "Model.h"

#define WIDTH 80
#define HEIGHT 100

using namespace std;

int main() {
//	Vector4 a(1,1,1,1);
//	Vector4 b(1,2,3,4);
//	Vector4 plus = a + b;
//	Vector4 minus = a - b;
//	Vector4 times = a * 2;
//	Vector4 normalize = b.Normalize();
//	//Vector4 perp = a.Perpendicular();
//	cout << plus.x << ", " << plus.y << ", " << plus.z << ", " << plus.w << endl;
//	cout << minus.x << ", " << minus.y << ", " << plus.z << ", " << plus.w << endl;
//	cout << times.x << ", " << times.y << ", " << plus.z << ", " << plus.w << endl;
//	cout << a.Magnitude() << endl;
//	cout << a.Dot(b) << endl;
//	cout << normalize.x << ", " << normalize.y << ", " << normalize.z << ", " << normalize.w << endl;
//	//cout << perp.x << ", " << perp.y << endl;
	//cout << Determinant(a,b) << endl;
    //Color c1(1.0, 0.25, 0.25, 0.50);
    //Color c2(0.0, 0.5, 1.0, 0.60);

    // cout << "----------  Overload the addition ----------" << endl;
    // Color c3 = c1 + c2;
    // cout << "Color c1: Red " << c1.red << ", Green" << c1.green << ", Blue" << c1.blue << ", Alpha" << c1.alpha << endl;
    // cout << "Color c2: Red " << c2.red << ", Green" << c2.green << ", Blue" << c2.blue << ", Alpha" << c2.alpha << endl;
    // cout << "Color c3 = c1 + c2" << endl;
    // cout << "Color c3: Red " << c3.red << ", Green" << c3.green << ", Blue" << c3.blue << ", Alpha" << c3.alpha << endl;

    // cout << "----------  Overload the subtraction ----------" << endl;
    // Color c4 = c2 - c1;
    // cout << "Color c4 = c2 - c1" << endl;
    // cout << "Color c4: Red " << c4.red << ", Green" << c4.green << ", Blue" << c4.blue << ", Alpha" << c4.alpha << endl;

    // cout << "----------  Overload the multiplication ----------" << endl;
    // Color c5 = c1 * 1.5;
    // cout << "Color c5 = c1 * 1.5" << endl;
    // cout << "Color c5: Red " << c5.red << ", Green" << c5.green << ", Blue" << c5.blue << ", Alpha" << c5.alpha << endl;

    // cout << "----------  Preprocessor Directives ----------" << endl;
    // Color c6 = Red;
    // cout << "Color c6: Red " << c6.red << ", Green" << c6.green << ", Blue" << c6.blue << ", Alpha" << c6.alpha << endl;

    //Raster test(WIDTH, HEIGHT, White);
    //Triangle2D myTriangle(Vector2(-40, 15),Vector2(20, 0),Vector2(45, 80),Red,Green,Blue);
    // test.GetColorPixel(3,0).print();
    //test.SetColorPixel(10,0, White);
    //test.DrawLine_DDA_Interpolated(0.0, 18.0, 17.0, 18.0, Blue, Green);
    //test.SetColorPixel(2.0, 15.0, Green);
    //test.SetColorPixel(72.0, 10.0, Green);
    //test.SetColorPixel(45.0, 80.0, Green);
    //test.SetColorPixel(0.0, 3.0, Green);
    //test.DrawLine_DDA_Interpolated(18.0, 6.0, 4.0, 2.0, Green, Red);
    //test.DrawLine_DDA_Interpolated(0.0, 18.0, 0.0, 3.0, Black,Red);
    //test.DrawTriangle2D_DotProduct(myTriangle);
    //test.DrawTriangle_Barycentric(myTriangle);
    //test.SetColorPixel(2.0, 80.0, Green);
    //test.SetColorPixel(70.0, 10.0, Green);
	//test.SetColorPixel(45.0, 80.0, Green);
	//test.SetColorPixel(45.0, 80.0, Green);
//	Vector4 V(3,5,7,9);
//    Matrix4 A(1 , 2 , 3 , 4 ,
//     5 , 6 , 7 , 8 ,
//     9 , 10 , 11 , 12 ,
//     13 , 14 , 15 , 16);
//    Vector4 result = A*V;
//     cout << "x: " << result.x
//          << " y: " << result.y
//		  << " z: " << result.z
//		  << " w: " << result.w << endl;

//    Matrix4 B(17 , 18 , 19 , 20 ,
//     21 , 22 , 23 , 24 ,
//     25 , 26 , 27 , 28 ,
//     29 , 30 , 31 , 32);
//
	Matrix4 C = Translate3D(50, 50, 0) *
    		RotateZ3D(-45.0);
			//Scale3D(0.5, 0.5, 0.5);
    cout << C.m11 << " " << C.m21 << " " << C.m31 << " " << C.m41 << endl;
    cout << C.m12 << " " << C.m22 << " " << C.m32 << " " << C.m42 << endl;
    cout << C.m13 << " " << C.m23 << " " << C.m33 << " " << C.m43 << endl;
    cout << C.m14 << " " << C.m24 << " " << C.m34 << " " << C.m44 << endl;
    Raster myRaster(100, 100, White);
    Model teapot = Model();
    teapot.ReadFromOBJFile("teapot.obj", Red);

    Matrix4 m = Translate3D(50, 50, 0) *
    		RotateZ3D(-45.0) *
			Scale3D(0.5, 0.5, 0.5);

    teapot.Transform(m);
    myRaster.DrawModel(teapot);
    myRaster.WriteToPPM();
    cin.get();
    return 0;
}
