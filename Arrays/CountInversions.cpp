
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MergreSort(vector<int>& nums,int start,int end){
            
         if(end-start>1){
           
            int mid=(start+end)/2;

            int leftcount  = MergreSort(nums,start,mid);
            int rightcount = MergreSort(nums,mid,end);

            int left=start,right=mid,count=0;
            
            while(left<mid && right<end){
                if(nums[left]<=nums[right]){
                    left++;
                }
                else{
                    count+=mid-left;

                    int temp=nums[right];
                    for(int idx=right-1;idx>=left;idx--){
                        nums[idx+1]=nums[idx];
                    }
                    nums[left]=temp;

                    left++;
                    right++;
                    mid++;
                }

            }
            
            return count+leftcount+rightcount;

         }
        else{

         return 0;
        
        }


    }
    int Inversions(vector<int> nums) {
        
        if(nums.size()==1){
            return 1;

        }

        int ans = MergreSort(nums,0,nums.size());
     
        return ans;
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

       int ans = solution->Inversions(nums);

       cout<<ans;

}