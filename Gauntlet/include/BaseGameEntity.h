#ifndef BASEGAMEENTITY_H
#define BASEGAMEENTITY_H

#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "Physics.h"

#include "UniqueIDGenerator.h"

#include <vector>

class BaseGameEntity{
public:
	enum ENTITYTYPE{ BLOCK, PLAYER, ELEVATOR, PRESSUREPAD, COMPANIONCUBE };
	BaseGameEntity(ENTITYTYPE type, hkVector4& pos);
	BaseGameEntity();
	virtual ~BaseGameEntity(){};
	virtual void update(const Ogre::FrameEvent& evt){}
	virtual void onContact()=0;
	ENTITYTYPE getType();
	char* m_name;
	virtual hkpRigidBody* getBody();
protected:
	ENTITYTYPE m_entitytype;
	hkVector4 m_position;
	unsigned int m_id;
	int m_dmgLvl;
	hkpRigidBody* m_body;
	bool m_needstoBeDestroyed;
	UniqueIDGenerator* m_idGen;
};

#endif