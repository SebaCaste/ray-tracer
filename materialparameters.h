#ifndef _MATERIALPARAMETERS_
#define _MATERIALPARAMETERS_

#include <iostream>
#include <vector>
#include "vector3.h"

class MaterialParameters{
	public:
		float opacity;
		Vector3 colour;
		MaterialParameters();
		MaterialParameters(const MaterialParameters& _parameters);
		MaterialParameters(float _opacity,float _colour_r,float _colour_g,float _colour_b);
		~MaterialParameters();
//		void objectCreation (Object())
		friend std::ostream& operator<<(std::ostream& os,const MaterialParameters& a);
};


#endif
