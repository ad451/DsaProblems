#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        ///sort the intervals in ascending order based on the first item of each pari
        sort(intervals.begin(),intervals.end());

        //create a container to store the final intervals
        vector<vector<int>> ans;

        /*checking if two intervals are overlopping,
        if yes we modify the next interval to be the merged interval else we 
        include the current interval in the ans*/ 

        for(int idx=0;idx<intervals.size()-1;idx++){
            //partial overlapp
            if(intervals[idx][1]>=intervals[idx+1][0] && intervals[idx][1]<intervals[idx+1][1]){
                intervals[idx+1][0]=intervals[idx][0];
            }
            //complete overlapp
            else if(intervals[idx][1]>=intervals[idx+1][1]) intervals[idx+1]=intervals[idx];
            else ans.push_back(intervals[idx]);

        }
        
        ans.push_back(intervals[intervals.size()-1]); // adding the last interval 
        return ans;
        
    }
};

int main(){
    //creating a Solution class object
    Solution* solution = new Solution();

    //declaring the Intervals vector
    vector<vector<int>> Intervals;
    int size;
    cin>>size;

    //Taking the input for the Intervals
    for(int i=0;i<size;i++){
        vector<int> temp;
        for(int j=0;j<2;j++){
            int number;
            cin>>number;
            temp.push_back(number);

        }
        Intervals.push_back(temp);
    }

    //calling the merge method of the solution object
    vector<vector<int>> ans = solution->merge(Intervals);


    //printing the vector after the merge method was called 
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }


}