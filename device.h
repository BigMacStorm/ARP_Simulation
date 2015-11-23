#ifndef DEVICE_H
#define DEVICE_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iostream>
#include "arpMessage.h"

using namespace std;


class device{
public:
	device(bool, string, string, string);
	arpMessage* handleMessage(arpMessage);
	arpMessage* poison();
	bool getHacker();
	string getProtocolAddress();
	string getHardwareAddress();
	void print();
	void setHackerTarget(string);
	void setHacker();

private:
	bool hacker;
	string protocolAddress;
	string hardwareAddress;
	string hackerTarget;

};

#include "device.cpp"

#endif