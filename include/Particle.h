#ifndef PARTICLE_H
#define PARTICLE_H


struct Particle
{	// Instance member variables m_
	double m_x;
	double m_y;

	//double m_xspeed;
	//double m_yspeed;
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
