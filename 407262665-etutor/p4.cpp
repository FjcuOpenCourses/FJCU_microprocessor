#include <bits/stdc++.h>

using namespace std ;

string printBinary(unsigned int numb,unsigned int start){
	string ans = "";
	for (unsigned  int k = 7; k >= 0 ; k--){
	      	unsigned  int n = (numb >> (k+start)) & (unsigned int)1;
			  ans+=char(48+n);
	    	//printf("%u",n);
	    if(k==0)
	    	break;
	}
	return ans;
}

int main(){
    
    char arr[4];
    for(int i=0;i<4;i++)
        cin>>arr[i];
    
    for(int i=0;i<4;i++){
        cout<<arr[i]<<":"<<endl<<(int)arr[i]<<" = ";
		for(int j=24;j>=8;j-=8){
			cout<<printBinary((unsigned int)arr[i],j)<<" ";
		}
		cout<<endl;
	}
	 printf("\'%c\' and \'%c\' and \'%c\' and \'%c\' packed in an unsigned int:\n",arr[0],arr[1],arr[2],arr[3]);

	 cout<<((unsigned int)arr[0]<<24)+((unsigned int)arr[1]<<16)+((unsigned int)arr[2]<<8)+(unsigned int)arr[3]<<" ";
	 
	 for(int i=0;i<4;i++)
	 	cout<<printBinary((unsigned int)arr[0],0)<<" ";
	 
	 cout<<endl;
	return 0;
}