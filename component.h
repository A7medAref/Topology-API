#pragma once
#ifndef H_COMPONENT
#define H_COMPONENT

#include <iostream>
#include "device.h"
#include <map>
using namespace std;
class component : public device
{
protected:
    map<string, string> netlist;

public:
    void setData(string& ID, string& TYPE, double& DEFAULT_VAL, double& MIN_VAL, double& MAX_VAL, map<string, string>& NETLIST);
    virtual void printSpecialData() = 0;
    void print();
    bool hasNetlistNode(string targetNode);
    map<string, string> getNetlist();
};
#endif;

