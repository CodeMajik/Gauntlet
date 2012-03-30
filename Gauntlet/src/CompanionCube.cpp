#include "CompanionCube.h"

CompanionCube::CompanionCube(hkVector4& pos, SceneManager* sceneMgr, hkpWorld& world, ContactListener* listener)
	: BaseBlockObject(BaseBlockObject::BLOCKTYPE::COMPANIONCUBE, 5.0f, 5.0f, 5.0f, pos, sceneMgr)
{
	m_pickedUp = false;
	world.addEntity((hkpEntity*)m_body);
	m_body->addContactListener(listener);
}

CompanionCube::~CompanionCube()
{

}

void CompanionCube::update(const Ogre::FrameEvent& evt)
{
	BaseBlockObject::update(evt);
	if(m_pickedUp)
	{
		
	}
}

void CompanionCube::update(const Ogre::FrameEvent& evt, hkVector4& lockPos)
{
	BaseBlockObject::update(evt);
	if(m_pickedUp)
	{
		m_body->setPosition(lockPos);
	}
}

void CompanionCube::onContact()
{

}

SceneNode* CompanionCube::getSceneNode()
{
	return BaseBlockObject::getSceneNode();
}