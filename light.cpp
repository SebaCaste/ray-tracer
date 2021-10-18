#include "light.h"

Light::Light(float _x,float _y,float _z,
				float _direction_x,float _direction_y,float _direction_z,
				float _power_r,float _power_g,float _power_b):position(Vector3(_x,_y,_z)),
																		direction(Vector3(_direction_x,_direction_y,_direction_z)),
																		power(Vector3(_power_r,_power_g,_power_b)){
}
//Light::Light(std::vector<Object> _objects){
//	objects=_objects;
//
//}

Light::~Light(){
}
void Light::at(Vector3 & position,Vector3 & direction,Vector3 & power){
	
}

std::ostream& operator<<(std::ostream& os,const Light& a){
//	os<<"ray origin:"<<a.origin<<" direction: "<<a.direction;
}

