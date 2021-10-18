#include "materialparameters.h"

MaterialParameters::MaterialParameters(float _opacity,
										float _colour_r,float _colour_g,float _colour_b):opacity(_opacity),
																							colour(Vector3(_colour_r, _colour_g, _colour_b)){
}
//Light::Light(std::vector<Object> _objects){
//	objects=_objects;
//
//}
MaterialParameters::MaterialParameters(const MaterialParameters& _parameters):opacity(_parameters.opacity),colour(_parameters.colour){
	
}
MaterialParameters::~MaterialParameters(){
}

MaterialParameters::MaterialParameters(){
}
std::ostream& operator<<(std::ostream& os,const MaterialParameters& a){
//	os<<"ray origin:"<<a.origin<<" direction: "<<a.direction;
}

