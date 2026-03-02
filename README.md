# Big-int
***
.gitignore contains main.c so this file will not be commited and can be used for testing. If you want to use the same repository for some reason you can delete the main.c line from .gitignore
***
## Using Big int
To create and use the big int you have to create it in your program and then initialize it
```C
BigInt yourBigInt;
BigIntInitialization(&yourBigInt);
```

To write your number in a big int use:
```c
SaveNumber(&yourBigInt, "YourNumber");
//The number is passed as a string so write your number in qoutes "" or pass it as a char array
//The number can be either a negative or a positive
```
To subtract two big ints use:
```c
SubtractBigInt(ResultingBigInt, FirstBigInt, SecondBigInt);
```
To add two big ints use:
```c
AddBigInt(ResultingBigInt, FirstBigInt, SecondBigInt);
```
To get a string value of the BigInt use. ALWAYS SAVE IT IN A CHAR ARRAY OR IT WILL CUASE A MEMEMORY LEAK:
```c
ReturnBigInt(&YourBigInt);
```
To destroy a BigInt use:
```c
DestroyBigInt(&YourBigInt);
//If after destroying a BigInt you want to use it again you have to initialize it first
```
To multiply two BigInts use:
```c
MultiplyBigInt(ResultingBigInt, FirstBigInt, SecondBigInt);
```
To divide two BigInts use: 
```c
int DivideBigInt(ResultQuotientBigInt,ResultRemainderBigInt,FirstBigInt, SecondBigInt);
```

All functions upon successful completion return a 1 and a 0 if they fail apart from the ReturnBigInt function which after successful vompletion returns the value of the BigInt as a string or upon failure NULL
***
## Functionality
- [x] Big int structure
- [x] initialization function
- [x] IsNumber function
- [x] Value change function
- [x] Return value of big int function
- [x] Adition of big ints
- [x] Subtraction of big ints
- [x] Multiplication of big ints
- [x] Division of big ints