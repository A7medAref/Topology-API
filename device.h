#pragma once
#include <iostream>
using namespace std;
class device
{
protected:
    string id, type;
    double default_val, min_val, max_val;
public:
    void setData(string& ID, string& TYPE, double& DEFAULT_VAL, double& MIN_VAL, double& MAX_VAL);
    string getID();
    string getType();
    void print();
    double getMin();
    double getMax();
    double getDefault();

};
