// this algo is used to find the maximum sum of subarray in an array
//in which we update the current to zero if the sum <=0
    
int maxSubarraySum(vector<int> &arr) {
    int j=0;
    int n=arr.size();
    int sum=0;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        mx=max(sum,mx);
        if(sum<=0){
            sum=0;
        }
    }
    return mx;
}