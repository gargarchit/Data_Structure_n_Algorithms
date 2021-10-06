#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j,k,a,b,u,v,n,ne=1,ba_op=0;
int min,mincost=0,cost[10][10],parent[10];
int find(int);
int uni(int,int);
void kruskal_MST();
void main()
{
double clk;
clock_t starttime,endtime;
printf("\n\tImplementation of Kruskal's algorithm\n");
printf("\nEnter the no. of vertices:");
scanf("%d",&n);
printf("\nEnter the cost adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0) //if no direct path
cost[i][j]=999;
}
printf("The edges of Minimum Cost Spanning Tree are\n");
starttime=clock();
kruskal_MST();
endtime=clock();
clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
printf("\n\tMinimum cost = %d\n",mincost);
printf("The time taken is %f\n",clk);
printf("Basic operation executed %d times\n",ba_op);
}
void kruskal_MST()
{
while(ne < n)
{
for(i=1,min=999;i<=n;i++)
for(j=1;j <= n;j++)
{ ba_op++;
if(cost[i][j] < min)//basic operation
{
min=cost[i][j];
a=u=i;
b=v=j;
}
}
u=find(u);
v=find(v);
if(uni(u,v))
{
printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
mincost +=min;
}
cost[a][b]=cost[b][a]=999;
}
}
int find(int i)
{
while(parent[i])
i=parent[i];
return i;
}
int uni(int i,int j)
{
if(i!=j)
{
parent[j]=i;
return 1;
}
return 0;
}
