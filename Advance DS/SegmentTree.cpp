// Segment Tree

// We implement a segment tree when we need to efficiently answer multiple range queries, like range sum, range max-min, etc.

// It is a type of complete binary tree used to store precalculated answers for a particular question. Whenever a query asks for a specific range, the segment tree helps in providing the answer efficiently.

// In other words, a segment tree is an efficient data structure that allows:

// Efficient querying of intervals/ranges.
// Efficient updating of intervals/ranges.


// Step 1-> built tree


#include<bits/stdc++.h>
using namespace std;
//Given array:
vector<int>nums={3,1,2,7,1};

//This function builds the tree
TC->O(n);
SC->O(n);
vector<int>SegmentTree(2*nums.size(),0);   //The Size of the segment Tree will equal to 2*n;
void buildTree(int index,int low,int high,vector<int>&nums){
    if(low==high){
        segmentTree[index]=nums[low];
        return;
    }
    int mid=(low+high)/2;
    buildTree(2*index+1,low,mid);
    buildTree(2*index+2,mid+1,high);
    segmentTree[index]=segmentTree[2*index+1]+segmentTree[2*index+2];
}

// void builtTree(vector<int>&arr,int idx,int l,int h,vector<int>&segTree){
//     if(l==h){
//         segTree[idx]=arr[l];
//         return;
//     }
//     int mid=(l+h)/2;
//     builtTree(arr,2*idx+1,l,mid,segTree);
//     builtTree(arr,2*idx+2,mid+1,h,segTree);
//     segTree[idx]=segTree[2*idx+1]+segTree[2*idx+2];
// }

// it it the update query code if somewant to change the particular index value of arr,which will change the 
//prefix sum and if we use that prefix array it takes almost o(n) tc
//but in this segment tree the update query will take time complexity of O(logn); 
void UpdateTree(int idx,int val,vector<int>&segTree,int l,int h,int i){
    if(l==h){ 
        segTree[i]=val;
        return;
    }
    int mid=(l+h)/2;
    if(mid>=idx){
        UpdateTree(idx,val,segTree,l,mid,2*i+1);
    }
    else{
        UpdateTree(idx,val,segTree,mid+1,h,2*i+2);
    }
    segTree[i]=segTree[2*i+1]+segTree[2*i+2];
}

//This function is to display the segment array

void displayTree(vector<int>&segTree){
    int n=segTree.size();
    for(int i=0;i<n;i++){
        cout<<segTree[i]<<" ";
    }
    cout<<endl;
}

// if you want to find the range sum within the range of start and end so this function help you to find the sum in log(n) tc.
int query(vector<int>&segTree,int start,int end,int i,int l,int r){
    if(end<l || r<start){
        return 0;
    }
    if(l>=start && r<=end){
        return segTree[i];
    }
    int mid=(l+r)/2;
    return query(segTree,start,end,2*i+1,l,mid)+query(segTree,start,end,2*i+2,mid+1,r);
}


int main(){
    vector<int>arr={3,1,2,7,2,1,2,3};
    int n=arr.size();
    vector<int>segTree(n*2);
    builtTree(arr,0,0,n-1,segTree);
    displayTree(segTree);    
    // UpdateTree(1,2,segTree,0,n-1,0);
    displayTree(segTree);
    cout<<query(segTree,2,6,0,0,n-1);
}