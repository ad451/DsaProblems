
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MergreSort(vector<int>& nums,int start,int end){

         //base case if the array length is one, we return 0 as the count else continue   
        
         if(end-start>1){
           
            int mid=(start+end)/2;

            int leftcount  = MergreSort(nums,start,mid); //apply mergesort on the left part
            int rightcount = MergreSort(nums,mid,end); //apply mergesort on the right part

            int left=start,right=mid,count=0; //initialize the pointers to traverse the left and right part
            
            while(left<mid && right<end){

                //if the left index is less than the right index, we do not do anything and increment left

                if(nums[left]<=nums[right]){
                    left++;  
                }

                /*if the right index is less than the left , then we need to insert the right in the left part
                and perform operation somewhat similar to insertion sort*/

                else{

                     /*we increment the count cause if the current element is greater than the right then 
                    all the elements to the left in the left array will also be greater*/
                   
                    count+=mid-left;

                    //perform the insertion operation 

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
            
            return count+leftcount+rightcount; //return the total ans 

         }
        else{

         return 0;
        
        }


    }
    int Inversions(vector<int> nums) {
        
        if(nums.size()==1){
            return 1;

        }

        int ans = MergreSort(nums,0,nums.size()); //helper function to merge sort without changing the given input array
     
        return ans; //return the Final inversion count 
    }
};


int main(){
       Solution* solution = new Solution(); //create a solution object
       vector<int> nums;

       int size;
       cin>>size;

       //taking the input of the vector 

       for(int i=0;i<size;i++) {
         int m;
         cin>>m;
         nums.push_back(m);

       }

       //running the Inversions method of the solution object on the vector 
       int ans = solution->Inversions(nums);

       cout<<ans;

}