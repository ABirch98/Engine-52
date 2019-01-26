//Engine52 V1.08 Instance Handler 
//main.cpp Simply calls the run function for world and cleans up after itself 
//HAPI(c) Keith Ditchburn 2018
//Engine52 (c) 
#if defined(DEBUG) | defined(_DEBUG) //while using debug checks for memory leaks upon program close 
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK,__FILE__, __LINE__)
#endif
#include"world.h"

void HAPI_Main()
{
	//World class is created as singleton so no need for new instance to be created it calls its own function 
	WORLD.Run();
	WORLD.DeleteInstance();
}
