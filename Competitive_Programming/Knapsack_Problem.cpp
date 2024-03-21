
/*

Question

A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item
weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to 
find and return the maximum value that a thief can generate by stealing items.

Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3
Time Limit: 1 second

Input Format:
First line contain 2 integers N and W
Next N lines input 2 integers wi and v1

*/

/*
Solution:
I have solve the problem in 4 different ways, improving the efficiency each time
1. Using Recursion                          # Time Complexity - O(2^n) , Space Complexity - O(1)
2. Using Recursion with memoization         # Time Complexity - O(n^2) , Space Complexity - O(n^2)
3. Using Tabulation Method                  # Time Complexity - O(n^2) , Space Complexity - O(n^2)
4. Improving on Tabulation Method           # Time Complexity - O(n^2) , Space Complexity - O(n)
*/

#include<iostream>
#include<vector>

using namespace std;

int SolveRec(vector<pair<int,int>> value,int maxWeight, int currentWeight=0,int index=0, int maxValue=0){
    // Base Case
    if(index>=value.size()){
        return maxValue;
    }

    int indexWeight=value[index].first;
    if(currentWeight+indexWeight>maxWeight){
        return maxValue;
    }

    // Solve for taking current and not taking current separately
    int including=SolveRec(value,maxWeight,currentWeight+indexWeight,index+1,maxValue+value[index].second);
    int excluding=SolveRec(value,maxWeight,currentWeight,index+1,maxValue);

    // Return Max of including and excluding current item
    maxValue=max(including,excluding);
    return maxValue;
}

int SolveRecMem(vector<pair<int,int>> value,int maxWeight,vector<vector<int>> &dp, int currentWeight=0,int index=0){
    // Base Case
    if(index>=value.size()){
        return 0;
    }

    int indexWeight=value[index].first;

    // If solved for before, return saved value
    if(dp[index][currentWeight]!=-1){
        return dp[index][currentWeight];
    }

    // Solve for taking current and not taking current separately
    int including=0;
    if(currentWeight+indexWeight<=maxWeight){
        including=value[index].second + SolveRecMem(value,maxWeight,dp,currentWeight+indexWeight,index+1); 
    }
    int excluding=SolveRecMem(value,maxWeight,dp,currentWeight,index+1);

    // Save in DP array
    dp[index][currentWeight]=max(including,excluding);
    return dp[index][currentWeight];
}

int SolveTab(vector<pair<int,int>> value,int maxWeight){
    
    vector<vector<int>> dp(value.size(),vector<int>(maxWeight+1,0));

    //Base Case
    for(int j=1;j<=maxWeight;j++){
        if(value[0].first>j){
            dp[0][j]=0;
        }
        else{
            dp[0][j]=value[0].second;
        }
    }

    // Loop through in reverse manner of recursion + memoization
    for(int i=1;i<value.size();i++){
        for(int j=1;j<=maxWeight;j++){
            int including=0;
            if(value[i].first<=j){
                including= value[i].second + dp[i-1][j-value[i].first];
            }
            int excluding=dp[i-1][j];

            dp[i][j]=max(including,excluding);
        }
    }
    return dp[value.size()-1][maxWeight];
}

int SolveEfficient(vector<pair<int,int>> value, int maxWeight){
    // Note that at any point answer is only dependent on one array worth of values
    vector<int> current(maxWeight+1,0);
    
    //Base Case
    for(int j=1;j<=maxWeight;j++){
        if(value[0].first>j){
            current[j]=0;
        }
        else{
            current[j]=value[0].second;
        }
    }

    for(int i=1;i<value.size();i++){
        for(int j=maxWeight;j>=1;j--){
            
            int including=0;
            if(value[i].first<=j){
                including= value[i].second + current[j-value[i].first];
            }
            current[j]=max(including,current[j]);

        }
    }

    return current[maxWeight];    
}

int Question1(vector<pair<int,int>> value,int maxWeight){
    // int answer1=SolveRec(value,maxWeight); Too Long

    // vector<vector<int>> dp(value.size(),vector<int>(maxWeight+1,-1));
    // int answer2 = SolveRecMem(value,maxWeight,dp);

    // int answer3=SolveTab(value,maxWeight);

    int answer4=SolveEfficient(value,maxWeight);
    return answer4;
}

int main(){

    int n,maxWeight;
    cin>>n>>maxWeight;

    vector<pair<int,int>> value;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;

        value.push_back(make_pair(a,b));
    }

    /*  Test Example
    vector<pair<int,int>> value;
    for(int i=0;i<10;i++){
        value.push_back(make_pair(1,5));
        value.push_back(make_pair(2,4));
        value.push_back(make_pair(4,13));
        value.push_back(make_pair(5,6));
    }
    int maxWeight=20;
    */

    cout<<"Maximum Value he can steal: "<<Question1(value,maxWeight)<<endl;
    
    return 0;
}