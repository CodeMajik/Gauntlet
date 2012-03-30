#include "BlockManager.h"
#include <string>

BlockManager* BlockManager::m_instance = 0;

BlockManager* BlockManager::instance(hkpWorld* world)
{
	if(!m_instance)
	{
		m_instance = new BlockManager(world);
		
	}
	return m_instance;
}

BlockManager* BlockManager::instance()
{
	if(!m_instance)
	{
		m_instance = new BlockManager();
	}
	return m_instance;
}

BlockManager::~BlockManager()
{
	for(int i = 0;i< m_blocks->getSize();i++){
		(*m_blocks)[i]->getBody()->removeReference();
	}
} 

BlockManager::BlockManager(hkpWorld* world)
{
	m_blockFactory = BlockFactory::instance();
	m_blocks = new hkArray<BaseBlockObject*>;
	m_worldPtr = world;
	position = hkVector4(25.0f, 25.0f, 0.0f );
	restrictMovement= false;
	m_contactListener = ContactListener::getInstance();
}

BlockManager::BlockManager()
{
	m_contactListener = ContactListener::getInstance();
}

BlockFactory* BlockManager::getBlockFactory()
{
	return m_blockFactory;
}

void BlockManager::init(int numBlocks, SceneManager* sceneMgr)
{
	//for(int i = 0;i < numBlocks;i++){
	//	m_blocks->pushBack(m_blockFactory->createBlock(BaseBlockObject::BLOCKTYPE::ICE, m_idGenerator->getNewID(), 1.0f, position, sceneMgr));
	//	//m_blocks->back()->getBody()->setUserData((hkUlong)m_blocks->back()->getId());
	//	m_worldPtr->addEntity((hkpEntity*)m_blocks->back()->getBody());
	//}
}

void BlockManager::update(const Ogre::FrameEvent& evt)
{
	for(int i = 0;i< m_blocks->getSize() ;i++){
		(*m_blocks)[i]->update(evt);
		if(restrictMovement)
		{
			hkVector4 pos = (*m_blocks)[i]->getBody()->getPosition();
			pos(2) = 0.0;
			(*m_blocks)[i]->getBody()->setPosition(pos);
			hkQuaternion rot = (*m_blocks)[i]->getBody()->getRotation();
			rot.set(0, 0, 0, 0);
			(*m_blocks)[i]->getBody()->setRotation(rot);
		}
	}
}

void BlockManager::addBlock(BaseBlockObject::BLOCKTYPE type, float size, hkVector4& pos, SceneManager* sceneMgr)
{
	m_blocks->pushBack(m_blockFactory->createBlock(type, size, pos, sceneMgr));
	//m_blocks->back()->getBody()->setUserData((hkUlong)m_blocks->back()->getId());
	m_worldPtr->addEntity((hkpEntity*)m_blocks->back()->getBody());
	m_blocks->back()->getBody()->addContactListener(m_contactListener);
}
  