# Circom & SnarkJS

###### tags: `ZK-Playground`

### Table of Contents
* Intro
* Circom
* Exercise
* Reference

---

## Intro

**circom** 是一個用 Rust 寫成的編譯器，編譯之後會 output 所有建置 ZKP 所需的限制和所需。 

**snarkjs** 是一個 npm package，可以用來產生與驗證 circom 產出的 artifacts（ZKP）。

![](https://i.imgur.com/UCTLITt.png)

Circom Compiler 和它整個生態系的工具可以幫助人們將原本撰寫零知識證明程式時，需要處理多項式與迴路（Circuits）的整個過程包起來，我們就只需要處理程式邏輯就好。

還有其他用來撰寫零知識證明系統的程式語言，例如 Cairo、Zinc、ZoKrates（包含 SNARK / STARK 證明系統）。

### Download Packages
Circom 的編譯器是使用 Rust 撰寫的，因此需要確認自己的電腦裡面有 Rust，MacOS & Linux 可以在終端機直接使用以下指令：
```
$ curl --proto '=https' --tlsv1.2 https://sh.rustup.rs -sSf | sh
```

1. Circom 也支援使用 npm 或 yarn 等套件管理器下載：

```
$ npm install -g circom
$ npm install -g snarkjs
```
2. 另外也可以使用 Cargo 來下載 Circom，細節可見[此處](https://docs.circom.io/getting-started/installation/#installing-circom)
```
$ git clone https://github.com/iden3/circom.git
$ cd circom
$ cargo build --release
$ cargo install --path circom
```

請確認自己的電腦裡面同時有 Circom 以及 SnarkJS 的存在，可以用以下指令確定自己有下載成功：

:::spoiler 1. Circom
```
$ circom --help
>
   Circom Compiler 2.0.0
   IDEN3
   Compiler for the Circom programming language

   USAGE:
      circom [FLAGS] [OPTIONS] [input]

   FLAGS:
      -h, --help       Prints help information
         --inspect    Does an additional check over the constraints produced
         --O0         No simplification is applied
      -c, --c          Compiles the circuit to c
         --json       outputs the constraints in json format
         --r1cs       outputs the constraints in r1cs format
         --sym        outputs witness in sym format
         --wasm       Compiles the circuit to wasm
         --wat        Compiles the circuit to wat
         --O1         Only applies var to var and var to constant simplification
      -V, --version    Prints version information

   OPTIONS:
         --O2 <full_simplification>    Full constraint simplification [default: full]
      -o, --output <output>             Path to the directory where the output will be written [default: .]

   ARGS:
      <input>    Path to a circuit with a main component [default: ./circuit.circom]
```
:::

:::spoiler 2. SnarkJS
```
$ snarkjs
>
snarkjs@0.5.0
        Copyright (C) 2018  0kims association
        This program comes with ABSOLUTELY NO WARRANTY;
        This is free software, and you are welcome to redistribute it
        under certain conditions; see the COPYING file in the official
        repo directory at  https://github.com/iden3/snarkjs 

Usage:
        snarkjs <full command> ...  <options>
   or   snarkjs <shorcut> ...  <options>

Type snarkjs <command> --help to get more information for that command

Full Command                  Description
============                  =================
powersoftau new               Starts a powers of tau ceremony
     Usage:  snarkjs ptn <curve> <power> [powersoftau_0000.ptau]
powersoftau contribute        creates a ptau file with a new contribution
     Usage:  snarkjs ptc <powersoftau.ptau> <new_powersoftau.ptau>
powersoftau export challenge  Creates a challenge
     Usage:  snarkjs ptec <powersoftau_0000.ptau> [challenge]
powersoftau challenge contributeContribute to a challenge
     Usage:  snarkjs ptcc <curve> <challenge> [response]
powersoftau import response   import a response to a ptau file
     Usage:  snarkjs ptir <powersoftau_old.ptau> <response> <<powersoftau_new.ptau>
powersoftau beacon            adds a beacon
     Usage:  snarkjs ptb <old_powersoftau.ptau> <new_powersoftau.ptau> <beaconHash(Hex)> <numIterationsExp>
powersoftau prepare phase2    Prepares phase 2. 
     Usage:  snarkjs pt2 <powersoftau.ptau> <new_powersoftau.ptau>
powersoftau convert           Convert ptau
     Usage:  snarkjs ptcv <old_powersoftau.ptau> <new_powersoftau.ptau>
powersoftau truncate          Generate diferent powers of tau with smoller sizes 
     Usage:  snarkjs ptt <powersoftau.ptau>
powersoftau verify            verifies a powers of tau file
     Usage:  snarkjs ptv <powersoftau.ptau>
powersoftau export json       Exports a power of tau file to a JSON
     Usage:  snarkjs ptej <powersoftau_0000.ptau> <powersoftau_0000.json>
r1cs info                     Print statistiscs of a circuit
     Usage:  snarkjs ri [circuit.r1cs]
r1cs print                    Print the constraints of a circuit
     Usage:  snarkjs rp [circuit.r1cs] [circuit.sym]
r1cs export json              Export r1cs to JSON file
     Usage:  snarkjs rej [circuit.r1cs] [circuit.json]
wtns calculate                Caclculate specific witness of a circuit given an input
     Usage:  snarkjs wc [circuit.wasm] [input.json] [witness.wtns]
wtns debug                    Calculate the witness with debug info.
     Usage:  snarkjs wd [circuit.wasm] [input.json] [witness.wtns] [circuit.sym]
wtns export json              Calculate the witness with debug info.
     Usage:  snarkjs wej [witness.wtns] [witnes.json]
zkey contribute               creates a zkey file with a new contribution
     Usage:  snarkjs zkc <circuit_old.zkey> <circuit_new.zkey>
zkey export bellman           Export a zKey to a MPCParameters file compatible with kobi/phase2 (Bellman)
     Usage:  snarkjs zkeb <circuit_xxxx.zkey> [circuit.mpcparams]
zkey bellman contribute       contributes to a challenge file in bellman format
     Usage:  snarkjs zkbc <curve> <circuit.mpcparams> <circuit_response.mpcparams>
zkey import bellman           Export a zKey to a MPCParameters file compatible with kobi/phase2 (Bellman) 
     Usage:  snarkjs zkib <circuit_old.zkey> <circuit.mpcparams> <circuit_new.zkey>
zkey beacon                   adds a beacon
     Usage:  snarkjs zkb <circuit_old.zkey> <circuit_new.zkey> <beaconHash(Hex)> <numIterationsExp>
zkey verify r1cs              Verify zkey file contributions and verify that matches with the original circuit.r1cs and ptau
     Usage:  snarkjs zkv [circuit.r1cs] [powersoftau.ptau] [circuit_final.zkey]
zkey verify init              Verify zkey file contributions and verify that matches with the original circuit.r1cs and ptau
     Usage:  snarkjs zkvi [circuit_0000.zkey] [powersoftau.ptau] [circuit_final.zkey]
zkey export verificationkey   Exports a verification key
     Usage:  snarkjs zkev [circuit_final.zkey] [verification_key.json]
zkey export json              Exports a circuit key to a JSON file
     Usage:  snarkjs zkej [circuit_final.zkey] [circuit_final.zkey.json]
zkey export solidityverifier  Creates a verifier in solidity
     Usage:  snarkjs zkesv [circuit_final.zkey] [verifier.sol]
zkey export soliditycalldata  Generates call parameters ready to be called.
     Usage:  snarkjs zkesc [public.json] [proof.json]
groth16 setup                 Creates an initial groth16 pkey file with zero contributions
     Usage:  snarkjs g16s [circuit.r1cs] [powersoftau.ptau] [circuit_0000.zkey]
groth16 prove                 Generates a zk Proof from witness
     Usage:  snarkjs g16p [circuit_final.zkey] [witness.wtns] [proof.json] [public.json]
groth16 fullprove             Generates a zk Proof from input
     Usage:  snarkjs g16f [input.json] [circuit_final.wasm] [circuit_final.zkey] [proof.json] [public.json]
groth16 verify                Verify a zk Proof
     Usage:  snarkjs g16v [verification_key.json] [public.json] [proof.json]
plonk setup                   Creates an initial PLONK pkey 
     Usage:  snarkjs pks [circuit.r1cs] [powersoftau.ptau] [circuit.zkey]
plonk prove                   Generates a PLONK Proof from witness
     Usage:  snarkjs pkp [circuit.zkey] [witness.wtns] [proof.json] [public.json]
plonk fullprove               Generates a PLONK Proof from input
     Usage:  snarkjs pkf [input.json] [circuit.wasm] [circuit.zkey] [proof.json] [public.json]
plonk verify                  Verify a PLONK Proof
     Usage:  snarkjs pkv [verification_key.json] [public.json] [proof.json]
file info                     Check info
```
:::

### Overview

![](https://i.imgur.com/wn4EKEM.png)

1. **Build Circuit *(Algebraic Circuit, R1CS)***: 
    * `circom xxx.circom` → circuit.json
1. **Setup *(circuit + r to setup system)***:
    * `snarkjs setup` → proving_key.json, verification_key.json
3. **Calculate Witness *(Proof System)***: ← input.json
    * `snarkjs calculatewitness` → witness.json
5. **Generate proof *(Proof System)***:
    * `snarkjs proof` → proof.json


![](https://i.imgur.com/69zNBoe.png)

#### Command Steps


如果我們有一個 Circom Program 的檔案名為 `circuit.circom`，撰寫完程式之後可以依序使用以下指令。

* Build Circuit
    * `$ circom circuit.circom  --r1cs --wasm --sym --c -o circuit.json`
    * 這一步我們會將程式邏輯（Circom Program）轉為多項式再轉為迴路
    * `-o circuit.json` 是一個 optional 的指令，可以指定輸出的檔名要叫做什麼
* Generate Input File
    * `$ node generate_circuit_input.js`
    * 這邊也可以使用其他方法，不一定要使用 js 產 `json`
* Generate proving key
    * `$ snarkjs plonk setup circuit.r1cs pot12_final.ptau circuit_final.zkey`
    * 得到迴路之後可以透過 sanrkjs 進行可信設定（trusted setup），trusted setup 會利用迴路還有隨機數產生兩把 Key
    * 產出一個 `.zkey` 檔案，裡面已經包含了 proving 和 verification keys 兩種 key，而且是已經經過所有 phase 2 contributions 的結果
        * 證明鑰匙（Proving Key），用於產生 ZKP
        * 驗證鑰匙（Verification Key），用於驗證其他 Program 產生的 ZKP
    * 需要注意 plonk 也可以使用其他演算法例如 groth16，在打指令的時候不要打錯了
* Export verification key
    * `$ snarkjs zkey export verificationkey circuit_final.zkey verification_key.json`
    * 這一步會特別產生驗證鑰匙（Verification Key）
* Calculate Witness
    * `$ snarkjs wtns calculate circuit.wasm input.json witness.wtns`
    * Witness 為隱私資訊，是不想漏漏的資料
    * 也有與 witness 相對應的公開資料，可視系統設計而定
    * 這一步會需要輸入值，以 `input.json` 的形式輸入
    * 只要 witness 已經被計算，且 trusted setup 已經被執行完成，我們就可以依據 circuit 和 witness 來產生 zk-proof
* Generate proof and public_info
    * `$ snarkjs plonk prove circuit_final.zkey witness.wtns proof.json public.json`
    * 這個指令會產生 ZKP， 需要 Proving Key（`circuit_final.zkey`）、witness（`witness.wtns`）、Public Information（`public.json`） 三者
    * 會產出以下這兩個結果：
        * `proof.json`: 包含 zk-proof
        * `public.json`: 包含 public 的 input 和 output
* Verify proof
    * `$ snarkjs plonk verify verification_key.json public.json proof.json`
    * 驗證需要 Verification Key（`verification_key.json`）、witness（`proof.json`）、Public Information（`public.json`） 三者
    * 如果 Proof 是合法的，我們可以看見 command 會輸出結果 `OK`
    * 一個合法的結果不只是我們知道符合電路的 signal 組合，也證明了 public 的 input 和 output 跟 `public.json` 檔案中的定義相符。
* Generate verifier contract
    * `$ snarkjs zkey export solidityverifier circuit_final.zkey verifier.sol`
    * 產生一個驗證合約，只要「產生證明者」提交他的 proof 到合約中的驗證函式，合約就可以判斷此 ZKP 是否合法
    * 我們也可以繼承這個合約並且加上自己想要的系統設計，成為一個可以驗證零知識證明的 Dapps！
    * 我們可以看見輸出的程式裡面包含兩個合約，`Pairing` 和 `Verifier`，我們只需要部署 `Verifier` 即可。
* Generate callcode
    * `$ snarkjs zkey export soliditycalldata public.json proof.json`
    * Verifier Contract 裡面會有一個 view function 叫做 `verifyProof`，我們可以提交 proof 給這個函式並且得到回傳值，如果 proof 合法則為 `TRUE`，反之則為 `FALSE`。
    * 我們可以藉由以上這個指令自動產出一個 callcode，直接複製就可以作為輸入函式的參數。

### Ceremony
如果還沒準備過 Power of Tau 可以到 github 下載，或者透過以下指令下載：

基本上 trusted setup 實際上有兩個步驟：
1. The powers of tau, which is independent of the circuit.
    * `$ snarkjs powersoftau new bn128 12 pot12_0000.ptau -v`
    * `$ snarkjs powersoftau contribute pot12_0000.ptau pot12_0001.ptau --name="First contribution" -v`
    * `$ snarkjs powersoftau prepare phase2 pot12_0001.ptau pot12_final.ptau -v`
1. The phase 2, which depends on the circuit.

---

## Circom

### Official Links

#### Circom
* [iden3/circom: zkSnark circuit compiler](https://github.com/iden3/circom)
* [Circom 2 Official Documentation](https://docs.circom.io/)
    * [Syntax Documantation](https://docs.circom.io/circom-language/signals/)
    * [Circom verifier.sol](https://docs.circom.io/getting-started/proving-circuits/#verifying-a-proof)
* [zkREPL an online playground for zk circuits](https://zkrepl.dev/)
* [0xPARC circom ECDSA circuit](https://github.com/0xPARC/circom-ecdsa)

#### SnarkJS
- [iden3/snarkjs](https://github.com/iden3/snarkjs)
- [SnarkJs Official Documentation](https://iden3-docs.readthedocs.io/en/latest/iden3_repos/snarkjs/README.html)

### Example

```circom=
include "../circomlib/circuits/mimcsponge.circom";

template example_MiMC() {
   var numInput = 2; // length of vector_inputs[]
   var rounds = 220;
   var numOutput = 1;
 
   signal private input ins[numInput]; //[3, 5]
   signal output outs[numOutput];

   component mimc = MiMCSponge(numInput, rounds, numOutput);
   for(var i=0; i<numInput; i++) {
       mimc.ins[i] <== ins[i];
        
   }
   mimc.k <== 0;

   for(var i=0; i<numOutput; i++) {
       outs[i] <==  mimc.outs[i];
   }
}
component main = example_MiMC();
```
* `include`: include modules
* `template`: function declaration
* `var`: variable declaration
> ```circom
> var x[3] = [2,8,4];
> var z[n+1];
> var dbl[16][2] = base;
> var y[5] = someFunction(n);
> ```
* `signal`: 代表此變數或陣列要轉換成迴路，有以下屬性：
    * `private`: 代表隱私資訊，如果沒有指定就會是公開資訊
    * `input`: input
    * `output`: output
* `component`: 使用情境是在於承接函數、對函數內的 signal 變數作操作，可以想作是一個物件，而 signal 變數則為 class 的公開成員變數。
* `main`: main

```circom=
template Internal() {
   signal input in[2];
   signal output out;
   out <== in[0]*in[1];
}

template Main() {
   signal input in[2];
   signal output out;
   component c = Internal ();
   c.in[0] <== in[0];
   c.out ==> out;  // c.in[1] is not assigned yet
   c.in[1] <== in[1];  // this line should be placed before calling c.out
}

component main = Main();
```

> At compilation time, the content of a signal is always considered unknown.

```
function func ( param_1, ... , param_n ) {
	.....
	return x;
}
```
* `function` can compute numeric values, arrays of values or expressions, but they can not generate constraints

### Syntax

**Reserved Keywords**: assert, Binary, component, do, else, FieldElement, for, function, if, include, input, log, output, public, return, signal, template, var, while.

#### Assign

* `<==  ==> `
    * assign values to signals AND define a constraint
    * 給予 signal 變數值，並且建立一個迴路的約束。
* `<--  --> `
    * assign values to signals
    * 給予 signal 變數值。
* `===`
    * define a constraint
    * 建立一個迴路的約束。
* 因此 `<== : <-- + ===`


#### Basic Operators

* Boolean operator: `&&, ||, !`
* Rational operator: `<, >, <=, >=, ==, !=`
* Arithmetic: `+, -, *, /, **, \, %`
* Bitwise: `&, |, ~, ^, <<, >>`
* Operator with assignment: `+= , -= , *= , /= , **=, \=, %= , ^= , |= , &= , >>=, <<=`

#### Control flow

```circom
// if-else
if (x >= 0) {
	x = y + 1;
	y += 1;
} else {
	x = c.b;
}

// for loop
for (var i = 0; i<n; i++) {
	lc1 += in[i] * e2;
	e2 = e2 + e2;
}

// do-while loop
while(i<n) {
	lc1 += in[i] * e2;
	e2 = e2 + e2;
	i = i+1;
}
do{
	lc1 += in[i] * e2;
	e2 = e2 + e2;
	i = i+1;
} while(i<n)
```

#### Others

```
// Assert
template Translate(n) {
	assert(n>0);
	assert(n<=254);
	…
}

// Debugging
log(135);
log(c.b);
log(x==y);
```

在 calculate witness 時會產出 `log()` 的結果。

### Compiler 

#### Message

* **Hint**
    * The compiler throws a hint when there is part of the code that is allowed but uncommon, and hence, it is better to check if that part of the code was written that way on purpose.
* **Warning**
    * The compiler throws a warning when there is part of the code that is allowed but it should not happen in general.
* **Error**
    * The compiler throws an error when there is part of the code that is not allowed.

---

## Exercise



---

## Reference

* [therealyingtong/roll_up_circom_tutorial](https://github.com/therealyingtong/roll_up_circom_tutorial)
* [動手實做零知識 — circom](https://medium.com/cryptocow/%E5%8B%95%E6%89%8B%E5%AF%A6%E5%81%9A%E9%9B%B6%E7%9F%A5%E8%AD%98-circom-d7ac1fa8bbd3)
* [Implementing Zero Knowledge Lottery’s Circom circuits PART 1 / 2](https://medium.com/@killari/implementing-zero-knowledge-lotterys-circom-circuits-part-1-2-16910b3732a2)


#### Sample
* [Sample](https://github.com/KimiWu123/Samples/tree/master/circom/TEMSample)
* [MiMC Spong](https://github.com/KimiWu123/Samples/blob/master/circom/mimcSponge/mimcSponge.circom)
* [SHA256](https://github.com/KimiWu123/Samples/tree/master/circom/sha256)