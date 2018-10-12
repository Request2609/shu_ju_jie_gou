/*************************************************************************
	> File Name: zhuan_zhi.c
	> Author: chang
	> Mail: xxxxx
	> Created Time: Sun 07 Oct 2018 12:06:38 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define SEP "\n\n-----------------------------------------------------------------\n"
typedef struct {

    int col , row ;
    int value ;

}triple;

typedef struct {

    triple data[MAXSIZE];
    int rows ,cols ,nums ;
}TSMartrix ;

int init_TS(TSMartrix* A);
void Print(TSMartrix* A);
void getTurn(TSMartrix* A,TSMartrix* B);

int main(){
    
    TSMartrix A , B;
    if(init_TS(&A)==0)return 0;
    Print(&A);
    
    printf(SEP);
    B.cols = A.cols ;
    B.rows = A.rows ;
    B.nums = A.nums ;

    getTurn(&A,&B);
}

void getTurn(TSMartrix* A,TSMartrix* B){

    if(A->nums <= 0)return  ;
    int nums[MAXSIZE];
    int  col= 0 ,i;
    for(col = 1 ; col <= A->nums ;col++){  
        
        nums[col] = 0 ;
    }

    for(i = 1 ; i <= A->nums ; i++ ){
    //every column has how many numbers    
        nums[A->data[i].col]++ ;
    }
     
    int pos[MAXSIZE];
    pos[1] = 1 ;
    //ji suan gai hang shou ge shu zi de di zhi
    for(i = 2 ; i < A->nums ; i++){
        
        pos[i] = pos[i-1]+nums[i-1];
    }

    //zhuan zhi 
    int  j ;
    for(i = 1 ; i <= B->nums ; i++ ){

        //ben hang yuan su de wei zhi 
        j = pos[A->data[i].col] ;
        B->data[j].row = A->data[j].col ;
        B->data[j].col = A->data[j].row ;
        B->data[j].value =A->data[j].value ;
        //zhi xiang gai hang xia yi ge yan su de cun chu wei zhi 
        pos[j]++ ;
    }
    printf("After turn up\n");
    printf(SEP);
    Print(B);
}

//Print square
void Print(TSMartrix * A){
    
    int  k= 1 ;
    while(A->nums > k){

        printf("%d  %d  %d\n",A->data[k].row ,A->data[k].col,A->data[k].value);
        k++ ;
    }
}


int init_TS(TSMartrix *A){
    
    int  i = 0 ,j = 0;
    printf(SEP);
    printf("Input rows:");
    scanf("%d",&(A->rows));
    printf("Input cloumns:");
    scanf("%d",&(A->cols));
    printf(SEP);
    printf("Input data in square");
    printf(SEP);
    A->nums = 0 ;
    while(1){
        (A->nums) ++ ;    
        while(1){
            printf("Input the num column:");
            scanf("%d",&(A->data[A->nums].col));
            if(A->data[A->nums].col > A->cols){
                printf("erorr!\n");
                return 0;
            }
            printf("Input the num row:");

            scanf("%d",&(A->data[A->nums].row));
           if(A->data[A->nums].row > A->rows){
                
                printf("error!\n");
                return 0 ;
            }
            break;
        }
        printf("Input the num(0 end):");
        scanf("%5d",&(A->data[A->nums].value));
        if(A->data[A->nums].value== 0)break;
    }
        (A->nums)-- ;
        return 1 ;
}

