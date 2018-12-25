


#ifndef engine_h
#define engine_h

#include<cmath>
#include<iostream>
#include<vector>
#include<stdio.h>

namespace mathengine {


	class enginemath {

	private:

		float x, y, z;
	public:


		inline enginemath() :x(0.0f), y(0.0f), z(0.0f) {};
		inline enginemath(float x1, float y1, float z1) :x(x1), y(y1), z(z1) {};

		inline friend enginemath operator +(enginemath const &, enginemath const &);
		 inline friend enginemath operator -(enginemath const &, enginemath const &);

		 inline friend enginemath operator  *(enginemath const &, enginemath const &);
		 inline friend enginemath multiply_scalar(enginemath const &, float const &);
		 inline float d_p(enginemath const &a, enginemath const &b)
		 {
			 return (a.x*b.x + a.y*b.y + a.z*b.z);


		 }
		 inline friend enginemath divide_scalar(enginemath const &, float const &);
		 inline friend enginemath dot_product(enginemath const &a, enginemath const &b);
		 inline friend enginemath cross_product(enginemath const &, enginemath const &b);
		 inline friend enginemath normalise(enginemath const &);
		 inline float magnitude(enginemath const &);
		 inline friend enginemath conjugate(enginemath const &);
		 inline friend enginemath absolute(enginemath const &);
		 inline float get_x(enginemath const &a)
		 {

			 return a.x;
		 }
		 inline float get_y(enginemath const &b)
		 {
			 return b.y;
		 }
		 inline float get_z(enginemath const &c)
		 {
			 return c.z;
		 }


		 inline void print();



	};

	enginemath operator +(enginemath const &a, enginemath const &b)
	{


		return enginemath(a.x + b.x, a.y + b.y, a.z + b.z);
	}

	enginemath operator -(enginemath const &a, enginemath const &b)
	{


		return enginemath(a.x - b.x, a.y - b.y, a.z - b.z);
	}

	void enginemath::print()
	{

		std::cout << x << " " << y << " " << z << std::endl;
	}

	enginemath operator *(enginemath const &a, enginemath const &b)
	{
		return enginemath(a.x*b.x, a.y*b.y, a.z*b.z);

	}
	enginemath multiply_scalar(enginemath const &a, float const &c)
	{
		return  enginemath(a.x*c, a.y*c, a.z*c);
	}

	enginemath divide_scalar(enginemath const &a, float const &d)
	{

		return enginemath(a.x / d, a.y / d, a.z / d);

	}
	enginemath dot_product(enginemath const &a, enginemath const &b)
	{

		return enginemath(a.x*b.x, a.y*b.y, a.z*b.z);

	}
	enginemath cross_product(enginemath const &a, enginemath const &b)
	{

		return enginemath(a.y*b.z - b.y*a.z,a.z*b.x - a.x*b.z,a.x*b.y - b.x*a.y);


	}
	enginemath normalise(enginemath const &a)
	{
		float mag = a.x*a.x + a.y*a.y + a.z*a.z;
		mag = sqrt(mag);
		if (mag > 0.0f)

		{
			float norm = 1.0f / mag;
			return enginemath(a.x*norm, a.y*norm, a.z*norm);
		}
		else
		{
			return enginemath(0.0f, 0.0f, 0.0f);
		}
	}

	float enginemath::magnitude(enginemath const &a)
	{
		float y = sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
		return y;
	}
	enginemath conjugate(enginemath const &a)
	{

		return enginemath(a.x*(-1.0f), a.y*(-1.0f), a.z*(-1.0f));

	}
	enginemath absolute(enginemath const &a)
	{

		return enginemath(std::abs(a.x),std::abs(a.y),std::abs(a.z));

	}


}
















#endif
