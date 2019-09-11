#ifndef SCREEN_H
#define SCREEN_H
#include<SDL2/SDL.h>
#include<memory.h>
#include<string.h>

class Screen {

public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:// Instance member variables m_
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:// Member functions
	Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);// Prototype
	bool processEvents();
	void close();
	//void clear();
	void boxBlur();
	virtual ~Screen();
};

#endif // SCREEN_H
