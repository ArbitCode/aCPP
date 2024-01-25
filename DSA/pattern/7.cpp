#include<iostream>
using namespace std;
int main(){
	int n = 10;
	for(int i = 0; i < n; i++){
		//print space
		for(int j = 0; j < n-i-1; j++){
			cout << " ";
		}
		for(int j = 0; j < 2*i+1; j++){
			cout << "*";
		}
		for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
		cout << endl;
	}
}
/*

         *         
        ***        
       *****       
      *******      
     *********     
    ***********    
   *************   
  ***************  
 ***************** 
*******************

*/
