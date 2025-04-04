#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int longestConsecutive(vector<int> nums){
    if(nums.empty()){
        return 0;
    }
    unordered_set<int> myset(nums.begin(), nums.end());
    int maxlength = 0;
    for(int num : nums){
        if(myset.find(num-1) == myset.end()){
            int currentNum = num;
            int currentlen = 1;
            while(myset.find(currentNum+1)!=myset.end()){
                currentNum++;
                currentlen++;
            }
            maxlength = max(maxlength, currentlen);
        }
    }
    return maxlength;
}
int main(){
    int n; 
    vector<int> vec;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the value of array: ";
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        vec.push_back(value);
    }
    int value = longestConsecutive(vec);
    cout<<"Length of consecutive Sequence is : "<<value<<endl;
    return 0;
}