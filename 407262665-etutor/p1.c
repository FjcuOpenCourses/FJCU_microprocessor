#include "stdio.h"
#include "stdlib.h"
 
unsigned  int display_nibble(unsigned  int val,unsigned  int k) {
   return (val >> (4*k)) & 0x0F;
}

int main(){
	unsigned  int val,i=0;
	
	while(scanf("%u",&val)!=EOF){

		printf("Case %u: %u\n",++i,val);
	

	for (unsigned  int k = 7; k >= 0 ; k--) {

	     unsigned  int n = display_nibble(val,k);

		//unsigned int n = (val>>4*k)
	    if(n>=10)
	    	printf("%c ",n+55);
	    	//cout<<char(n+55)<<" ";
	    else
	    	printf("%u ",n);
	    	//cout << n <<" ";

	    if(k==0)
	    	break;

	}
			printf("\n");
		
}
return 0;
}

