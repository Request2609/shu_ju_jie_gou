/*************************************************************************
	> File Name: migong.c
	> Author: 
	> Mail: 
	> Created Time: Mon 08 Oct 2018 04:30:31 AM PDT
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
typedef struct node{
	//分别代表x坐标，y坐标，方向 
	int x, y , d ;
	struct node *next ;
}s_node;

typedef struct queue{
	s_node * top;
	s_node data;
}q_node;
void init_q(q_node * q);
void goMap(q_node * q,int row ,int col); 
void push(q_node* s , s_node *q );
void pop(q_node * s );
void Print(q_node*s);
char  map[N][N];
char map1[N][N] ;
int main(){
	
	q_node  *q = NULL ;
	q = malloc(sizeof(q_node));
	init_q(q);
	int i ,j ;
	int row ,col ;
	scanf("%d%d",&row,&col);

    memset(map , 0 ,sizeof(map));
    for(i = 0 ;i < row ; i++){
        scanf("%s",map[i]);
        getchar();
	}
    memset(map1 ,0 ,sizeof(map1));
    for( i= 0 ;i <= row+1 ;i++){
        for(j = 0 ;j<= col+1 ;j++ ){
            if(i == 0||j == 0 || i == row+1 ||j == col+1){
    
                map1[i][j] = '1';
            }
            else{
                 map1[i][j] = map[i-1][j-1];      
            }
        }
    }
    
	goMap(q,row ,col); 
    Print(q);
}


void Print(q_node *s){
    s_node * q ,* p ,*h = NULL;
    
    h= (s_node*)malloc(sizeof(s_node));

    h->next = NULL;
    q = s->top ;
    while(q->next != NULL){
        p = (s_node*)malloc(sizeof(s_node));
        
        p->x = q->x ;
        p->y = q->y ;
        p-> d = q->d ;
        p->next = h->next ;
        h->next = p ;
        s->top = q->next ;
        free(q);
        q = s->top ;
    }
    s_node *tmp = h ;
    p = tmp->next ;
    while(p){
        printf("(%d ,%d ,%d )",p->x ,p->y ,p->d);
        free(tmp) ;
        tmp = p ;
        p = p->next ;
    }
    printf("\n");
}
void goMap(q_node * q,int row ,int col){
	s_node *p ;
	p = malloc(sizeof(s_node));
	p->x = 1 ;
	p->y = 1;
    map1[p->x][p->y] = 1 ;
	push(q,p);
    while(q->top->x != row || q->top->y != col){    
        if(map1[q->top->x][q->top->y+1] =='0'){
            q->top->d = 1 ;
            p = malloc(sizeof(s_node));
            p->y = q->top->y+1 ;
            p->x = q->top->x;
            map1[p->x][p->y] = '1' ;
            push(q,p);
            continue ;
        }

        if(map1[q->top->x+1][q->top->y] =='0'){
            q->top->d = 2 ;
            p = malloc(sizeof(s_node)); 
            p->x = q->top->x+1 ;
            p->y = q->top->y ;
            map1[p->x][p->y]= '1' ;
            p->d = 2 ;
            push(q , p );
            continue ;
        }
        if(map1[q->top->x][q->top->y-1] == '0'){
           q->top->d = 3 ;    
            p = malloc(sizeof(s_node));
            p->x = q->top->x ;
            p->y = q->top->y-1 ;
            p->d = 3;
            map1[p->x][p->y] = '1' ;
            push(q,p);
            continue ;
        }
        if(map1[q->top->x-1][q->top->y] =='0'){
            q->top->d = 4;        
            p = malloc(sizeof(s_node));
            p->x = q->top->x -1;
            p->y =q->top->y ;
            p->d = 4 ;
            map1[p->x][p->y] ='1' ; 
            push(q,p);
            continue ;
        }
        if(map1[q->top->x -1][q->top->y] != '0'&&map1[q->top->x+1][q->top->y]!='0'&&map1[q->top->x][q->top->y-1]!='0'&&map1[q->top->x][q->top->y+1]!='0'){
            
            pop(q);

        }
    }
    q->top->d = 0 ;
    return  ;
}
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

