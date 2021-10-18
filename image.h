#ifndef _IMAGE_
#define _IMAGE_


#include <iostream>
#include <vector>
#include <string>
#include "camera.h"
#include "scene.h"

class Image{
	public:
		int width, height;
		Camera *camera;
		std::vector<Vector3> myImage; 
		Image(const int _width,const int _height,Camera* _camera);
		~Image();
		friend std::ostream& operator<<(std::ostream& os,const Image& a);
		bool write(const std::string& filename) const;
		void render(const Scene& scene);
};



#endif
