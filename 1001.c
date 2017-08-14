#include<stdio.h>

int main()
{
	int n, sum=0;
	scanf("%d",&n);
	if(n == 1){
		sum = 0;
		printf("%d", sum);
		return 0;
	}
	while(1){
		if(n%2 == 0){
			n/=2;
			printf("%d ",n);
		}else{
			n=(3*n+1)/2;
			printf("%d ",n);
		}
		sum++;
		if(n == 1) break;
	}
//	printf("%d",sum);
	return 0;
}
