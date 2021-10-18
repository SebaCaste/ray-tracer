#include "ray.h"
#include "vector3.h"

Ray::Ray(Vector3 _origin, Vector3 _direction):origin(_origin),direction(_direction){
	
}
Ray::~Ray(){
}
std::ostream& operator<<(std::ostream& os,const Ray& a){
	os<<"ray origin:"<<a.origin<<" direction: "<<a.direction;
}
