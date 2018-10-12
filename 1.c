/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Oct 2018 09:50:10 PM PDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#define COL 8
#define ROW 8
//棋盘数据结构定义
typedef struct snode{
    int flag;
    int x;
    int y;
}Snode;

typedef struct node{
    int top;    //栈顶指针
    Snode *p;   //路径栈
}Node;

//初始化栈
Node *CreateStack(void)
{
    Node *s = (Node *)malloc(sizeof(Node));
    s->p = (Snode *)malloc(sizeof(Snode)*COL*ROW);
    s->top = 1;
    return s;
}

//入栈
void Push(Node *s,Snode e)
{
    s->p[s->top++] = e;
}

//出栈
void Pop(Node *s)
{
    s->top--;
}

//输出棋盘
void Print(int ar[][COL])
{
    for(int i = 0;i < ROW;i++) {
        for(int j = 0;j < COL;j++)
            printf("%3d",ar[i][j]);
    putchar('\n');
    }
}

void GetWay(Node *s,int ar[][COL])
{
    int flag;
    Snode e;
    int i;
    int ch[8][2] = {
        {1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}
    };
    scanf("%d %d",&e.x,&e.y);
    ar[e.x][e.y] = 1;
    

    //第一个元素入栈
    Push(s,e);
    while(s->top <= ROW*COL) {
        for(i = 0;i < 8;i++) {
            e.x = s->p[s->top-1].x + ch[i][0];
            e.y = s->p[s->top-1].y + ch[i][1];
            //若坐标没有超范围，并且未走过,则元素入栈
            if(e.x >= 0 && e.y >= 0 && e.x < ROW && e.y < COL && !ar[e.x][e.y] ) {

                //未退回来的
                if(flag) {
                    ar[e.x][e.y] = s->top;
                    e.flag = 1;
                    e.flag = i;
                    Push(s,e);
                    flag = 1; 
                    break;
                }
                //退回来的
                else {
                    if(s->p[s->top].flag < i)
                        flag = 1;

                }
            }
        }

        //无方向可走且未走完
        if(i == 8) {
            ar[s->p[s->top -1].x][s->p[s->top-1].y] = 0;
            Pop(s);
            flag = 0;
        }        
    }

}


int main()
{
    //初始化栈
    Node *s = CreateStack();
    //创建路径数组
    int ar[ROW][COL] = {0};
    GetWay(s,ar);
    Print(ar);
    return 0;
}
