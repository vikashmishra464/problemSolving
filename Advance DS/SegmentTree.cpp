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