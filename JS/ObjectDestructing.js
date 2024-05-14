const vehicleOne = {
    brand: 'Ford',
    model: 'Mustang',
    type: 'car',
    year: 2021, 
    color: 'red',
    registration: {
      city: 'Houston',
      state: 'Texas',
      country: 'USA'
    }
  }

const msg = myVehicle(vehicleOne);
console.log(msg);

function myVehicle({brand, model, year, registration:{state}}){

    const message = "brand is " + brand + ". Model is " + model + ". Year is " + year + 
    ". registered state is " + state;
    return message;
}