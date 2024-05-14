
function greet(){
    console.log("Hello " + this.name);
}


const person = {name: "Musthak"};
person.greet = greet;

person.greet();
