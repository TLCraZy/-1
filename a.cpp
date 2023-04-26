#define ITC_TL
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
template <typename T> inline void read(T &zbc) {
	zbc=0;
	int Para=1;
	char ITC=getchar();
	for(; !isdigit(ITC); ITC=getchar()) if(ITC=='-') Para=-1;
	for(; isdigit(ITC); ITC=getchar()) zbc=(zbc<<1)+(zbc<<3)+(ITC^48);
	if(Para==-1) zbc=-zbc;
}
template <typename T> inline void write(T zbc) {
	if(zbc<0) putchar('-'),zbc=-zbc;
	if(zbc>9) write(zbc/10);
	putchar(zbc%10+48);
}
inline ll gcd(ll x,ll y) {
	return y==0?x:gcd(y,x%y);
}
ll n,m,siz,a[212345],belo[212345],k;
ll zuo[212345],you[212345];
bool GG[2123456];
struct node {
	ll l,r,xu;
#define l(x) ken[x].l
#define r(x) ken[x].r
#define xu(x) ken[x].xu
} ken[212345];
ll ans[212345],sum1=0,ge[212345];
inline void addl(ll p) {
	zuo[a[p]]--;
	sum1-=you[a[p]];
	return ;
}
inline void addr(ll p) {
	you[a[p]]--;
	sum1-=zuo[a[p]];
	return ;
}
inline void dell(ll p) {
	zuo[a[p]]++;
	sum1+=you[a[p]];
	return ;
}
inline void delr(ll p) {
	you[a[p]]++;	
	sum1+=zuo[a[p]];
	return ;
}
inline bool cmp(node x,node y) {
	return belo[x.l]==belo[y.l]?x.r<y.r:belo[x.l]<belo[y.l];
}

int main() {
	read(n);
	siz=sqrt(n);
	for(register int i=1; i<=n; i++) read(a[i]),belo[i]=i/siz;
	read(m);
	for(register int i=1; i<=m; i++) {
		read(l(i));
		read(r(i));
		xu(i)=i;
	}
	sort(ken+1,ken+1+m,cmp);
	for(register int i=1;i<l(1);i++) zuo[a[i]]++;
	for(register int j=n;j>r(1);j--) you[a[j]]++,sum1+=zuo[a[j]];
	ans[xu(1)]=sum1;
	ll l=l(1),r=r(1);
	for(register int i=2; i<=m; i++) {
		while(l(i)<l) addl(--l);
		while(r(i)>r) addr(++r);
		while(l(i)>l) dell(l++);
		while(r(i)<r) delr(r--);
		ans[xu(i)]=sum1;
	}
	for(register int i=1; i<=m; i++) {
		write(ans[i]);
		putchar('\n');
	}
	return 0;
}
/*
6
1 1 4 5 1 4
6
1 1
2 3
3 4
1 4
5 5
1 6
*/