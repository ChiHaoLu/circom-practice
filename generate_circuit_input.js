const fs = require("fs");

var address = "<put_your_address_here>"
var ADD = 147;
var SUB = 148;
var MUL = 149;

var arr = [
    address,
    ADD, 3,
    MUL, 5,
    SUB, 6,
    MUL, 4
];

const inputs = {
    "arr": arr,
}

fs.writeFileSync(
    "./input.json",
    JSON.stringify(inputs),
    "utf-8"
);