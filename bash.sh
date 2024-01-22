#! /bin/bash
:<<COMMENT
this is practice bash set.
COMMENT

echo "Hello world!"

# var in bash `var_name=value`
first_mid=Raja\ Ram
surname=Sharma
echo $first_mid $surname

#Arithmetic
:<<COMMENT
+, -, *, /, **, %
COMMENT

#var=$((expression))
var=$((3+9))
var=$((2+5))
echo $var

#Read input
#read -p "Enter your age" var_name

read -p "Enter your age: $first_mid $surname " age
echo "age:" $age

:<<COMMENT
comparision:
1. equality -eq
2. greater than equal to -ge
3. greater than -gt
4. less than equal to -le
5. less than -lt
6. not equal to -ne
COMMENT

# condition
:<<COMMENT
if [condition]
then
commands
elif [condition]
then
commands
else
do
commands
fi
COMMENT

# looping

:<<COMMENT
for i in {1..5}
do
echo $i
done
COMMENT

#arguemnts
:<<COMMENT
$@
COMMENT
for i in $@
do 
echo "Entered arguemnts: $i"
done

#function
print(){
    echo "I am print"
}
print

# function arguemnts
print(){
    echo "I am 2nd print"
    echo "arguemnts: " $1 $2 $3
    return 5
    
}
print 1 2 3
#return val
echo $?

