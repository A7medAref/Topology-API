#include "topology.h"
void topology:: setID(string ID)
{
    id = ID;
}
string topology::getID()
{
    return id;
}
component* topology::insertComponent(string& ID, string& TYPE, double& DEFAULT, double& MIN, double& MAX, map<string, string>& NETLIST)
{
    component* newComponent;
    if (TYPE == "resistor")
        newComponent = new resistor(ID, TYPE, DEFAULT, MIN, MAX, NETLIST);
    else
        newComponent = new mosfet(ID, TYPE, DEFAULT, MIN, MAX, NETLIST);
    components.push_back(newComponent);
    return newComponent;
}
vector<component*> topology::getComponents()
{
    return components;
}
vector<component*> topology::getComponentsWithNetlistId(string Node)
{
    vector<component*> collectedComponents;
    for (component* comp : components)
        if (comp->hasNetlistNode(Node))
            collectedComponents.push_back(comp);
    return collectedComponents;
}
bool topology::hasThatId(string ID)
{
    return id == ID;
}
topology::~topology()
{
    for (component* comp : components)
        delete comp;
    components.clear();
}