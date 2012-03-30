#include "BaseBlockObject.h"

BaseBlockObject::BaseBlockObject()
{

}

BaseBlockObject::BaseBlockObject(BLOCKTYPE type, float sizeX, float sizeY, float sizeZ, hkVector4& pos, SceneManager* sceneMgr)
	: BaseGameEntity(BaseGameEntity::ENTITYTYPE::BLOCK, pos), m_blocktype(type)
{
	hkVector4 halfSize( sizeX/2.0,sizeY/2.0,sizeZ/2.0 );
	m_shapeDef = new hkpBoxShape( halfSize , 0 );
	m_shapeDef->setRadius( 0.0f );

	hkpRigidBodyCinfo boxInfo;

	m_node = sceneMgr->getRootSceneNode()->createChildSceneNode("Block" + StringConverter::toString(m_id));
	m_node->scale( sizeX/2.0,sizeY/2.0,sizeZ/2.0 );
	m_entity = sceneMgr->createEntity("Block" + StringConverter::toString(m_id), "cube.mesh");
	AxisAlignedBox abb = m_entity->getBoundingBox();

	switch(type)
	{
		case 0://Ice
		{
			boxInfo.m_mass = 50.0f;
			boxInfo.m_friction = 0.1f;
			boxInfo.m_restitution = 0.1f;

			m_normMat = "Examples/Ice";
			m_DmgMat = "Examples/IceDamaged";

			m_entity->setMaterialName("Examples/Ice");
		}
		break;
		case 1://Wood
		{
			boxInfo.m_mass = 60.0f;
			boxInfo.m_friction = 0.8f;
			boxInfo.m_restitution = 0.2f;

			m_normMat = "Examples/Wood";
			m_DmgMat = "Examples/WoodDamaged";

			m_entity->setMaterialName("Examples/Wood");
		}
		break;
		case 2://Stone
		{
			boxInfo.m_mass = 100.0f;
			boxInfo.m_friction = 0.9f;
			boxInfo.m_restitution = 0.1f;

			m_normMat = "Examples/Stone";
			m_DmgMat = "Examples/StoneDamaged";

			m_entity->setMaterialName("Examples/Stone");
		}
		break;
		case 3://Stone
		{
			boxInfo.m_mass = 100.0f;
			boxInfo.m_friction = 0.9f;
			boxInfo.m_restitution = 0.1f;

			m_normMat = "Examples/Stone";
			m_DmgMat = "Examples/StoneDamaged";

			m_entity->setMaterialName("Examples/Stone");
		}
		break;
		case 4://Player
		{
			boxInfo.m_mass = 100.0f;
			boxInfo.m_friction = 0.9f;
			boxInfo.m_restitution = 0.1f;

			m_normMat = "Examples/Wood";
			m_DmgMat = "Examples/WoodDamaged";

			m_entity->setMaterialName("Examples/Wood");
		}
		break;
		case 5://Elevator
		{
			boxInfo.m_mass = 100.0f;
			boxInfo.m_friction = 0.9f;
			boxInfo.m_restitution = 0.1f;

			m_normMat = "Examples/Wood";
			m_DmgMat = "Examples/WoodDamaged";

			m_entity->setMaterialName("Examples/Wood");
		}
		break;
		case 6://Pressure Pad
		{
			boxInfo.m_mass = 100.0f;
			boxInfo.m_friction = 0.9f;
			boxInfo.m_restitution = 0.1f;

			m_normMat = "Examples/RustySteel";
			m_DmgMat = "Examples/RustySteel";

			m_entity->setMaterialName("Examples/RustySteel");
		}
		break;
		case 7://Companion Cube
		{
			boxInfo.m_mass = 100.0f;
			boxInfo.m_friction = 0.9f;
			boxInfo.m_restitution = 0.1f;

			m_normMat = "Examples/CompanionCube";
			m_DmgMat = "Examples/CompanionCube";

			m_entity->setMaterialName("Examples/CompanionCube");
		}
		break;
	}
	//
	hkpMassProperties massProperties;
	hkpInertiaTensorComputer::computeBoxVolumeMassProperties(halfSize, boxInfo.m_mass, massProperties);
	//
	boxInfo.m_mass = massProperties.m_mass;
	boxInfo.m_centerOfMass = massProperties.m_centerOfMass;
	boxInfo.m_inertiaTensor = massProperties.m_inertiaTensor;

	boxInfo.m_shape = m_shapeDef;
	boxInfo.m_solverDeactivation = boxInfo.SOLVER_DEACTIVATION_MEDIUM; // used to deal with resting contacts
	boxInfo.m_qualityType = HK_COLLIDABLE_QUALITY_MOVING;// default collision quality
	boxInfo.m_motionType = hkpMotion::MOTION_BOX_INERTIA;
	boxInfo.m_position = pos;

    m_body = new hkpRigidBody(boxInfo);

	Vector3 sz = abb.getSize();
	float scalesizex = sizeX/sz.x;
	float scalesizey = sizeY/sz.y;
	float scalesizez = sizeZ/sz.z;
	m_node->setPosition(pos.getComponent(0),pos.getComponent(1),pos.getComponent(2));
	m_node->setScale(scalesizex,scalesizey,scalesizez);
	m_node->attachObject(m_entity);

	m_needstoBeDestroyed = false;
	m_size = sizeX*sizeY*sizeZ;

	//long int val = reinterpret_cast<long int>( (hkUlong)m_birds->back()->getId() );
			//m_birds->back()->getBody()->setUserData(

	hkUlong data = reinterpret_cast<hkUlong>( this );
	m_body->setUserData(data);
}

