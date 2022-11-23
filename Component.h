
#ifndef CLOUDSERVICE_COMPONENT_H
#define CLOUDSERVICE_COMPONENT_H

class Component {
public:
    virtual void getInformation() = 0;
    virtual int getCapacity() = 0;
};

#endif //CLOUDSERVICE_COMPONENT_H
