//Given a string S. Two position i and j of the string are friends 
//if they have the same character. The distance between two friends at positions i and j is defined as |i- j|. 
//Find the sum of distances of all the pairs of friends in the given strings. inO(n) and O(n2)
#include <bits/stdc++.h> // header file includes every Standard library
#include<cstring>
#include<string.h>
#include<map>
using namespace std;

int main() {
	string s;
	int sum=0,sum1=0;
	map<char,int> m;
	cin>>s;
	int n=s.length();
	for(int j=0;j<n;j++)
	{
		m.insert(make_pair(s[j],j));
	}
	for(auto i:m)
		cout<<i.first<<"and"<<i.second<<endl;
	cout<<endl;

	//In O(n)
	for(int i=0;i<n;i++)
	{
			auto itr=m.find(s[i]);
			int ref=itr->second;
			sum1+=i-ref;
	}
	cout<<sum1<<endl;

	//In O(n2)
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(s[i]==s[j])
			{
				sum+=j-i;
			}
		}
	}
	cout<<sum;

	// Your code here
	return 0;
}
