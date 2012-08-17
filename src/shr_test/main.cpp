/* This project is for testing purposes only
 * set it as a startup project to test a particular feature of the product
 * for now just replace everything in main with the thing you want to see
 * working. Or stuff. We could probably extend this into a proper set of
 * tests that we run to test everything.
 */

#include <iostream>

/* Libraries to be tested */
#include "Tuple.h"
#include "Table.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "HPoint.h"
#include "HPoint.cpp"
#include "HMatrix.h"
#include "HMatrix.cpp"
#include "AVector.h"
#include "AVector.cpp"
#include "APoint.h"
#include "APoint.cpp"
#include "Float3.h"
//#include "Transform.h"
//#include "Transform.inl"


using namespace std;


void TupleTest()
{
	cout << "Testing tuples" << endl;

	Tuple<3,float> test;

	test[0] = 2.2f;
	test[1] = 3.3f;
	test[2] = 4.4f;

	cout << test[0] << endl << test[1] << endl << test[2] << endl;

	if( test[0] < test[1] )
		cout << "wow" << endl << endl;
}

void TableTest()
{
	cout << "Testing tables" << endl;

	Table<2,2,float> test;
	
	test[0][0] = 1.1f;
	test[0][1] = 1.1f;
	test[1][0] = 2.2f;
	test[1][1] = 2.2f;

	for( int i = 0; i < 2; i++ )
	{
		for( int j = 0; j < 2; j++ )
		{
			cout << test[i][j] << " ";
		}
		cout << endl << endl;
	}

}
void VectorTest()
{

	cout << "Testing vectors and operations" << endl;

	 Vector3<float> A;
	 Vector3<float> B(4.0f,5.0f,6.0f); //direct input for Vector B
	 Vector3<float> C;
	 Vector3<float> D;
	 Vector3<float> E;
	 Vector3<float> F;
	
	 A[0] = 1.0f;
	 A[1] = 2.0f;
	 A[2] = 3.0f;
	 C = A + B;
	 D = B - A;
	 E = A * 5.0f;
	 F = Vector3f::ZERO;
	 cout << "A = " << A << endl;
	 cout << "B = " << B << endl;
	 cout << "C = A + B = " << C << endl;
	 cout << "D = B - A = " << D << endl;
	 cout << "E = A * 5 = " << E << endl;
	 cout << "F = ZERO = " << F << endl << endl;

	
}



void MatrixTest()
{
	cout << "Testing Matrix and operations" << endl;

	Matrix3<float> matA(1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f);  // Direct input for the matrix
	Vector3<float> A;
	Vector3<float> B;
	Vector3<float> C;
		
	A[0] = 1.0f;
	A[1] = 2.0f;
	A[2] = 3.0f;
	B = A * 2;
	C = A + B;
	
	Matrix3<float> matB(A,B,C,1);  // Matrix created from 3 vectors
	Matrix3<float> matC(1.0f,2.0f,3.0f);  // Create a diagonal Matrix
	Matrix3<float> matD = matB;  // Assignment operator
	Matrix3<float> matE;
	Matrix3<float> matF;
	Matrix3<float> matG;

	matE.MakeZero();  //Make matE a Zero Matrix

	matF = matA * matE; //testing overloaded Operations
	matG = matA + matB; //testing overloaded Operations

	cout << matA; //matA (direct input)
	cout << matB; //matB (created from 3 vectors)
	cout << matC; //matC  (created as a diagonal  matrix)
	cout << matD; //matD  (testing assigment operator)
	cout << matE; //matE (zero matrix)
	cout << matF; //matF (testing overloaded operators)
	cout << matG; //matG (testing overloaded operators)
	
}

void HpointTest()
{
	cout << "Testing homogeneus points" << endl;

	HPoint hp1(2.0f, 1.0f, 6.0f, 1.0f);	//initializing with 4 floats
	HPoint hp2(1.0f, 2.0f, 3.0f, 1.0f);	//initializing with 4 floats
	HPoint hp3(hp2);					//initializing with an Hpoint
	HPoint hp4;							//unitialized
	hp4=hp3;							//assignment operator


	cout << "hp2 = " << hp2.X() << " " << hp2.Y() << " " << hp2.Z() << " " << hp2.W() << endl;
	cout << "hp3 = " << hp3.X() << " " << hp3.Y() << " " << hp3.Z() << " " << hp3.W() << endl;

	if((hp2 == hp3) &&(hp3 == hp4))
		cout << "True" << endl;

	if(hp1 != hp3)
		cout << "True" << endl;

	if(hp2 >= hp1)
		cout << "True" << endl << endl;
}

void HmatrixTest()
{
	cout << "Testing HMatrix" << endl;

	Matrix3<float> matA(1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f);  //matrix3
	HMatrix hm1(matA);													//initializing from matrix3
	HMatrix hm2();														//uninitialized
	HMatrix hm3(hm1);													//Initializing from another HMatrix
	HMatrix hm4(1.0f, 2.0f, 3.0f);										//Initializing with 3 floats (diagonal)
	HMatrix hm5(1.0f, 2.0f, 3.0f, 4.0f,									//Initializing with 16 floats
				5.0f, 6.0f, 7.0f, 8.0f,
				9.0f, 10.f, 11.0f, 12.0f,
				13.0f, 14.0f, 15.0f, 16.0f);		
	
	if(hm1 == hm3)
		cout << "True" << endl;					

	if(hm1 != hm4)
		cout << "True" << endl;

	hm1 = hm1 + hm3;													//assignment operator and mathemathic operators

	if(hm1 == ((hm1*2)- hm1))
		cout << "True" << endl << endl;

}

void AvectApoint()
{
	cout << "Testing AVectors and APoints" << endl;

	Tuple<3,float> test;
	test[0] = 2.2f;
	test[1] = 3.3f;
	test[2] = 4.4f;
	
	Vector3f A(2.0f, 2.0f, 2.0f);

	APoint ap1(1.0f, 3.0f, 5.0f);		//initialized with 3 floats
	APoint ap2(1.0f, 1.0f, 1.0f);		
	APoint ap3(ap1);					//initialized from an APoint
	APoint ap4(test);					//initialized from a Tuple
	APoint ap5(A);						//initialized from a vector3f

	AVector av1(1.0f, 2.0f, 3.0);		//initialized with 3 floats
	AVector av2(test);					//initialized from a Tuple
	AVector av3(A);						//initialized from a vector3f

	ap2 = ap1;							//assignment operator

	ap3 = ap2 - av2;					//poit - vector = point
	av1 = ap1 - ap2;					//point - point = vector

	ap4 = ap2 * 3;						//point by scalar
	ap5 += ap1;							// += operator

	av1 = av3.Cross(av2);				//assignment and cross operator

	cout << av2.Length() << endl;		//length
	cout << "av1 = "<< av1.X() << " " << av1.Y() << " " << av1.Z() << endl<< endl;
		
}

int main( int argc, char **argv )
{
	cout << "SHR Test Framework 0.1" << endl;

	TupleTest();
	TableTest();
	VectorTest();
	MatrixTest();
	HpointTest();
	HmatrixTest();
	AvectApoint();

	return 0;
}