#include <bits/stdc++.h>  
  
using namespace std ;  
  
string printBinary(unsigned int numb,unsigned int start){  
    string ans = "";  
    for (unsigned  int k = 7; k >= 0 ; k--){  
            unsigned  int n = (numb >> (k+start)) & (unsigned int)1;  
              ans+=char(48+n);   
        if(k==0)  
            break;  
    }
	return ans;    
}  
  
int main(){  
    unsigned int number;  
    unsigned int arr[4];  
    cin>>number;  
  
    arr[0]=number&0xFF000000;  
    arr[1]=number&0xFF0000;  
    arr[2]=number&0xFF00;  
    arr[3]=number&0xFF;  

      
    printf("The packed character representation is:\n%u = ",number);  
	
	for(int i=0;i<4;i++)
		cout<<printBinary(number,24-i*8)<<" ";
		
	cout<<endl<<endl;
      
 
    arr[1]=arr[1]>>16;  
    arr[2]=arr[2]>>8;  

    for(int i=0;i<4;i++){  
		cout<<arr[i]<<" = ";
		for(int j=24;j>=0;j-=8){
        cout<<printBinary(arr[i],j)<<" ";  
		}
		cout<<endl;
	}

    return 0;  
}  