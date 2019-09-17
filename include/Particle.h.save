#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle
{	// Instance member variables 'prefixed with an ' m_',
	double m_x; // The use of 'doubles' is necessary  to ensure the illusion of a smooth transition
	double m_y;

private:
	double m_speeed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};
#endif // PARTICLE_H
