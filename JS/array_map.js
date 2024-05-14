
/*
The map() method creates a new array by performing a function on each array element.

The map() method does not execute the function for array elements without values.

The map() method does not change the original array
*/
const numbers1 = [45, 4, 9, 16, 25];

const numbers2 = numbers1.map((value) =>{return value*2});

/*
instead of (value) =>{return value*2} this, myFunction can be passed in the map function..
*/
function myFunction(value, index, array){
    return value*2;
}

console.log(numbers2);