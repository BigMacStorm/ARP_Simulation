#ifndef ARPTABLE_H
#define ARPTABLE_H

#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class arpTable{

	public:
		void addItem(int time, string ip, string mac);
		void tick();
		void printTable();
		bool checkTable(string protocol);
		string getHardwareAddress(string protocol);
		void sendRequest(string protocol);
		vector<device> deviceList;
	
	private:
		//The arpTable data, first pair is time left
		//and dest, with the dest pair being the
		//ip being mapped to which physical address
		vector<pair<int, pair<string, string> > > data;
};

#include "arpTable.cpp"

#endif