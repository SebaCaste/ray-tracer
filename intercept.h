#ifndef _INTERCEPT_
#define _INTERCEPT_

#include <iostream>
#include <vector>
#include "vector3.h"
#include "materialparameters.h"

class Intercept{
	public:
		bool detect;
		Vector3 position;
		Vector3 direction;
		MaterialParameters parameters;
		Intercept();
		Intercept(const Intercept& other);
		Intercept(float _x,float _y,float _z,
					float _direction_x,float _direction_y,float _direction_z,
					MaterialParameters _parameters);
		~Intercept();
//		void objectCreation (Object())
		friend std::ostream& operator<<(std::ostream& os,const Intercept& a);
};


#endif
