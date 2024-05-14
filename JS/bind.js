/*
 * Function Borrowing
 * With the bind() method, an object can borrow a method from another object.
*/

const person = {
    firstName : "Musthak",
    lastName : "Ahamed",
    fullName : function()
    {
        return this.firstName + " " + this.lastName;
    }
}

const member = {
    firstName : "Yasith",
    lastName : "Ahamed"
}

let FullName = person.fullName.bind(member);

console.log(FullName());