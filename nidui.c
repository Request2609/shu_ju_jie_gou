/*************************************************************************
	> File Name: nidui.c
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Oct 2018 11:59:30 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct node{

    int data ;
    struct node* next ;
}node_t;
void init(node_t* h);
void input(node_t * h);
void output(node_t * h);
int main(){
    node_t * h=NULL ;
    h = malloc(sizeof(node_t));
    init(h);
    input(h);
    output(h);
}


void output(node_t * h){

    node_t *p,*q;
    p = h->next ;
    q = p->next ;
    printf("\ndata\n");
    while(p!=q){
        
        printf("%d",p->data);
        h->next = p->next ;
        free(p);
        p = q ;
        q = p->next ;
    }
    free(h);

}
void init(node_t* h){

    h ->next = h ;
}

void input(node_t*h){
    
    node_t* q,*p ;
    p = h ;
    int data ;
    printf("input -1 end\n");
    while(scanf("%d" ,&data)!= EOF&& data != -1){
        
        q = malloc(sizeof(node_t));
        q->data = data ;
        q->next = p->next  ;
        p->next = q ;
        q= q->next ;
    }
}

