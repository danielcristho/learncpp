#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool n(char kurungBuka,char kurungTutup)	                         //bool for true or false
{
	if(kurungBuka == '(' && kurungTutup == ')') return true;
	else if(kurungBuka == '{' && kurungTutup == '}') return true;
	else if(kurungBuka == '[' && kurungTutup == ']') return true;
	return false;
}
bool palindrom_Bracket(string exp)
{
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.empty() || !n(S.top(),exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;	 //condition ? result1
	
}
int main()
{
	string expression;
	cout<<"\n "; 
	cin>>expression;
	if(palindrom_Bracket(expression)) //jika palindrom bracket benar semua/ sama maka print "ya"
		cout<<"Ya" <<endl;
	else
		cout<<"Tidak" <<endl;
}