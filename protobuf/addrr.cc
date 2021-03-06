#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"
using namespace std;

void ListPeople(const tutorial::AddressBook& address_book){
	for(int i=0; i< address_book.person_size(); i++){
		const tutorial::Person& person = address_book.person(i);

		cout << "Person ID: " << person.id() << endl;
		cout << " - Name: " << person.name() << endl;
		cout << " - Email address: " << person.email() << endl;

		for(int j=0; j<person.phone_size(); j++){
			const tutorial::Person::PhoneNumber& phone_number = person.phone(j);
			switch(phone_number.type()){
				case tutorial::Person::MOBILE:
					cout << " - Mobile phone #: ";
					break;
				case tutorial::Person::HOME:
					cout << " - Home phone #: ";
					break;
				case tutorial::Person::WORK:
					cout << " - Work phone #: ";
					break;
			}
			cout << phone_number.number() << endl;
		}
	}
}

int main(int argc, char* argv[]){
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	tutorial::AddressBook address_book;
	{
		fstream input("addr", ios::in | ios::binary);
		if(!address_book.ParseFromIstream(&input)){
			cerr << "Failed to parse address book." << endl;
			return -1;
		}
	}

	ListPeople(address_book);
	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}

