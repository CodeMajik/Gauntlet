#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Ogre.h"
#include "BaseBlockObject.h"
#include "BaseGameEntity.h"
#include "PressurePad.h"

using namespace Ogre;

class Elevator: BaseBlockObject{
public:
	enum STATE{ MOVINGTODESTINATION, RETURNING, STOPPED, RESTING };
private:
	STATE m_state, m_prevState;
	hkVector4 m_point1, m_point2;
	bool m_atRest, m_atDestination, m_moving;
	PressurePad* m_pressurePad;
public:
	Elevator(hkVector4& point1, hkVector4& point2, hkVector4& padPos, SceneManager* sceneMgr, hkpWorld& world, ContactListener* listener);
	~Elevator();
	void move();
	void update(const Ogre::FrameEvent& evt);
	void changeState(STATE newState);
	hkpRigidBody* getBody();
};

#endif