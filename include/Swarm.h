#ifndef SWARM_H
#define SWARM_H
#include"Particle.h"
class Swarm
{
public:
	const static int NPARTICLES = 5000;

private:
	Particle* m_pParticle;
	int lastTime;

public:

	Swarm();
	virtual ~Swarm();
	void update(int elapsed);

	const Particle* const getParticle() { return m_pParticle; };

};
#endif // SWARM_H
