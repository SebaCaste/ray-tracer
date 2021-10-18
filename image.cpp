#include "Image.h"
#include <fstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include "object.h"
#include "intercept.h"


Image::Image( int _width,  int _height,Camera* _camera):width(_width),height(_height),camera(_camera){
	myImage.resize(width*height);
	for(int i=0;i<width*height;i++){
		myImage[i].x=0;	
		myImage[i].y=0;
		myImage[i].z=0;
	}
	
}
Image::~Image(){
}
std::ostream& operator<<(std::ostream& os,const Image& a){
	os<<"image width:"<<a.width<<" height: "<<a.height;
}

bool Image::write(const std::string& filename) const{
//	std::string file(filename+".ppm");
	std::ofstream ofs;
	unsigned char * temp = new unsigned char[3];
	ofs.open("image.ppm", std::ios_base::out | std::ios_base::binary);
    ofs << "P3" << std::endl << width << ' ' << height << std::endl << "255" << std::endl;
 
    for (int j = 0; j < height; ++j){
        for (int i = 0; i < width; ++i){
        	//passa posizione pixel crea raggio che con posizione camera torna se hitta un oggetto
			ofs <<	myImage[j*width+i].x <<' ';
			ofs <<	myImage[j*width+i].y <<' ';//SEBA
			ofs <<	myImage[j*width+i].z <<' ';//SEBA
		}
	}
    ofs.close();
    return true;
}
void Image::render(const Scene& scene){
	
	for(int i=0;i<this->height;i++){
		for(int j=0;j<this->width;j++){
			std::vector<Object>::const_iterator iter;
			float detection(-1);
		    for (iter = scene.objects.begin(); iter != scene.objects.end(); ++iter){// DENCTION OF OBJECT WITH RAY FROM CAMERA PIXEL 
//				if(i==height-1 && j==width-1){
////					std::cout<<"pixel to ray :"<<camera->pixelToRay(j,i);	
//					}
//				std::cout<<"qui ci arrivo";
				
//				if(i==0 && j==0){
////					std::cout<<"pixel to ray :"<<camera->pixelToRay(j,i);	
//					}
				Intercept temp=iter->intersect(camera->pixelToRay(j,i));//OBJECT DETECT WITH ATTRIBUTES
				float incident_light=0;
//				std::cout<<"qui ci arrivo";
				if(temp.detect && (temp.position.distance(this->camera->position)<detection || detection==-1)){// IF NOT INTERFIRENCE AND DETECTION TRUE
//						std::cout<<"qui ci arrivo";
						detection=temp.position.distance(this->camera->position);//SET THE MINUMUN DISTANCE 
						std::vector<Light>::const_iterator iter_light;
					    for (iter_light = scene.lights.begin(); iter_light != scene.lights.end(); ++iter_light){//DETECT EVERY LIGHT
					    	float distance_light(temp.position.distance(iter_light->position));//DISTANCE OF THE CURRENT LIGHT
					    	std::vector<Object>::const_iterator iter_obj2;
					    	bool direct_shadow=false; 
					   		 for (iter_obj2 = scene.objects.begin(); iter_obj2 != scene.objects.end(); ++iter_obj2){//DETECT IF OTHER OBJECT IS BETWEEN THE CURRENT OBJECT AND THE CURRENT LIGHT
					   		 	if(iter_obj2!=iter){//NOT CONSIDER THE CURRENT OBJECT
					   		 			Intercept current_object=iter_obj2->intersect(Ray(temp.position,temp.position.direction(iter_light->position)));//OBJECT ANALIZE IF IT IS IN BETWEEN
					   		 		if(current_object.detect && current_object.position.distance(iter_light->position)<distance_light){
					   		 			direct_shadow=true;//IT IS IN BETWEEN
					   		 			
					   		 			break;
										}
					   		 		
									}
								}
								if(!direct_shadow){//THE OBJECT DETECT HAS DIRECT LIGHT
									if(temp.position.distance(iter_light->position)<sqrt(pow(iter->position.distance(iter_light->position),2)+pow((iter->radius),2))){
										incident_light=temp.position.direction(iter_light->position).dot(temp.direction)/((
										temp.position.direction(iter_light->position).norm())*
										temp.direction.norm());
									}else{
										incident_light=0;
									}
									myImage[i*width+j].x=int(temp.parameters.colour.x*incident_light);
//									std::cout<<std::abs(incident_light)<<"  --  "<<temp.parameters.colour.x<<"--тт--";
									myImage[i*width+j].y=int(temp.parameters.colour.y*incident_light);
									myImage[i*width+j].z=int(temp.parameters.colour.z*incident_light);

									
								}
								
						}

				}
			}			
		}
	}
}
