//*******Abhijit Burman***********//
//Jalpaiguri Government Engineering College//

// Taken From Striver_79
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts
// Donot treat CP as a placement thing, love it and enjoy it, you will succeed for sure.
//Problem Link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define MAXX (1000000000000000000+7)
#define mod 1000000007
#define endl "\n"
#define PI 3.14159265358979323846
#define all(x) (x).begin(),(x).end()
#define fio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
void printv(vector<ll> v) { ll sz = v.size(); for(ll i=0;i<sz;i++) {if (i == sz - 1) cout << v[i] << "\n"; else cout << v[i] << " ";}}
void input(ll a[], ll sz) {for(ll i=0;i<sz;i++) cin >> a[i];}
void print(ll a[], ll sz) {for(ll i=0;i<sz;i++) {if (i == sz - 1) cout << a[i] << "\n"; else cout << a[i] << " ";}}
ll dx1[] = {1, 1, 0, -1, -1, -1, 0, 1};
ll dy1[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll dx2[] = {1, 0, -1, 0};
ll dy2[] = {0, 1, 0, -1};

ll mul(ll a, ll b, ll p = mod) {return ((a % p) * (b % p)) % p;}
ll add(ll a, ll b, ll p = mod) {return (a % p + b % p) % p;}
ll power(ll x,ll y,ll p = mod)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
ll modInverse(ll n, ll p = mod)
{
    return power(n, p - 2, p);
}
ll ncrMod(ll n, ll r, ll p = mod)
{
    if (r == 0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1 ; i <= n; i++)
        fac[i] = fac[i - 1] * i % p;
    return (fac[n] * modInverse(fac[r], p) % p *
            modInverse(fac[n - r], p) % p) % p;
}
// a+b=xor(a,b)+2*(a&b)//
ll convert(string num){
    ll sum=0;
    for(int i=0;i<num.size();i++){
        sum=sum*10;
        sum+=(num[i]-'0');
    }
    return sum;
}
bool ispeed2ime(ll n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
bool isPowerof2(ll n){
    while(n>1){
        if(n%2!=0){
            return true;
        }
        n/=2;
    }
    return false;
}
ll dp[100][5][5][5];
ll cost(string num,ll pos,ll size,ll even,ll leading, ll tight){
    if(pos>=size){
        return 1;
    }
    if(dp[pos][even][leading][tight]!=-1){
        return dp[pos][even][leading][tight];
    }
    ll ans=0;
    if(leading==0){
        ans+=cost(num,pos+1,size,0,0,0);

    }

    if(even==1){
        ll upper = 9;
        if(tight==1){
            upper = num[pos]-'0';
        }
        for(ll i=0;i<=upper;i+=2){
            if(i<=upper){
                ans+=cost(num,pos+1,size,0,1,(tight&(i==upper)));
            }
        }
    }
    else{
        ll upper = 9;
        if(tight==1){
            upper = num[pos]-'0';
        }
        for(int i=1;i<=upper;i+=2){
            if(i<=upper){
                ans+=cost(num,pos+1,size,1,1,(tight&(i==upper)));
            }
        }
    }

    return dp[pos][even][leading][tight]=ans;
}


void solve()
{
    ll l,r;
    cin>>l>>r;
    l--;
    string s1 = to_string(l);
    string s2 = to_string(r);
    ll n1 = s1.size(),n2=s2.size();
    memset(dp,-1,sizeof(dp));
    ll ans1 = cost(s1,0,n1,0,0,1);
    memset(dp,-1,sizeof(dp));
    ll ans2 = cost(s2,0,n2,0,0,1);
    // cout<<ans1<<" "<<ans2<<endl;
    cout<<(ans2-ans1)<<endl;
}


int main()
{
	fio;
// 	#ifndef ONLINE_JUDGE
//     // for getting input from input.txt
//     freopen("input.txt", "r", stdin);
//     // for writing output to output.txt
//     freopen("output.txt", "w", stdout);
// 	#endif


	ll t=1;
	cin>>t;
	ll k=1;
	while(t--)
	{
	    cout<<"Case #"<<k<<": ";
		solve();

		k++;
	}
	return 0;
}
