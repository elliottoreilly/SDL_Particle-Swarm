#include "Screen.h"


Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {

}

bool Screen::init() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}
	// Begin the process of setting up the renderer and texture
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);//We want to render to the screen in sync with the refresh rate
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,//4bytes per pixel to correspond with Uint32
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];// Allocate enough memory for 4bytes per pixel to correspond with Uint32.
	m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // After all the screen size is just an array of pixels


	//************ Learn this *************// Writing some pixel information from the buffer..Setting all the cells the pixel buffer
	memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	// A function to quickly allocate a memory block and fill every byte with the int value..in this case 255 for white or 0xFF

	return true;
}
void Screen::boxBlur() {
	// Swap the buffers, so pixel is in m_buffer2 and we are drawing to m_buffer1
	Uint32* temp = m_buffer1;
	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			/*Using BitWise AND & from here		0 0 0
											0 1	0
											0 0 0
			*/
			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for (int row = -1; row <= 1; row++) { // Iterate over all the surrounding pixels(including center)
				for (int col = -1; col<= 1; col++) {
					int currentX = x + col;
					int currentY = y + row;

					if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
						Uint32 color = m_buffer2[currentY * SCREEN_WIDTH + currentX];

						Uint8 red = color >> 24; // BitWise shift
						Uint8 green = color >> 16; // BitWise shift
						Uint8 blue = color >> 8; // BitWise shift

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}
				}
			}

			Uint8 red = redTotal / 9;
			Uint8 green = greenTotal / 9;
			Uint8 blue = blueTotal / 9;

			setPixel(x, y, red, green, blue);
		}
	}
}
//void Screen::clear() {
//	memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
//	memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
//}

void Screen::update() {

	SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

}
void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	// Ensure a pixel is not drawn outside of the screen dimensions inefficient for now!
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}

	Uint32 colour = 0;

	colour += red;
	colour <<= 8; // Bitwise shift of 8 bits
	colour += green;
	colour <<= 8; // Bitwise shift of 8 bits
	colour += blue;
	colour <<= 8; // Bitwise shift of 8 bits
	colour += 0xFF; // Alpha byte of RGBA = opaque

	m_buffer1[(y * SCREEN_WIDTH) + x] = colour;
	// Remember, the buffer represents the whole screen
	// of pixels, going from left to right, row after row

}
bool Screen::processEvents() {
	// Check for messages/events
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {//If for instance if the 'X' is clicked at the top of the window to close
			return false;
		}
	}
	return true;;
}

void Screen::close() {
	// Begin the process of cleaning up and freeing up all the resources and memory

	delete[] m_buffer1; //Free up memory from the screen buffer by destroying the pointer array
	delete[] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}

Screen::~Screen() {

}
