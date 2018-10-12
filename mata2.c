/*************************************************************************
	> File Name: mata2.c
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Oct 2018 02:26:23 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#include<string.h>
typedef struct node{
    int x ,y ;
    
    int d ;
    struct node * next ;
}node_t ;

typedef struct st{
    node_t* top ;
}st_node;

int can_go(int x, int y);
int next_dir(node_t cur);
void init(st_node * s);
void gomap(st_node* s ,node_t *cur);
void freenode(st_node *s);
int  ok(int x ,int y);
int  cango(node_t * cur,node_t ** next);
void push(st_node* s,node_t*cur);
void print();
const int a[2][9] = {{-2,-1,1,2,2,1,-1,-2},{1,2,2,1,-1,-2,-2,-1}};

int step =0;
int map[8][8];

int main(){
    memset(map,0,sizeof(map));    
    st_node* s ;
    int m,n ;
    s = (st_node*)malloc(sizeof(st_node));
    init(s);
    scanf("%d%d",&m,&n);       
    node_t* cur ;
    cur = malloc(sizeof(node_t));
    cur ->x = m-1 ;
    cur ->y = n-1 ;
    cur->d =  0 ;
    gomap(s,cur);
    print() ;
    freenode(s);
}

void freenode(st_node* s){
    
    node_t * p;
    p = s->top ;
    while(p){
        s->top = s->top->next ;
        free(p);
        p = s->top ;
    }
}

void print(){
    
    int i,j ;
    for(i = 0;i < 8;i++ ){
        printf("\n");
        for(j = 0 ;j< 8 ;j++){

            printf("%2d ",map[i][j]);
        }
    }

}

void push(st_node* s ,node_t* cur){

    cur->next = s->top ;
    s->top = cur;
    
}

void gomap(st_node* s ,node_t *cur){
    node_t *next ;
    step++ ;
    map[cur->x][cur->y]= step;
    push(s,cur);
    int flag ;
    while(step != 64){
        flag =cango(cur,&next);
        if(flag >= 0){
            step++ ;
            (cur->d) ++;
            push(s,next);
            cur = s->top ;
            cur->d = 0 ;
            map[cur->x][cur->y] = step ;
        }
        else{
            step-- ;
            map[cur->x][cur->y] = 0 ;
            s->top = cur->next;
            free(cur);
            cur = s->top ;
        }
    }
}

int cango(node_t * cur,node_t ** next){
    
    int i = 0 ;
    *next = malloc(sizeof(node_t));
    for(i = cur->d ;i<8;i++ ){
        (*next)->x = cur->x+a[0][i];
        (*next)->y = cur->y+a[1][i];
        
        if(ok((*next)->x,(*next)->y)){

            cur->d = i ;
            return  i ;
        }
    }
    free(*next);
    return -1 ;

}

int ok(int x ,int y){
    if(x>=0&&x<8&&y>=0&&y<8&&map[x][y] == 0){
        return 1 ;
    }
    return 0 ;
 }
void init(st_node* s){
    
    node_t * p= NULL ;
    p = malloc(sizeof(node_t));



    p->next = NULL ;
    s->top = p ;
}

