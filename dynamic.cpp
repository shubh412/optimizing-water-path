#include<iostream>
using namespace std;
int d1[100],d2[100],p[100];
int min(int a[],int n,int c[],int d[],int q)
{int m=a[0],t=0;
for(int i=0;i<n;i++)
{if(a[i]<m)
{m=a[i]; t=i;}
}
d[q]=c[t];
return m;
}
int main()
{ int n,f1[100][2],f12[100][2],f123[2][2];
f123[0][0]=6;
f123[1][0]=7;
f123[0][1]=f123[1][1]=0
; cout<<"\nvalue of n: ";
cin>>n;
int j=0;
int
k=0;
int x;
cout<<"\nLevel 1: Critcial Points connected to Target\n";
for(int i=1;i<=n;i++)
{
 cout<<"\nDistance between "<<i<<" and L:";
 cin>>x;
if(x!=0)
9
{f1[j][0]=i;
f1[j][1]=x;
j++;
}
else if(x==0)
{f12[k][0]=i;
f12[k][1]=0;
k++;
}
}
int c[100];
if(k!=0)
{cout<<"\nLevel 2: Critcial Points connected to Source(s)\n";
for(int i=0;i<k;i++)
{int a=0,f12m[100];
for(int l=0;l<j;l++)
{ cout<<"\nDistance between "<<f12[i][0]<<" and "<<f1[l][0]<<":";
cin>>x;
if(x!=0)
{f12m[a]=x+f1[l][1];
c[a]=f1[l][0];
a++;
}
}
f12[i][1]=min(f12m,a,c,d1,i);
}
}
else{
{f12[k][0]=f1[0][0];
f12[k][1]=f1[0][1];
k++;
}}
cout<<"\nLevel 3: Distance between Level 2 points and Source(s)\n";
for(int i=0;i<2;i++)
{int b=0,f123m[100];
10
for(int l=0;l<k;l++)
{ cout<<"\nDistance between "<<f123[i][0]<<" and "<<f12[l][0]<<":";
cin>>x;
if(x!=0)
{f123m[b]=x+f12[l][1];
c[b]=f12[l][0];
b++;
}
}
f123[i][1]=min(f123m,b,c,d2,i);
}
int i;
if(f123[0][1]<f123[1][1])
{i=0;}
else
i=1;
p[0]=d1[i]; p[1]=d2[i];
int m;
if(f123[0][1]>f123[1][1])
{m=f123[1][1]; p[2]=f123[1][0];}
else
{m=f123[0][1]; p[2]=f123[0][0];}
cout<<"--------------------------------\nPath: "<<p[2]<<"->"<<p[1]<<"-
>"<<p[0]<<"->L"<<"\n\nTotal Minimum Distance: "<<m;
return 0;
}
