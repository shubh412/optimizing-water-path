#include<stdio.h>
#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1
void findpath(int s,int v);
void Dijkstra(int s);
int min_temp();
void create_graph();
int n; /*Denotes number of vertices in the graph*/
int adj[MAX][MAX];
int predecessor[MAX];
int pathLength[MAX];
int status[MAX];
main()
{
int s,v;
create_graph();
while(1)
{
14
printf("Enter source vertex(-1 to quit) : ");
scanf("%d",&s);
if(s==-1)
break;
Dijkstra(s);
printf("Enter destination vertex: ");
scanf("%d",&v);
if(v<0||v>=n)
printf("The vertex does not exist: ");
else if(v==s)
printf("Source and destination vertices are same");
else if(pathLength[v]==infinity)
printf("there is no path from source to destination");
else
findpath(s,v);
}
}/*End of main()*/
void Dijkstra(int s)
{
int i,current;
/*Make all vertices temporary*/
for(i=0;i<n;i++)
{
predecessor[i]= NIL;
15
pathLength[i] = infinity;
status[i]=TEMP;
}
/*Make pathLength of source vertex equql to zero*/
pathLength[s]=0;
while(1)
{
/*Search for minimum pathlength and make it current vertex*/
current=min_temp();
if(current==NIL)
return;
status[current]=PERM;
for(i=0;i<n;i++)
{
/*checks for adjacent temporary vertices*/
if(adj[current][i]!=0 && status[i]==TEMP)
if(pathLength[current]+adj[current][i]<pathLength[i])
{
predecessor[i]=current;
pathLength[i]=pathLength[current] +adj[current][i];
}
}
}
}
16
/*End of Dijkstra*/
/*returns the temporary vertex with minimum value of pathlength,
Returns NIL if no
temporary
vertex left or all temporary vertices left have path length infinity*/
int min_temp()
{
int i;
int min = infinity;
int k = NIL;
for(i=0;i<n;i++)
{
if(status[i]==TEMP && pathLength[i]<min)
{
min=pathLength[i];
k=i;
}
}
return k;
}
/*End of min_temp()*/
void findpath(int s,int v)
{
int i,u;
17
int path[MAX];/*Stores the shortest path*/
int shortdist=0;/*length of shortest path*/
int count =0;/*number of vertices in the shortest path*/
/*Stores the full path in the array path*/
while(v!=s)
{
count++;
path[count]=v;
u=predecessor[v];
shortdist += adj[u][v];
v=u;
}
count++;
path[count]=s;
printf("Shortest Path is: ");
for(i=count; i>=1; i--)
printf("%d ",path[i]);
printf("\n Shortest distance is : %d\n",shortdist);
}/*End of findpath()*/
void create_graph()
{
int i ,max_edges,origin,destin,wt;
printf("Enter the number of vertices: ");
scanf("%d",&n);
18
max_edges=n*(n-1);
for(i=1;i<=max_edges; i++)
{
printf("Enter edge %d Origin followed by Destination(-1 -1 to
quit)\n", i);
scanf("%d%d",&origin,&destin);
if((origin==-1)&&(destin==-1))
break;
printf("Enter weight for this edge : ");
scanf("%d",&wt);
if(origin>=n || destin>=n || origin<0 || destin<0)
{
printf("invalid edge!\n");
i--;
}
else
adj[origin][destin]=wt;
}
}
