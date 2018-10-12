#include<stdio.h>
#include<stdlib.h>
#define SEP "\n-------------------------------------------------\n"
typedef struct list{
	
	int data ;
	struct node * next ;

}listnode ,*linklist ;

void init_list(linklist* h) ;
void input_data(linklist h) ;
void add_in(linklist pro , linklist newnode);
void prt(linklist h);
void destroy_list(linklist h);
void turn_back(linklist h);

int main(){

	linklist h ;
	
	init_list(&h);
	input_data(h);
	printf("初始数据如下：");
	printf(SEP);
	prt(h);

	printf("逆置后：");
	printf(SEP);
	turn_back(h);
}

void turn_back(linklist h){

	
	linklist p ,q;
	linklist h2 ;
	init_list(&h2);
	p = h -> next ;
	h->next = NULL ;
	q = p ;
	while( p != NULL ){

		q = p ;
		p = p->next ;
		q -> next = h->next ;
		h -> next = q ;
	}
	prt(h);
	destroy_list(h);
}

//打印数据
void prt(linklist h){

	linklist p ;
	p = h->next ;
	while(p != NULL){
		
		printf("%d\n",p->data);
		p = p->next ;
	}
}

//销毁链表
void destroy_list(linklist h){

	linklist tmp ,p;
	tmp = h->next ;
	while(h->next != NULL){
		p = tmp ;
		tmp = tmp ->next ;
		h->next = tmp ;
		free(p);
	}
	free(h);
}

//往单链表中添加节点
void add_in(linklist pro ,linklist newnode){

		newnode->next = pro ->next ;
		pro ->next = newnode ;
}

//录入数据,尾插
void input_data(linklist  h){

	linklist p ,tmp ;
	tmp = h ;
	printf(SEP);
	int n ;
	while(1){

		printf("请输入数据(输入-1结束)：");
		scanf("%d",&n);
		if(n == -1)break ;
		p = (linklist)malloc(sizeof(listnode));
		p->data = n ;
		add_in(tmp , p);
		tmp = tmp->next ;//这一操作上面函数内进行就成头插?为什么?
	}
}

//初始化线性表
void init_list(linklist * h){

	linklist p ;
	*h = NULL ;
	(*h) = (linklist)malloc(sizeof(listnode));
	(*h)->next = NULL ;
}
