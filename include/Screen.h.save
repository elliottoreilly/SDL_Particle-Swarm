#ifndef SCREEN_H
#define SCREEN_H
#include<SDL2/SDL.h>
#include<memory.h>
#include<string.h>

class Screen {

public: // Set up a standard Screen ration aspect size , will be compatible with all screens
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:   // Instance member variables 'prefixed with an ' m_',
                  //...note it's important to use pointer  variables  as a mass amount of memory will be used to update and re-draw the pixels to the screen
	SDL_Window  *m_window;
	SDL_Renderer  *m_renderer; //  This will be set equal to  'SDL_CreateRenderer'
	SDL_Texture  *m_texture;
	Uint32  *m_buffer1;
	Uint32  *m_buffer2; // We create a second buffer so we look at buffer 1 can put our calculated box blur results in buffer 2

public:// Member functions
	Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);// Prototype
	bool processEvents(); // Check for events/interrupts
	void close(); // Deallocation of  all resource memory
	void boxBlur();
	virtual ~Screen();
};

#endif // SCREEN_H
