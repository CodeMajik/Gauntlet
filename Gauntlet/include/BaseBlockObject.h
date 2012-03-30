#pragma once
#ifndef BASEBLOCKOBJECT_H
#define BASEBLOCKOBJECT_H

#include "BaseGameEntity.h"
#include <iostream>
using namespace Ogre;

class BaseBlockObject: public BaseGameEntity{
public:
	enum BLOCKTYPE{ ICE, WOOD, STONE, WALL, PLAYERBODY, ELEVATOR, PRESSUREPAD, COMPANIONCUBE };
	BaseBlockObject(BLOCKTYPE type, float size, hkVector4& pos, SceneManager* sceneMgr);
	BaseBlockObject(BLOCKTYPE type, float sizeX, float sizeY, float sizeZ, hkVector4& pos, SceneManager* sceneMgr);
	BaseBlockObject();
	~BaseBlockObject();
	BLOCKTYPE getType();
	ENTITYTYPE getEntityType();
	hkpRigidBody* getBody();
	virtual void update(const Ogre::FrameEvent& evt);
	virtual void onContact();
	unsigned int getId();
	void changeMats();
	float size();
	SceneNode* getSceneNode();
protected:
	BLOCKTYPE m_blocktype;
	
	SceneNode* m_node;
	Entity* m_entity;
	hkpBoxShape* m_shapeDef;
	float m_size;
	Radian angleRot;
	Ogre::Vector3 axisRot;
	Ogre::Quaternion newOgRot;
	
	Ogre::String m_normMat, m_DmgMat;
};

#endif

