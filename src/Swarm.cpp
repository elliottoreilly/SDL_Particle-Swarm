#include "Swarm.h"

Swarm::Swarm(): lastTime(0) {
	m_pParticle = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete[] m_pParticle;
}

void Swarm::update(int elapsed) {

	int interval = elapsed - lastTime; // This helps to run the simulation suitable for the clock speed of all computers that run it

	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticle[i].update(interval);
	}
	lastTime = elapsed;
}
