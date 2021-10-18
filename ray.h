#ifndef _RAY_
#define _RAY_

#include <iostream>
#include "vector3.h"

class Ray{
	public:
		const Vector3 origin, direction;
		Ray(Vector3 o, Vector3 d);
		~Ray();
		friend std::ostream& operator<<(std::ostream& os,const Ray& a);
};


#endif
