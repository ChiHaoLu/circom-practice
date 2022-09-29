template operation(k){
    
    signal input arr[k];
    signal output out;
    var result = arr[0];
    var temp_op = arr[1];

    /*
    TODO: 
    complete this function, and return the correct result to pass the assert in operation.
    */

    /*
    for(var i = 2; i < k; i++){
        if(i % 2){
            // now element is value
            if(temp_op == 147){
                result = result + arr[i];
            }
            else if(temp_op == 148){
                result = result - arr[i];
            }
            else if(temp_op == 149){
                result = result * arr[i];
            }
        }
        else{
            // now element is operation
            if(arr[i] == 147){
                temp_op = 147;
            }
            else if(arr[i] == 148){
                temp_op = 148;
            }
            else if(arr[i] == 149){
                temp_op = 149;
            }
        }
    }
    */

    /* ----------------------------------------------- */

    // assert(result == ((arr[0] + 3) * 5 - 6) * 4);
    out <== result;
}

component main = operation(9);

/* Wait for revising...

1. Compile:
$ circom circuit.circom  --r1cs --wasm --sym --c -o circuit.json

2. Genearate input file:
$ node generate_circuit_input.js

3. Trusted setup to get two keys:
$ snarkjs setup -c circuit.json

4. Calculate the witness:
$ snarkjs calculatewitness -c circuit.json -i input.json

5. Generate the proof to get proof and public_info
$ snarkjs proof -w witness.json --pk proving_key.json

6. Verify the proof 
$ snarkjs verify

7. Generate the solidity verifier
$ snarkjs generateverifier
*/