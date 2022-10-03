template operation(k){
    
    signal input arr[k];
    signal output out;
    var temp = (((arr[0] + 3) * 5) -6) * 4; 
    
    /*
    TODO: 
    complete this function, and return the correct result to pass the assert in operation.
    */
    // signal result; <-- arr[0];
    // var temp_op = arr[1];

    // for(var i = 2; i < k; i++){

    //     if(i % 2){
    //         // now element is operation

    //         if(arr[i] == 147){
    //             temp_op = 147;
    //         }
    //         else if(arr[i] == 148){
    //             temp_op = 148;
    //         }
    //         else if(arr[i] == 149){
    //             temp_op = 149;
    //         }
    //     }
    //     else{
    //         // now element is value

    //         if(temp_op == 147){
    //             result <-- result + arr[i];
    //         }
    //         else if(temp_op == 148){
    //             result <-- result - arr[i];
    //         }
    //         else if(temp_op == 149){
    //             result <-- result * arr[i];
    //         }
    //     }
    // }
   
    // log(result - temp);
    // result === temp;

    // /* ----------------------------------------------- */

    signal result[k];
    result[0] <-- arr[0];
    result[1] <-- result[0] + arr[2];
    result[2] <-- result[1] * arr[4];
    result[3] <-- result[2] - arr[6];
    result[4] <-- result[3] * arr[8];

    log(result[4] - temp);
    assert(result[4] - temp);
    result[4] === temp;
    
    out <== result[4];
}

component main = operation(9);

/*
$ circom circuit.circom  --r1cs --wasm --sym --c -o circuit.json
$ (optional) node generate_circuit_input.js
$ (optional) snarkjs powersoftau prepare phase2 pot12_0001.ptau pot12_final.ptau -v
$ snarkjs plonk setup circuit.r1cs pot12_final.ptau circuit_final.zkey
$ snarkjs zkey export verificationkey circuit_final.zkey verification_key.json
$ snarkjs wtns calculate circuit.wasm input.json witness.wtns
$ snarkjs plonk prove circuit_final.zkey witness.wtns proof.json public.json
$ snarkjs plonk verify verification_key.json public.json proof.json
$ snarkjs zkey export solidityverifier circuit_final.zkey verifier.sol
$ snarkjs zkey export soliditycalldata public.json proof.json
*/

/*
0x108e29f6d97ad180f4940221cb2ef402167f8230f10cfc6e5e228d7d758a02e3004238f22ab3a157f387707ec5a1d92deafc4f63957be1631357825336833ecc2432fd8ce237168ad0fdc1cf7c9179e968ff302278c4b67ace7bee0fe40755ce1347b4861a09db1c90213e4f3073d5f9aa2de8466f2f84dd06c07c6773eba9a823644fee1c2ff9f3a7c2215f3e36a639f6d4d24f88d58af9bb322066988d9a80073e3e04aa77dd715ece9655a21c10c49d86cf405b50d66bf3991eea7a45c1dd20ba0526e8d4754546ee1a7d6ccf218bdc0f658766303c74097d5a729043bbc51c5e97675fb0f594b194b2d2f20eea4bc074cec4da622768829b8e19aa9a05f929d641dba6e4154b74de72d741ab04521161e888587bacca17cdb1b173db93a828a0146bde2b9a073494848b7581d9784674659824fae4088895b304f266f51f12e09bcece23b3cb17d63af6c119cbaa889ad647c9289c2d8ce2e02323f9c88b1ad815b940bf42c1e235ac4f3d1ed941325870ee67331d8cbb7a9599d4a236b50a3d701993634f7eebc99e90085615505adddd5825c15706612fe1d25e78c1420ead1a900482fbf6af8488b1fb874eb0cd12efd677868ace7a70ee84467896cc1f781183a0d671ade60aa5c9488fdf61214ec9c66785fb6ff918878edf35d45f13d38933ecfb0cc2252f899106c9f55bed38b2f938529b0cbbd5befe0d70c33e235c9ec0696f83cd9f1a35e5823d0c12ae48ee728ab9802e97ae13fc46d14cb31b1b16912b03aebbcb1b45943e98e22a5a92b6685ed0b9129cc0aac628f1bf3c094bb937735e666eb52a7e78d27748aae9f0cedb1fd98bd47d829dfda26f8f0a1608a9a8413c45e79a6e395b587012e788505f82a96555e66f2053fd3f762c79232798d298a85eba8fc51ca07be6e12d9af97f6187cf5dbf303f4ee5c74630e41770b037620325d8fb93034c9a6f23e17e269f4e004b4438e8c3e942c8a293a50a71c6c6ab75f10eb3a23a9ca0f991010748e8e69ba034d064513a583d56d05923eed76e7d6939e5ede1ffa16dd10fb8eb4cfcc58b816822ed77c0b559335c0227dea2cb304822518725debbe77e3329a6a2aab914b6132e5a8f5fa185257f63,["0x00000000000000000000000e13b96f5abda2eb75c428dc62c2d0b73d70f66294","0x000000000000000000000000b42fabf7bcae8bc5e368716b568a6f8fdf3f84ec","0x0000000000000000000000000000000000000000000000000000000000000093","0x0000000000000000000000000000000000000000000000000000000000000003","0x0000000000000000000000000000000000000000000000000000000000000095","0x0000000000000000000000000000000000000000000000000000000000000005","0x0000000000000000000000000000000000000000000000000000000000000094","0x0000000000000000000000000000000000000000000000000000000000000006","0x0000000000000000000000000000000000000000000000000000000000000095","0x0000000000000000000000000000000000000000000000000000000000000004"]
*/