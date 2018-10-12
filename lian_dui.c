#include<stdio.h>
#include<stdlib.h>
#define SEP "\n-----------------------------------------------\n"
typedef struct queue{

	int data ;
	struct queue *next ;

}pnode;

typedef struct queuelist{

	pnode * front ;
	pnode * rear  ;
}pnode_t , *queuelist ;

void init_queue(queuelist * h);
void input_data(queuelist h) ;
int is_empty(queuelist h);
void out_queue(queuelist h);

int main(){
	queuelist  h ;
	init_queue(&h);
	printf("\n入队：\n");
	printf(SEP);
	input_data(h);
	printf("\n出队：\n");
	printf(SEP);
	out_queue(h);
	return 0 ;
}

//出队
void out_queue(queuelist h){
	
	pnode * p ;
	
	while(1){
		if(h->front->next == NULL)
		{
			printf("\n队列为空!\n");
			break ;
		}
		p=  h->front->next ;
		h->front ->next = p->next ;
		printf("\n%d\n",p->data);
		free(p);
	}
}

int is_empty(queuelist h){
	if(h->front =  h->rear) return 1;
	return 0 ;
}
//入队
void input_data(queuelist h){
	
	pnode* q ;
	int data ;
	while(1){

		printf("请输入数据(-1退出):");
		scanf("%d",&data);
		if(data == -1)break ;
		q = (pnode*)malloc(sizeof(pnode));
		q->next = NULL ;
		q->data = data ;
		h->rear->next = q ;
		h->rear=  q ;
	}
}

//初始化队列
void init_queue(queuelist *h){
	
	*h = (queuelist)malloc(sizeof(pnode_t));
	pnode* q ;
	q = (pnode*)malloc(sizeof(pnode));
	q->next = NULL ;
	(*h)->front = (*h)->rear = q ;
}

