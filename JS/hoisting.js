
// Hoisting: behavior of moving declarations to the top..
// variables can be used before they have been declared

/*
 * Hoisting is JavaScript's default behavior of moving all declarations 
   to the top of the current scope (to the top of the current script or the current function).
*/

num = 100;
console.log(num);
var num;  // declaration is done here..


/*
    can't do above to let and const,... Their declarations will be hoisted to the top.
    But they will not be initialized at that point., they will be in a TDZ, temporal dead zone..
    The variable is in a "temporal dead zone" from the start of the block until it is declared:
*/