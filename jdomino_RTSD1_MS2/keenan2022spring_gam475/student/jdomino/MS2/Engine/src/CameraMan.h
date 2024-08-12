#ifndef CAMERA_MAN_H
#define CAMERA_MAN_H

#include "Camera.h"

	class CameraMan
	{
		//Camera Manager's job:
			//Handle creation of cameras
			//Each camera is a new instance of camera
			//On button press, swap camera to the chosen camera
			//If camera does not exist with that button (#1-#3)
				//Make a new camera and set it to that number at default pos
			//Need to destroy cameras as well
				//after destroying, if button is pressed, create a new camera at default pos

	//enum CamChoice
	//{
	//	Cam1,
	//	Cam2,
	//	Cam3,
	//	Cam4,
	//	Unitialized
	//};

	public:
		static void Create();
		static void Destroy();
		static Azul::Camera* SetCamera(int camSelection);
		static Azul::Camera* RemoveCamera(Azul::Camera* currCam);
		static bool CameraExists(int camSelection);

	private:
		static CameraMan* privGetInstance();

		~CameraMan();
		CameraMan();

		Azul::Camera* activeCam = nullptr;
		Azul::Camera* cam1 = nullptr;
		Azul::Camera* cam2 = nullptr;
		Azul::Camera* cam3 = nullptr;
		Azul::Camera* cam4 = nullptr;
		Azul::Camera* cam5 = nullptr;
		static CameraMan* posInstance;

	};
#endif