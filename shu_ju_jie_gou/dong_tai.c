#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	
	int length ;
	int *a ;
	int maxsize ;

}node_t;
int main(){
	
	node_t * p ;
	int  n ,i;
	printf("\n请输入数据容量:");
	scanf("%d",&p->maxsize);
	printf("\n");
	p->a = (int*)malloc(p->maxsize);
	for(p->length = 0 ; p->length < p->maxsize ;(p->length)++)
	{
	
		printf("\n\n请输入数据(0 结束输入):");
		scanf("%d" ,&(p->a[p->length])) ;
		i = p->a[p->length];
		
		if( i == 0)break;
	}
	//打印数据
	
	printf("\n输入的数据如下:");
	for( i = 0 ;i < p->length ;i++){
		printf("\n数据:%d\n",p->a[i]);
	}
	//增加空间，扩大数组容量
	printf("\n扩展数组空间\n");
	printf("\n请输入数组空间:");
	scanf("%d",&p->maxsize);
	p->a = (int *)realloc(p->a , p->maxsize);

	for( p->length; p->length < p->maxsize ;p->length++){
	
		printf("\n请继续输入数据:");
		scanf("%d",&(p->a[p->length]));
		
	}
	printf("\n开辟空间，添加数据后:");
	for( i = 0 ;i < p->length ;i++){
		printf("\n数据:%d\n",p->a[i]);
	}
	//按下标查找
	printf("\n查找第几个元素:");
	scanf("%d",&n);
	printf("\n第%d个元素是%d。\n",n,p->a[n-1]);

	//删除数组元素
	
	printf("\n请输入要删除元素位置:");
	scanf("%d",&n);
	if(n >= p->length){
		printf("\n数组没那么大！\n");
		free(p);
		return ;
	}
	int tmp ;
	
	printf("\n要删除的元素是%d\n",p->a[n-1]);
	for( i = n ; i< p->length ;i++  ){
		p->a[i-1] = p->a[i];
		if(i == p->length-1)break ;	
	}
	p->maxsize-- ;
	p->length -- ;
	//删除后数据输出
	printf("\n删除数据后数据元素情况:\n");
	for( i = 0 ;i < p->length ;i++){
		if(i == p->length-1){
			break;
		}
		printf("\n数据:%d\n",p->a[i]);
	
	}

	free(p->a);
}

