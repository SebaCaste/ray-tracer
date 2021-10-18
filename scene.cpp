#include "scene.h"

Scene::Scene(){
}
Scene::Scene(std::vector<Object> _objects,std::vector<Light> _lights){
	objects=_objects;
	lights=_lights;

}

Scene::~Scene(){
}
std::ostream& operator<<(std::ostream& os,const Scene& a){
//	os<<"ray origin:"<<a.origin<<" direction: "<<a.direction;
}

