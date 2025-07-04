#import <queue>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
priority_queue<int,vector<int>,greater<int>>min_heap;
    //make heap for first k elements.
    for(int i=0;i<k;i++){
        min_heap.push(nums[i]);
    }
    // now if in remainder array,we encounter a greater number than the top of heap,we remove the top elt and replace it with the greater elt.
    for(int i=k;i<nums.size();i++){
        if(nums[i]>min_heap.top()){
            min_heap.pop();
            min_heap.push(nums[i]);
        }
    }
    int ans=min_heap.top();
    return ans;
    }
// Hope it helps! Kindly upvote.
};