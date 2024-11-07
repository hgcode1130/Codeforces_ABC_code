#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2003,mod=1e9+7;
int ma[MAXN][MAXN];
int s[MAXN][MAXN];
int stk[MAXN],top;
int n;
ll ans1,ans2;

/*
单调栈图片便于理解
https://cdn.luogu.com.cn/upload/pic/56750.png
*/
int main(){
	ios::sync_with_stdiO(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&ma[i][j]);
		}
	}
	for(int k=0;k<31;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((ma[i][j]>>k)&1)s[i][j]=s[i-1][j]+1;
				else s[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			ll ans=0;top=0;
			for(int j=1;j<=n;j++){
				ans+=s[i][j];
				while(top&&s[i][stk[top]]>=s[i][j]){
					ans-=(stk[top]-stk[top-1])*(s[i][stk[top]]-s[i][j]);
					//栈顶对于第二大的元素的距离×栈顶与j的落差，即为上图中j=3时灰色线的上半部分
					top--;
				}
				ans1+=ans<<k;
				ans1%=mod;
				stk[++top]=j;
			}
		}
	}
	cout<<ans1<<" ";
	for(int k=0;k<31;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((ma[i][j]>>k)&1)s[i][j]=0;
				else s[i][j]=s[i-1][j]+1;
			}
		}
		for(int i=1;i<=n;i++){
			ll ans=0;top=0;
			for(int j=1;j<=n;j++){
				ans+=s[i][j];
				while(top&&s[i][stk[top]]>=s[i][j]){
					ans-=(stk[top]-stk[top-1])*(s[i][stk[top]]-s[i][j]);
					top--;
				}
				ans2+=(i*j-ans)<<k;
				ans2%=mod;
				stk[++top]=j;
			}
		}
	}
	cout<<ans2<<endl;	
	return 0;
}
