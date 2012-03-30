#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include "Physics.h"
//#include "BaseBlockObject.h"
//#include "BlockManager.h"
//#include "PigManager.h"
//#include "BirdFactory.h"
//#include "Player.H"

//class BaseGameEntity;
//class BaseBlockObject;
//class BlockManager;

#define THRESHOLD 8.0

#define IS_PIG(x) (x->getType() == BaseGameEntity::ENTITYTYPE::PIG)

class ContactListener: public hkpContactListener{
private:
	ContactListener()
	{
		//plr = Player::getInstance();
	}
	static ContactListener* m_instance;
public:
	static ContactListener* getInstance();

	virtual void contactPointCallback( const hkpContactPointEvent& event )
	{
		// Disable normal collision response.
		//event.m_contactPointProperties->m_flags |= hkContactPointMaterial::CONTACT_IS_DISABLED;

		hkContactPoint cp = *event.m_contactPoint;

		// The impulse we apply is a function of the contact normal.
		hkVector4 impulse;
		{
			// If the listener was attached to the B body in this collision, then the contact normal
			// is the wrong way around.
			hkReal factor = ( event.m_source == hkpCollisionEvent::SOURCE_A ) ? 1.5f : -1.5f;
			impulse.setMul4( factor, event.m_contactPoint->getNormal() );
		}

		hkpRigidBody* box = event.getBody( 0 );
		hkUlong id = box->getUserData();

		hkpRigidBody* box2 = event.getBody( 1 );
		hkUlong id2 = box2->getUserData();

		/*BaseGameEntity* obj1 = NULL;
		obj1 = reinterpret_cast<BaseGameEntity*>( id );
		BaseGameEntity* obj2 = NULL;
		obj2 = reinterpret_cast<BaseGameEntity*>( id2 );*/

		/*if(obj1 && obj2)
		{
			if(obj1->getType() == BaseGameEntity::ENTITYTYPE::BLOCK && obj2->getType() == BaseGameEntity::ENTITYTYPE::BLOCK)
			{
				float vel1 = 0.0f;
				vel1 = sqrt((obj1->getBody()->getLinearVelocity().getComponent(0)*obj1->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj1->getBody()->getLinearVelocity().getComponent(1)*(obj1->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj1->getBody()->getLinearVelocity().getComponent(2)*obj1->getBody()->getLinearVelocity().getComponent(2)));

				float vel2 = 0.0f;
				vel2 = sqrt((obj2->getBody()->getLinearVelocity().getComponent(0)*obj2->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj2->getBody()->getLinearVelocity().getComponent(1)*(obj2->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj2->getBody()->getLinearVelocity().getComponent(2)*obj2->getBody()->getLinearVelocity().getComponent(2)));
				
				if(vel1 > THRESHOLD || vel2 > THRESHOLD)
				{
					obj1->onContact();
					obj2->onContact();
					plr->addScore(50);
				}
			}
			if(obj1->getType() == BaseGameEntity::ENTITYTYPE::PIG && obj2->getType() == BaseGameEntity::ENTITYTYPE::BIRD)
			{
				float vel1 = 0.0f;
				vel1 = sqrt((obj1->getBody()->getLinearVelocity().getComponent(0)*obj1->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj1->getBody()->getLinearVelocity().getComponent(1)*(obj1->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj1->getBody()->getLinearVelocity().getComponent(2)*obj1->getBody()->getLinearVelocity().getComponent(2)));

				float vel2 = 0.0f;
				vel2 = sqrt((obj2->getBody()->getLinearVelocity().getComponent(0)*obj2->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj2->getBody()->getLinearVelocity().getComponent(1)*(obj2->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj2->getBody()->getLinearVelocity().getComponent(2)*obj2->getBody()->getLinearVelocity().getComponent(2)));
				
				if(vel1 > THRESHOLD || vel2 > THRESHOLD)
				{
					obj1->onContact();
					obj2->onContact();
					plr->addScore(1000);
				}
			}
			if(obj1->getType() == BaseGameEntity::ENTITYTYPE::BIRD && obj2->getType() == BaseGameEntity::ENTITYTYPE::PIG)
			{
				float vel1 = 0.0f;
				vel1 = sqrt((obj1->getBody()->getLinearVelocity().getComponent(0)*obj1->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj1->getBody()->getLinearVelocity().getComponent(1)*(obj1->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj1->getBody()->getLinearVelocity().getComponent(2)*obj1->getBody()->getLinearVelocity().getComponent(2)));

				float vel2 = 0.0f;
				vel2 = sqrt((obj2->getBody()->getLinearVelocity().getComponent(0)*obj2->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj2->getBody()->getLinearVelocity().getComponent(1)*(obj2->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj2->getBody()->getLinearVelocity().getComponent(2)*obj2->getBody()->getLinearVelocity().getComponent(2)));
				
				if(vel1 > THRESHOLD || vel2 > THRESHOLD)
				{
					obj1->onContact();
					obj2->onContact();
					plr->addScore(1000);
				}
			}
			if(obj1->getType() == BaseGameEntity::ENTITYTYPE::BLOCK && obj2->getType() == BaseGameEntity::ENTITYTYPE::PIG)
			{
				float vel1 = 0.0f;
				vel1 = sqrt((obj1->getBody()->getLinearVelocity().getComponent(0)*obj1->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj1->getBody()->getLinearVelocity().getComponent(1)*(obj1->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj1->getBody()->getLinearVelocity().getComponent(2)*obj1->getBody()->getLinearVelocity().getComponent(2)));

				float vel2 = 0.0f;
				vel2 = sqrt((obj2->getBody()->getLinearVelocity().getComponent(0)*obj2->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj2->getBody()->getLinearVelocity().getComponent(1)*(obj2->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj2->getBody()->getLinearVelocity().getComponent(2)*obj2->getBody()->getLinearVelocity().getComponent(2)));
				
				if(vel1 > THRESHOLD || vel2 > THRESHOLD)
				{
					obj1->onContact();
					obj2->onContact();
					plr->addScore(200);
				}
			}
			if(obj1->getType() == BaseGameEntity::ENTITYTYPE::PIG && obj2->getType() == BaseGameEntity::ENTITYTYPE::BLOCK)
			{
				float vel1 = 0.0f;
				vel1 = sqrt((obj1->getBody()->getLinearVelocity().getComponent(0)*obj1->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj1->getBody()->getLinearVelocity().getComponent(1)*(obj1->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj1->getBody()->getLinearVelocity().getComponent(2)*obj1->getBody()->getLinearVelocity().getComponent(2)));

				float vel2 = 0.0f;
				vel2 = sqrt((obj2->getBody()->getLinearVelocity().getComponent(0)*obj2->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj2->getBody()->getLinearVelocity().getComponent(1)*(obj2->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj2->getBody()->getLinearVelocity().getComponent(2)*obj2->getBody()->getLinearVelocity().getComponent(2)));
				
				if(vel1 > THRESHOLD || vel2 > THRESHOLD)
				{
					obj1->onContact();
					obj2->onContact();
					plr->addScore(200);
				}
			}
			if(obj1->getType() == BaseGameEntity::ENTITYTYPE::BIRD && obj2->getType() == BaseGameEntity::ENTITYTYPE::BLOCK)
			{
				float vel1 = 0.0f;
				vel1 = sqrt((obj1->getBody()->getLinearVelocity().getComponent(0)*obj1->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj1->getBody()->getLinearVelocity().getComponent(1)*(obj1->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj1->getBody()->getLinearVelocity().getComponent(2)*obj1->getBody()->getLinearVelocity().getComponent(2)));

				float vel2 = 0.0f;
				vel2 = sqrt((obj2->getBody()->getLinearVelocity().getComponent(0)*obj2->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj2->getBody()->getLinearVelocity().getComponent(1)*(obj2->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj2->getBody()->getLinearVelocity().getComponent(2)*obj2->getBody()->getLinearVelocity().getComponent(2)));
				
				if(vel1 > THRESHOLD || vel2 > THRESHOLD)
				{
					obj1->onContact();
					obj2->onContact();
					plr->addScore(200);
				}
			}
			if(obj1->getType() == BaseGameEntity::ENTITYTYPE::BLOCK && obj2->getType() == BaseGameEntity::ENTITYTYPE::BIRD)
			{
				float vel1 = 0.0f;
				vel1 = sqrt((obj1->getBody()->getLinearVelocity().getComponent(0)*obj1->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj1->getBody()->getLinearVelocity().getComponent(1)*(obj1->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj1->getBody()->getLinearVelocity().getComponent(2)*obj1->getBody()->getLinearVelocity().getComponent(2)));

				float vel2 = 0.0f;
				vel2 = sqrt((obj2->getBody()->getLinearVelocity().getComponent(0)*obj2->getBody()->getLinearVelocity().getComponent(0)) + 
					(obj2->getBody()->getLinearVelocity().getComponent(1)*(obj2->getBody()->getLinearVelocity().getComponent(1))) + 
					(obj2->getBody()->getLinearVelocity().getComponent(2)*obj2->getBody()->getLinearVelocity().getComponent(2)));
				
				if(vel1 > THRESHOLD || vel2 > THRESHOLD)
				{
					obj1->onContact();
					obj2->onContact();
					plr->addScore(200);
				}
			}*/
	}
};

#endif