#pragma once
#include "resistor.h"
#include "mosfet.h"
#include <vector>
class topology
{
private:
    vector<component*> components;
    string id;

public:
    void setID(string ID);
    string getID();
    component* insertComponent(string& ID, string& TYPE, double& DEFAULT, double& MIN, double& MAX, map<string, string>& NETLIST);
    vector<component*> getComponents();
    vector<component*> getComponentsWithNetlistId(string Node);
    bool hasThatId(string ID);
    ~topology();
};
