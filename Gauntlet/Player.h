#ifndef PLAYER_H
#define PLAYER_H

#include "Ogre.h"

using namespace Ogre;

class Player{
private:
	Vector3 m_position, m_velocity;
public:
	Player();
	~Player();
};

#endif