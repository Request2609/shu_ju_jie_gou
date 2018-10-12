/*************************************************************************
	> File Name: m.c
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Oct 2018 10:55:22 PM PDT
 ************************************************************************/

#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int flag=1;
int num[500][500];
int dis[500][500];
int sx,sy;
int n=8,m=8;
int dir[8][2]={{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
struct node
{
  int x;
  int y;
};
int bfs()
{
	int i;
  queue<node>que;
  memset(dis,-1,sizeof(dis));
  node p;
  p.x=sx;
  p.y=sy;
  que.push(p);
  dis[sx][sy]=0;
  while(!que.empty())
  {  flag++;
     node tmp=que.front();
     que.pop();
     if(flag==n*m) break;
     for(i=0;i<8;i++)
     {
        int nx=tmp.x+dir[i][0];
        int ny=tmp.y+dir[i][1];
       if(dis[nx][ny]==-1&&nx<=m&&nx>0&&ny<=n&&ny>0)
          { 
            node next;
            next.x=nx;
            next.y=ny;
            que.push(next);
            dis[nx][ny]=dis[tmp.x][tmp.y]+1;
      }
     }
  }
  return dis[sx][sy];
}
int main()
{
	int i;
  scanf("%d%d",&sx,&sy);
  bfs();
    for(i=1;i<=m;i++)
	printf("\n");
      for(int j=1;j<=n;j++)
        {
            
            printf("%3d",dis[i][j]);
  
             }
}

