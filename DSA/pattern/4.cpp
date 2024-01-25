#include<iostream>
using namespace std;
int main(){
	int n = 10;
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= i; j++){
			cout << i ;
		} 
		cout << endl;
	}
}
/*
1
22
333
4444
55555
666666
7777777
88888888
999999999
*/
