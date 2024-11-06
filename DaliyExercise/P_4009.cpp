#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int map[102][102],f[102][102][11],n,k,a,b,c,an=199999999;

void dfs(int x,int y,int fy,int rs)
{
	int add=0;
	if (map[x][y]==-1) return;
	if (rs<=0||fy>=an) return;
	rs--;
	for (int i=rs;i<=k;i++)
	if (f[x][y][i]<=fy) return;
	f[x][y][rs]=fy;
	if (x==n&&y==n)
	{
		an=min(an,fy); 
		return;
	}
	if (map[x][y]==1) add=a,rs=k;
	if (rs==0) add=a+c,rs=k;
	dfs(x+1,y,fy+add,rs);
	dfs(x,y+1,fy+add,rs);
	dfs(x-1,y,fy+add+b,rs);
	dfs(x,y-1,fy+add+b,rs);
}

int main()
{
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&c);
	for (int i=0;i<=n+1;i++)
	map[0][i]=map[i][0]=map[i][n+1]=map[n+1][i]=-1; 
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		scanf("%d",&map[i][j]);
		for (int k=0;k<=10;k++)
		f[i][j][k]=99999999; 
	}
	dfs(1,1,0,k+1);
	printf("%d",an);
	return 0;
}