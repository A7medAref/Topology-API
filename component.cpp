#include "component.h"

void component:: setData(string& ID, string& TYPE, double& DEFAULT_VAL, double& MIN_VAL, double& MAX_VAL, map<string, string>& NETLIST)
{
    device::setData(ID, TYPE, DEFAULT_VAL, MIN_VAL, MAX_VAL);
    netlist = NETLIST;
}
void component:: print()
{
    device::print();
    for (auto it : netlist)
        cout << '"' << it.first << "\" : \"" << it.second << "\"\n";
    cout << "}";
}
bool component:: hasNetlistNode(string targetNode)
{
    for (auto node : netlist)
        if (node.second == targetNode)
            return true;
    return false;
}
map<string, string> component::getNetlist()
{
    return netlist;
}
