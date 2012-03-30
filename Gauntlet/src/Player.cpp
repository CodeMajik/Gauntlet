#include "Player.h"

Player::Player()
{

}

Player::Player(hkVector4 &pos, hkpWorld& world, SceneManager * sceneMgr)
	: BaseGameEntity(BaseGameEntity::PLAYER, pos)
{
	blkMgr = BlockManager::instance(&world);
	m_physicalBody = blkMgr->getBlockFactory()->createBlock(BaseBlockObject::BLOCKTYPE::PLAYERBODY, 2.0f, 3.0f, 2.0f, pos, sceneMgr);
	listener = ContactListener::getInstance();
	m_physicalBody->getBody()->addContactListener(listener);
	world.addEntity((hkpEntity*)m_physicalBody->getBody());

	m_raySceneQuery = sceneMgr->createRayQuery(Ogre::Ray());
	m_intersectionPlane = Ogre::Plane(Ogre::Vector3::UNIT_Z, 0);
}

Player::~Player()
{

}

void Player::injectMouseDown(const MouseEvent& evt, MouseButtonID id, Camera* m_camera, CompanionCube* cube)
{
	Ogre::Real screenWidth = Ogre::Root::getSingleton().getAutoCreatedWindow()->getWidth();
	Ogre::Real screenHeight = Ogre::Root::getSingleton().getAutoCreatedWindow()->getHeight();
 
	Ogre::Real offsetX = evt.state.X.abs / screenWidth;
	Ogre::Real offsetY = evt.state.Y.abs / screenHeight;
 
	Ogre::Ray mouseRay = m_camera->getCameraToViewportRay(offsetX, offsetY);
 
	std::pair<bool, Ogre::Real> result = mouseRay.intersects(m_intersectionPlane);
 
	if(result.first) 
	{ 
		Ogre::Vector3 intersectionPoint = mouseRay.getPoint(result.second);
		Ogre::Vector3 objPoint = cube->getSceneNode()->getPosition();

		float distance = Math::Sqrt(((intersectionPoint.x - objPoint.x) * (intersectionPoint.x - objPoint.x)) + ((intersectionPoint.y - objPoint.y) * (intersectionPoint.y - objPoint.y)));
		
		if(distance < 60.0f)
		{
			cube->setPickedUp(true);
		}
		/*if(intersectionPoint.x >= cube->getSceneNode()->getPosition().x && intersectionPoint.x <= cube->getSceneNode()->getPosition().x + 5)
			if(intersectionPoint.y <= cube->getSceneNode()->getPosition().y && intersectionPoint.y >= cube->getSceneNode()->getPosition().y - 5)
			{
				cube->setPickedUp(true);
				*cube->lockPos = m_body->getPosition();
			}*/
	}
}

void Player::injectMouseUp(const MouseEvent& evt, MouseButtonID id, Camera* m_camera, CompanionCube* cube)
{
	Ogre::Real screenWidth = Ogre::Root::getSingleton().getAutoCreatedWindow()->getWidth();
	Ogre::Real screenHeight = Ogre::Root::getSingleton().getAutoCreatedWindow()->getHeight();
 
	Ogre::Real offsetX = evt.state.X.abs / screenWidth;
	Ogre::Real offsetY = evt.state.Y.abs / screenHeight;
 
	Ogre::Ray mouseRay = m_camera->getCameraToViewportRay(offsetX, offsetY);
 
	std::pair<bool, Ogre::Real> result = mouseRay.intersects(m_intersectionPlane);
 
	if(result.first) 
	{ 
		Ogre::Vector3 intersectionPoint = mouseRay.getPoint(result.second);
		

	}
}

void Player::update(const Ogre::FrameEvent& evt)
{
	m_physicalBody->update(evt);
	//hkVector4 rot(0.0, 0.0, 0.0, 0.0);

	//m_physicalBody->getBody()->setAngularVelocity(rot);
}

void Player::moveForward()
{
	
	//m_physicalBody->getBody()->setPosition();
}

void Player::moveBackwards()
{
	
	//m_physicalBody->getBody()->setPosition();
}

void Player::onContact()
{

}

hkVector4 Player::getPosition()
{
	return m_physicalBody->getBody()->getPosition();
}

void Player::setPosition(hkVector4& newPos)
{
	m_physicalBody->getBody()->setPosition(newPos);
}