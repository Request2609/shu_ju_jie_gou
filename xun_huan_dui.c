#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
#define SEP "\n---------------------------------------\n"
typedef struct queue{

	int rear , front ;
	int data[maxsize];
}queuenode;
void init_queue(queuenode * h);
int menu();
void prt(queuenode *h);
void input_data(queuenode * h);
int is_empty(queuenode * h);

int main(){
	
	queuenode h ;
	init_queue(&h);
	int ch ;
	while(ch = menu()){
	
		switch(ch){
		
			case 1:
				input_data(&h);
				break ;
			case 2:
				prt(&h);
				break ;
			case 3:
				init_queue(&h);
				break ;
		}
	}


}

int is_empty(queuenode * h){

	if(h->front == h->rear)return 1 ;
	else  return 0 ;
}

void prt(queuenode * h){
	if(is_empty(h) == 1){
		printf("\n队列为空!\n");
		return ;
	}
	printf(SEP);
	printf("队列成员：\n");
	while(1){
		h->front = (h->front+1)%(maxsize);
		printf("%d\n",h->data[h->front]);
		if(h->front == h->rear){
			printf("\n出队完毕!\n");
			break ;
		}
	}
}

void input_data(queuenode * h){

	if((h->rear+1) % (maxsize) == h->front){
		printf("队列已满!\n");
		return ;
	}
	else{
		int  num;
		h->rear = (h->rear+1)%maxsize ;
		printf("请输入：");
		scanf("%d",&num);
		h->data[h->rear] = num ;
		printf("\n入队成功!\n");
	}
}

void init_queue(queuenode * h){

	h->rear = h->front = maxsize-1;
}

int menu(){

	int ch ;
	printf(SEP);
	printf("\n1.入队\n");
	printf("\n2.打印队列数据\n");
	printf("\n3.初始化队列\n");
	printf("\n0.退出程序");
	printf(SEP);
	printf("请输入选项：");
	scanf("%d",&ch);
	return ch ;

}
