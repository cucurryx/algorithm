#include<iostream>
#include<stack>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;

double Evaluate(ifstream &in)
{
	stack<double> vals;
	stack<string> ops;
	string s;

	while(in>>s)
	{
		if(s == "(");
		else if (s == "+") ops.push(s);
		else if (s == "-") ops.push(s);
		else if (s == "*") ops.push(s);
		else if (s == "/") ops.push(s);
		else if (s == "sqrt") ops.push(s);
		else if (s == ")")
		{
			string op = ops.top();
			ops.pop();

			double v = vals.top();
			vals.pop();

			if (op == "+")
			{
				v = vals.top() + v;
				vals.pop();
			}
			else if (op == "-") 
			{	
				v = vals.top() - v;
				vals.pop();
			}
			else if (op == "*") 
			{	
				v = vals.top() * v;
				vals.pop();
			}
			else if (op == "/") 
			{	
				v = vals.top() / v;
				vals.pop();
			}
			else if (op == "sqrt") v = sqrt(v);
			vals.push(v);
		}
		else vals.push(stod(s));
	}


	return vals.top();
}

int main()
{
	//cout<<stod("123")<<endl;
	ifstream in("input.txt");
	double res = Evaluate(in);
	cout<<res<<endl;

	return 0;
}