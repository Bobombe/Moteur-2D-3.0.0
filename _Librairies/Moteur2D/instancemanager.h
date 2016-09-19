#ifndef INSTANCEMANAGER_H
#define INSTANCEMANAGER_H


class InstanceManager
{
    public:
        static InstanceManager * getInstance();
    protected:
        InstanceManager();
        virtual ~InstanceManager();
        static InstanceManager * m_iMng;
    private:
};

#endif // INSTANCEMANAGER_H
