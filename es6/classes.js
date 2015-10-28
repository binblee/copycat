"use strict";

class Person {
  constructor(name){
    this._name = name;
  }
  sayHello(){
    console.log(`I'm ${this._name}`);
    console.log(`I'm ${this.getName()}`);
  }
  getName(){
    return this._name;
  }
}

class Student extends Person {
  sayHello(){
    console.log(`I'm ${this.getName()} and I'm a student`);
  }
}

var p = new Person("David");
p.sayHello();

p = new Student("Mary");
p.sayHello();
