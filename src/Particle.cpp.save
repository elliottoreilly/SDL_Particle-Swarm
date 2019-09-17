#include "Particle.h"
#include"Screen.h"
#include<math.h>
#include<stdlib.h>

Particle::Particle(): m_x(0), m_y(0) {//from the centre of the screen

	init();
	//.Cartesian method from previous program
	//rand returns between 0 and 1
	//m_x	= ((2.0*rand()) / RAND_MAX) - 1; // returns a double between -1 and +1
	//m_y	= ((2.0*rand()) / RAND_MAX) - 1; // returns a double between -1 and +1

	 //m_xspeed = 0.005 * (((2.0 * rand()) / RAND_MAX) - 1);
	 //m_yspeed = 0.005 * (((2.0 * rand()) / RAND_MAX) - 1);
}
// new measurements using radians and trig functions from  math.h
void Particle::init() {

	m_x = 0;
	m_y = 0;
	m_direction = (2 * M_PI * rand()) / RAND_MAX; // new measurements using radians
	m_speeed = (0.04 * rand()) / RAND_MAX;

	m_speeed *= m_speeed;//Squaring the speed of the particles gives the impression of exponential growth/acceleration
}
Particle::~Particle() {
}


void Particle::update(int interval) {

	m_direction += interval * 0.0003;

	double xspeed = m_speeed * cos(m_direction);
	double yspeed = m_speeed * sin(m_direction);


	m_x += xspeed * interval;
	m_y += yspeed * interval;

	if (m_x < -1 || m_x > 1 || m_y < - 1 || m_y > 1) {
		init(); // If particles hit edge of scree, re-draw
	}

	if (rand() < RAND_MAX / 100) {
		init();
	}
}
