#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "topology.h"

using json = nlohmann::json;

class JsonParser
{
public:
    json read(string fileName);
    void store(json jsonData, topology* newTopology);
    void write(topology* targetTopology, string fileName);
};

