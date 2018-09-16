#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

typedef struct list {
	
	int data ;
	struct list *next ;
}list , *plist ,**pplist;

void pop_front(plist head , int * out);
void push_front(plist head , int d);
void isempty(plist l);
void * producter((void *)arg);
void * consumer((void *)lock);
void free_node(plist l);
void destroy(plist head);
plist alloc_node(int d , plist l);

plist head ;

pthread_cond_t  cond  =PTHREAD_COND_INITIALIZER ;

plist alloc_node(int d , plist l){

	plist tmp  = (plist)malloc(sizeof(list));
	if(!tmp){
		
		perror("malloc");
		exit(1);
	}
	tmp->data = d ;
	tmp ->nexp = l ;
	return tmp ;
}

void isempty(plist l){
	
	return l->next == NULL ? 1:0 ;
}

void free_node(plist l){
	if(l != NULL){
		
		free(l);
		l = NULL ;
	}
}

void destroy(plist l){
	
	int data ;
	while(!isempty(l)){
	
		pop_front(l , &data);
	}
	free_node(1);
}
void pop_front(plist l , int * out){
	
	if(!isempty(l)){
	
		plist tmp = l->next ;
		l->next =tmp ->next ;
		*out = tmp ->data ;
		free_node(tmp);
	}
}

void * consumer((void *)lock){
	
	pthread_mutex_t * lockp = (pthread_mutex_t*)lock ;
	int data = 0;
	while(1){
		
		pthread_mutex_lock(lockp);
		while(isempty(head)){
			
			pthread_cond_wait(&cond,&lockp);
		}
		pop_front(head , &data);
		printf("consume done:%d\n",data);
		pthread_mutex_unlock(lockp);
		pthread_cond_signal(&cond);
	}
}

void push_front(plist head , int d){
	
	plist tmp = alloc_node(d ,NULL);
	tmp ->next  = l->next ;
	l->next = tmp ;
}

void * producter((void *)arg){
	
	pthread_mutex_t * lockp = (pthread_mutex_t*)arg ;
	int data=0;
	while(1){
	
		pthread_mutex_lock(lockp);
		data = rand()%1234 ;
		push_front(head , data);
		printf("product data:%d\n",data );
		pthread_mutex_unlock(&lockp);
		pthread_mutex_signal(&cond);
	}
}
int main(){

	pthread_muetex_t lock ;
	pthread_mutex_init(&lock ,NULL);
	initlist(&head);
	pthread_t consume , product ;
	pthread_create(&consume , NULL , consumer ,(pthread_mutex_t *)&lock);
	pthread_create(&product ,NULL , producter ,(pthread_mutex_t*)&lock);
	pthread_join(consume ,NULL);
	pthread_join(product ,NULL);
	destroy(head);
	pthread_mutex_destroy(&lock ); 
	return 0 ;
}
