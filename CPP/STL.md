# STL
Collection of containers and useful function.<br>
the containers and functions inside C++ STL are defined in the std namespace.
STL is implemented through class template.

## Containers
A container is a place where we store our objects.
- Sequential Containers
- Associative Containers
## Sequential Containers
Sequential containers store objects in a sequence, one next to the other in memory.
- std::vector
- std::list : A doubly linked list
- std::forward_list : A singly linked list
- std::deque : A double-ended queue
`Nevertheless, As far as sequence container go, the std::vector is the container we want to be using most of the time.`
## Associative containers
- std::map

## std::vector
- A vector is container
- A sequence of contiguous elements of any non-const type
- A vector can grow and shrink itself as insert and delete elements into and from vector.
```cpp
//signature
//std::vector<some_type>
#intclude<vector>
int main(){
  std::vector<int> vec = {1,2,3,4,5};
}
```
## std::array
The std::array is thin wrapper around a C-style raw array.
```cpp
//signature
//std::array<type_name, array_size> arr;
#include<iostream>
#include<array>
int main(){
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    for(auto el : arr){
        std::cout << el << " ";
    }
}
/*
1 2 3 4 5
*/
```
`Note: In modern C++, prefer std::array or std::vector to old/raw C-style arrays.`
## std::set
A set is a container that holds unique, sorted objects. `It is a binary tree of sorted objects.`
```cpp
#include<iostream>
#include<set>
int main(){
    std::set<int> myset = {1, 2, 3, 4};
    myset.insert({1, 2, 5});
    for(auto el : myset)
        std::cout << el << " ";
}
/*
1 2 3 4 5
*/
```
## std::map
A map is an associative container that holds key-value. Keys are sorted and unique.<br>
`A map is implemented as a balanced binary tree`
```cpp
#include<iostream>
#include<map>
int main(){
    std::map<int, char> mymap = {
        {1, 'a'},
        {2, 'b'},
        {3, 'c'},
        {4, 'a'},
        {5, 'b'},
        {5, 'a'},
    }; //dupicate will be discared
    mymap[8.7] = 'd'; //if not exists then insert narrow down to 8
    for (auto it : mymap)
    {
        std::cout << it.first <<"->"<< it.second <<"\n";
    }
    auto it = mymap.find(8.7);
    if(it!= mymap.end()){
        std::cout << "Found: " << it->first << "->" << it->second << "\n";
    }else{
        std::cout << "Not Found.";
    }
}
/*
1->a
2->b
3->c
4->a
5->b
8->d
Found: 8->d
*/
```

## std::pair
the std::pair class template is a wrapper that can represent a pair of values.
```cpp
#include<iostream>
#include<utility>
int main(){
    std::pair<int, double> mypair = {1'2'3, 3.14};
    std::cout << "mypair:[" << mypair.first << "," << mypair.second <<"]\n";
    auto mypair1 = std::make_pair(123, 3.14);
    std::cout << "mypair1:[" << mypair1.first << "," << mypair1.second << "]\n";
}
/*
mypair:[123,3.14]
mypair1:[123,3.14]
*/
```
## Range based for loop
Range based for loop, which allows us to iterate over the container/range content.<br>
`for each element of`
```cpp
/*
signature:
for(some_type element_name : container_name){
  //code
}
*/
#include<iostream>
#include<string>
#include<vector>
int main(){
    std::vector<std::string> vStr = { "RAJA", "RAM", "SHARMA"};
    for(auto el : vStr) // el is a copy of each of elements.
    {
        std::cout << el << " ";
    }
    for (auto &el : vStr) // el reference using it vector can modify
    {
        el = "RAM";
    }
    std::cout << "\n";
    for (const auto &el : vStr) //el read-only reference.
    {
        std::cout << el << " ";
    }

    std::cout << "\n";
}
/*
RAJA RAM SHARMA 
RAM RAM RAM 
*/
```
## Iterators
`Containers have Iterators.`<br>
Iterators are pointer-like entities `capable of pointing to individual container elements.`<br>
Iterator pointing at the first element of a container is expressed.
`a.begin()`<br>
Iterator pointing at `one past the last element` of a container is expressed.
`a.end()`<br>
Iterators can be incremented or decremented.<br>

```cpp

#include<iostream>
#include<vector>
#include<iterator>
int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto it = vec.begin(); it != vec.end(); it++) // iterator is similar to pointer over container.
        std::cout << *it << " ";
}

```
`erase-remove idiom`<br>
```cpp

#include<iostream>
#include<vector>
#include<algorithm>
int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5,3,4};
    std::cout << "before delete: ";
    for (auto it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    auto it = vec.begin() + 2; //3rd element
    std::cout << "\nafter delete: ";
    vec.erase(std::remove(vec.begin(), vec.end(), *it), vec.end());
    for(auto el : vec)
        std::cout << el <<" ";
}
/*
before delete: 1 2 3 4 5 3 4
after delete: 1 2 4 5 3
*/
```
## Alogrithms and Utilities
A set of useful functions located in the <algorithm> header.
- std::sort
- std::find
## std::sort
if we want to sort our container, we can use the std::sort function.<br>
sort function sorts a range of elements.<br>
it takes 3 parameter
1. start of Range
2. one past the end of range
3. comparator/function object.

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
int main(){
    std::vector<int> vec = {6, 5, 1, 85, 3, 2, 4};
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    for(const auto &el  : vec){
        std::cout << el << " ";
    }
}
/*
85 6 5 4 3 2 1
*/
```

## std::find
To find a certain element by value and return an iterator pointing at the element.
```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
int main(){
    std::vector<int> vec = {6, 5, 1, 85, 3, 2, 4};
    auto result = std::find(std::begin(vec), std::end(vec), 2);
    if(result != vec.end()){
        std::cout << "Element found: " << *result;
    }else{
        std::cout << "Element not found!";
    }
}
/*
Element found: 2
*/
```
`std::find_if  accept predicate`
## Lambda expressions
`Lambda expressions are so called anonymous function objects`.<br>
A function object, or a functor, is an object of a class that can be called as a function.<br>
- to be able to call an object like a function, we must overload call operator () for our class.
```cpp
#include<iostream>
class MyClass{
    public:
    bool operator()(int x){
        return x % 2 == 0;
    }
};
int main(){
    MyClass myobject;
    bool isEven = myobject(123);
    if(isEven){
        std::cout << "Even\n";
    }else{
        std::cout << "Odd\n";
    }
}
```
- function objects carry their values. since they are object of a class.
they can have data members. This seprate them from regular function.
- so function objects encapsulate data hence it preserve stateful.

`if we want only function object then writting the entire function and overloading the operator () can be skipped` that is where `lamda expression come into play.`
`lambda expressions are unnamed function objects.`

```cpp
#include<iostream>
int main(){
    auto mylambda = []()
    {
        std::cout << "Hello from lambda expression.";
    };
    mylambda();
}
/*
Hello from lambda expression
*/
```
Here, We assign the resulf of a lambda expression to a variable mylambda. then we invoke this lambda by using the function call operator ().
- lambdas are mostly used as predicates inside STL algorithm function.
```cpp
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    auto countEven = std::count_if(std::begin(v), std::end(v), [](int x)
                                   { return x % 2 == 0; });
    std::cout << countEven;
}
/*
3
*/
```
---
