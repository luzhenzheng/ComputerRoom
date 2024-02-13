#pragma once
#include<string>
using namespace std;
class ComputerRoom
{
public:
	ComputerRoom(string id, string capacity) :m_id(id), m_capacity(capacity) {}
	string m_id;
	string m_capacity;
};

