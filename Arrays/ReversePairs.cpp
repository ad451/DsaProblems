#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans=0;
    vector<int> merge(vector<int>&nums,int lower,int higher){
        if(higher-lower>1){
            int mid=(lower+higher)/2;
            vector<int> left = merge(nums,lower,mid);
            vector<int> right = merge(nums,mid,higher);

            //counting the number of reverse pairs for each left element
            //if the left element > 2*rightelement, we increment the right element
            //when the left element <=2*rightelement, we add the total count of rightelements to the ans
            //we then again continue this for other left elements

            //The time complexity - O(left+right)-O(n)
            int j=0;
            for(int i=0;i<left.size();i++){
                while(j<right.size()&&left[i]>2*(long long)right[j]){
                    j++;
                }
                ans+=j;

            }
            

            //Merge part - O(n)
            vector<int> temp;
            int start1=0;
            int start2=0;
            int pos3=0;
            while(start1<left.size()&&start2<right.size()){
                if(left[start1]<=right[start2]){
                    temp.push_back(left[start1]);
                    start1++;
                    pos3++;

                }
                else{
                    temp.push_back(right[start2]);
                    start2++;
                    pos3++;
                }

            }


            while(start1<left.size()){
               temp.push_back(left[start1]);
                    start1++;
                    pos3++;
            }
             while(start2<right.size()){
                temp.push_back(right[start2]);
                    start2++;
                    pos3++;
            }
            return temp;


        }
        else{
            return vector<int> {nums[lower]};
        }

    }
     
    int reversePairs(vector<int>& nums) {
        
        merge(nums,0,nums.size());
        int tem=ans;
        ans=0;
        return tem;

     

    }


    //Time complexity Overall - O(2nlogn);
    //Space complexity - O(n);
};