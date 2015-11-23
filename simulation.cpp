#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "device.h"
#include "arpTable.h"
#include <time.h>
#include <sstream>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//macro taken from stack overflow
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

string randIP(){
	string temp = "";
	for(int x=0; x<3; x++){
		string hold = SSTR(rand()%184+70);
		temp.append(hold);
		temp.append(".");
	}
	string hold = SSTR(rand()%184+70);
	temp.append(hold);
	return temp;
}

string randMAC(){	
	string temp = "";
	for(int x=0; x<3; x++){
		string hold = SSTR(rand()%98+1);
		temp.append(hold);
		temp.append(":");
	}
	string hold = SSTR(rand()%98+1);
	temp.append(hold);
	return temp;
}

using namespace std;

int main(int argc, char *argv[]){
	srand(time(NULL));
	arpTable table;
	//create some random val between 2 and 4
	int amount = rand()%3 + 2;
	int temp;
	bool demoPoison = false;
	if(argc > 1) demoPoison = true;


	cout << endl << endl << "SYS: Simulation starting..." << endl;
	usleep(1000000);
	cout << "SYS: Creating a random amount of devices..." << endl;
	for(int x=0; x<amount; x++){
		device newDevice(false, randIP(), randMAC(), "000.000.000.000");
		table.deviceList.push_back(newDevice);
		usleep(1000000);
	}
	usleep(1000000);

	if(demoPoison){
		cout << "SYS: Adding a hacker to the devices who will send out fake " <<
			"ARP reply messages in order to add false data to the cache" << endl << endl;
		table.deviceList[1].setHacker();
		table.deviceList[1].setHackerTarget(table.deviceList[0].getProtocolAddress());
		table.deviceList[1].print();
		usleep(1000000);
	}


	cout << endl << "SYS: Current ARP table:" << endl;
	table.printTable();
	usleep(1000000);
	while(true){
		cout << endl << "SYS: The simulation is now going to randomly " << 
							"choose a device IP to try and send a " <<
							"message to. The ARP Table will handle " << 
							"all of the neccesary calls and actions" << endl << endl;

		usleep(1000000);
		//randomly chose a device as the target.
		temp = rand()%table.deviceList.size();

		if(!table.checkTable( table.deviceList[temp].getProtocolAddress() )){
			cout << "SYS: Having ARP ask devices who owns this protocol..." << endl << endl;
			usleep(1000000);
			table.sendRequest( table.deviceList[temp].getProtocolAddress() );
		}else{
			cout << "SYS: Protocol found in ARP cache pointing at physical address " << 
					table.getHardwareAddress(table.deviceList[temp].getProtocolAddress()) << endl;
		}

		table.printTable();
		usleep(1000000);
		table.tick();

		cout << "=======================================================" << endl << endl;
	}

	
	return 0;
}