/*************************************************************************
	> File Name: guang_yi.c
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Oct 2018 07:29:28 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef enum{
    ATOM ,LIST
}Elemtag;
//kuo zhan cun chu (1,(1,3),(2,3),9)
typedef struct GLNode{

    Elemtag tag ;
    union{

        int atom ;
            
        struct GLNode* hp ;
    }a;
    struct GLNode*tp ;

}*GList ,GLNode ;
void InitLs(GList * ls);
void SaveList(GList *ls);

int main(){

    GList  ls ;
    ls = (Glist)malloc(sizeof(GLNode));
    Init_LS(ls);
    printf("Input list data");
    SaveList(ls);
}

//cun chu guang yi biao yuan su
//kuo zhan cun chu (1,(1,3),(2,3),9)
void SaveList(GList * ls){
        
    
       

}
void InitLs(GList* ls){
        
    ls = NULL ;
    
}
