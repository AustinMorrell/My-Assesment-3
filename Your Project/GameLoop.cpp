//////////////////////////////////////////////////
// Austin Morrell //
// November 16, 2015//
// File: GameLoop.cpp//
//////////////////////////////////////////////////

// Before anything I need to include my math library and header files.
#include "GameLoop.h"
#include <Vector2.h>
#include <Vector4.h>

// These are the Vectors for our player characters.
Vector2<int> CircleVecter(500, 450);
Vector2<int> CircleVecter2(1100, 450);
Vector4<int> Color(0, 255, 255, 150);

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

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

		Draw();

		Graphics::Flip(); // Required to update the window with all the newly drawn content
	}

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void GameLoop::Update()
{
	if ((CircleVecter2.x != CircleVecter.x + (size * 2)) || (CircleVecter2.y != CircleVecter.y + (size * 2)))
	{
		CircleVecter2.x = CircleVecter2.x + ((CircleVecter.x - CircleVecter2.x) * DeltaTime);
		CircleVecter2.y = CircleVecter2.y + ((CircleVecter.y - CircleVecter2.y) * DeltaTime);
	}
	Color.y++*DeltaTime;
	if (Color.y == 200)
	{
		Color.z--*DeltaTime;
	}
		Color.w++*DeltaTime;

		MathMakesNotMath(CircleVecter.x, CircleVecter.y);
		cout << "The Location of the Circle is: (" << numbx << " , " << numby << ")" << endl;
		system("cls");
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

int GameLoop::MathMakesNotMath(int x, int y)
{
	x = (x - 800) / 100;
	y = ((y - 450) / 100 * -1);
	numbx = x;
	numby = y;
	return numbx, numby;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void GameLoop::GetDeltaTime()
{
	int now = SDL_GetTicks();
	DeltaTime = ((float)(now - last)) / 1000;
	last = now;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas

	// First we draw the x and y axis using lines.
			Graphics::DrawLine({ 800, 1600 }, { 800, 0 }, { 255, 255, 0, 255 });
			Graphics::DrawLine({ 1600, 450 }, { 0, 450 }, { 255, 255, 255, 255 });

	// Same for the tick marks on the lines.
			for (int x = 0; x < 16; x++)
			{
				Graphics::DrawLine({ 775, ticksy + 50 }, { 825, ticksy + 50 }, { 255, 255, 255, 255 });
				ticksy += 100;
				if (x == 15)
				{
					ticksy = 0;
				}
			}

			for (int x = 0; x < 16; x++)
			{
				Graphics::DrawLine({ ticksx, 425 }, { ticksx, 475 }, { 255, 255, 0, 255 });
				ticksx += 100;
				if (x == 15)
				{
					ticksx = 0;
				}
			}

	// We can then make the player and second player.
	Graphics::DrawCircle({ CircleVecter.x, CircleVecter.y }, size, sides, { Color.x, Color.y, Color.z, Color.w });
	Graphics::DrawCircle({ CircleVecter2.x, CircleVecter2.y }, size, sides, { Color.x, Color.y, Color.z, Color.w });
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void GameLoop::OnMouseMove(const int ac_iMouseX, const int ac_iMouseY, const int ac_iVelX, const int ac_VelY, const bool ac_bLeft, const bool ac_bRight, const bool ac_bMiddle)
{
	if ((CircleVecter.x != ac_iMouseX) && (CircleVecter.y != ac_iMouseY) && (ac_bLeft == true))
	{
		CircleVecter.x = CircleVecter.x + ac_iVelX;
		CircleVecter.y = CircleVecter.y + ac_VelY;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
// Player 1 control commands.
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

// Player 2 control commands.
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

// Controls for both players size and number of sides.
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

	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default: printf("%s\n", SDL_GetKeyName(ac_sdlSym)); break;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	default: break;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void GameLoop::OnExit()
{
	m_bRunning = false; // End the loop
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

GameLoop::GameLoop()
{
	m_bRunning = true;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

GameLoop::~GameLoop()
{

}
