#include <stdio.h>
#define MAX_SIZE 1000000
#define ll long long
ll segmentTree[4*MAX_SIZE],lazy[4*MAX_SIZE];
ll arr[MAX_SIZE];
void buildSegmentTree(ll node,ll start,ll end){
    if(start==end) {
        segmentTree[node]=arr[start];
    } else {
        ll mid=(start+end)/2;
        buildSegmentTree(node*2,start,mid);
        buildSegmentTree(node*2+1,mid+1,end);
        segmentTree[node]=segmentTree[node*2]+segmentTree[node*2+1];
    }
}
void rangeUpdate(ll node,ll start,ll end,ll left,ll right,ll value){
    if(lazy[node]!=0) {
        segmentTree[node]+=(end-start+1)*lazy[node];
        if(start!=end) {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(right<start||end<left) return;
    if(left<=start&&end<=right){
        segmentTree[node]+=(end-start+1)*value;
        if(start!=end) {
            lazy[node*2]+=value;
            lazy[node*2+1]+=value;
        }
        return;
    }
    ll mid=(start+end)/2;
    rangeUpdate(node*2,start,mid,left,right,value);
    rangeUpdate(node*2+1,mid+1,end,left,right,value);
    segmentTree[node]=segmentTree[node*2]+segmentTree[node*2+1];
}
ll query(ll node,ll start,ll end,ll left,ll right){
    if(lazy[node]!=0){
        segmentTree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(right<start||end<left) return 0;
    if(left<=start&&end<=right) return segmentTree[node];
    ll mid=(start+end)/2;
    ll leftSum=query(node*2,start,mid,left,right);
    ll rightSum=query(node*2+1,mid+1,end,left,right);
    return leftSum+rightSum;
}
int main(){
    ll N,M,K;
    scanf("%lld %lld %lld",&N,&M,&K);
    for(ll i=1;i<=N;i++){
        scanf("%lld",&arr[i]);
    }
    buildSegmentTree(1,1,N);
    ll a,b,c,d;
    for(int i=1;i<=M+K;i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==1){
            scanf("%lld",&d);
            rangeUpdate(1,1,N,b,c,d);
        } else if(a==2){
            printf("%lld\n",query(1,1,N,b,c));
        }
    }
}