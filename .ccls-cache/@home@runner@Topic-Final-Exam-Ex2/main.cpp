#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool lessThan(const int op1[], const int op2[]);		// our comparator function

string sum(string s1, string s2);						// our sum function

int main()
{
	int pos=0;
	
	string s1,op,s2,res;			// To accept two numbers from the user
	
	cout<<"\nEnter an expression ---> ";
	
	cin>>s1>>op>>s2;
	
	res = sum(s1,s2);
	
	cout<<"\n"<<s1<<" "<<op<<" "<<s2<<" = ";
	
	
		while(res[pos]=='0')			// to avoid any trailing zeroes that occur
		{
			pos++;
		}
		
	for(int r = pos; r<res.length();++r)
	
	cout<<res[r];

	return 0;
	
}

bool lessThan(const int op1[50], const int op2[50])				// comparator function definition
{
	int c1=0,c2=0;
	
	while(op1[c1]!='!')
	{
		c1+=1;
	}
	
	while(op2[c2]!='!')
	{
		c2+=1;
	}
	
	if(c1==c2)
	{
		return op1[c1-1]>op2[c2-1] and op1[0]>op2[0] ?true:false;
	}
	
	return c1>c2?true:false;
}

string sum(string s1, string s2)			// returns a string value after adding s1 and s2 logically as we desire
{
	
	string res="";
	
	int s;						// to store size+1 of bigger string among s1 and s2. It is size+1 because adding two numbers can result
								// in a number greater than the length of s1 or s2.
	int i;
	
	int op1[50],op2[50];	
	
	for(i = 0 ; s1[i]!='\0' ; ++i)			
	{
		op1[i]=(int)s1[i]-48;
	}
	op1[i] = '!';
	
	for(i = 0 ; s2[i]!='\0' ; ++i)
	{
		op2[i]=(int)s2[i]-48;
	}
	op2[i] = '!';
								
	if(lessThan(op1,op2))				// call lessThan() to see which number is larger
	{
		s = s1.length()+1;
		cout<<"\nFirst operand is not less than second operand\n ";
	}
	else
	{
		s = s2.length()+1;
		cout<<"\nFirst operand is less than second operand\n ";
	}
	
	int num1[s],num2[s];			// integer arrays num1 and num2 to store strings s1 and s2.
	
	for(int i = 0 ; i<s ; ++i)		// first we assign all elements of num1 and num2 as 0.
	{
		num1[i] = num2[i] = 0;
	}
	
	if(s1.length()>s2.length())			// depending upon which number is smaller, we convert from strings to numbers accordingly
	{									
										// if the expression given is 99999 + 222 where s1=9999, s2=22 (length of s1> length of s2)
										
										// then we assign num1 as 09999 and num2 as 00022 by below code snippet
	
		for(int i = s1.length()-s2.length(), c = 0 ; s2[c]!='\0' ; ++i, ++c)
		{
			num2[i+1] = (int)s2[c]-48;
		}	
	
		for(int i = 1, c = 0 ; s1[c]!='\0' ; ++i,c++)
		{
			num1[i] = (int)s1[c]-48;
		}
	}
	else							// if the expression given is 22 + 9999 where s1=22, s2=9999 (length of s1< length of s2)
	{								
									// then we assign num1 as 09999 and num2 as to 00022 by the below code snippet
	
		for(int i = s2.length()-s1.length(), c = 0 ; s1[c]!='\0' ; ++i, ++c)
		{
			num1[i+1] = (int)s1[c]-48;
		}
	
	
		for(int i = 1, c = 0 ; s2[c]!='\0' ; ++i,c++)
		{
			num2[i] = (int)s2[c]-48;
		}
	}
	
	// now we continue to add num1 and num2 similar to how we add numbers on a paper with carry and sum
	
	int sum,carry;
	
	sum=carry=0;

		for(int i = s-1 ; i>=0 ; -- i)
		{
			sum = num1[i]+num2[i]+carry;
			if(sum<10)
			{
				res = res + char(sum+48);			// when sum < 10 , carry will be 0, add sum to the string called "res"
				carry = 0;
			}
			else
			{
				carry = (sum - 10);					// when sum is equal or greater than 10, carry becomes sum - 10 , add carry to string called "res"
				res = res + char(carry+48);
				carry = 1;
			}
		}
		
		// since we have the reverse of added numbers num1 and num2 in "res",
		// we return a reversed value of "res"
		
		reverse(res.begin(),res.end());
		
		return res;
}