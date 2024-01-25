#include<iostream>
using namespace std;
int main(){
	int n = 10;
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n - i; j++){
			cout << j <<" ";
		}
		cout <<endl;
	}
}

/*
1 2 3 4 5 6 7 8 
1 2 3 4 5 6 7 
1 2 3 4 5 6 
1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1 
*/
