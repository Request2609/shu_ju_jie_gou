#include<stdio.h>
#include<stdlib.h>
#define SEP "\n-----------------------------------------\n"

typedef struct queue{

	int front ,rear;
	int data[maxsize] ;

}listnode ,*linklist;
void init_queue(linklist *h);
void input_data(linklist h);
void menu();

int main(){
	
	linklist h ;
	init_queue(&h);
	int choose ;
	if(choose = menu()){
	
		switch(choose){
		
			case 1:
				break ;
			case 2:
				break ;
			case 3:
				break ;
			case 4:
				break ;
		}
	}

}

//打印菜单
int menu(){

	int ch ;
	printf(SEP);
	printf("\n1.存数据");
	printf("\n2.读数据");
	printf("\n3.初始化");
	printf("\n0.退出\n");
	scanf("%d",&ch);
}

//初始化队列
void init_queue(linklist *h){

	(*h)->front = (*h)->rear = 1 ;

}

//入队
void input_data(linklist h){

	if()
}
