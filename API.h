#pragma once
#include "JsonParser.h"
class API
{
private:
    JsonParser JP;
    vector<topology*> topologies;

public:
    bool readJson(string fileName);
    bool writeJson(string topologyID, string fileName);
    vector<topology*> queryTopology();
    bool deleteTopology(string TopologyID);
    vector<component*> queryDevices(string topologyID);
    vector<component*> queryDevicesWithNetlistNode(string topologyID, string NetlistNode);
};