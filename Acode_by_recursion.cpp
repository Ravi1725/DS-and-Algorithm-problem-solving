//string generation Acode Recursion problem 
//this program generate all strings corressponding to given number strings
//examples input string -'1234'- output strings are -ABCD,AWD,LCD
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
void generate_string(char *input,char *output, int i, int j)
{
	//base case
	if(input[i]=='\0')
	{
		output[j]=='\0';
		cout<<output<<endl;
		return;
	}

	int digit=input[i]-'0';
	char ch= 'A'-1 +digit;
	output[j]=ch;
	generate_string(input,output,i+1,j+1);
	if(input[i+1]!='\0')
	{
		int digit1=input[i+1]-'0';
		digit=10*digit+digit1;
		if(digit<=26)
		{
			ch='A'-1+digit;
			output[j]=ch;
			generate_string(input,output,i+2,j+1);
		}
	}
	return;
}

int main()
{
	char *input;
	char *output;
	int n;
	cout<<"Enter the length of input string "<<endl;
	cin>>n;
	input=new char[n];
	output=new char[n];
	cout<<"Input the string "<<endl;
	cin>>input;
	generate_string(input,output,0,0);

	return 0;
}