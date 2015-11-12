/*
 * Main.cpp
 *
 *  Created on: Nov 10, 2015
 *      Author: doncole
 */

#include <stdio.h>
#include <iostream>
#include <Eigen>
#include <Dense>

using namespace std;
using namespace Eigen;

ArrayXXf InitMatrix(ArrayXXf matrix);
ArrayXf InitVector(ArrayXf vector);
ArrayXXf AddRowToMatrix(ArrayXf rowA, ArrayXXf matrixU, int i);
ArrayXf AddNumBToVectorB(float numB,ArrayXf vectorB, int j);


int main(void){

	int squareNum = 7;	//square matrix 7x7 and vector = 7

	ArrayXXf matrixA(squareNum,squareNum);
	ArrayXXf matrixU(squareNum,squareNum);
	ArrayXf vectorB(squareNum);
	ArrayXf rowA(squareNum), rowB(squareNum), solutionX(squareNum);
	float numA, numB;
	//Init the Matrix and Vector
	matrixA = InitMatrix(matrixA);
	vectorB = InitVector(vectorB);
	matrixU = matrixA;

	cout << "Matrix A " << endl << matrixA << endl;
	cout << "Vector B " << endl << vectorB << endl;
	//Solve by G.E.
	//iterate squareNum-1 times
	for (int i = 0; i < squareNum -1; i++)
	{
		rowA = matrixU.row(i);	//Get the row
		numA = rowA[i];	//Get the Rows first number
		rowA = rowA/numA; 	//divide the row by the number
		numB = vectorB[i]/numA;	//divide the Vector by the number
		//numB = vectorB[i];	//copy the number for the rest of the vector

		for (int j = i+1; j< squareNum; j++)
		{
			rowB = rowA;	//get the beginning Row again
//			cout << "Matrix U" << endl << matrixU << endl;	//print the Matrix out
			//Multiply the Row by the Next row's first Integer
			//get the next rows first integer
//			cout << "The next Rows integer" << matrixU.row(j)[i] << endl;
			rowB = rowB * (-1.0) * matrixU.row(j)[i];
			numB = (numB * (-1.0) * matrixU.row(j)[i]);
//			cout << "The num B " << endl << numB << endl;
//			cout << "The row multiplied By" << endl << rowB << endl;
			//Add the row to the next Rows
			matrixU = AddRowToMatrix(rowB, matrixU, j);		//add the row to the rest of the matrix
			vectorB = AddNumBToVectorB(numB, vectorB, j);	//add the number to the rest of the vector
		}
	}
	solutionX[squareNum-1] = vectorB[squareNum-1]/matrixU.row(squareNum-1)[squareNum-1];
//	cout << "Solution X" << endl << solutionX << endl;

	for (int i = squareNum-2; i>-1; i--)
	{
		float sum = 0;
//		cout << "VectorB" << endl << vectorB[i] << endl;
//		matrixU.row(i)/matrixU.row(i)[i];
//		vectorB[i] = vectorB[i]/matrixU.row(i)[i];
//		cout << "Matrix U" << endl << matrixU << endl;
//		cout << "Vector B" << endl << vectorB << endl;

		for (int j = 6; j > i; j--)
		{
			sum = sum + matrixU.row(i)[j] * solutionX[i+1];
			//cout << "sum" << endl << sum << endl;
		}
		solutionX[i] = (vectorB[i] - sum)/matrixU.row(i)[i];
//		cout << "Solution X" << endl << solutionX << endl;
	}
	//Print the outputs
	cout << "Matrix U " << endl << matrixU << endl;
	cout << "Vector B " << endl << vectorB << endl;
	cout << "The Solution Matrix " << endl << solutionX << endl;

	return 0;
}

ArrayXf AddNumBToVectorB(float numB, ArrayXf vectorB, int row)
{
	//vectorB[0] = 100.0;
	while (row < 7)
	{
		vectorB[row] = vectorB[row] + numB;
		row++;
	}
	//print the Vector
	//cout << "VectorB" << endl << vectorB << endl;
	return vectorB;
}

ArrayXXf AddRowToMatrix(ArrayXf rowA, ArrayXXf matrixU, int row)
{
	//we need to construct the matrices
	//By first adding the row to the rest of the matrix
//	ArrayXXf tempArray(7, 7);
//	tempArray = matrixU.array();
	while (row < 7)
	{
		//add to the rest of the rows
		matrixU.row(row) += rowA;
		row++;
	}
	//print the array
	//cout << "MatrixU" << endl << matrixU << endl;
	return matrixU;
}

//Initialize the Given 7x7 Matrix
ArrayXXf InitMatrix(ArrayXXf matrix)
{
	int i= 0, j = 0;
	//First Row
	matrix(i, j++) = .1897;
	matrix(i, j++) = .3784;
	matrix(i, j++) = .6449;
	matrix(i, j++) = .7271;
	matrix(i, j++) = .4449;
	matrix(i, j++) = .1730;
	matrix(i, j++) = .0118;
	j = 0;
	i++;
	//Second Row
	matrix(i, j++) = .1934;
	matrix(i, j++) = .8600;
	matrix(i, j++) = .8180;
	matrix(i, j++) = .3093;
	matrix(i, j++) = .6946;
	matrix(i, j++) = .9797;
	matrix(i, j++) = .8939;
	j = 0;
	i++;
	//Third Row
	matrix(i, j++) = .6822;
	matrix(i, j++) = .8537;
	matrix(i, j++) = .6602;
	matrix(i, j++) = .8385;
	matrix(i, j++) = .6213;
	matrix(i, j++) = .2714;
	matrix(i, j++) = .1991;
	j = 0;
	i++;
	//FourthRow
	matrix(i, j++) = .3028;
	matrix(i, j++) = .5936;
	matrix(i, j++) = .3420;
	matrix(i, j++) = .5681;
	matrix(i, j++) = .7948;
	matrix(i, j++) = .2523;
	matrix(i, j++) = .2987;
	j = 0;
	i++;
	//Fifth Row
	matrix(i, j++) = .5417;
	matrix(i, j++) = .4966;
	matrix(i, j++) = .2897;
	matrix(i, j++) = .3704;
	matrix(i, j++) = .9568;
	matrix(i, j++) = .8757;
	matrix(i, j++) = .6614;
	j = 0;
	i++;
	//6th Row
	matrix(i, j++) = .1509;
	matrix(i, j++) = .8998;
	matrix(i, j++) = .3412;
	matrix(i, j++) = .7027;
	matrix(i, j++) = .5226;
	matrix(i, j++) = .7373;
	matrix(i, j++) = .2844;
	j = 0;
	i++;
	//7th Row
	matrix(i, j++) = .6979;
	matrix(i, j++) = .8216;
	matrix(i, j++) = .5341;
	matrix(i, j++) = .5466;
	matrix(i, j++) = .8801;
	matrix(i, j++) = .1365;
	matrix(i, j++) = .4692;

	return matrix;
}

ArrayXf InitVector(ArrayXf vector){
	int i = 0;
	vector(i++) = .5000;
	vector(i++) = -.3000;
	vector(i++) = -.2000;
	vector(i++) = .7000;
	vector(i++) = -.9000;
	vector(i++) = .3000;
	vector(i++) = .1000;
	return vector;
}
