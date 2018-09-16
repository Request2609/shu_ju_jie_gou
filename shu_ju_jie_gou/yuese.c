#include<stdio.h>
#include<stdlib.h>
#define SEP "-----------------------------------------------"

typedef struct node{

	int id ;
	int psd;
	struct node *next ;
}node_t ,*linklist ;
void init_list(linklist h);
int input_data(linklist h);
void prt(linklist h);
void add_node(linklist pro, linklist node);
void free_node(linklist h ,linklist p);
void out(linklist h ,int flag , int n);

int main(){
	
	linklist h ;
	h = NULL;
	h = (linklist)malloc(sizeof(node_t));
	init_list(h);
	printf("\n");
	printf(SEP);
	int p ;
	printf("\n请输入原始密码：");
	scanf("%d",&p);
	int n = input_data(h);
	prt(h);
	out(h , p , n);
}

void out( linklist h , int flag , int n){
 
	linklist p ,q;
	q = h ;
	p = h->next ;
	int i = 1;
	printf("\n");
	printf(SEP);
	printf("****%d****\n",n);
	getchar();
	printf("\n出队顺序：\n");
	while(1){
		
		if(i == flag ){

			if(p == h){
				
				p = h->next ;
			}
			
			printf("\n密码：%d , ID：%d\n",p->psd,p->id);
			q->next = p->next ;
			free(p);
			p = q->next ;
			getchar();
			flag = p->psd ;
			i = 0;
			n -- ;
			i ++ ;
			continue ;
		}
		if(n == 0)break ;
		q= p ;
		p= p->next ;
		i ++ ;
	}
	
	free(h);
}

void free_node(linklist h ,linklist p){
	
	linklist q,tmp ;
	tmp = h ;
	if(p == h ){
		free(h);
		return ;
	}
	q = h->next;
	while(q != h){
		
		if(q == p){

			tmp->next = p->next ;
			free(p);

		}
		tmp = q ;
		q = q->next ;
	}
}

void add_node(linklist pro, linklist newnode){

	newnode->next = pro->next  ;
	pro->next = newnode;
	
}

void prt(linklist h){

	linklist p ;

	p = h->next ;
	printf("\n\n");
	printf(SEP);
	while(1){
		
		printf("\n密码：%d , ID：%d\n",p->psd,p->id);
		p = p->next ;
		if(p == h){
			break ;
		}
	}	
	
}

void init_list(linklist h){

	linklist p ;
	p = h ;
	p->next = h;
	h->id = 0 ;
	linklist q ;

	q = h->next ;

}

int input_data(linklist h){

	linklist p,q ;
	int i = 0,n ,k ;
	printf("\n请输入成员个数：");
	scanf("%d",&n);
	k = n ;
	printf("\n");
	printf(SEP);
	q = h ;
	while(1){
		
		if(n == 0)break ;
			
		p = (linklist)malloc(sizeof(node_t));
	
		printf("\n\n请输入密码:");
		scanf("%d",&p->psd);
		i ++ ;
		p->id = i ;
		add_node(q , p);
		q = p ;
		n -- ;
	}
	return k ;
}

