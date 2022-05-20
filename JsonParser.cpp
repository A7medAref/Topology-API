#include "JsonParser.h"
json JsonParser:: read(string fileName)
{
    ifstream file(fileName);
    json topologyData = json::parse(file);
    return topologyData;
}
void JsonParser::store(json jsonData, topology* newTopology)
{
    newTopology->setID(jsonData["id"]);
    string type, id, valueName;
    double DEFAULT, MIN, MAX;
    for (auto comp : jsonData["components"])
    {
        map<string, string> netlist;
        type = comp["type"];
        id = comp["id"];
        if (type == "resistor")
            valueName = "resistance";
        else if (type.find("mos"))
            valueName = "m(l)";
        for (auto it : comp["netlist"].items())
            netlist[it.key()] = it.value();
        MIN = (double)comp[valueName]["min"];
        MAX = (double)comp[valueName]["max"];
        DEFAULT = (double)comp[valueName]["default"];
        newTopology->insertComponent(id, type, DEFAULT, MIN, MAX, netlist);
    }
}
void JsonParser::write(topology* targetTopology, string fileName)
{
    ofstream file(fileName);
    json jsonFile;
    jsonFile["id"] = targetTopology->getID();
    string valuesName;
    for (component* comp : targetTopology->getComponents())
    {
        json jsonTopologyComp;
        jsonTopologyComp["id"] = comp->getID();
        jsonTopologyComp["type"] = comp->getType();
        if (comp->getType() == "resistor")
            valuesName = "resistance";
        else if (comp->getType() == "nmos")
            valuesName = "m(l)";
        jsonTopologyComp[valuesName]["default"] = comp->getDefault();
        jsonTopologyComp[valuesName]["min"] = comp->getMin();
        jsonTopologyComp[valuesName]["max"] = comp->getMax();
        for (auto net : comp->getNetlist())
            jsonTopologyComp["netlist"][net.first] = net.second;
        jsonFile["components"].push_back(jsonTopologyComp);
    }
    file << jsonFile;
}
