#ifndef _CAMERA_
#define _CAMERA_

#include <vector>
#include <iostream>
#include "vector3.h"
#include "object.h"


class Camera{
	public:
		Vector3 position;
		Vector3 X;
		Vector3 Y;
		float focalLenght;
		Vector3 targetposition_position;
		Vector3 targetposition_direction;
		float height;
		float width;
		float sensor_size_x;//1 x pixel, 2 y pixel , 3 ratio
		float sensor_size_y;
		Vector3 up;
		std::vector<Object*> objects;
		Camera(float _x,float _y,float _z,
				float _focalLenght,
				float _targetposition_x,float _targetposition_y,float _targetposition_z,
				Vector3 _up,
				float _sensor_size_x,
				float _width);
		Camera();
		~Camera();
		Ray pixelToRay(int pixelX,int pixelY) const;
		void objectCreation (Object());
		friend std::ostream& operator<<(std::ostream& os,const Camera& a);
};


#endif
