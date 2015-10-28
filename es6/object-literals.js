var name = "object name";

var obj = {
  // shorthand for name:name
  name,
  // methods
  toString() {
    // super call
    return this.name + super.toString();
  },
  // computed dynamic property names
  [ 'prop_' + (() => 42)() ]: 42,
  ['thank']: 'you',
}
console.log(obj.toString());
console.log(obj.prop_42);
console.log(obj.thank);
