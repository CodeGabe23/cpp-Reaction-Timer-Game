#include <raylib.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>


// Reaction Timer Game:
// TODO:
// Wait a random number of seconds on a black screen
// then display a green screen with text "CLICK NOW"
// while displaying, count the number of miliseconds it takes from start of green screen till end
// dipsplay if it was fast or not

int main()
{	
	//seed for randomness
	srand(time(0));

	double randomTime = rand() % 6 + 2; // a random number between 2 and 5
	
	float timer = 0.0f;

	InitWindow(800,800,"Reacter Timer Game");
	SetTargetFPS(60);
	
	bool init = false;

	
	//WaitTime(randomTime);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		if (!init)
		{
			std::cout << "\ninit\n";
			// Display black screen at first
			ClearBackground(BLACK);	
		
			init = true;
			timer = 0.0f;
		
					
		}

		// Then display green text with text "CLICK NOW"
		// start timer to count how many miliseconds it takes for the user to click the screen

		if (init)
		{
			ClearBackground(GREEN);
			timer += GetFrameTime();
	
			if (IsMouseButtonPressed(0))
			{
				EndDrawing();
				break;
			}
		}
		EndDrawing();
	}

	std::cout << "\n\nYour reaction time: " << timer;

	return 0;
}
