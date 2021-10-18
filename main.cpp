#include <fstream>
#include <vector>
#include <iostream>
#include <windows.h>

#include "vector3.h"
#include "image.h"
#include "scene.h"
#include "camera.h"
#include "light.h"


//using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char** argv) {
//	Vector3 PrimoVettore (67,77,85);
//	Vector3 SecondoVettore (57,37,86);
//	std::cout<<PrimoVettore;
//	std::cout<<PrimoVettore+SecondoVettore;
	Camera camera(0,0,0,
				0.036,
				0,1,1,
				Vector3(0,0,1),
				0.036,
				1350);
	Image a(camera.width,camera.height,&camera);
	Object o1(1,
				0,5,5,
				255,255,255,
				1);
	Object o2(1,
				1,3,3,
				255,255,255,
				1);
	Light l1(0,3,3,
				1,3,3,
				255,255,255);
	std::vector<Object> vec;
	std::vector<Light> lig;
	
	vec.push_back(o1);
	vec.push_back(o2);
	lig.push_back(l1);
	Scene scena(vec,lig);
	a.render(scena);

	a.write("ima");
	
#include <iostream>
#include <windows.h>


    ShellExecute(NULL, "open", "C:\\Users\\sebac\\Desktop\\uni\\Sorbonne1annoMaster\\secondo semestre\\ig3d\\lab\\primolab\\image.ppm", NULL, NULL, SW_SHOWDEFAULT);

	return 0;
}
