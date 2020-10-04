#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
char keyword[][10]={"","","abc","def","ghi","klm","nop","qrs","tuv","wxyz"};

void phone_notebook(char * phone, char *output,int i,int j)
{
	if(phone[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<endl;
		return;
	}

	//recursive step
	int digit = phone[i]-'0';
	if(digit==0 || digit==1)
		{
			phone_notebook(phone,output,i+1,j);
		}

	for(int k=0;keyword[digit][k]!='\0';k++)
	{
		
		output[j]=keyword[digit][k];
		phone_notebook(phone,output,i+1,j+1);
	}
	return;
}

int main()
{
	char output[100];
	char phone[100];
	cout<<"Enter the phone number"<<endl;
	cin>>phone;
	phone_notebook(phone,output,0,0);

	return 0;
}