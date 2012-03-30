#ifndef BLOCKMANAGER_H
#define BLOCKMANAGER_H

#include <vector>
#include "BlockFactory.h"
#include "BaseBlockObject.h"
#include "ContactListener.h"

using namespace std;

class BlockManager{
public:
	~BlockManager();
	static BlockManager* instance(hkpWorld* world);
	static BlockManager* instance();
	void init(int numBlocks, SceneManager* sceneMgr);
	void update(const Ogre::FrameEvent& evt);
	void addBlock(BaseBlockObject::BLOCKTYPE type, float size, hkVector4& pos, SceneManager* sceneMgr);
	hkArray<BaseBlockObject*>* m_blocks;
	BlockFactory* getBlockFactory();
	bool restrictMovement;
private:
	BlockManager(hkpWorld* world);
	BlockManager();
	static BlockManager* m_instance;
	hkVector4 position;
	BlockFactory* m_blockFactory;
	hkpWorld* m_worldPtr;
	ContactListener* m_contactListener;
};

#endif