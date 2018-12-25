#ifndef matrix_h
#define matrix_h
#include<iostream>
#include<stdio.h>
#include<cmath>
#include "engine.h"
#include "degree_radian.h"

using namespace std;
using namespace mathengine;
using namespace degree;
namespace matrixengine {

	class matrix {

	private:
		float mat[9] = { 0.0f};
	public:
		inline matrix()
		{
			for (int i = 0; i < 9; i++)
			{
				mat[i] = 0.0f;
			}

			mat[0] = mat[4] = mat[8] = 1;

		}

		inline matrix(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8)
		{

			mat[0] = m0;
			mat[3] = m3;
			mat[6] = m6;


			mat[1] = m1;
			mat[4] = m4;
			mat[7] = m7;

			mat[2] = m2;
			mat[5] = m5;
			mat[8] = m8;


		}

	
	inline friend matrix operator +(matrix const &,matrix const &);
	inline friend matrix operator -(matrix const &, matrix const &);
	inline friend matrix scalar_m(matrix const &,float const &);
	inline friend matrix divide_m(matrix const &,float const &);
	inline friend matrix transpose(matrix const &);
	
	inline float det(matrix const &);
	inline friend matrix inverse(matrix const &);

	inline friend enginemath rotate_x(enginemath const &,float const &);
	inline void print();






 };

	matrix operator +(matrix const  &a,matrix const &c)
	{
		matrix b;

		b.mat[0] = c.mat[0] + a.mat[0];
		b.mat[3] = a.mat[3] + c.mat[3];
		b.mat[6] = a.mat[6] + c.mat[6];
	    b.mat[1] = a.mat[1] + c.mat[1];
		 b.mat[4] = a.mat[4] + c.mat[4];
		b.mat[7] = a.mat[7] + c.mat[7];
		b.mat[2] = a.mat[2] + c.mat[2];
		b.mat[5] = a.mat[5] + c.mat[5];
		b.mat[8] = a.mat[8] + c.mat[8];

		return b;

  }


	matrix operator -(matrix const &a, matrix const &b)
	{
		matrix c;

		c.mat[0] = a.mat[0] - b.mat[0];
		c.mat[3] = a.mat[3] - b.mat[3];
		c.mat[6] = a.mat[6] - b.mat[6];
		c.mat[1] = a.mat[1] - b.mat[1];
		c.mat[4] = a.mat[4] - b.mat[4];
		c.mat[7] = a.mat[7] - b.mat[7];
		c.mat[2] = a.mat[2] - b.mat[2];
		c.mat[5] = a.mat[5] - b.mat[5];
		c.mat[8] = a.mat[8] - b.mat[8];
		return c;

	}
  
	matrix scalar_m(matrix const &a, float const &k)
	{
		matrix b;
		b.mat[0] = a.mat[0] * k;
		b.mat[3] = a.mat[3] * k;
		b.mat[6] = a.mat[6] * k;
		b.mat[1] = a.mat[1] * k;
		b.mat[4] = a.mat[4] * k;
		b.mat[7] = a.mat[7] * k;
		b.mat[2] = a.mat[2] * k;

		return b;
	}
	matrix divide_m(matrix const &a, float const &k)
	{
		matrix b;
		b.mat[0] = a.mat[0] / k;
		b.mat[3] = a.mat[3] / k;
		b.mat[6] = a.mat[6] / k;
		b.mat[1] = a.mat[1] / k;
		b.mat[4] = a.mat[4] / k;
		b.mat[7] = a.mat[7] / k;
		b.mat[2] = a.mat[2] / k;
		b.mat[5] = a.mat[5] / k;
		b.mat[8] = a.mat[8] / k;
		return b;





	}
	 
	matrix transpose(matrix const &a)
	{

		matrix b;
		b.mat[0] = b.mat[0];
		b.mat[4] = b.mat[4];
		b.mat[8] = b.mat[8];

		b.mat[3] = a.mat[1];
		b.mat[1] = a.mat[3];
			
			 
		b.mat[6] = a.mat[2];
			b.mat[2] = a.mat[6];
		

			b.mat[7] = a.mat[5];
		b.mat[5] = a.mat[7];
		


		
		return b;

	}

	float matrix::det(matrix const &a)
	{

		float t1 = a.mat[0] * (a.mat[4]*a.mat[8] - a.mat[7]*a.mat[5]);
		float t2 = a.mat[3] * (a.mat[2] * a.mat[7] - a.mat[1] * a.mat[8]);
		float t3 = a.mat[6] * (a.mat[1]*a.mat[5]-a.mat[2]*a.mat[4]);
		float result = t1 + t2 + t3;
		return result;

	}


	matrix inverse(matrix const &a)
	{
		matrix v = transpose(a);

		float t1 = a.mat[0] * (a.mat[4] * a.mat[8] - a.mat[7] * a.mat[5]);
		float t2 = a.mat[3] * (a.mat[2] * a.mat[7] - a.mat[1] * a.mat[8]);
		float t3 = a.mat[6] * (a.mat[1] * a.mat[5] - a.mat[2] * a.mat[4]);
		float result = t1 + t2 + t3;

		matrix b = divide_m(v,result);
		return b;



	}

	enginemath rotate_x(enginemath const &b,float const &angle)
	{

		radian x;
		x.set_value(angle);
		float s_theta = x.sin_theta(angle);
		float c_theta = x.cos_theta(angle);
		float minus_s_theta = -(x.sin_theta(angle));
		matrix a(1,0,0,0,c_theta,minus_s_theta,0,s_theta,c_theta);
		enginemath d(b);
		float first = d.get_x(b);
		float second = d.get_y(b);
		float third = d.get_z(b);
		float one = a.mat[0] * first + a.mat[3] * second + a.mat[6] * third;
		float two = a.mat[1] * first + a.mat[4] * second + a.mat[7] * third;
		float three = a.mat[2] * first + a.mat[5] * second + a.mat[7]*third;

		return	enginemath(one,two,three);







	}


	void matrix::print()
	{
	cout << mat[0] << " " << mat[3] << " " << mat[6] << endl;

		cout << mat[1] << " " << mat[4] << " " << mat[7] << endl;
		cout << mat[2] << " " << mat[5] << " " << mat[8] << endl;

}











}



















#endif