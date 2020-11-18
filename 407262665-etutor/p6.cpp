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

string printBinaryRevseve(unsigned int numb,unsigned int start){  
    string ans = "";  
    for (unsigned  int k = 0; k <=7 ; k++){  
            unsigned  int n = (numb >> (k+start)) & (unsigned int)1;  
              ans+=char(48+n);   
    }
	return ans;    
} 
  
int main(){  
    unsigned int number,sum=0;  
    unsigned int arr[4];
    cin>>number;
    

    printf("Before bits are reversed:\n");

    sum=0;
    for(unsigned int i=0;i<=31;i++){   
        sum+=((number>>i)&(unsigned int )1)<<(i);
    }
        
    cout<<sum<<" = ";
    for(int i=3;i>=0;i--){
        cout<<printBinary(number,i*8)<<" ";
    }

    printf("\n\nAfter bits are reversed:\n");

    sum=0;
    for(unsigned int i=0;i<=31;i++){   
        sum+=((number>>i)&(unsigned int )1)<<(31-i);
    }

    cout<<sum<<" = ";
    for(int i=0;i<4;i++){
        cout<<printBinaryRevseve(number,i*8)<<" ";
    }
    cout<<endl;

    return 0;  
}  