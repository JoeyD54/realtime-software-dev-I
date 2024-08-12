#include "Camera.h"
#include "CameraMan.h"

	CameraMan* CameraMan::posInstance = nullptr;

	CameraMan::CameraMan()
	{
		// initialize derived data here
		//this->cam1 = new Azul::Camera();
		//this->activeCam = this->cam1;
	}

	CameraMan::~CameraMan()
	{
		//Delete every camera inside manager
		//delete this->activeCam;

		if (this->cam1)
		{
			delete this->cam1;
		}
		if (this->cam2)
		{
			delete this->cam2;
		}
		if (this->cam3)
		{
			delete this->cam3;
		}
		if (this->cam4)
		{
			delete this->cam4;
		}
		if (this->cam5)
		{
			delete this->cam5;
		}

	}

	void CameraMan::Create()
	{
		// initialize the singleton here
		assert(posInstance == nullptr);

		// Do the initialization
		posInstance = new CameraMan();	
	}

	void CameraMan::Destroy()
	{		
		//Calls destructor
		delete CameraMan::posInstance;

		CameraMan::posInstance = nullptr;
	}

	Azul::Camera* CameraMan::SetCamera(int camSelection)
	{
		CameraMan* pCamMan = privGetInstance();

		switch (camSelection)
		{
		case 1:
			if (pCamMan->cam1 == nullptr)
			{
				pCamMan->cam1 = new Azul::Camera();
			}

			pCamMan->activeCam = pCamMan->cam1;

			break;
		case 2:
			if (pCamMan->cam2 == nullptr)
			{
				pCamMan->cam2 = new Azul::Camera();
			}

			pCamMan->activeCam = pCamMan->cam2;

			break;
		case 3:
			if (pCamMan->cam3 == nullptr)
			{
				pCamMan->cam3 = new Azul::Camera();
			}

			pCamMan->activeCam = pCamMan->cam3;

			break;
		case 4:
			if (pCamMan->cam4 == nullptr)
			{
				pCamMan->cam4 = new Azul::Camera();
			}

			pCamMan->activeCam = pCamMan->cam4;

			break;
		case 5:
			if (pCamMan->cam5 == nullptr)
			{
				pCamMan->cam5 = new Azul::Camera();
			}

			pCamMan->activeCam = pCamMan->cam5;

			break;
		default:
			break;
		}
		
		return pCamMan->activeCam;
	}

	Azul::Camera* CameraMan::RemoveCamera(Azul::Camera* currCam)
	{
		CameraMan* pCamMan = privGetInstance();


		int camSelected = 0;

		if (currCam == pCamMan->cam1)
		{
			camSelected = 1;
		}
		else if (currCam == pCamMan->cam2)
		{
			camSelected = 2;
		}
		else if (currCam == pCamMan->cam3)
		{
			camSelected = 3;
		}
		else if (currCam == pCamMan->cam4)
		{
			camSelected = 4;
		}
		else if (currCam == pCamMan->cam5)
		{
			camSelected = 5;
		}

		Trace::out("Camera To Delete: %d \n", camSelected);

		switch (camSelected)
		{
		case 1:
			if (pCamMan->CameraExists(1))
			{
				if (pCamMan->CameraExists(2))
				{
					pCamMan->activeCam = pCamMan->cam2;
					delete pCamMan->cam1;
					pCamMan->cam1 = nullptr;
				}
				else if (pCamMan->CameraExists(3))
				{
					pCamMan->activeCam = pCamMan->cam3;
					delete pCamMan->cam1;
					pCamMan->cam1 = nullptr;
				}
				else if (pCamMan->CameraExists(4))
				{
					pCamMan->activeCam = pCamMan->cam4;
					delete pCamMan->cam1;
					pCamMan->cam1 = nullptr;
				}
				else if (pCamMan->CameraExists(5))
				{
					pCamMan->activeCam = pCamMan->cam5;
					delete pCamMan->cam1;
					pCamMan->cam1 = nullptr;
				}
			}
			break;
		case 2:
			if (pCamMan->CameraExists(2))
			{
				if (pCamMan->CameraExists(3))
				{
					pCamMan->activeCam = pCamMan->cam3;
					delete pCamMan->cam2;
					pCamMan->cam2 = nullptr;
				}
				else if (pCamMan->CameraExists(4))
				{
					pCamMan->activeCam = pCamMan->cam4;
					delete pCamMan->cam2;
					pCamMan->cam2 = nullptr;
				}
				else if (pCamMan->CameraExists(5))
				{
					pCamMan->activeCam = pCamMan->cam5;
					delete pCamMan->cam2;
					pCamMan->cam2 = nullptr;
				}
				else if (pCamMan->CameraExists(1))
				{
					pCamMan->activeCam = pCamMan->cam1;
					delete pCamMan->cam2;
					pCamMan->cam2 = nullptr;
				}
			}
			break;
		case 3:
			if (pCamMan->CameraExists(3))
			{
				if (pCamMan->CameraExists(4))
				{
					pCamMan->activeCam = pCamMan->cam4;
					delete pCamMan->cam3;
					pCamMan->cam3 = nullptr;
				}
				else if (pCamMan->CameraExists(5))
				{
					pCamMan->activeCam = pCamMan->cam5;
					delete pCamMan->cam3;
					pCamMan->cam3 = nullptr;
				}
				else if (pCamMan->CameraExists(1))
				{
					pCamMan->activeCam = pCamMan->cam1;
					delete pCamMan->cam3;
					pCamMan->cam3 = nullptr;
				}
				else if (pCamMan->CameraExists(2))
				{
					pCamMan->activeCam = pCamMan->cam2;
					delete pCamMan->cam3;
					pCamMan->cam3 = nullptr;
				}
			}
			break;
		case 4:
			if (pCamMan->CameraExists(4))
			{
				if (pCamMan->CameraExists(5))
				{
					pCamMan->activeCam = pCamMan->cam5;
					delete pCamMan->cam4;
					pCamMan->cam4 = nullptr;
				}
				else if (pCamMan->CameraExists(1))
				{
					pCamMan->activeCam = pCamMan->cam1;
					delete pCamMan->cam4;
					pCamMan->cam4 = nullptr;
				}
				else if (pCamMan->CameraExists(2))
				{
					pCamMan->activeCam = pCamMan->cam2;
					delete pCamMan->cam4;
					pCamMan->cam4 = nullptr;
				}
				else if (pCamMan->CameraExists(3))
				{
					pCamMan->activeCam = pCamMan->cam3;
					delete pCamMan->cam4;
					pCamMan->cam4 = nullptr;
				}
			}
			break;
		case 5:
			if (pCamMan->CameraExists(5))
			{
				if (pCamMan->CameraExists(1))
				{
					pCamMan->activeCam = pCamMan->cam1;
					delete pCamMan->cam5;
					pCamMan->cam5 = nullptr;
				}
				else if (pCamMan->CameraExists(2))
				{
					pCamMan->activeCam = pCamMan->cam2;
					delete pCamMan->cam5;
					pCamMan->cam5 = nullptr;
				}
				else if (pCamMan->CameraExists(3))
				{
					pCamMan->activeCam = pCamMan->cam3;
					delete pCamMan->cam5;
					pCamMan->cam5 = nullptr;
				}
				else if (pCamMan->CameraExists(4))
				{
					pCamMan->activeCam = pCamMan->cam4;
					delete pCamMan->cam5;
					pCamMan->cam5 = nullptr;
				}
			}
			break;
		default:
			break;
		}

		return pCamMan->activeCam;
		
	}

	bool CameraMan::CameraExists(int camSelection)
	{
		CameraMan* pCamMan = privGetInstance();

		bool result = false;

		switch (camSelection)
		{
		case 1:
			if (pCamMan->cam1 != nullptr)
			{
				result = true;
			}
			break;
		case 2:
			if (pCamMan->cam2 != nullptr)
			{
				result = true;
			}
			break;
		case 3:
			if (pCamMan->cam3 != nullptr)
			{
				result = true;
			}
			break;
		case 4:
			if (pCamMan->cam4 != nullptr)
			{
				result = true;
			}
			break;
		case 5:
			if (pCamMan->cam5 != nullptr)
			{
				result = true;
			}
			break;
		default:
			break;
		}

		return result;
	}

	CameraMan* CameraMan::privGetInstance()
	{
		assert(CameraMan::posInstance);
		return posInstance;
	}

	