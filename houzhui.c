/*************************************************************************
	> File Name: houzhui.c
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Oct 2018 06:31:45 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
typedef struct node{

    char ch ;
    int pow ;
    struct node* next ;

}node_t;

typedef struct s_node{
    
    node_t * top ;
}s_node ;

int getpow(char ch);
void init(s_node* s);
void push(s_node* s ,node_t *p);
void pop(s_node*s);
void zhuan(s_node* s);
int isfuhao(char ch);
void pushwhile(char ch,s_node* s);
void popwhile(s_node *s);
int cmp(char sch1,char qch);
int main(){
    
    s_node* s ;
    s = malloc(sizeof(s_node));
    init(s);
    zhuan(s);
}

int getpow(char ch){
    
    switch(ch){

        case '*':
            return 2 ;
        case '/':
            return 2 ;
        case '-':
        
            return 1;
        case '+':
            return 1 ;
    }

}
int isfuhao(char ch){

    switch(ch){

        case '*':
        case '+':
        case '/':
        case '-':
        case '(':
        case ')':
            return 1 ;
        default:
            return 0 ;
    }
}
void pushwhile(char ch,s_node* s){
    
    node_t*q ;
    q = s->top;
    while(1){
        
        if(q->pow >= getpow(ch)){
        
            s->top = q->next;
        
            free(q);
            q = s->top ; 
        }
        else{
            q = malloc(sizeof(node_t));
            q->ch = ch;
            ch = getpow(ch);
            push(s,q);
            break ;
        }
    }
}

void zhuan(s_node* s){
    char str[N];
    scanf("%s",str);
    strcat(str,"#");
   // printf("huhuhi(%s)\n",str);
    int num = 0 ,i=0;
    char ch = *(str+i);
    while(ch != '#'){
        
        if(!isfuhao(ch)){
            
            num = num*10 + (ch-'0');
            i++ ;
        }
        else if(ch == '('){
            node_t* q ;
            q = malloc(sizeof(node_t));
            push(s,q);
            i++ ;
        }
        else if(ch == ')'){
            popwhile(s);
            i++ ;
        }
        else if(ch ==' '){
                i++ ;
        }
        else{
            pushwhile(ch,s);
            printf("%d",num);
            num = 0 ;
            i ++ ;
        }
        ch = *(str+i);
    }

    node_t * h ;
    h = s->top ;
    while(h->ch!= '#'){
        s->top = h->next ; 
        printf("%c",h->ch);
        free(h);
        h = s->top;
    }
    free(h);
}

void popwhile(s_node * s){
    
    node_t* p ;
    p = s->top ;
    while(p->ch!= ')'){
        s->top = p->next ;    
        printf("%c",p->ch);
        free(p);
        p =s->top ;
    }
    s->top = p->next ;
    free(p);
}

void init(s_node* s){
    
    node_t *p=NULL ;
    p = malloc(sizeof(node_t));
    p->next = NULL ;
    p->ch = '#';
    p->pow = 0 ;
    s->top = p ;
}
void push(s_node* s ,node_t* p){
    
    p->next = s->top ;
    s->top = p ;
}

void pop(s_node* s){
    

    node_t* p ;
    p = s->top ;
    s->top = p->next ;
    free(p);
}
