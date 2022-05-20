#include "mosfet.h"
mosfet::mosfet(string ID, string TYPE, double DEFAULT, double MIN, double MAX, map<string, string> NETLIST)
{
    setData(ID, TYPE, DEFAULT, MIN, MAX, NETLIST);
};
void mosfet ::printSpecialData()
{
    cout << "3 edges device\n";
}