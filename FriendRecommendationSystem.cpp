/*Scenario:
A social networking platform wants to suggest friends to users based on mutual connections. 
If user A and user B have multiple mutual friends, they should be recommended to each other.
Task:
Implement a friend recommendation system using C++ and STL. 
The system should support:
Adding friendships (addFriend(userA, userB)).
Finding mutual friends between two users (getMutualFriends(userA, userB)).
Suggesting new friends for a user (suggestFriends(userA)).
Hint:
Use unordered maps (std::unordered_map<int, std::unordered_set<int>>) to store friendships efficiently and set operations 
(std::set_intersection) to find mutual friends.*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
void addFriend(unordered_map<string, vector<string>>& um, string userA, string userB){
    um[userA].push_back(userB);
    um[userB].push_back(userA);
}
vector<string> getMutualFriends(unordered_map<string, vector<string>> um, string userA, string userB){
    vector<string> vec;
    unordered_map<string, bool> friendset;
    for(const string& friendA : um[userA]){
        friendset[friendA]=true;
    }
    for(const string& friendB : um[userB]){
        if(friendset.find(friendB) != friendset.end()){
            vec.push_back(friendB);
        }
    }
    return vec;
}
vector<string> getMutualFriends1(unordered_map<string, vector<string>>um, string userA, string userB){
    for (string i : um[userA] ){
        cout << i << endl;
    }
    // **need to sort the vector to get the set intersection or the set functions to work with it, un-regards to the data type. **
    sort(um[userA].begin(), um[userA].end());
    sort(um[userB].begin(), um[userB].end());

    vector<string> vec(20);
    vector<string>::iterator it;
    it = set_intersection(um[userA].begin(), um[userA].end(),  um[userB].begin(), um[userB].end(), vec.begin());
    // to resize 
    vec.resize(it-vec.begin());
    //for checking the values in the vec.
    // for(string j : vec){
    //     cout << "-" << j << endl;
    // }
    return vec;
}
int main(){
    vector<string> vec2, vec3;
    unordered_map<string, vector<string>> um;
    um.insert({"userA", {"Love", "Vicky", "Kundan", "Satyam", "Lucky", "Adarsh"}});
    um.insert({"userB", {"Rahul", "Satyam", "Rohit", "Rocky", "Adarsh", "Love"}});
    addFriend(um, "userA", "userB" );
    vec2 = getMutualFriends(um, "userA", "userB");
    cout<<"Mutual Friend between userA and userB are: ";
    for(string value : vec2){
        cout<<value<<" ";
    }
    cout<<endl;
    vec3 = getMutualFriends1(um, "userA", "userB");
    for(string value : vec3){
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}