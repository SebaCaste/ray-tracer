#include "object.h"
#include "vector3.h"
#include <math.h> 

Object::Object(unsigned int _radius,
				float _x,float _y,float _z,
				float _r,float _g,float _b,float _opacity):position(_x,_y,_z),
												radius(_radius),parameters(_opacity,_r,_g,_b){
}
Object::~Object(){
}
Intercept Object::intersect (const Ray& ray)const{	
	float d=-ray.direction.dot(position);
	float t=-(ray.direction.dot(ray.origin)+d)/(pow(ray.direction.x,2)+pow(ray.direction.y,2)+pow(ray.direction.z,2));
	float dx=ray.origin.x+ray.direction.x*t;
	float dy=ray.origin.y+ray.direction.y*t;
	float dz=ray.origin.z+ray.direction.z*t;
	float distance=pow(dx-position.x,2)+pow(dy-position.y,2)+pow(dz-position.z,2);
	if(distance<=pow(this->radius,2)){
		Intercept temp =Intercept(dx,dy,dz,dx-this->position.x,dy-this->position.y,dz-this->position.z,this->parameters);
		return temp;
	}
	else{
		return Intercept();
	}
}

std::ostream& operator<<(std::ostream& os,const Object& a){
//	os<<"ray origin:"<<a.origin<<" direction: "<<a.direction;
}


