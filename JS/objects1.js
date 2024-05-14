
// creating a simple person object..

const person = {
    FirstName: "Musthak",
    LastName: "Ahamed",
    Age: 24,
    FullName: function(){
        return this.FirstName + " " + this.LastName;
    }

};

console.log(person);
console.log(person.Age);
console.log(person.FullName());