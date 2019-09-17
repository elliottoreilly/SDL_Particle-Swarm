//***********************************************************************************
/** SDL2 Program that creates a window  and manipulates the pixels within.
It results in emulated particle  explosion that resembles a random swarm.
Sourced code gleaned and adapted fro John Purcell, at Cave of Programming**

Author: Elliott O'Reilly
Level -2 Computer Science Student.  ID: 17666843
University of Lincoln
13/09/19 */
//***********************************************************************************
#include<iostream>
#include<SDL2/SDL.h>
#include<iomanip>
#include<stdlib.h>
#include"Screen.h"
#include"Swarm.h"

using namespace std;

int main(int argc, char* argv[]) {

	srand(time(NULL)); //  Seed the random number generator

	Screen screen; // Create an instance of the Screen class

	if (screen.init() == false)  // This function  initialises  the SDL library
		cout << "Failed to initialise SDL!" << endl;

	Swarm mySwarm;  // Create an instance of the Swarm class

	while (true) {  // This is the main 'Game ' loop. It will continue to run as long as the program is running or until an event is triggered.
            // It's  responsible for triggering all the  heavy vital  screen functions of the program. I.e. updating/re-drawing the pixels to the screen.

		int elapsed = SDL_GetTicks(); // Time elapsed in milliseconds

		mySwarm.update(elapsed); // Updates the position of all the particles by passing the time elapsed to the function

        // Using the trig functions from the
		// We type cast to an unsigned char
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.001)) * 128); // Oscillates between 1 and -1 to give a smooth transition
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003)) * 128);

		const Particle* const pParticles = mySwarm.getParticle();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

            // Draw particles
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2; // We add 1 here so the 'x' value is from 0 -2 to accommodate the -1 to +1 (sin Wave)
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}
        // Before update the screen and re-drawing the pixels, we can implement the 'box blur' function.
		screen.boxBlur(); // This function calls 'box blur' responsible for prettifying the pixels with fad in/out

		// Draw the screen
		screen.update();

		//Check for messages/events i.e. clicking 'X'
		if (screen.processEvents() == false) {
			break;
		}
	}
	screen.close(); // Clean up!
	return 0;

}
