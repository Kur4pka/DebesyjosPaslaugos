
#ifndef CLOUDSERVICE_COMPOSITE_H
#define CLOUDSERVICE_COMPOSITE_H

#include "Component.h"
#include <iostream>
#include <vector>

using namespace std;

class Composite : public virtual Component {
public:
    explicit Composite(string name);

    void getInformation() override;
    int getCapacity() override;
    void addComponent(Component *component);
private:
    string name;
    vector<Component*> components;
};


#endif //CLOUDSERVICE_COMPOSITE_H
