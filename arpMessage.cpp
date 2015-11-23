#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

arpMessage::arpMessage(int sent_hardwareType,
					   int sent_protocolType,
					   int sent_hardwareAddressLength,
					   int sent_protocolAddressLength,
					   int sent_opCode,
					   string sent_senderHardwareAddress,
					   string sent_senderProtocolAddress,
					   string sent_targetHardwareAddress,
					   string sent_targetProtocolAddress){
					   
	hardwareType = sent_hardwareType;
	protocolType = sent_protocolType;
	hardwareAddressLength = sent_hardwareAddressLength;
	protocolAddressLength = sent_protocolAddressLength;
	opCode = sent_opCode;
	senderHardwareAddress = sent_senderHardwareAddress;
	senderProtocolAddress = sent_senderProtocolAddress;
	targetHardwareAddress = sent_targetHardwareAddress;
	targetprotocolAddress = sent_targetProtocolAddress;

	cout << endl << "Created the following message:" << endl << endl;
	print();
}


int arpMessage::getHardwareType(){
	return hardwareType;
}

int arpMessage::getProtocolType(){
	return protocolType;
}

int arpMessage::getHardwareAddressLength(){
	return hardwareAddressLength;
}

int arpMessage::getProtocolAddressLength(){
	return protocolAddressLength;
}

int arpMessage::getOpCode(){
	return opCode;
}

string arpMessage::getSenderHardwareAddress(){
	return senderHardwareAddress;
}

string arpMessage::getSenderProtocolAddress(){
	return senderProtocolAddress;
}

string arpMessage::getTargetHardwareAddress(){
	return targetHardwareAddress;
}

string arpMessage::getTargetProtocolAddress(){
	return targetprotocolAddress;
}

void arpMessage::print(){
	cout << "Address Resolution Protocol Message" << endl;
	cout << "	Hardware Type: " << getHardwareType() << endl;
	cout << "	Protocol Type: " << getProtocolType() << endl;
	cout << "	Hardware Address Length: " << getHardwareAddressLength() << endl;
	cout << "	Protocol Address Length: " << getProtocolAddressLength() << endl;
	cout << "	Operation Code: " << getOpCode() << endl;
	cout << "	Sender Hardware Address: " << getSenderHardwareAddress() << endl;
	cout << "	Sender Protocol Address: " << getSenderProtocolAddress() << endl;
	cout << "	Target Hardware Address: " << getTargetHardwareAddress() << endl;
	cout << "	Target Protocol Address: " << getTargetProtocolAddress() << endl;
	cout << endl << endl;
}

		
	
