#include "testingAPI.h"
bool testingAPI::testing_function1()
{
	API apiObject;
	bool success = 1;
	cout << "testing function 1 is running...\n";
	try {
		//valid reading
		if(!apiObject.readJson("testingTopology.json"))
			throw exception();
		cout << "test 1 passed\n";
	}
	catch (exception&)
	{
		cout << "Error in test case 1\n";
		success = 0;
	}
	try {
		//invalid reading format
		if (apiObject.readJson("not a valid name"))
			throw exception();
		cout << "test 2 passed\n";
	}
	catch (exception&)
	{
		cout << "Error in test case 2\n";
		success = 0;
	}
	try {
		//invalid reading format
		if(apiObject.readJson("notExist.json"))
			throw exception();
		cout << "test 3 passed\n";
	}
	catch (exception&)
	{
		cout << "Error in test case 3\n";
		success = 0;
	}
	if(success)
		return 1;
	return 0;
}
bool testingAPI::testing_function2()
{
	API apiObject;
	bool success = 1;
	cout << "testing function 2 is running...\n";
	try {
		// topologyID doesn't exist
		if (apiObject.writeJson("notExist", "testingTopology.json"))
			throw exception();
		cout << "test 1 passed\n";
	}
	catch (exception&)
	{
		cout << "Error in test case 1\n";
		success = 0;
	}
	try {
		// read to store some data
		apiObject.readJson("testingTopology.json");
		// topologyID exist
		if (!apiObject.writeJson("top1", "testingTopology.json"))
			throw exception();
		cout << "test 2 passed\n";
	}
	catch (exception&)
	{
		cout << "Error in test case 2\n";
		success = 0;
	}
	if (success)
		return 1;
	return 0;
}

bool testingAPI::testing_function3()
{
	API apiObject;
	bool success = 1;
	cout << "testing function 3 is running...\n";
	try {
		if(apiObject.queryTopology().size() != 0)
			throw exception();
		cout << "test 1 passed\n";

	}
	catch (exception&)
	{
		cout << "Error in test case 1\n";
		success = 0;
	}
	try {
		apiObject.readJson("testingTopology.json");
		if (apiObject.queryTopology().size() == 0)
			throw exception();
		cout << "test 2 passed\n";
	}
	catch (exception&)
	{
		cout << "Error in test case 2\n";
		success = 0;
	}

	if (success)
		return 1;
	return 0;
}

bool testingAPI::testing_function4()
{
	API apiObject;
	bool success = 1;
	cout << "testing function 4 is running...\n";
	try {
		if (apiObject.deleteTopology("idDoesntExist") != 0)
			throw exception();
		cout << "test 1 passed\n";
	}
	catch (exception&)
	{
		cout << "Error in test case 1\n";
		success = 0;
	}
	try {
		apiObject.readJson("testingTopology.json");
		topology* topologies =  apiObject.queryTopology()[0];
		if (apiObject.deleteTopology(topologies->getID()) == 0)
			throw exception();
		cout << "test 2 passed\n";
	}
	catch (exception&)
	{
		cout << "Error in test case 2\n";
		success = 0;
	}

	if (success)
		return 1;
	return 0;
}

bool testingAPI::testing_function5()
{
	API apiObject;
	bool success = 1;
	cout << "testing function 5 is running...\n";
	try {
		if (apiObject.queryDevices("idDoesntExist").size() != 0)
			throw exception();
		cout << "test 1 passed\n";
	}
	catch (exception&)
	{
		cout << "Error in test case 1\n";
		success = 0;
	}
	try {
		apiObject.readJson("testingTopology.json");
		topology* topologies = apiObject.queryTopology()[0];
		if (apiObject.queryDevices(topologies->getID()).size() != topologies->getComponents().size())
			throw exception();
		cout << "test 2 passed\n";
	}
	catch (exception&)
	{
		cout << "Error in test case 2\n";
		success = 0;
	}

	if (success)
		return 1;
	return 0;
}

bool testingAPI::testing_function6()
{
	API apiObject;
	bool success = 1;
	cout << "testing function 6 is running...\n";
	try {
		if (apiObject.queryDevicesWithNetlistNode("doesntExistTopology","doesntExistNode").size() != 0)
			throw exception();
		cout << "test 1 passed\n";
	}
	catch (exception&)
	{
		cout << "Error in test case 1\n";
		success = 0;
	}
	try {
		apiObject.readJson("testingTopology.json");
		topology* currentTopology= apiObject.queryTopology()[0];
		string netlistValue = "";
		for (auto it : currentTopology->getComponents()[0]->getNetlist())
		{
			netlistValue = it.second;
			break;
		}
		try {
			if (apiObject.queryDevicesWithNetlistNode("doesntExistTopology",netlistValue).size() != 0)
				throw exception();
			cout << "test 2 passed\n";
		}
		catch (exception&)
		{
			cout << "Error in test case 2\n";
			success = 0;
		}
		try {
			if (apiObject.queryDevicesWithNetlistNode(currentTopology->getID(), netlistValue).size() == 0)
				throw exception();
			cout << "test 3 passed\n";
		}
		catch (exception&)
		{
			cout << "Error in test case 3\n";
			success = 0;
		}
	}
	catch (exception&)
	{
		cout << "Error in test case 2\n";
		cout << "Error in test case 3\n";
		success = 0;
	}
	if (success)
		return 1;
	return 0;
}
