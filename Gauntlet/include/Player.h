#ifndef PLAYER_H
#define PLAYER_H

#include "Ogre.h"
#include <OIS.h>
#include <SdkTrays.h>
#include "BlockManager.h"
#include "ContactListener.h"
#include "CompanionCube.h"

using namespace Ogre;
using namespace OIS;

class Player : BaseGameEntity{
private:
	BlockManager* blkMgr;
	BaseBlockObject* m_physicalBody;
	ContactListener* listener;
	Ogre::RaySceneQuery * m_raySceneQuery;
	Ogre::Plane m_intersectionPlane;
	hkVector4* mPos;
public:
	Player();
	Player(hkVector4 &pos, hkpWorld& world, SceneManager * sceneMgr);
	~Player();
	void moveForward();
	void moveBackwards();
	void update(const Ogre::FrameEvent& evt);
    void onContact();
	BaseBlockObject* getPhysicalBody(){ return m_physicalBody; }
	hkVector4 getPosition();
	void setPosition(hkVector4& newPos);
	void injectMouseDown(const MouseEvent& evt, MouseButtonID id, Camera* m_camera, CompanionCube* cube);
	void injectMouseUp(const MouseEvent& evt, MouseButtonID id, Camera* m_camera, CompanionCube* cube);
	void injectMouseMove(const MouseEvent& evt);
};

#endif