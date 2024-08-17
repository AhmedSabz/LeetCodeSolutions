using namespace std;
#include <iostream>
#include <vector>
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int jumps=0; // number of minimum jumps to reach the last element
        int currFarthest=0; //the farthest point we can reach with current number of jumps
        int Farthest=0; //farthest point we can reach overall
        for(int i=0; i<nums.size()-1;i++){
            farthest=max(farthest,i+nums[i]); 
            if(i ==currFarthest){ // reached the end of our current range
                jumps++;
                currFarthest=farthest;
            }
            if(currFarthest >= nums.size()-1){ //curent end is at last index or beyond
                return jumps;
            }
        }
     return -1;
    }
};