#include<iostream>
using namespace std;
int main()
{
	int n = 10;
	for(int i = 0; i < n; i++){ //row
		for(int j = 0; j < i; j++){ //row filling => column
			cout << j + 1;	
		}
		cout << endl;
	}
}

/*
1
12
123
1234
12345
123456
1234567
12345678
123456789
*/
