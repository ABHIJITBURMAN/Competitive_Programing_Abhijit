#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void build(vector<ll>& tree,ll index,ll a[], ll ss, ll se){
    if(ss==se){
        tree[index] = a[ss];
        return ;
    }
    ll mid = (ss+se)/2;
    build(tree,2*index+1,a,ss,mid);
    build(tree,2*index+2,a,mid+1,se);
    
    tree[index] = tree[2*index+1]+tree[2*index+2];
    
}
ll query(vector<ll>& tree, ll index,ll ss, ll se, ll qs, ll qe){
    if(qs>qe){
        return 0;
    }
    else if(qs==ss and qe==se){
        return tree[index];
    }
    ll mid = (ss+se)/2;
    ll left = query(tree,2*index+1,ss,mid,qs,min(qe,mid));
    ll right = query(tree,2*index+2,mid+1,se,max(qs,mid+1),qe);
    
    return (left+right);
    
}

void update(vector<ll>& tree,ll index,ll ss, ll se, ll pos, ll val){
    if(ss==se){
        tree[index] = val;
        return ;
    }
    else{
        ll mid = (ss+se)/2;
        
        if(pos<=mid){
            update(tree,2*index+1,ss,mid,pos,val);
        }
        else{
            update(tree,2*index+2,mid+1,se,pos,val);
        }
        
        tree[index] = tree[2*index+1]+tree[2*index+2];
    }
}

void solve()
{
    //size of the array and query
    ll n,m;
    cin>>n>>m;
    
    ll a[n];
    input(a,n);
    vector<ll> tree(4*n+1);
    build(tree,0,a,0,n-1);
    //start query
    //type 1 query find the range in L to range
    //type 2 query update the element
    for(int i=0;i<m;i++){
        ll type,x,y;
        cin>>type>>x>>y;
        
        if(type==1){
            x--,y--;
            ll ans = query(tree,0,0,n-1,x,y);
            
            cout<<ans<<endl;
        }
        else{
            x--;
            update(tree,0,0,n-1,x,y);
        }
    }
}


int main()
{
	fio;
	ll t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}