/*************************************************************************
	> File Name: guang.c
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Oct 2018 07:47:35 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{

    int col ,row ;
    int value ;
    
   struct node * right,* down ; 
}node_t;
typedef struct {

    int rows ,cols ,nums;
    node_t * rowhead,*colhead ;
}ls;
void createlist(ls_node*ls,int m ,int n);


int main(){

    ls * ls_node ;
    int  m,n ;
    int a[m][n];
    //init "a" ju zhen
    createlist(ls,m,n);

}

void createlist(ls_node* ls,int row,int col){
        
    int i = 0 ;
    ls = malloc(sizeof(ls_node));
    ls->rows = row ;
    ls->cols = col ;
    ls->nums = row*col ;
    ls->rowhead = malloc(row*sizeof(node_t));
    if(ls->rowhead== NULL){

        printf("init rowhead failed!");
        return ;
    }

    for(i = 0 ;i < row ;i++){
        ls->rowhead[i]=NULL ;
    }

    ls->colhead = malloc(col*sizeof(node_t));
    if(ls->colhead[i]== NULL){

            printf("colhead init failed!\n");
            return ;
    }
    for( i= 0 ;i < col ;i++ ){
        
        ls ->colhead[i] = NULL ;
    }
    int j ;
    for(i = 0 ;i< row ;i++){
        for(j = 0 ;j< col ;j++){
            if(a[i][j] != 0){
                
            }
        }
    }
    
}
