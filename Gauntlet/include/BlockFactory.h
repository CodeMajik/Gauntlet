#ifndef BLOCKFACTORY_H
#define BLOCKFACTORY_H

#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include "BaseBlockObject.h"
#include "Physics.h"

class BlockFactory{
public:
	~BlockFactory();
	static BlockFactory* instance();
	BaseBlockObject* createBlock(BaseBlockObject::BLOCKTYPE type, float size, hkVector4& pos, SceneManager* sceneMgr);
	BaseBlockObject* createBlock(BaseBlockObject::BLOCKTYPE type, float sizeX, float sizeY, float sizeZ, hkVector4& pos, SceneManager* sceneMgr);
private:
	BlockFactory();
	static BlockFactory* m_instance;

	hkpBoxShape* m_shapeDefinition;
	hkpRigidBodyCinfo* m_bodyInfo; 
	hkpMassProperties massProperties;
};

#endif