
#ifndef CLOUDSERVICE_LEAF_H
#define CLOUDSERVICE_LEAF_H
#include "Component.h"
#include <iostream>
#include <vector>

using namespace std;


class Leaf : public virtual Component{
public:
    Leaf(const vector<string> &serverType, int storage, int database);

    void getInformation() override;
    int getCapacity() override;
    virtual int getStorageAvailability(int in);
    virtual int getDataAvailability(int in);
    virtual void clearUserPlan(Leaf *leaf);
    virtual void assignServerType(int in, Leaf *m_Server);
    virtual void assignStorage(int in, Leaf *m_Server);
    virtual void assignDatabase(int in, Leaf *m_Server);

private:

    vector<string> serverType;
    int storage;
    int database;
};


#endif //CLOUDSERVICE_LEAF_H