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

int main( int argc, char **argv )
{
	cout << "SHR Test Framework 0.1" << endl;

	TupleTest();
	TableTest();
	VectorTest();
	MatrixTest();

	return 0;
}