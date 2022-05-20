#include "device.h"
void device::setData(string& ID, string& TYPE, double& DEFAULT_VAL, double& MIN_VAL, double& MAX_VAL)
{
    id = ID;
    type = TYPE;
    default_val = DEFAULT_VAL;
    min_val = MIN_VAL;
    max_val = MAX_VAL;
}

void device::print()
{
    cout << "ID = " << id;
    cout << "\nType is " << type;
    cout << "\n(min,default max) = (" << min_val << "," << default_val << "," << max_val << ")\n";
    cout << "netlist {\n";
}

string device::getID()
{
    return id;
}
string device::getType()
{
    return type;
}
double device::getMin()
{
    return min_val;
}
double device::getMax()
{
    return max_val;
}
double device::getDefault()
{
    return default_val;
}

