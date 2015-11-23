#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "arpMessage.h"
#include <unistd.h>

using namespace std;

device::device(bool sent_hacker, 
			   string sent_protocolAddress, 
			   string sent_hardwareAddress,
			   string sent_hackerTarget){

	hacker = sent_hacker;
	protocolAddress = sent_protocolAddress;
	hardwareAddress = sent_hardwareAddress;
	hackerTarget = sent_hackerTarget;

	cout << endl << "Device created :" << endl;
	print();
}

arpMessage* device::handleMessage(arpMessage sent){
	arpMessage* temp;
	if(sent.getTargetProtocolAddress() != protocolAddress){
		cout << "DEVICE: I do not have that protocol!" << endl;
		return NULL;
	}else{
		cout << "DEVICE: I do indeed have that protocol!" << endl;
		cout << "DEVICE: Now creating a arp reply message..." << endl;
		usleep(1000000);
		temp = new arpMessage(sent.getHardwareType(),
							sent.getProtocolType(),
							sent.getHardwareAddressLength(),
							sent.getProtocolAddressLength(),
							2,
							hardwareAddress,
							protocolAddress,
							sent.getSenderHardwareAddress(),
							sent.getSenderProtocolAddress());
		return temp;
	}
}

arpMessage* device::poison(){
	arpMessage* temp;
	if(!hacker){
		return NULL;
	}else{
		cout << "DEVICE: I am going to poison the cache!" << endl;
		cout << "DEVICE: Now creating a fake arp reply message..." << endl;
		usleep(1000000);
		temp = new arpMessage(1, 2048, 6, 4, 2, hardwareAddress, hackerTarget, 
						"FF:FF:FF:FF", "255.255.255.255");
		return temp;
	}
}

bool device::getHacker(){
	return hacker;
}

string device::getProtocolAddress(){
	return protocolAddress;
}

string device::getHardwareAddress(){
	return hardwareAddress;
}

void device::print(){
	string temp = "True";
	if(!hacker) temp = "False";
	cout << "Device" << endl;
	cout << "	Hacker: " << temp << endl;
	cout << "	Protocol Address: " << protocolAddress << endl;
	cout << "	Hardware Address: " << hardwareAddress << endl;
	cout << "	Hacker Target: " << hackerTarget << endl;
	cout << endl;
}

void device::setHackerTarget(string sent){
	hackerTarget = sent;
}

void device::setHacker(){
	hacker = true;
}