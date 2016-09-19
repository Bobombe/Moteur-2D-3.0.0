#include "instancemanager.h"

InstanceManager * InstanceManager::m_iMng = 0;

InstanceManager * InstanceManager::getInstance()
{
    if (m_iMng == 0)
    {
        m_iMng = new InstanceManager();
    }
    return m_iMng;
}

InstanceManager::InstanceManager()
{
    //ctor
}

InstanceManager::~InstanceManager()
{
    //dtor
}