BaseBlockObject::BaseBlockObject(BLOCKTYPE type, float size, hkVector4& pos,
SceneManager* sceneMgr)
	: BaseGameEntity(BaseGameEntity::ENTITYTYPE::BLOCK, pos), m_blocktype(type)
{
	hkVector4 halfSize( size/2.0,size/2.0,size/2.0);
	m_shapeDef = new hkpBoxShape( halfSize , 0 );
	m_shapeDef->setRadius( 0.0f );

	hkpRigidBodyCinfo boxInfo;

	m_node = sceneMgr->getRootSceneNode()->createChildSceneNode("Block" + StringConverter::toString(m_id));
	m_node->scale( size/2.0,size/2.0,size/2.0 );
	m_entity = sceneMgr->createEntity("Block" + StringConverter::toString(m_id), "cube.mesh");
	AxisAlignedBox abb = m_entity->getBoundingBox();

	switch(type)
	{
		case 0://Ice
		{
			boxInfo.m_mass = 50.0f;
			boxInfo.m_friction = 0.1f;
			boxInfo.m_restitution = 0.1f;

			m_normMat = "Examples/Ice";
			m_DmgMat = "Examples/IceDamaged";

			m_entity->setMaterialName("Examples/Ice");
		}
		break;
		case 1://Wood
		{
			boxInfo.m_mass = 60.0f;
			boxInfo.m_friction = 0.8f;
			boxInfo.m_restitution = 0.2f;

			m_normMat = "Examples/Wood";
			m_DmgMat = "Examples/WoodDamaged";

			m_entity->setMaterialName("Examples/Wood");
		}
		break;
		case 2://Stone
		{
			boxInfo.m_mass = 100.0f;
			boxInfo.m_friction = 0.9f;
			boxInfo.m_restitution = 0.1f;

			m_normMat = "Examples/Stone";
			m_DmgMat = "Examples/StoneDamaged";

			m_entity->setMaterialName("Examples/Stone");
		}
		break;
		case 3://Stone
		{
			boxInfo.m_mass = 100.0f;
			boxInfo.m_friction = 0.9f;
			boxInfo.m_restitution = 0.1f;

			m_normMat = "Examples/Stone";
			m_DmgMat = "Examples/StoneDamaged";

			m_entity->setMaterialName("Examples/Stone");
		}
		break;
	}
	//
	hkpMassProperties massProperties;
	hkpInertiaTensorComputer::computeBoxVolumeMassProperties(halfSize, boxInfo.m_mass, massProperties);
	//
	boxInfo.m_mass = massProperties.m_mass;
	boxInfo.m_centerOfMass = massProperties.m_centerOfMass;
	boxInfo.m_inertiaTensor = massProperties.m_inertiaTensor;

	boxInfo.m_shape = m_shapeDef;
	boxInfo.m_solverDeactivation = boxInfo.SOLVER_DEACTIVATION_MEDIUM; // used to deal with resting contacts
	boxInfo.m_qualityType = HK_COLLIDABLE_QUALITY_MOVING;// default collision quality
	boxInfo.m_motionType = hkpMotion::MOTION_BOX_INERTIA;
	boxInfo.m_position = pos;

    m_body = new hkpRigidBody(boxInfo);

	Vector3 sz = abb.getSize();
	float scalesizex = size/sz.x;
	float scalesizey = size/sz.y;
	float scalesizez = size/sz.z;
	m_node->setPosition(pos.getComponent(0),pos.getComponent(1),pos.getComponent(2));
	m_node->setScale(scalesizex,scalesizey,scalesizez);
	m_node->attachObject(m_entity);

	m_needstoBeDestroyed = false;
	m_size = size;

	//long int val = reinterpret_cast<long int>( (hkUlong)m_birds->back()->getId() );
			//m_birds->back()->getBody()->setUserData(

	hkUlong data = reinterpret_cast<hkUlong>( this );
	m_body->setUserData(data);
}

BaseBlockObject::~BaseBlockObject()
{

}

BaseBlockObject::BLOCKTYPE BaseBlockObject::getType()
{
	return m_blocktype;
}

unsigned int BaseBlockObject::getId()
{
	return m_id;
}

SceneNode* BaseBlockObject::getSceneNode()
{
	return m_node;
}

float BaseBlockObject::size()
{
	return m_size;
}

void BaseBlockObject::onContact()
{
	m_dmgLvl++;
	changeMats();
}

hkpRigidBody* BaseBlockObject::getBody()
{
	return m_body;
}

void BaseBlockObject::changeMats()
{
	switch(m_dmgLvl)
	{
		case 1:
		{
			m_entity->setMaterialName(m_DmgMat);
		}
		break;
		case 2:
		{
			
		}
		break;
	}
}

void BaseBlockObject::update(const Ogre::FrameEvent& evt)
{
	hkVector4 p(0,0,0);
	p = m_body->getPosition();
	Vector3 pos = Vector3(p(0),p(1),p(2));
	m_node->setPosition(pos);

	hkQuaternion q; 
	q = hkQuaternion(m_body->getRotation());
	angleRot = q.getAngle();

	hkVector4 axis = hkVector4(0,0,0);
	if(q.hasValidAxis())
		q.getAxis(axis); 

	axisRot=Ogre::Vector3(axis(0),axis(1),axis(2));
	newOgRot=Ogre::Quaternion(angleRot,axisRot);

	m_node->setOrientation(newOgRot);
}

BaseGameEntity::ENTITYTYPE BaseBlockObject::getEntityType()
{
	return m_entitytype;
}