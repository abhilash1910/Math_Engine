#include<iostream>
#include<cmath>
#include<stdio.h>
#include "engine.h"
#include "matrix.h"
#include "quaternion.h"
using namespace mathengine;
using namespace matrixengine;
using namespace quarternion;
void main()
{
	float x;
	std::cout << "Hi" << std::endl;
	enginemath vector1(2.0f, 3.0f, 5.0f);
	enginemath vector2(3.0f, 4.0f, 6.0f);


	enginemath(vector1 + vector2).print();
	enginemath(vector1 - vector2).print();
	enginemath vector3 = vector1 * vector2;
	enginemath(vector3).print();
	vector3 = multiply_scalar(vector1, 0.5f);
	enginemath vector4 = multiply_scalar(vector2, 0.5);
	enginemath(vector3).print();
	enginemath(vector4).print();
	enginemath vector5 = divide_scalar(vector1,0.5f);
	enginemath vector6 = divide_scalar(vector2, 0.5f);
	vector5.print();
	vector6.print();
	enginemath vector7 = dot_product(vector1,vector2);
	vector7.print();
	enginemath vector8 = cross_product(vector1, vector2);
	vector8.print();
	enginemath vector9 = normalise(vector1);
	vector9.print();
	enginemath vector10 = normalise(vector2);
	vector10.print();
	float mag1 = vector1.magnitude(vector1);
	std::cout << mag1 << std::endl;
	float mag2 = vector2.magnitude(vector2);
	std::cout << mag2 << std::endl;

	enginemath vector11 = conjugate(vector1);
	vector11.print();
	enginemath vector12 = conjugate(vector2);
	vector12.print();
	enginemath vector13 = absolute(vector1);
	vector13.print();
	enginemath vector14 = absolute(vector2);
	vector14.print();
	std::cin >> x;
	std::cout << x << "  end of  vector program" << std::endl;

	
	




	matrix mat(1,2,3,4,5,6,7,8,9);
	matrix(mat).print();
	matrix mat1(2,3,4,8,7,10,5,8,9);
	matrix mat2(7, 8, 9, 4, 0, 2, 5, 3, 4);
	matrix mat4 = mat1 + mat2;
	matrix(mat4).print();
	matrix mat5 = mat1 - mat2;
	matrix(mat5).print();

	matrix mat6 = scalar_m(mat1,0.5f);
	matrix(mat6).print();
	matrix mat7 = scalar_m(mat2, 0.5f);
	matrix(mat7).print();

	matrix mat8 = divide_m(mat1, 0.5f);
	matrix(mat8).print();
	matrix mat9 = divide_m(mat2,0.5f);
	matrix(mat9).print();
	matrix mat21(7, 8, 9, 10, 0, 2, 15, 13, 24);
	matrix mat10 = transpose(mat21);
	std::cout << "transpose" << std::endl;
	mat10.print();
	std::cout<<mat10.det(mat1)<<std::endl;
	matrix mat11 = inverse(mat1);
	std::cout << "inverse" << std::endl;
	mat11.print();
	std::cout << "rotation" << std::endl;
	enginemath vect_rotate = rotate_x(vector1,45.0f);
	vect_rotate.print();
	std::cin >> x;
	std::cout << x << "  end of  matrix program" << std::endl;
	std::cin >> x;
	

	
	quart q1(1.0f, 2.0f, 3.0f, 5.0f);
	q1.print_quart(q1);
	quart q2(2.0f, 5.0f, 8.0f, 4.0f);
	q2.print_quart(q2);
	quart q3 = q1 + q2;
	q3.print_quart(q3);
	quart q4 = multiply_scalar_quart(q1, 0.5f);
	q4.print_quart(q4);
	quart q5 = inverse(q1);
	q5.print_quart(q5);
	float q6 = q2.norm(q2);
	std::cout << "norm" << q6 << endl;
	quart q7 = unit_norm(q1);
	q7.print_quart(q7);
	quart q8 = conjugate(q2);
	q8.print_quart(q8);
	quart q9 = rotate(q1);
	q9.print_quart(q9);
	std::cout << "end of quart" << std::endl;
	int abcd;
	std::cin >>abcd;



}