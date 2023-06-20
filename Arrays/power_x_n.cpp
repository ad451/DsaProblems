#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
      double mypow(double x,int n){
        //intitializing the answer
        double ans = 1;

        if(n==0){
            return ans;
        }
        //if n>0, we have to multiply answer with x if n is odd else multiply x by x
        else if (n>0){
           while(n){
            if(n%2==1){
                ans=ans*x;

            }

            x=x*x;

            n=n/2;


           }
        }

        else{

            while(n){
                cout<<n<<endl;
                if(n%2==-1) ans=ans/x;

                x=x*x;
                n=n/2;
            }
        }


        return ans;
      }
    
};

int main(){
    //creating a Solution class object
    Solution* solution = new Solution();

    //declaring the number and power pair
    pair<double,int> pi;
    double x;
    int n;
    
    cin>>x>>n;
    pi.first=x;
    pi.second=n;
    
    double ans = solution->mypow(pi.first,pi.second);
    cout<<ans;


}