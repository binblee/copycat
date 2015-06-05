import tutorial.AddressBookProtos.AddressBook;
import tutorial.AddressBookProtos.Person;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintStream;

class ListPeople{
	static void Print(AddressBook addressBook){
		for(Person person : addressBook.getPersonList()){
			System.out.println("Person ID: " + person.getId());
			System.out.println(" - Name: " + person.getName());
			System.out.println(" - Email address: " + person.getEmail());

			for(Person.PhoneNumber phoneNumber : person.getPhoneList()){
				switch(phoneNumber.getType()){
					case MOBILE:
						System.out.print(" - Mobile phone #: ");
						break;
					case HOME:
						System.out.print(" - Home phone #: ");
						break;
					case WORK:
						System.out.print(" - Work phone #: ");
						break;
				}
				System.out.println(phoneNumber.getNumber());
			}
		}
	}

	public static void main(String[] args) throws Exception{
		AddressBook addressBook = AddressBook.parseFrom(new FileInputStream("addr"));
		Print(addressBook);
	}
}

