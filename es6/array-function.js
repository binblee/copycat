// lambda

//  v => ...
function setOffset(offset){
  return v => offset + v;
}
func = setOffset(3);
console.log(func(5));

// use self to ref this in outer scope
var calc1 = {
  inner: 10,
  setOffsetWithInnerVariable: function(offset){
    self = this;
    return function(v1,v2){
      return self.inner + offset + v1 + v2;
    }
  }
}

// no need to use self in array function
var calc2 = {
  inner: 10,
  setOffsetWithInnerVariable: function(offset){
    return (v1,v2) => {
      return this.inner + offset + v1 + v2;
    }
  }
}
func1 = calc1.setOffsetWithInnerVariable(3);
console.log(func1(2,3));
func2 = calc2.setOffsetWithInnerVariable(3);
console.log(func2(2,3));
