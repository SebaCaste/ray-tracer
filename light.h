#ifndef _LIGHT_
#define _LIGHT_

#include <iostream>
#include <vector>
#include "vector3.h"

class Light{
	public:
		Vector3 position;
		Vector3 direction;
		Vector3 power;
//		Light();
		Light(float _x,float _y,float _z,float _direction_x,float _direction_y,float _direction_z,float _power_r,float _power_g,float _power_b);
		~Light();
//		void objectCreation (Object())
		friend std::ostream& operator<<(std::ostream& os,const Light& a);
		void at(Vector3 & position,Vector3 & direction,Vector3 & power);
};


#endif
