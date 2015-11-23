#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <unistd.h>
#include "arpMessage.h"

using namespace std;


void arpTable::addItem(int time_sent, string ip, string mac){
	cout << "ARP: Adding item to table..." << endl << endl;
	usleep(1000000);
	pair<int, pair<string, string> > insert;
	insert.first = time_sent;
	insert.second.first = ip;
	insert.second.second = mac;

	//if arpTable is Empty
	if(data.size() == 0){
		data.push_back(insert);
		return;
	}

	//if ip is already in table overwrite mac, used by hackers generally.
	for(int x=0; x<data.size(); x++){
		if(data[x].second.first == ip){
			data[x].second.second = mac;
			return;
		}
	}

	data.push_back(insert);
	return;
}

void arpTable::tick(){
	arpMessage* ptr;
	//reduce the time on each pair, remove if == 0
	for(int x=0; x<data.size(); x++){
		data[x].first -= 1;
		if(data[x].first == 0){
			data.erase(data.begin()+x);
			x=0;
		}
	}
	//the hacker is going to poison the table during the tick	
	for(int x=0; x<deviceList.size(); x++){
		ptr = deviceList[x].poison();
		usleep(1000000);
		if(ptr != NULL) {
			addItem(4, ptr->getSenderProtocolAddress(), 
						ptr->getSenderHardwareAddress());
		}
	}

}

void arpTable::printTable(){
	cout << "ARP: Addreess Routing Protocol Table" << endl;
	for(int x=0; x<data.size(); x++){
		cout << "	" << data[x].first << "	" << data[x].second.first 
			 << "	" << data[x].second.second << endl;
	}
	cout << endl;
	usleep(1000000);
}

bool arpTable::checkTable(string protocol){	
	cout << "ARP: Checking ARP Table for " << protocol << "..." << endl << endl;
	for(int x=0; x<data.size(); x++){
		if(data[x].second.first == protocol){
			cout << "ARP: Protocol found in ARP Table!" << endl << endl;
			return true;
		}
	}
	cout << "ARP: Protocol not found in ARP Table!" << endl << endl;
	return false;
}

string arpTable::getHardwareAddress(string protocol){
	for(int x=0; x<data.size(); x++){
		if(data[x].second.first == protocol){
			return data[x].second.second;
		}
	}	
}

void arpTable::sendRequest(string protocol){
	cout << "ARP: Creating ARP Message for request...";
	usleep(1000000);
	arpMessage* ptr;
	arpMessage newMessage(1, 2048, 6, 4, 1, "FF:FF:FF:FF", 
						"255.255.255.255", " ", protocol);
	usleep(1000000);
	cout << "ARP: Now asking all of the devices..." << endl;
	for(int x=0; x<deviceList.size(); x++){
		ptr = deviceList[x].handleMessage(newMessage);
		usleep(1000000);
		if(ptr != NULL) {
			addItem(4, ptr->getSenderProtocolAddress(), 
						ptr->getSenderHardwareAddress());
			return;
		}
	}
	usleep(1000000);

}
