//http://www.html5rocks.com/en/tutorials/es6/promises/

var promise = new Promise( function(resolve,reject){
  if( false ){
    resolve("It worked.");
  }else{
    reject("Something broken.");
  }
}
);

promise.then((result) => {
    console.log("1st then: " + result);
    return result + "(after 1st then)"
  }).then((result) => {
    console.log("2nd then: " + result);
  }).catch((err) => {
    console.log(err);
  }
);
