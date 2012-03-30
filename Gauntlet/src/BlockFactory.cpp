#include "BlockFactory.h"

BlockFactory* BlockFactory::m_instance = 0;

BlockFactory* BlockFactory::instance()
{
	if(!m_instance)
	{
		m_instance = new BlockFactory();
	}
	return m_instance;
}

BlockFactory::BlockFactory()
{

}

BlockFactory::~BlockFactory()
{

}

BaseBlockObject* BlockFactory::createBlock(BaseBlockObject::BLOCKTYPE type, float size, hkVector4& pos, SceneManager* sceneMgr)
{
  	return new BaseBlockObject(type, size, pos, sceneMgr);
}

BaseBlockObject* BlockFactory::createBlock(BaseBlockObject::BLOCKTYPE type, float sizeX, float sizeY, float sizeZ, hkVector4& pos, SceneManager* sceneMgr)
{
  	return new BaseBlockObject(type, sizeX, sizeY, sizeZ, pos, sceneMgr);
}
