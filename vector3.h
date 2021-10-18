#ifndef _VECTOR3_
#define _VECTOR3_

#include <iostream>

class Vector3{
	public:
		float x, y, z;
		Vector3(float _x, float _y, float _z);
		Vector3();
		~Vector3();
		friend std::ostream& operator<<(std::ostream& os,const Vector3& a);
		Vector3 operator*(float scale)const;
		float dot(const Vector3& a)const;
		Vector3 cross(const Vector3& a)const;
		Vector3 direction(const Vector3 & a)const;
		Vector3 operator-(const Vector3& a)const;
		Vector3 operator+(const Vector3& a)const;
		Vector3 normalize()const;
		float distance(const Vector3& a)const;
		float norm()const;


};



//std::ostream& operator<<(std::ostream& os,const Vector3& a){
//	os<<"vector 3 x:"<<a.x<<" y: "<<a.y<<" z: "<<a.z;
//}


#endif
