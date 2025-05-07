// By Roberto Reynoso

#include "Engine.h"
#include "GameObject.h"
#include "GLib.h"
#include <memory>

using namespace std;

int WINAPI wWinMain(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow)
{
	Engine::Initialize();

	// IMPORTANT: first we need to initialize GLib
	bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "GawrGuraPong", -1, 800, 600, true);
	bool goodToGo = false;

	if (bSuccess)
	{
		std::shared_ptr<GameObject> backGround = Engine::CreateActor("data\\BackGround.json");
		std::shared_ptr<GameObject> playerOne = Engine::CreateActor("data\\Player.json");
		std::shared_ptr<GameObject> playerTwo = Engine::CreateActor("data\\PlayerTwo.json");
		std::shared_ptr<GameObject> ball = Engine::CreateActor("data\\Ball.json");
		std::shared_ptr<GameObject> upperWall = Engine::CreateActor("data\\UpperWall.json");
		std::shared_ptr<GameObject> bottomWall = Engine::CreateActor("data\\BottomWall.json");

		std::vector<std::shared_ptr<GameObject>> io_Objects;
		io_Objects.push_back(backGround);
		io_Objects.push_back(playerOne);
		io_Objects.push_back(playerTwo);
		io_Objects.push_back(ball);
		io_Objects.push_back(upperWall);
		io_Objects.push_back(bottomWall);

		for (auto& io_Object : io_Objects)
		{
			if (io_Object)
			{
				goodToGo = true;
			}
			else
			{
				goodToGo = false;
			}
		}

		if (goodToGo)
		{
			Engine::Run(io_Objects);
		}
	}
	

#if defined _DEBUG
	_CrtDumpMemoryLeaks();
#endif // _DEBUG
}

/*Point2D *point2D = new Point2D;

cout << point2D->x();*/



