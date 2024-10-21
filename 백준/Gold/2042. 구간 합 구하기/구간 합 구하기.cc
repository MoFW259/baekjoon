#include <stdio.h>
#include <math.h>
#define MAX_SIZE 1000000
long long segmentTree[4*MAX_SIZE];
long long arr[MAX_SIZE];
long long buildSegmentTree(long long node,long long start,long long end){
    if(start==end){
        return segmentTree[node]=arr[start];
    }else{
        long long mid=(start+end)/2;
        long long leftSum=buildSegmentTree(node*2,start,mid);
        long long rightSum=buildSegmentTree(node*2+1,mid+1,end);
        return segmentTree[node]=leftSum+rightSum;
    }
}
long long query(long long node,long long start,long long end,long long left,long long right){
    if(right<start||end<left){
        return 0;
    }
    if(left<=start&&end<=right){
        return segmentTree[node];
    }
    long long mid=(start+end)/2;
    long long leftSum=query(node*2,start,mid,left,right);
    long long rightSum=query(node*2+1,mid+1,end,left,right);
    return leftSum+rightSum;
}
void update(long long node,long long start,long long end,long long index,long long value){
    if(start==end){
        arr[index]=value;
        segmentTree[node]=value;
    }else{
        long long mid=(start+end)/2;
        if(start<=index&&index<=mid){
            update(node*2,start,mid,index,value);
        } else {
            update(node*2+1,mid+1,end,index,value);
        }
        segmentTree[node]=segmentTree[node*2]+segmentTree[node*2+1];
    }
}
int main(){
    long long N,m,k;
    scanf("%lld %lld %lld",&N,&m,&k);
    for(long long i=1;i<=N;i++){
        scanf("%lld",&arr[i]);
    }
    buildSegmentTree(1,1,N);
    long long a,b,c;
    for(int i=1;i<=m+k;i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==1){
            update(1,1,N,b,c);
        }else if(a==2){
            printf("%lld\n",query(1,1,N,b,c));
        }
    }
}
