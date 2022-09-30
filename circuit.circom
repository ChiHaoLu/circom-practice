template operation(k){
    
    signal input arr[k];
    signal output out;
    var result = arr[0];
    var temp_op = arr[1];

    /*
    TODO: 
    complete this function, and return the correct result to pass the assert in operation.
    */
    
    for(var i = 2; i < k; i++){
        if(i % 2){
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
        else{
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
    }    

    /* ----------------------------------------------- */

    log(result);
    log(((arr[0] + 3) * 5 - 6) * 4);
    assert(result == ((arr[0] + 3) * 5 - 6) * 4);
    
    out <== result;
}

component main = operation(9);