#pragma once
#include "component.h"
class mosfet : public component
{
public:
    mosfet(string ID, string TYPE, double DEFAULT, double MIN, double MAX, map<string, string> NETLIST);
    void printSpecialData();
};

