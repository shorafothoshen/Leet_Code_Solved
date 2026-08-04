#include<bits/stdc++.h>
using namespace std;

vector<int> missingNum(vector<int>&arr){
	int n = arr.size() + 1;
    vector<int>ans;

    int mx=INT_MIN;
    int mn=INT_MAX;

    for(int i=0;i<n-1;i++){
    	mx=max(arr[i],mx);
    	mn=min(arr[i],mn);
    }

    int size=mx-mn;

    vector<int> hash(size+1, 0);

    for (int i = 0; i < n - 1; i++) {
        hash[arr[i]]++;
    }

    for (int i = 1; i <= n+1; i++) {
        if (hash[i] == 0) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
	vector<int> arr = {5,1};
    vector<int> res = missingNum(arr);
    for(auto val:res){
    	cout<<val<<" ";
    }
}