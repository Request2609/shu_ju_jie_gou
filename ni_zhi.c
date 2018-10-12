#include<stdio.h>
#include<stdlib.h>
#define SEP "\n------------------------------------------------\n"
#define maxsize 100
//定义顺序表数据结构
typedef struct list{
	
	int data[maxsize] ;
	int length ;

}list_t;
void input_data(list_t * l);
void init_list(list_t *l);
void prt(list_t * l);
void turn_back(list_t * l);

int main(){
	

	int n ;
	list_t l;
	init_list(&l);
	input_data(&l);

	printf("原始数据如下:");
	prt(&l);
	printf("逆置数据如下:");
	turn_back(&l);	
	prt(&l);

}

//逆置
void turn_back(list_t *l){

	int i = 0, n;
	int flag;
	if((l->length -1)%2 == 0)flag = 1 ;
	else flag = 0 ;
	n = (l->length-1)/2 ;
	int tmp ;
	while(1){
		
		if(flag == 1){
			if(i > n)break ;
		}
		else{
			if(i == n)break ;
		}
		tmp = l->data[i];
		l->data[i] = l->data[l->length - i -1];
		l->data[l->length - i - 1] = tmp ;
		i ++ ;
	}
}

//打印表中数据
void prt(list_t *l){
	
	int i ;
	printf(SEP);
	for(i = 0 ;i < l->length ;i++){
		
		printf("%d\n",l->data[i]);
	}
}

//初始化顺序表
void init_list(list_t * l){

	l->length = 0 ;
}

//输入数据
void input_data(list_t * l){
	
	printf(SEP);
	int n ,i;
	for(l->length ;l->length< maxsize ; l->length++){
		if(l->length == maxsize){
			printf("\n表已满!不能再存数据!\n");
			break ;
		}
		printf("请输入数据(0结束输入):");
		scanf("%d",&n);
		if(n == 0)break ;
		l->data[l->length] = n ;
	}
}
