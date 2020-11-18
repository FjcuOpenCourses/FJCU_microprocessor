#include "stdio.h"
#include "stdlib.h"




void printBinary(unsigned int numb){
	for (unsigned  int k = 31; k >= 0 ; k--) {
	      	unsigned  int n = (numb >> k) & 0x00000001;
	    	printf("%u",n);

	    if(k==0)
	    	break;

	}
	printf("\n");	
}


	void printOctal(unsigned int numb){
	for (unsigned  int k = 11; k >= 0 ; k--) {
		if(k==11){
		printf("%u",0);
		continue;
		}
	      unsigned  int n = (numb >> k*3) & 0x00000007;

	    	printf("%u",n);
	    	//cout << n <<" ";

	    if(k==0)
	    	break;
       }

     printf("\n");
}


	void printHexidecimal(unsigned int numb){
		 printf("%s","0x");
	for (unsigned  int k = 7; k >= 0 ; k--) {
	      unsigned  int n = (numb >> k*4) & 0x0000000f;

	      if(n>=10)
	      	printf("%c",n+55);
	      else
	    	printf("%u",n);
	    	

	      if(k==0)
	    	break;

       }

     printf("\n");

}

 




int main(){
	unsigned int val,i=0;
	
	while(scanf("%u",&val)!=EOF){

		printf("Case %u: %u\n",++i,val);
		printBinary(val);
		
		printOctal(val);
		printHexidecimal(val);
	}
		

return 0;

}