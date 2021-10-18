#ifndef _OBJECT_
#define _OBJECT_

#include <iostream>
#include "ray.h"
#include "vector3.h"
#include "materialparameters.h"
#include "intercept.h"



class Object{
	public:
		unsigned int radius;
		Vector3 position;
		MaterialParameters parameters;
		Object(unsigned int _radius,float _x,float _y,float _z,float _r,float _g,float _b,float _opacity);
		~Object();
		Intercept intersect (const Ray& ray)const;
		

		friend std::ostream& operator<<(std::ostream& os,const Object& a);
};


#endif
