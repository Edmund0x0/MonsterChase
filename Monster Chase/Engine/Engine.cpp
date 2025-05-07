#include "Engine.h"
#include <thread>

Engine::Engine()
{

}

Engine::~Engine()
{

}

bool Engine::Initialize()
{
	return true;
}

bool QuitRequested()
{
	return false;
}

void Engine::Run(std::vector<std::shared_ptr<GameObject>> io_Objects)
{
	bool bQuit = false;

	while (!bQuit)
	{
		GLib::Service(bQuit);

		float dt = Timing::CalcLastFrameTime();

		// Check for user input here
		for (auto& io_Object : io_Objects)
		{
			Input::CheckForInput(io_Object);
		}
		
		// Exit the Game if Requested
		if (bQuit)
		{
			break;
		}

		// Update Game "State"
		for (auto& io_Object : io_Objects)
		{
			Physics::Update(io_Object, dt, io_Objects);
		}
		
		Renderer::Run(io_Objects);		
	}

	// Release sprites
	for (auto& io_Object : io_Objects)
	{
		if (io_Object->pGoodGuy)
		{
			Renderer::releaseSprite(io_Object->pGoodGuy);
		}
	}

	// IMPORTANT:  Tell GLib to shutdown, releasing resources.
	GLib::Shutdown();
}


std::shared_ptr<GameObject> Engine::CreateActor(const char* i_pScriptFilename)
{
	// Read from Json and create object
	json gameData;

	std::ifstream file(i_pScriptFilename);
	file >> gameData;
	
	std::string spriteToRender = gameData["components"]["renderable"]["sprite_texture_source"];
	float setHeight = gameData["components"]["size"]["height"];
	float setWidth = gameData["components"]["size"]["width"];
	float xPosition = gameData["components"]["position"]["xPos"];
	float yPosition = gameData["components"]["position"]["yPos"];
	float mass = gameData["components"]["moveable"]["mass"];
	float force = gameData["components"]["moveable"]["force"];
	bool isPlayerOne = gameData["components"]["moveable"]["playerone"];
	bool isPlayerTwo = gameData["components"]["moveable"]["playertwo"];
	bool isBall = gameData["components"]["moveable"]["ball"];
	bool isUpperWall = gameData["components"]["moveable"]["upperwall"];
	bool isBottomWall = gameData["components"]["moveable"]["bottomwall"];
	float setXVel = gameData["components"]["moveable"]["velocityX"];
	float setYVel = gameData["components"]["moveable"]["velocityY"];
	float getNormalX = gameData["components"]["position"]["normalX"];
	float getNormalY = gameData["components"]["position"]["normalY"];

	Vector2 _center = Vector2(0, (setHeight / 2));
	Vector2 _extents = Vector2((setWidth / 2), (setHeight / 2));
	Vector2 _setNormal = Vector2(getNormalX, getNormalY);


	std::shared_ptr<GameObject> gameActor = std::make_shared<GameObject>();

	gameActor->spriteFile = _strdup(spriteToRender.c_str());
	gameActor->playerOne = isPlayerOne;
	gameActor->playerTwo = isPlayerTwo;
	gameActor->ball = isBall;
	gameActor->bottomWall = isBottomWall;
	gameActor->upperWall = isUpperWall;
	gameActor->height = setHeight;
	gameActor->width = setWidth;
	gameActor->normalDeezNuts = _setNormal;
	gameActor->velocityX = setXVel;
	gameActor->velocityY = setYVel;
	gameActor->m_AABB = std::make_unique<AABB>(AABB(_center, _extents));
	gameActor->positionX = xPosition;
	gameActor->positionY = yPosition;
	gameActor->m_Position.x(xPosition);
	gameActor->m_Position.y(yPosition);
	gameActor->mass = mass;
	gameActor->force = force;

	return gameActor;

}