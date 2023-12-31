#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

     int length = matrix.size();
    
    //taking the transpose
     for(int row=0;row<length;row++){
         for (int column=0;column<length-row-1;column++){
             swap(matrix[row][column],matrix[length-1-column][length-row-1]);
         }
     }


     //Reversing the order of the numbers by column

     for(int column=0;column<length;column++){
        for(int row=0;row<length/2;row++){
            swap(matrix[row][column],matrix[length-row-1][column]);
        }
     }

    }
};

int main(){
    //creating a Solution class object
    Solution* solution = new Solution();

    //declaring the matrix
    vector<vector<int>> Matrix;
    int size;
    cin>>size;

    //Taking the input for the Matrix
    for(int i=0;i<size;i++){
        vector<int> temp;
        for(int j=0;j<size;j++){
            int number;
            cin>>number;
            temp.push_back(number);

        }
        Matrix.push_back(temp);
    }

    //calling the rotate method of the solution object
    solution->rotate(Matrix);


    //printing the matrix after the rotate method was called 
    for(auto x:Matrix){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }


}