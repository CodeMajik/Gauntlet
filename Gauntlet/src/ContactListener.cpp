#include "ContactListener.h"

ContactListener* ContactListener::m_instance = 0;

ContactListener* ContactListener::getInstance()
{
	if(!m_instance)
	{
		m_instance = new ContactListener();
	}
	return m_instance;
}