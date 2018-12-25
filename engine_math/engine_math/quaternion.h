#ifndef quaternion_h
#define quaternion_h

#include "engine.h"
#include<iostream>
#include<cmath> 

using namespace std;

using namespace mathengine;
/*enginemath  x(float a, float b, float c)
{
	return enginemath(a,b,c);
}
*/

namespace quarternion {


	class quart {

	protected:
		float s;
		float x;
		float y;
		float z;
		
	public:
		inline quart()
		{
			enginemath x();
			s = 0.0f;

		}
		inline quart(float scalar,float x1, float y1, float z1) {
			x = x1;
			y = y1;
			z = z1;

			enginemath vec(x, y, z);
			s = scalar;


		}
		inline friend quart operator +(quart const &, quart const &);
		inline friend quart operator -(quart const &, quart const &);
		inline friend quart operator *(quart const &, quart const &);
		inline float norm(quart const &);
		inline friend quart multiply_scalar_quart(quart const &, float const &);
		inline friend quart unit_norm(quart const &);
		inline friend quart conjugate(quart const &);
		inline friend quart inverse(quart const &);
		inline friend quart rotate(quart const &);
        
		inline void print_quart(quart const &);






	};
	void quart::print_quart(quart const &a)
	{

		enginemath zec(a.x,a.y,a.z);
		float scal = a.s;
		cout << scal << " " << zec.get_x(zec) << " " << zec.get_y(zec) << " " << zec.get_z(zec) << endl;


	}

	quart operator +(quart const &a,quart const &b)
	{

		float xec = a.s;
		float yec = b.s;
		float zec = xec + yec;
		enginemath x1(a.x,a.y,a.z);
		enginemath x2(b.x,b.y,b.z);
		//from engine.h override
		enginemath  x3 = x1+x2;
		
		quart ad_quart(zec,x3.get_x(x3),x3.get_y(x3),x3.get_z(x3));
		return ad_quart;

		





}

	quart operator -(quart const &a,quart const &b)
	{

		float x = a.s;
		float y = b.s;
		float z = x - y;

		enginemath x1(a.x,a.y,a.z);
		enginemath x2(b.x,b.y,b.z);
		enginemath x3 = x1 - x2;
		quart sub_quart(z, x3.get_x(x3), x3.get_y(x3), x3.get_z(x3));
		return sub_quart;
     




	}

	quart operator *(quart const &a, quart const &b)
	{

		float x = a.s;
		float y = b.s;
		float z = x * y;
		enginemath x1(a.x,a.y,a.z);
		enginemath x2(b.x,b.y,b.z);
		enginemath x3 = cross_product(x1, x2);
		enginemath x4(a.x,a.y,a.z);
		float z_e = x4.d_p(x1, x2);
		z -= z_e;
		enginemath x5 = multiply_scalar(x2, x);
		enginemath x6 = multiply_scalar(x1, y);
		enginemath x7 = x5 + x6 + x3;
		quart result(z, x7.get_x(x7), x7.get_y(x7), x7.get_z(x7));
		return result;




   }
	float quart::norm(quart const &b)
	{
       

		float scale = b.s;
		enginemath x1(b.x,b.y,b.z);
		float mag = x1.magnitude(x1);
		float mag_sq = mag * mag;
		float scale_sq = scale * scale;
		float result = sqrt(scale_sq + mag_sq);
		return result;




	}

	quart multiply_scalar_quart(quart const &a,float const &b)
	{
		float x_val = a.s;
		x_val *= b;
		enginemath vector(a.x,a.y,a.z);
		enginemath res = multiply_scalar(vector,b);
		quart final(x_val, res.get_x(res), res.get_y(res),res.get_z(res));
		return final;




	}
	quart unit_norm(quart const &a)
	{
		float scalar = a.s;
		enginemath vect(a.x,a.y,a.z);

		quart b(a.s, vect.get_x(vect), vect.get_y(vect), vect.get_z(vect));
		float mag = b.norm(b);
		scalar /= mag;
		enginemath vect2 = divide_scalar(vect,mag);
		quart res(scalar, vect2.get_x(vect2), vect2.get_y(vect2), vect2.get_z(vect2));
		return res;



	}

	quart conjugate(quart const &b)
	{

		enginemath vect(b.x,b.y,b.z);
		enginemath vect1 = conjugate(vect);
		quart res(b.s,vect1.get_x(vect1),vect1.get_y(vect1),vect1.get_z(vect1));
		return res;


	}
	quart inverse(quart const &a)
	{
		conjugate(a);
		quart b(a);
		float mag = b.norm(b);
		mag *= mag;
		float sc = a.s;
		sc /= mag;
		enginemath z(a.x,a.y,a.z);
		enginemath ze = divide_scalar(z, mag);
		quart inv(sc, ze.get_x(ze), ze.get_y(ze), ze.get_z(ze));
		return inv;



	}

	quart rotate(quart const &a)
	{

		

		enginemath vect(a.x,a.y,a.z);
		quart b(a);
		quart p(0.0f, vect.get_x(vect), vect.get_y(vect), vect.get_z(vect));
		quart inv = inverse(a);
		quart res = b*p;
		quart res1 = res*inv;
		return res1;


	}



}

















#endif