
// converting to decimal to binary..

function dectoBin(dec){
    // getting unsigned value format of the dec string...
    return (dec>>>0).toString(2);
}

console.log("binary form of 10: ", dectoBin(10));
console.log("binary form of -15: ", dectoBin(-15));

// converting to binary to decimal..

function bintoDec(bin){
    // checking the msb for getting sure about the sign.
    let value = 1; // initially assume positive..
    if (bin[0] == 1){
        value = -1; // if msb is 1 then negative number..
    }

    bin = parseInt(bin,2);

    if (value == -1){
        bin = ~bin;
        const add = parseInt("1", 2);

        bin = bin + add;
        bin = bin.toString(2);
    }


    bin = parseInt(bin, 2);

    if(value == -1){
        bin = value*bin;
    }

    return bin
}

console.log("decimal form of 1010: ", bintoDec("1010"));
console.log("decimal form of 11111111111111111111111111110001: ", bintoDec("11111111111111111111111111110001"));
