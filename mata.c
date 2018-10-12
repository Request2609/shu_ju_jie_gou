/*************************************************************************
	> File Name: mata.c
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Oct 2018 12:25:59 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define N 100
#include<stdlib.h>
#include<string.h>
#define N 100
typedef struct node{
	
    int x ,y ;
    int step ;
    int data;
	struct node *next ;
}s_node;

typedef struct queue{
	s_node * top;
}q_node;
void init_q(q_node * q); 

void push(q_node* s , s_node *q );
void pop(q_node * s );
void gomap(q_node *q);
int  map[N][N];
int jumpout(int x ,int y);
const int tip[N][N]= {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
int main(){

	
	q_node  *q = NULL ;
	q = malloc(sizeof(q_node));
	init_q(q);
    gomap(q);
}

void gomap(q_node*q){
    
    int x ,y ;
    while((scanf("%d%d",&x,&y))!=EOF){
        s_node*  p ;
        p =malloc(sizeof(q_node));
        p ->x = x ;
        p ->y = y ;
        p->step = 1 ;
        p->data = map[p->x][p->y];
        map[x][y] = 1;
        push(q,p);
        while(p->step == 64){
            
            

        }
            

    }

}

//初始化栈 
void init_q(q_node * q ){
	
	s_node * p = NULL ;
	p = malloc(sizeof(s_node));
	q->top= p ;
}

//将数据压入栈中 
void push(q_node * s ,s_node *q){
	q ->next = s->top;
	s->top = q ;
}

//弹出数据 
void pop(q_node * s ){
	
	s_node *p ;
	p = s->top ;
	s->top = p->next ;
    free(p);
}
