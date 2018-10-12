/*************************************************************************
	> File Name: huiwen.c
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Oct 2018 11:12:44 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
typedef struct node{

    char ch ;
    struct node*next ;
}node_t;

typedef struct s_node{

    node_t* top ;

}s_node;

int isTurnNum(const char * str);
void init(s_node* h);
void push(s_node * h ,node_t *q);
void pop(s_node * h );
int  main(){

    char str[N];
    while((scanf("%s",str))!=EOF){
        
        if(isTurnNum(str)){

            printf("is hui wen!\n");
        }
        else{

            printf("is not hui wen!\n");
        }
    }
}


void pop(s_node * h ){
            
    node_t *q ;
    q = h->top ;
    h->top = h->top->next ;
    free(q);
}

void push(s_node* h ,node_t *p){
    
    p->next = h->top->next ;
    h->top= p ;
}
void init(s_node* h){
    
    h->top = malloc(sizeof(node_t));
    node_t * p=NULL ;
    p = malloc(sizeof(node_t));
    p->next = NULL ;
    h->top =  p ;
}
int isTurnNum(const char * str){
    
    s_node *h ;
    h = (s_node*)malloc(sizeof(s_node));
    init(h);
    node_t * q;
    q = (malloc(sizeof(node_t)));
    int  i = 0 ;
    int len ;
    len = strlen(str);
    while(1){
        if( i > len/2 ){
            free(q);
            break ;
        }
        q->ch = *(str+i);
        push(h,q);
        q = malloc(sizeof(node_t));
        i++ ;
    }
    if(len%2 == 1){

        i = len/2+1 ;
    }
    else{
        
        i = len/2 ;
    }
    while(1){
        if(h->top->ch == *(str+i)){
            
            pop(h);
        }
        else{
		
            return 0 ;
 
       }
    }
    return 1 ;
}
