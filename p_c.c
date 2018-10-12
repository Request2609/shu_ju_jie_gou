#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>
#define random(x,y) (rand()%(y-x)+x)//生成x->y的随即数
pthread_cond_t cond ;

pthread_mutex_t mutex;
typedef struct data{

	int data ;
	struct data* next ;
}data_t ;

typedef struct node{
	int a ;
	data_t * rear ;
	data_t * front ;
}node_t ,*nodelist ;
nodelist h ;//队头
void * producer(void * arg);
void * consumer(void * arg);
void init_queue(nodelist* h);
void input_data();

void init_queue(nodelist* h){
	
	data_t *p ;
	p = malloc(sizeof(data_t));
	*h = malloc(sizeof(node_t));	
	p->next = NULL ;
	(*h)->rear = (*h)->front= p ;
}

void input_data(){
	
	srand((int)time(0));
	data_t* p ;
	int x = 1 , y = 100 ;
	p = (data_t *)malloc(sizeof(data_t));
	p->next = NULL;
	p->data = random(x,y);
	
	h->rear->next = p ;
	h->rear =  p ;
	printf("\n生产者产出%d",p->data);

}

void * consumer(void * arg){

	data_t* q ;
	while(1){
		
		if(h->front == h->rear)pthread_cond_wait(&cond , &mutex);
		pthread_mutex_lock(&mutex);
		q = h->front ;
		h->front = q->next;
		printf("\n消费者拿出%d",h->front->data);
		free(q);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
		sleep(1);
	}
}

void * producer(void * args){

	while(1){
			pthread_mutex_lock(&mutex);
			input_data();
			h->front = h->front->next ;
			printf("%d\n",h->front->data);
			pthread_mutex_unlock(&mutex);
			pthread_cond_signal(&cond);
			sleep(1);
	}
}

int main(){
	
	
	init_queue(&h);
	int status ;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	pthread_t thid1 ,thid2 ;
	pthread_create(&thid1 , NULL ,(void *)&producer , NULL);
	pthread_create(&thid2 , NULL , (void *)&consumer ,NULL);
	pthread_join(thid1 , (void *)&status);
	pthread_join(thid2 , (void *)&status);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
}
