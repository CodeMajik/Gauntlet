#ifndef COMPANIONCUBE_H
#define COMPANIONCUBE_H

#include "Ogre.h"
#include "BaseBlockObject.h"
#include "BaseGameEntity.h"
#include "ContactListener.h"

class CompanionCube: BaseBlockObject{
private:
	bool m_pickedUp;
	
public:
	CompanionCube(hkVector4& pos, SceneManager* sceneMgr, hkpWorld& world, ContactListener* listener);
	~CompanionCube();
	void update(const Ogre::FrameEvent& evt);
	void update(const Ogre::FrameEvent& evt, hkVector4& lockPos);
    void onContact();
	SceneNode* getSceneNode();
	bool Pickedup(){ return m_pickedUp; }
	void setPickedUp(bool arg){ m_pickedUp = arg; }
};

#endif