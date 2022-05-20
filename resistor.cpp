#include "resistor.h"
resistor::resistor(string& ID, string& TYPE, double& DEFAULT, double& MIN, double& MAX, map<string, string>& NETLIST)
{
    setData(ID, TYPE, DEFAULT, MIN, MAX, NETLIST);
}
void resistor::printSpecialData()
{
    cout << "2 edges device\n";
}