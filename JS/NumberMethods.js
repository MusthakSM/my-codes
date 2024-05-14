
// getting max and min integers in number type..
console.log(Number.MAX_SAFE_INTEGER);
console.log(Number.MIN_SAFE_INTEGER);

let x = 10;
let y = 10.5;

console.log(Number.isInteger(x));
console.log(Number.isInteger(y));

var z = 9007199254740991;
console.log(Number.isSafeInteger(z));
var z = 9007199254740992;
console.log(Number.isSafeInteger(z));
