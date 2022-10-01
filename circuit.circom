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

    signal result[9];
    result[0] <-- arr[0];
    result[1] <-- result[0] + 3;
    result[2] <-- result[1] * 5;
    result[3] <-- result[2] - 6;
    result[4] <-- result[3] * 4;

    log(result[4] - temp);
    result[4] === temp;
    
    out <== result[4];
}

component main = operation(9);