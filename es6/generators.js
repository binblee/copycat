function *gen(){
  var x = 1 + (yield "foo");
  console.log(x);
}

var it = gen();
var message = it.next(1);
console.log(message);
message = it.next(2);
console.log(message);
message = it.next(3);
console.log(message);

function *foo(){
  yield 3;
  yield 4;
}

function *bar(){
  yield 1;
  yield 2;
  yield *foo();
  yield 5;
}

for (var v of bar()){
  console.log(v);
}
