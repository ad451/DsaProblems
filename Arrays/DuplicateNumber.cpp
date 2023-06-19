
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //using the floyd hare and tortoise algo to detect cycle


        //point both the hare and tortoise to the front of the array
        int tortoise = nums[0];
        int hare = nums[0];
        

        //make the hare two times faster than the tortoise
        while(true){
            hare=nums[nums[hare]];
            tortoise=nums[tortoise];
            if(hare==tortoise) break;
        }

        //once the 1st loop break, we have to find the entry point of the cycle

        //create a pointer to the first entry

        int pointer =  nums[0];


        //change both the pointers and the tortoise at the same pace
        while(true){
            
            if(pointer==tortoise) break;
            pointer=nums[pointer];
            tortoise=nums[tortoise];
        }


        return pointer;

        
    }
};


int main(){
       Solution* solution = new Solution();
       vector<int> nums;

       int size;
       cin>>size;

       for(int i=0;i<size;i++) {
         int m;
         cin>>m;
         nums.push_back(m);

       }


       int ans = solution->findDuplicate(nums);

       cout<<ans;

}