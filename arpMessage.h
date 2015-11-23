#ifndef ARPMESSAGE_H
#define ARPMESSAGE_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iostream>

using namespace std;


class arpMessage{
	
	public:
		arpMessage(int, int, int, int, int, string, string, string, string);
		int getHardwareType();
		int getProtocolType();
		int getHardwareAddressLength();
		int getProtocolAddressLength();
		int getOpCode();
		string getSenderHardwareAddress();
		string getSenderProtocolAddress();
		string getTargetHardwareAddress();
		string getTargetProtocolAddress();
		void print();


	private:
		int hardwareType;
		int protocolType;
		int hardwareAddressLength;
		int protocolAddressLength;
		int opCode;
		string senderHardwareAddress;
		string senderProtocolAddress;
		string targetHardwareAddress;
		string targetprotocolAddress;
};

#include "arpMessage.cpp"

#endif