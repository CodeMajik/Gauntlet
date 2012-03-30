#include "PressurePad.h"

PressurePad::PressurePad(hkVector4& pos, SceneManager* sceneMgr, hkpWorld& world, ContactListener* listener)
	: BaseBlockObject(BaseBlockObject::BLOCKTYPE::PRESSUREPAD, 15.0f, 1.0f, 15.0f, pos, sceneMgr)
{
	m_pressed = false;
	world.addEntity((hkpEntity*)m_body);
	m_body->addContactListener(listener);
}

PressurePad::~PressurePad()
{

}

void PressurePad::update(const Ogre::FrameEvent& evt)
{
	BaseBlockObject::update(evt);
}

void PressurePad::onContact()
{
	m_pressed = true;
}