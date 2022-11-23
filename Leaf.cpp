
#include "Leaf.h"
#include <algorithm>

Leaf::Leaf(const vector<string> &serverType, int storage, int database) : serverType(serverType),
                                                                          storage(storage),
                                                                          database(database) {}

void Leaf::getInformation() {
    cout << "| ";
    for (int i = 0; i < serverType.size(); ++i) {
    cout << serverType[i] << " | ";
    }
    cout << endl;
    cout << "Saugyklos talpa: " << storage << "TB" << endl;
    cout << "Duomenu bazes talpa: " << database << "GB" << endl;
}

void Leaf::clearUserPlan(Leaf *m_Server) {
    m_Server->database += this->database;
    m_Server->storage += this->storage;
    m_Server->serverType.insert(m_Server->serverType.end(),this->serverType.begin(), this->serverType.end());
    this->storage = 0;
    this->database = 0;
    this->serverType.clear();
}

int Leaf::getCapacity() {
    if(this->database != 0 || this->storage != 0 || this->serverType.empty() == 0) {
    return 1;
    }else {return 0;}
}


int Leaf::getStorageAvailability(int in) {
    if((this->storage - in) >= 0) {
        return true;
    }else {
        return false;
    }
}

int Leaf::getDataAvailability(int in) {
    if((this->storage - in) >= 0) {
        return true;
    }else {
        return false;
    }
}

void Leaf::assignServerType(int in, Leaf *m_Server) {
    if(!this->serverType.empty()) {
            m_Server->serverType.emplace_back(this->serverType[0]);
    }

    this->serverType.clear();

    switch(in) {
        case 1:
            this->serverType.emplace_back(string("Basic"));
            m_Server->serverType.erase(find(m_Server->serverType.begin(), m_Server->serverType.end(), this->serverType[0]));
            break;

        case 2:
            this->serverType.emplace_back(string("Middle"));
            m_Server->serverType.erase(find(m_Server->serverType.begin(), m_Server->serverType.end(), this->serverType[0]));
            break;
        case 3:
            this->serverType.emplace_back(string("Max"));
            m_Server->serverType.erase(find(m_Server->serverType.begin(), m_Server->serverType.end(), this->serverType[0]));
            break;
        default: break;
    }
        cout << endl;
}

void Leaf::assignStorage(int in, Leaf *m_Server) {
    if(m_Server->getStorageAvailability(in) == true) {
        m_Server->storage -= in;
        this->storage = in;
        } else {
            cout << "not enough resources available" << endl;
        }
}

void Leaf::assignDatabase(int in, Leaf *m_Server) {
    if(m_Server->getDataAvailability(in) == true) {
        m_Server->database -= in;
        this->database = in;
    } else {
        cout << "not enough resources available" << endl;
    }
}