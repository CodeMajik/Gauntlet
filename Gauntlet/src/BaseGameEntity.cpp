#include "BaseGameEntity.h"

BaseGameEntity::BaseGameEntity()
{
	m_dmgLvl = 0;
	m_idGen = UniqueIDGenerator::getInstance();
}

BaseGameEntity::ENTITYTYPE BaseGameEntity::getType()
{
	return m_entitytype;
}

BaseGameEntity::BaseGameEntity(ENTITYTYPE type, hkVector4& pos)
{
	m_entitytype = type;
	m_position = pos;
	m_id = m_idGen->getNewID();
	m_dmgLvl = 0;
}

hkpRigidBody* BaseGameEntity::getBody()
{
	return m_body;
}