#include "camera.h"

Camera::Camera(float _x,float _y,float _z,
				float _focalLenght,
				float _targetposition_x,float _targetposition_y,float _targetposition_z,
				Vector3 _up,
				float _sensor_size_x,
				float _width):position(Vector3(_x,_y,_z)),
											focalLenght(_focalLenght),
											targetposition_position(_targetposition_x,_targetposition_y,_targetposition_z),
											up(_up),
											sensor_size_x(_sensor_size_x),sensor_size_y(_sensor_size_x*2/3),
											width(_width),height(_width*2/3){
targetposition_direction=this->targetposition_position.direction(this->position).normalize();
X=this->targetposition_direction.cross(this->up).normalize();
Y=this->X.cross(this->targetposition_direction).normalize();
std::cout<<"X: "<<X<<"Y:"<<Y<<"Z:"<<targetposition_direction<<"up:"<<up;
}
Camera::Camera(){
	position.x=0;position.y=0;position.z=0;
}
Camera::~Camera(){
}
Ray Camera::pixelToRay(int pixelX,int pixelY) const{

	return Ray(position,
			(this->targetposition_direction*(-this->focalLenght))+
					this->Y*((pixelY/(this->height-1))*this->sensor_size_y-(this->sensor_size_y/2))+
					this->X*((pixelX/(this->width-1))*this->sensor_size_x-(this->sensor_size_x/2)));
}
std::ostream& operator<<(std::ostream& os,const Camera& a){
//	os<<"ray origin:"<<a.origin<<" direction: "<<a.direction;
}
