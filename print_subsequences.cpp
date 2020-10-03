#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
void print_susequences(char *arr,char  *output,int i,int j)
{
	//base step
	if (arr[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<endl;
		return;
	}

	//recursive step
	output[j]=arr[i];
	print_susequences(arr,output, i+1,j+1);
	print_susequences(arr,output,i+1,j);
}

int main()
{
	char arr[]="abc";
	char output[100];
	print_susequences(arr,output,0,0);

	return 0;
}