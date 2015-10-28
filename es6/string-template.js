var message = ['this message is ',
  'constructed using join'
].join('\n')
console.log(message);

var hello = 'world'
console.log("I'm spliter ${hello}");

var newMessage = `this message is
constructed using ES6 template string
and it has a variable in it: ${hello}
`;

console.log(newMessage);
