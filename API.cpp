#include "API.h"
bool API::readJson(string fileName)
{
    try {
        topology* newTopology = new topology();
        topologies.push_back(newTopology);
        JP.store(JP.read(fileName), newTopology);
    }
    catch (exception&)
    {
        return 0;
    }
    return 1;
}
bool API::writeJson(string topologyID, string fileName)
{
    topology* targetTopology = NULL;
    for (topology* topo : topologies)
        if (topo->hasThatId(topologyID))
        {
            targetTopology = topo;
            break;
        }
    if (!targetTopology)
        return 0;
    try
    {
        JP.write(targetTopology, fileName);
    }
    catch (const std::exception&)
    {
        return 0;
    }
    
    return 1;
}
vector<topology*> API::queryTopology()
{
    return topologies;
}
bool API::deleteTopology(string TopologyID)
{
    for (int i = 0; i < topologies.size(); i++)
        if (topologies[i]->hasThatId(TopologyID))
        {
            swap(topologies[i], topologies[topologies.size() - 1]);
            topologies.pop_back();
            return 1;
        }
    return 0;
}
vector<component*> API::queryDevices(string topologyID)
{
    for (topology* singleTopology : topologies)
        if (singleTopology->hasThatId(topologyID))
            return singleTopology->getComponents();
    vector<component*> noResult;
    return noResult;
}
vector<component*> API::queryDevicesWithNetlistNode(string topologyID, string NetlistNode)
{
    for (topology* singleTopology : topologies)
        if (singleTopology->hasThatId(topologyID))
        {
            return singleTopology->getComponentsWithNetlistId(NetlistNode);
        }
    vector<component*> noResult;
    return noResult;
}