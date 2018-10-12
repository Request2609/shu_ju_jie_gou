#include<stdio.h>
#include<stdlib.h>
typedef struct duoxiang{
	
	int xishu ;
	int zhishu ;
	struct duoxiang* next ;

}mem_t;
void input_data(mem_t * h);
void print_data(mem_t *h);
void add_two(mem_t *h1 ,mem_t *h2);
void free_node(mem_t * h) ;
void add_node(mem_t* pro , mem_t * newnode);
void sort(mem_t *h) ;


int main(){

	mem_t * h1,*h2 ;
	h1= (mem_t *)malloc(sizeof(mem_t)) ;
	h2= (mem_t *)malloc(sizeof(mem_t)) ;
	input_data(h1);
	input_data(h2);
	printf("\n多项式1.....  ：) \n");
	printf("----------------------------------------------------------------------\n");
	sort(h1) ;
	printf("p1 = ");
	print_data(h1);
	printf("\n多项式2.....  ：) \n");
	printf("----------------------------------------------------------------------\n");
	sort(h2) ;
	printf("p2 = ") ;
	print_data(h2);
	add_two(h1 ,h2);
	free_node(h1) ;
	free_node(h2) ;
}

//往新节点录入数据
void input_data(mem_t * h){
	
	mem_t *q ,*p ;
	int x , z ;
	h->next = NULL ;
	p = h ;
	printf("\n每次分别输入系数，指数两组数据,若输入的两个输同时为0，则表示输入结束\n");
	printf("----------------------------------------------------------------------\n");
	while(1){
		
		scanf("%d%d",&x ,&z);
		if(x == 0 && z == 0){
			break ;
		}
		q = (mem_t *)malloc(sizeof(mem_t)) ;
		q->xishu = x ;
		q->zhishu = z ;
		add_node(p , q) ;
	}
	
}

//给链表传入新节点
void add_node(mem_t * pro , mem_t * newnode ){

	newnode->next = pro->next ;
	pro->next = newnode ;
}

//打印多项式
void print_data(mem_t * h){

	mem_t *temp ;
	temp = h->next ;
	if(temp != NULL){
	
		if(temp->xishu < 0){
		
			printf("-");
		}
	}
	while(temp != NULL){
		
		if(temp->xishu < 0){
		
			if(temp->xishu != -1)printf("%d",-temp->xishu);
		
		}

		else{
			if(temp->xishu != 1){
				printf("%d",temp->xishu) ;
			}
		}

		if(temp->zhishu != 0){
			if(temp->zhishu != 1){
			
				printf("X^(%d)",temp->zhishu);

			}
			else{

				printf("X");
			}
		}
		temp = temp->next ;

		if(temp != NULL){
		
			if(temp->xishu > 0)	printf(" + ") ;
			else printf(" - ");

		}
	}
	printf("\n");
}

//释放链表空间
void free_node(mem_t * h){

	mem_t * temp , *q; 
	temp = h->next ;
	while(temp != NULL){
		
		h->next = temp->next ;
		free(temp) ;
		temp = h->next ;
	}
	free(h) ;
}

//对链表中指数进行从小到大排序
void sort(mem_t *h){

	mem_t *temp , *q , *p;
	int flag ;
	p =(mem_t *)malloc(sizeof(mem_t));
	temp = h->next ;

	while(temp != NULL){
		flag = 0 ;	
		q= temp->next ;
		while(q !=NULL){
	
			if(temp->zhishu > q->zhishu){
				flag = 1 ;
				p->xishu = temp->xishu ;
				p->zhishu = temp->zhishu ;
				temp->xishu = q->xishu ;
				temp->zhishu = q->zhishu ;
				q->xishu = p->xishu ;
				q->zhishu = p->zhishu ;
			}
	
			q = q->next ; 
		}
		if(flag == 0)break ;
		temp = temp->next ;
	}
}

//多项式相加,并显示结果
void add_two(mem_t * h1, mem_t *h2){
	
	mem_t * h3 ,*q , *p ;
	h3 = (mem_t *)malloc(sizeof(mem_t)) ;
	mem_t * tp1 ,*tp2 ;
	tp1 = h1->next ;
	tp2 = h2->next ;
	h3->next = NULL ;
	q = h3 ;
	while(tp1 != NULL && tp2 !=NULL){
		
		p = (mem_t*)malloc(sizeof(mem_t)) ;
		
		if(tp1->zhishu < tp2->zhishu){
			
			p->zhishu = tp1->zhishu ;
			p->xishu = tp1->xishu ;
			add_node(q , p);
			q= q->next ;
			tp1 = tp1->next ;
		}
		else if(tp1->zhishu > tp2->zhishu){
			p -> zhishu = tp2 -> zhishu ;
			p -> xishu = tp2-> xishu ;
			add_node(q , p) ;
			q= q->next ;
			tp2 = tp2->next ;
		}
		else{
		
			p -> xishu = tp1 -> xishu + tp2 -> xishu ;
			p -> zhishu = tp1->zhishu ;
			add_node(q , p);
			q = q->next ;
			tp1 = tp1-> next ;
			tp2 = tp2 -> next ;
		}

	}

	mem_t *temp = NULL ;
	if(tp1 != NULL){
	
		temp = tp1 ;
	}
	if(tp2 !=NULL){
		
		temp = tp2 ;
	}
	if(temp != NULL){
		while(1){
			printf("-------%d--%d----\n",temp->xishu,temp->zhishu);
			p = (mem_t* )malloc(sizeof(mem_t)) ;
			p->xishu = temp->xishu ;
			p->zhishu = temp->zhishu ;
			add_node(q , p);
			q =q-> next ;
			temp = temp->next ;
			if(temp == NULL)break ;

		}
	}

	printf("\n两多项式相加结果\n");
	printf("----------------------------------------------------------------------\n");
	sort(h3);
	print_data(h3) ;
	free_node(h3);
}
