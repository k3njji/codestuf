#include<stdio.h>

long long max(long long a,long long b){
	if(a<b){
		return b;
	}
	return a;
}

long long solve(){
	long long n,m;
	scanf("%lld %lld",&n,&m);
	long long a[n];
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	long long l=0,r=-1,sum=0,ans=-1;
	while(r<n-1){
		r++;
		sum+=a[r];
		if(sum<=m){
			ans=max(ans,(r-l)+1);
		}
		while(m<sum){
			sum-=a[l];
			l++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

int main(){
	long long t;
	scanf("%lld",&t);
	for(long long i=1;i<=t;i++){
		printf("Case #%lld: ",i);
		solve();
	}
	return 0;
}
