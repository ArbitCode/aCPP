# pointers
A pointer is a variable that contains the address of a variable
## Pointers and addresses
`A typical machine has an array of consecutively numbered or addressed memory cells.`<br>
`&: gives address of an object, this operator can be applied only to objects in memory : variable and array elements.`<br>
`*: when applied to a pointer, it accesses the object that pointer points to.`<br>
`Every pointer points to a specific data type`
```cpp
int x = 1, y = 2, z[10];
int *ip;    // pointer to int
int *iq;    // pointer to int
ip = &x;    // ip points to x, since ip stores the address of x
iq = ip;    // iq points to whatever ip pointed to
y = *ip;    // y is now 1
*ip = 0;    // x is now 0
ip = z + 2; // ip points to z[2];
*ip = 5;    // z[2] is now 5
```
`if a pointer ptr points to a variable x, then *ptr can occur in any context where x could.`

## Pointers and Function arguments
```cpp
void swap(int *x, int *y){
    int * temp;
    temp = x;
    x = y;
    y = temp;
}
int main(){
    int a = 10, b = 20;
    swap(&a, &b); // pass address
    return 0;
}
```

## Pointers and arrays
Any operation that can be achieved by array indexing can also be done with pointers.
```cpp
int arr[10];    // a[10]: {1,2,3,4,5,6,7,8,9,0}
int *pa;        // pa pointer to int
pa = &arr[0];   // pa pointers to a
pa = arr;       // &arr[0] and array-name have identical value 
int x = *pa;    // x is no arr[0]
```
`Note: A pointer is a variable so pa = arr and pa++ is legal, but an array name is not a variable so arr = pa or arr++ is illegal.`<br>
`pass array name as function argument`

```cpp
void printArray( const int *arr, int n){
    for(int i=0; i<n; i++){ // sizeof(arr) will return size of arr pointer not size of array.
       // *(arr + i) = 4;     // error: read-only variable is not assignable
        printf("%d", *(arr + i));
    }
}
int main(){
    int arr[] = {0,1,2,3,4,5,6};
    printArray(arr, 7);
}
```

```cpp
// strlen: return length of string s
int strlen(const char *s){
    int n = 0;
    while(s!='\0'){
        n++;
        s++;
    }
    return n;
}
```
## Pointes arithmetic
`pointers, arrays, and address arithmetic is one of strengths of the language.`<br>
`if p is a pointer to some element of an array, then p++ increments p to the next element of the array, and p+=i increments to point ith elements beyond where it currently pointed.`<br>

`The valid pointer operations` : 
1. assignment of pointers of the same type, 
2. adding and subtracting a pointer and integer, 
3. assigning and comparing to zero(NULL).<br>
4. subtracting and comparing two pointers to members of the same array, 

`Illegal pointer operations` : 
1. All other pointer operation are illegal,  
2. not legal to add/subtract/multiply/divide/shift/mask two pointers. 
3. add float or double to them. 
4. Assign a pointer of one type to a pointer of another type without a cast illegal. except `void *`

## Character pointers and functions
A string constant, written as
```cpp
"I am a string"
```
is an array of characters. In the internal representation, the array is terminated with null character `\0` so that program can the find end.

```cpp
char amessage[] = "now is time"; // amessage: [now is time\0]
char *pmessage = "now is time";   // pmessage --> [now is time\0]
```

## pointer array
Array of pointers.
```cpp
/*
int *p1, *p2;
var: [p1, p2];
*/
int *var[2]; // var is array of size 2 pointer to integer
/*
var -> [1,2]
*/
int (*var)[2] // var is pointer to array of size 2 integer.
```

## 2-D arrays
If 2D array is to be passed to a function, parameter declaration in function must include the number of columnss the number of rows is irrelevant, since a pointer to an array of row is passed to a the function.
```cpp
// Online C++ compiler to run C++ program online
#include <iostream>
/*void show2D(int dayTab[4][5]){..}
void show2D(int dayTab[][5]){...}*/
void show2D(int (*dayTab)[5]){
 for(int i =0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            std::cout << dayTab[i][j] << "\t";
        }
        std::cout <<"\n";
    }   
}
int main() {
    int dayTab[4][5] = {{0,1,2,3,4},
                        {0,1,2,3,4},
                        {0,1,2,3,4},
                        {0,1,2,3,4}
                        };
    show2D(dayTab);
    return 0;
}
```

## Pointers to functions
A function itself is not a variable, but it is possible to define pointers to functions which can be assigned, placed in arrays, passed to functions, returned by functions and so on.

```cpp
// function pointer
#include<iostream>
using namespace std;
typedef bool (*funPtr)(int, int);
typedef int *p;
bool fun(int x, int y){
    return x>y?true:false;
}
void fun1(int x, int y, bool (*fun2)(int, int)){
    
    cout << boolalpha << fun2(x,y) << endl;
}
funPtr fun3(){
    return fun;
}
bool (*fun4())(int, int){
    return fun;
}
int main(){
    cout << boolalpha << fun(4,3) << endl;
    bool (*comp)(int, int);
    comp = fun;
    cout << boolalpha << comp(4,3) << endl;
    fun1(4,6,fun);
    funPtr f = fun3();
    cout<< boolalpha << f(4,5) << endl;
    funPtr arr[2] = {comp, f};
    cout << boolalpha << arr[0](4,5) << endl;
    cout << boolalpha << arr[0](7,5) << endl;
    bool(*fun5)(int, int) = fun4();
    cout << boolalpha << fun5(6,7) << endl;
    p q;
    q = new int(2);
    cout << *q;
}
/*
true
true
false
false
false
true
false
2
*/
```

## Complicated Pointer Declarations
`right -> left rules`:<br>
First, symbols. Read<br>
- `*` as "pointer to"
- `[]` as "array of"
- `()` as "function returning"

1. STEP1:
Find the identifier. This is your starting point.
then say `Identifier is ...`
2. STEP2: Look at the symbols on the right of the identifier. continue right until you run out of symbols *OR* hit a *right* parenthesis `)`.
3. STEP3: Look at the symbols to the left of the identifier. If it is not one of our symbols just say it. otherwise translate into English using above table. keep going left until you run out of symbols *OR* hit a *left* parenthesis `(`.

Example:
int *p[];
1. find identifier "p is"
2. move right until run out of symbols or right parenthesis hit.
   "p is array of"
3. can't move right anymore so move left and find.
   "p is array of pointer to"
4. keep going left until you run out of symbols or left parenthesis hit
   "P is array of pointer to int."
<br>
`int*(*func())()`
func is function returning pointer to function returning pointer to int.
<br>
`int (*(*fun_one)(char *,double))[9][20];`
fun_one is pointer to function(char *, double) returning pointer to array(size 9) of array(size 20) of int.

## typedef specifier used in declaration
`Typedef can be used to aliasing predefined types.`









