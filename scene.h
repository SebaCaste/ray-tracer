#ifndef _SCENE_
#define _SCENE_

#include <iostream>
#include <vector>
#include "object.h"
#include "light.h"

class Scene{
	public:
		std::vector<Object> objects;
		std::vector<Light> lights;
		Scene();
		Scene(std::vector<Object> _objects,std::vector<Light> _lights);
		~Scene();
//		void objectCreation (Object())
		friend std::ostream& operator<<(std::ostream& os,const Scene& a);
};


#endif
