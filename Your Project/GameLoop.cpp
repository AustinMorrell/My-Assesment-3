#include "GameLoop.h"
#include <Vector3.h>
#include <Vector2.h>

Vector2<int> CircleVecter(500, 450);
Vector2<int> CircleVecter2(1100, 450);

void GameLoop::Loop()
{
	SDL_Event sdlEvent; // Will hold the next event to be parsed

	while (m_bRunning)
	{
		// Events get called one at a time, so if multiple things happen in one frame, they get parsed individually through 'SDL_PollEvent'
		// The next event to parse gets stored into 'sdlEvent', and then passed to the 'EventHandler' class which will call it's appropriate function here
		// 'SDL_PollEvent' returns 0 when there are no more events to parse
		while (SDL_PollEvent(&sdlEvent))
		{
			// Calls the redefined event function for the EventHandler class
			// Refer to its header file and cpp for more information on what each inherited function is capable of
			// and its syntax
			OnEvent(sdlEvent);
		}
		GetDeltaTime();

		Update();

		LateUpdate();

		Draw();

		Graphics::Flip(); // Required to update the window with all the newly drawn content
	}

}

void GameLoop::Update()
{
	color1++*DeltaTime;
	if (color1 == 200)
	{
		color2--*DeltaTime;
	}
		color3++*DeltaTime;
		bool theSwitch = 1;
		size++*DeltaTime;
		switch (theSwitch)
		{
		case 1:
			size++*DeltaTime;
			if (size >= 500)
			{
				theSwitch = 0;
			}
			break;

		case 0:
			size--*DeltaTime;
			if (size <= 0)
			{
				theSwitch = 1;
			}
			break;
			
		default:
			break;
		}
}

void GameLoop::GetDeltaTime()
{
	int now = SDL_GetTicks();
	DeltaTime = ((float)(now - last)) / 1000;
	last = now;
}

void GameLoop::LateUpdate()
{

}

void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas

	//Graphics::DrawRect({ 400, 400 }, { 450, 400 }, { 160, 65, 255, 255 });
	//Graphics::DrawRect({ 250, 500 }, { 1000, 200 }, { 0, 255, 0, 255 });

	//Graphics::DrawLine({ 10, 10 }, { 100, 100 }, { 255, 255, 255, 255 });
	//Graphics::DrawPoint({ 5, 5 }, { 255, 255, 255, 255 });
	
	cout << DeltaTime << endl;

	Graphics::DrawRing({ CircleVecter.x, CircleVecter.y }, size, sides, { 50, 0, 200, 255 });
	Graphics::DrawCircle({ CircleVecter.x, CircleVecter.y }, size, sides, { 0, color1, color2, color3 });

	Graphics::DrawCircle({ CircleVecter2.x, CircleVecter2.y }, size, sides, { 0, color1, color2, color3 });
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
//------------------------------------------------
	switch (ac_sdlSym)
	{
	case SDLK_a:
		CircleVecter.x -= 10;
		if (CircleVecter.x <= 0)
		{
			CircleVecter.x += 10;
		}
		break;

	case SDLK_s:
		CircleVecter.y += 10;
		if (CircleVecter.y >= 800)
		{
			CircleVecter.y -= 10;
		}
		break;

	case SDLK_d:
		CircleVecter.x += 10;
		if (CircleVecter.x >= 1600)
		{
			CircleVecter.x -= 10;
		}
		break;

	case SDLK_w:
		CircleVecter.y -= 10;
		if (CircleVecter.y <= 0)
		{
			CircleVecter.y += 10;
		}
		break;
//------------------------------------------------

	case SDLK_LEFT:
		CircleVecter2.x -= 10;
		if (CircleVecter2.x <= 0)
		{
			CircleVecter2.x += 10;
		}
		break;

	case SDLK_DOWN:
		CircleVecter2.y += 10;
		if (CircleVecter2.y >= 800)
		{
			CircleVecter2.y -= 10;
		}
		break;

	case SDLK_RIGHT:
		CircleVecter2.x += 10;
		if (CircleVecter2.x >= 1600)
		{
			CircleVecter2.x -= 10;
		}
		break;

	case SDLK_UP:
		CircleVecter2.y -= 10;
		if (CircleVecter2.y <= 0)
		{
			CircleVecter2.y += 10;
		}
		break;

//------------------------------------------------
	case SDLK_q:
		size -= 5;
		break;

	case SDLK_e:
		size += 5;
		break;

	case SDLK_z:
		sides -= 1;
		break;

	case SDLK_x:
		sides += 1;
		break;
//------------------------------------------------
	case SDLK_h:
		color1 -= 5;
		break;

	case SDLK_j:
		color1 += 5;
		break;

	case SDLK_k:
		color2 -= 5;
		break;

	case SDLK_l:
		color2 += 5;
		break;

	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default: printf("%s\n", SDL_GetKeyName(ac_sdlSym)); break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	default: break;
	}
}
void GameLoop::OnExit()
{
	m_bRunning = false; // End the loop
}

GameLoop::GameLoop()
{
	m_bRunning = true;
}
GameLoop::~GameLoop()
{

}
