#include "vector3.h"
#include <math.h>

Vector3::Vector3(float _x, float _y, float _z){
	x=_x;
	y=_y;
	z=_z;
}
Vector3::Vector3(){
	x=0;
	y=0;
	z=0;
}
Vector3::~Vector3(){
}
std::ostream& operator<<(std::ostream& os,const Vector3& a){
	os<<"vector 3 x:"<<a.x<<" y: "<<a.y<<" z: "<<a.z<<std::endl;
}

Vector3 Vector3::operator * (const float scale) const{
         return Vector3(x*scale,y*scale,z*scale);
     }
     
Vector3 Vector3::operator + (const Vector3& a) const{
        Vector3 temp;
        temp.x = x + a.x;
		temp.y = y + a.y; 
        temp.z = z + a.z; 
        return temp;
     }
Vector3 Vector3::operator - (const Vector3& a) const{
        Vector3 temp;
        temp.x = x - a.x;
		temp.y = y - a.y; 
        temp.z = z - a.z; 
        return temp;
    }
float Vector3::dot(const Vector3& a)const{
	return x*a.x+y*a.y+z*a.z;
}
Vector3 Vector3::cross(const Vector3& a)const{
	return Vector3(this->y*a.z-this->z*a.y,-(this->x*a.z+this->z*a.x),this->x*a.y-this->y*a.x);
}
Vector3 Vector3::direction(const Vector3 & a)const{
	return Vector3(this->x-a.x,this->y-a.y,this->z-a.z);
}
Vector3 Vector3::normalize()const{
	float lenght= sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
	return Vector3(this->x/lenght,this->y/lenght,this->z/lenght);
}

float Vector3::distance(const Vector3& a)const{
return sqrt(pow(a.x-this->x,2)+pow(a.y-this->y,2)+pow(a.z-this->z,2));
}

float Vector3::norm()const{
	return sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
}



