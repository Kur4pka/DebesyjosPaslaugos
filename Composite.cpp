
#include "Composite.h"
#include <utility>

Composite::Composite(std::string name) : name(std::move(name)) {}

int Composite::getCapacity() {
    for (Component *i: components) {
        i->getCapacity();
    }
}

void Composite::getInformation() {
    cout << "-----------------------" << endl;
    cout << "         " << name << endl;
    cout << " -----------------------" << endl;
    for (Component *i : components) {
        i->getInformation();
    }
}

void Composite::addComponent(Component *component) {
    components.emplace_back(component);
}