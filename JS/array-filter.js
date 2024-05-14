/*
The filter() method creates a new array with array elements that pass a test.

This example creates a new array from elements with a value larger than 18:
*/

const numbers = [45, 4, 9, 16, 25];

const over18 = numbers.filter(myFunction)

function myFunction(value, index, array){
    if (value>18)
        return value;
}

console.log(over18);