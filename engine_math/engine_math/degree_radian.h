#ifndef degree_radian_h
#define degree_radian_h
#define USE_MATH_DEFINES
# define M_PI  3.14159265358979323846
#include<cmath>
#include<math.h>
using namespace std;

namespace degree {

	class radian {
	protected:
		float uangle;

	public:
		
		inline float set_value(float x)
		{
			uangle = x;

			return uangle;
		}

		inline float degree_to_radian(float const &);
		inline float radian_to_degree(float const &);
		inline float sin_theta(float const &);
		inline float cos_theta(float const &);
		//inline float conversion(radian const &);
		

	};

float radian::degree_to_radian(float const &a)
	{

		float b = a * (M_PI / 180);
		return b;
}

	float radian::radian_to_degree(float const &b)
	{
		
		float a = b * (180 / M_PI);
		return a;
	}

	float radian::sin_theta(float const &a)
	 {
		 return sin(a);
	 }
	float  radian::cos_theta(float const &b)
	 {
		 return cos(b);
	 }

}












#endif