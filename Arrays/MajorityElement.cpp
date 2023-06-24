#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> array) {

       int currAns = array.front();
       int count=0;
       
       for(int i=0;i<array.size();i++){
        if(currAns!=array[i]){
            count--;
            if(!count){
                count=1;
                currAns=array[i];
            }

        }
        else{
            count++;
        }
       }

       count=0;

       for(int j=0;j<array.size();j++){
        if(array[j]==currAns) count++;
       }

       if(count>array.size()/2) return currAns;
       else return -1;
    }
};

int main(){
    //creating a Solution class object
    Solution* solution = new Solution();

    //declaring the array
    vector<int> arr;
    int size;
    cin>>size;

    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    int ans = solution->majorityElement(arr);
    
    // cout<<(ans>=0)?(ans):("Majority element does not exist")<<endl;
    if(ans==-1){
        std::cout<<"Majority element does not exist"<<endl;
    }
    else std::cout<<ans<<endl;

}