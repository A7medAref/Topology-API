#pragma once
#include "component.h"
class resistor : public component
{
    string t1, t2;

public:
    resistor(string& ID, string& TYPE, double& DEFAULT, double& MIN, double& MAX, map<string, string>& NETLIST);
    void printSpecialData();
};
