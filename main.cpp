#include<iostream>
#include<SDL2/SDL.h>
#include<iomanip>
#include<stdlib.h>
#include"Screen.h"
#include"Swarm.h"
using namespace std;

int main(int argc, char* argv[]) {

	srand(time(NULL)); // seen the random number generator

	Screen screen;

	if (screen.init() == false) {
		cout << "Failed to initialise SDL!" << endl;
	}
	Swarm mySwarm;
	while (true) {
		// Update particles

		//// Draw particles

		int elapsed = SDL_GetTicks(); // Time elapsed in milliseconds


		//screen.clear(); // used before the blur method is introduced
		mySwarm.update(elapsed);

		//We type cast to an unsigned char
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.001)) * 128); // Oscillates between 1 and -1 to give a smooth transition
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003)) * 128);

		const Particle* const pParticles = mySwarm.getParticle();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;

			//int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			//int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

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
