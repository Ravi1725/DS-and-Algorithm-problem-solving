
#include<iostream>
#include<string.h>
using namespace std;
char word[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

//function to convert  digits to words recursively.
void digit_to_words(int n)
{
	//base case
	if(n==0)
		return;

	//recursive case
	digit_to_words(n/10);
	int digit=n%10;
	cout<<word[digit]<<" ";
	return;
}

//function to convert string to integers
int string_to_int(char *arr, int n)
{
	//base case
	if(n==0)
		return 0;
	int num =arr[n-1]-'0';

	int x=string_to_int(arr,n-1);
	int y=x*10+num;
	return y;


}

int main()
{
	int n;
	char arr[]={"12784"};
	cout<<"Enter the number to conert"<<endl;
	cin>>n;
	digit_to_words(n);
	cout<<endl;
	int n1=strlen(arr);
	cout<<string_to_int(arr,n1);
	return 0;
}