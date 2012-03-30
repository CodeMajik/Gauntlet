#include "Elevator.h"

Elevator::Elevator(hkVector4& point1, hkVector4& point2, hkVector4& padPos, SceneManager* sceneMgr, hkpWorld& world, ContactListener* listener)
	: BaseBlockObject(BaseBlockObject::BLOCKTYPE::ELEVATOR, 40.0f, 1.0f, 40.0f, point1, sceneMgr), m_point1(point1), m_point2(point2)
{
	m_atRest = true; 
	m_atDestination = false;
	m_moving = false;
	m_state = RESTING;
	m_prevState = RESTING;

	world.addEntity((hkpEntity*)m_body);
	m_body->addContactListener(listener);

	m_pressurePad = new PressurePad(padPos, sceneMgr, world, listener);

	m_body->setGravityFactor(0.0);
}

Elevator::~Elevator()
{

}

void Elevator::move()
{

}

void Elevator::changeState(STATE newState)
{
	m_prevState = m_state;
	m_state = newState;
}

hkpRigidBody* Elevator::getBody()
{
	return BaseBlockObject::getBody();
}

void Elevator::update(const Ogre::FrameEvent& evt)
{
	BaseBlockObject::update(evt);
	m_pressurePad->update(evt);
	hkVector4 rot(0.0f, 0.0f, 0.0f, 0.0f);
	m_body->setAngularVelocity(rot);
	switch(m_state)
	{
		case RESTING:
		{
			//Do nothing
		}
		break;
		case MOVINGTODESTINATION:
		{
			//Moving to dest
			hkVector4 pos = m_body->getPosition();
			if(pos(1) < m_point2(1))
			{
				pos(1)+=0.05f;
				m_body->setPosition(pos);
			}
			else
			{
				this->changeState(STATE::RETURNING);
			}
		}
		break;
		case RETURNING:
		{
			hkVector4 pos = m_body->getPosition();
			if(pos(1) > m_point1(1))
			{
				pos(1)-=0.05f;
				m_body->setPosition(pos);
			}
			else
			{
				this->changeState(STATE::MOVINGTODESTINATION);
			}
		}
		break;
		case STOPPED:
		{
			//Do nothing
		}
		break;
	}
}