
.PHONY: all protocompile clean

all: addrw addrr java

protocompile: addressbook.proto
	protoc --cpp_out=. --python_out=. --java_out=. addressbook.proto

addrw: protocompile addrw.cc addressbook.pb.cc addressbook.pb.h
	g++ -o addrw addrw.cc addressbook.pb.cc `pkg-config --cflags --libs protobuf`

addrr: protocompile addrr.cc addressbook.pb.cc addressbook.pb.h
	g++ -o addrr addrr.cc addressbook.pb.cc `pkg-config --cflags --libs protobuf`

java: ListPeople.java tutorial/AddressBookProtos.java
	javac -cp protobuf-java-3.0.0-alpha-4-pre.jar:. ListPeople.java tutorial/AddressBookProtos.java

clean:
	rm -f addr
	rm -f addressbook.pb.h
	rm -f addressbook.pb.cc
	rm -f addrw
	rm -f addrr
	rm -f addressbook_pb2.py
	rm -f *.class
	rm -rf tutorial
