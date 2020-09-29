//delete characters from the strig following the given instruction
//delete exactly one occurrence of every presen in the string 
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<char, bool> m;
    int t,n,k;
    char *arr;
    int *value;
    cin>>t;
    for(int i=0;i<t;i++)
    {
    	
        int sum=0;
        cin>>n;
        arr=new char[n];
        value=new int[n];
        cin>>arr;
        for(int i=0;i<n;i++)
        {
            cin>>value[i];
        }
        
        for(int i=0;i<n;i++)
        {
            if(m.find(arr[i])==m.end())
            {
                m.insert({arr[i], true});
                 k=i;
            for(int j=i+1;j<n;j++)
            {
               
                if(arr[i]==arr[j])
                {
                    if(value[i]<value[j])
                    {
                        k=j;
                    }
                }
            }
            value[k]=0;
            }
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
        	cout<<value[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            sum+=value[i];
        }
        cout<<sum<<endl;
        m.clear();
        delete[] arr;
        delete[] value;
        m.clear();
        }
    return 0;
}