#ifndef PRESSUREPAD_H
#define PRESSUREPAD_H

#include "Ogre.h"
#include "BaseBlockObject.h"
#include "BaseGameEntity.h"
#include "ContactListener.h"

using namespace Ogre;

class PressurePad: BaseBlockObject{
private:
	bool m_pressed;
public:
	PressurePad(hkVector4& pos, SceneManager* sceneMgr, hkpWorld& world, ContactListener* listener);
	~PressurePad();
	bool Pressed(){ return m_pressed; }
	void setPressed(bool arg){ m_pressed = arg; }
    void update(const Ogre::FrameEvent& evt);
    void onContact();
};

#endif