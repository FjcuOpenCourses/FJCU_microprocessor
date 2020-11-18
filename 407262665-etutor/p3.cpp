#include <bits/stdc++.h>

using namespace std ;

void printBinary(unsigned int numb){
	for (unsigned  int k = 31; k >= 0 ; k--) {
	      	unsigned  int n = (numb >> k) & 0x00000001;
	    	printf("%u",n);

	    if(k==0)
	    	break;

	}
	printf("\n");
}

int main(){

	 int n ,testCase=0;
	set <int> s ;

	while(1){
		scanf("%d",&n);
		if(n==-1)
		break;
		s.insert(n);
	}


	for (auto it = s.begin();it != s.end(); it++)
        cout << *it << " ";

	cout<<endl;
	unsigned  int number;


	while(scanf("%u",&number)!=EOF){
		testCase++;
		int count=0;
		printf("Case %d: %u\n",testCase,number);

		//printBinary(number);
		for (auto it = s.begin();it != s.end(); it++){
			if((number>>*it)&(unsigned int)1)
				count++;
		}
		if(count==s.size()){
			printf("true(all bits 1)\n");

		}
		else{
			printf("false(all bits 1)\n");
		}
		if(count!=0){
			printf("true(exist bits 1)\n");

		}
		else{
			printf("false(exist bits 1)\n");
		}

	}
	return 0;
}#include <bits/stdc++.h>

using namespace std ;

void printBinary(unsigned int numb){
	for (unsigned  int k = 31; k >= 0 ; k--) {
	      	unsigned  int n = (numb >> k) & 0x00000001;
	    	printf("%u",n);

	    if(k==0)
	    	break;

	}
	printf("\n");
}

int main(){

	 int n ,testCase=0;
	set <int> s ;

	while(1){
		scanf("%d",&n);
		if(n==-1)
		break;
		s.insert(n);
	}


	for (auto it = s.begin();it != s.end(); it++)
        cout << *it << " ";

	cout<<endl;
	unsigned  int number;


	while(scanf("%u",&number)!=EOF){
		testCase++;
		int count=0;
		printf("Case %d: %u\n",testCase,number);

		//printBinary(number);
		for (auto it = s.begin();it != s.end(); it++){
			if((number>>*it)&(unsigned int)1)
				count++;
		}
		if(count==s.size()){
			printf("true(all bits 1)\n");

		}
		else{
			printf("false(all bits 1)\n");
		}
		if(count!=0){
			printf("true(exist bits 1)\n");

		}
		else{
			printf("false(exist bits 1)\n");
		}

	}
	return 0;
}
