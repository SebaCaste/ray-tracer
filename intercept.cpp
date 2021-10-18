#include "intercept.h"

Intercept::Intercept(float _x,float _y,float _z,
					float _direction_x,float _direction_y,float _direction_z,
					MaterialParameters _parameters):position(Vector3(_x,_y,_z)),direction(Vector3(_direction_x,_direction_y,_direction_z)),parameters(_parameters){
detect=true;						
}
//Light::Light(std::vector<Object> _objects){
//	objects=_objects;
//
//}
Intercept::Intercept(){
	detect=false;
}
Intercept::Intercept(const Intercept& other){
	detect=true;
	this->position=other.position;
	this->direction=other.direction;
	this->parameters=other.parameters;
}
Intercept::~Intercept(){
}
//
std::ostream& operator<<(std::ostream& os,const Intercept& a){
	os<<"ray position:"<<a.position<<" direction: "<<a.direction;
}

