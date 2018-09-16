#include<stdio.h>
#include<stdlib.h>
int main(){

	int *a ;
	int i ,k;
	printf("\n请输入数据量:");
	scanf("%d",&i);
	a = (int *)realloc(a,i);
	k = 0 ;
	while(1){
		printf("请存入数据:");
		scanf("%d",a+k);
		printf("%d",*(a+k));
		k++ ;
		if(k == i)break ;
	}
	free(a);
}
