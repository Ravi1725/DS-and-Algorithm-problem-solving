//A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example, the sequence {A,B,D} // is a subsequence of {A,B,C,D,E,F}, obtained after removal of elements C, E and F.

//Given two strings A and B of size n and m respectively, you have to print the Longest Common Subsequence(LCS) of strings A and B, where LCS is the longest sequence present in both A and //B
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string lcs(string a,string b)
{
    int la=a.length();
    int lb=b.length();
    int dp[1001][1001] = {0};

    for(int i=0;i<=la;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=lb;i++)
    {
        dp[0][i]=0;
    }

    // Following steps build dp[m+1][n+1] in bottom up fashion. Note 
    // that dp[i][j] contains length of LCS of a[0..i-1] and b[0..j-1]
    for(int i=1;i<=la;i++)
    {
        for(int j=1;j<=lb;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=la,j=lb;
    string ans="";
    // Start from the right-most-bottom-most corner and 
    // one by one store characters in lcs[] 
    while(i>0 && j>0)
    {
        if(a[i-1] == b[j-1])
        {
            // If current character in a and b are same, then 
            // current character is part of LCS 
            ans=a[i-1]+ans;
            i--;
            j--;
        }
        // If not same, then find the larger of two and 
        // go in the direction of larger value
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return ans;
}