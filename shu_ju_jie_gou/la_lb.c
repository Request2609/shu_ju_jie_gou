#include<stdio.h>
#include<stdlib.h>
#define SEP "\n-------------------------------------------------\n"

typedef struct list{
	
	int data ;
	struct list* next ;

}listnode ,*linklist;

void init_list(linklist *h);
void input_data(linklist h);
void add_in(linklist pro ,linklist newnode);
void insert_list(linklist la ,linklist lb);
void destroy_list(linklist h);
void prt(linklist h);


int main(){

	linklist la ,lb;
	init_list(&la);
	init_list(&lb);
	printf("往表a输入数据：");
	input_data(la);
	printf("往表b输入数据：");
	input_data(lb);
	insert_list(la,lb);
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
//结合两个链表

void insert_list(linklist la , linklist lb){

	int find ,insert ; 
	printf("请输入a链表中的节点位置：");
	printf(SEP);
	printf("\n");
	scanf("%d",&find);
	printf("\n");
	printf("请输入b链表开始插的位置：");
	printf(SEP);
	scanf("%d",&insert);
	linklist p,s ;
	s = la ;
	p = la -> next ;
	while(p != NULL){

		find -- ;
		if(find == 0)break ;
		s =  p ;
		p = p ->next ;
	}

	if(find != 0){
		
		printf("超出检索范围!\n");
		destroy_list(la);
		destroy_list(lb);
		exit(0);
	}
	s->next = NULL ;
	linklist l ; 
	linklist q ;
	q = lb ;
	l = lb -> next ;
	while(l != NULL){
		insert -- ;
		if(insert == 0)	break ;
	 	q = l ;
		l = l ->next ;
	}
	if(insert != 0){
	
		printf("超出检索范围!\n");
		destroy_list(la);
		destroy_list(lb);
		exit(0);
	}
	linklist tmp ;
	tmp = p ;
	p = p->next ;
	while(1){
		
		if(p == NULL ){
			tmp ->next = l ;
			q->next = tmp ;
			break ;
		}
		tmp ->next = l ;
		q->next = tmp ;
		q = tmp;
		l = tmp -> next ;
		tmp = p ;
		p = p->next ;
	}

	printf("结合后的链表情况：");
	printf(SEP);
	printf("a表：\n");
	prt(la);
	printf("b表：\n");
	prt(lb);
	destroy_list(la);
	destroy_list(lb);
	
}

//往表中录入数据
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

//往链表中添加节点
void add_in(linklist pro ,linklist newnode){

		newnode->next = pro ->next ;
		pro ->next = newnode ;
}

//初始化链表
void init_list(linklist * h){
	
	*h = NULL ;
	(*h) = (linklist)malloc(sizeof(listnode));
	(*h)->next = NULL ;
}

