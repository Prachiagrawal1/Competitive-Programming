#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define pb(x) push_back(x)
#define mem(dp,a) memset(dp,a,sizeof(dp))

class Item 
{
	public:
	ll val,w;

};

bool cmp(Item a,Item b)
{
	double r1= (double)a.val/a.w;
	double r2= (double)b.val/b.w;
	return r1>r2;
}

double calc(double var)
{
	double t=(int)(var*100+0.5);
	return (double)t/100;
}

double frac(ll W,Item arr[], ll n)
{
	sort(arr,arr+n,cmp);
	
	ll curw=0;
	double value=0.0;
	
	f(i,n)
	{
		 if(curw+arr[i].w<=W)
		 {
		 	curw+=arr[i].w;
		 	value+=arr[i].val;
		 }
		 else
		 {
		 	ll rem=W-curw;
			 value+= arr[i].val*((double)rem/arr[i].w);
			 break;	
		 }
	}
	return value;
}

int main()
{

	ll t;
	cin>>t;
	while(t--)
	{
		ll n,W;
		cin>>n>>W;
		Item a[n];
		ll val,w;
		f(i,n)
		{
			cin>>a[i].val;
			cin>>a[i].w;
		}
		double valuee=frac(W,a,n);
		cout<<calc(valuee)<<endl;
		
	}
    return 0;
}

