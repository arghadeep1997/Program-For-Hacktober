#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define endl '\n'
using namespace std;
void permute(vector<int>&arr,int n,vector<vector<int>>&ans,vector<int>&ds,unordered_map<int,bool>&freq){
	if(ds.size()==arr.size()){
		ans.push_back(ds);
		return;
	}
	for(int j=0;j<n;j++){
		if(freq[j]!=true){
			ds.push_back(arr[j]);
			freq[j]=true;
		//	cout<<arr[j]<<" ";
			permute(arr,n,ans,ds,freq);
		//	cout<<endl;
			ds.pop_back();
			freq[j]=false;
		}
	}
}
int main(){
	int n;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		arr.push_back(k);
	}
	vector<vector<int>>ans;
	vector<int>ds;
	unordered_map<int,bool>freq;
	permute(arr,n,ans,ds,freq);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}