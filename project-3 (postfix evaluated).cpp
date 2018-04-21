#include <bits/stdc++.h>
using namespace std;

bool Digit(char ch)
{
	if(ch >= '0' && ch <= '9'){
        return true;
	}
	else if(ch >= 'a' && ch <= 'z'){
        cout << "Not Evaluated" << endl;
        exit(0);
	}
	else if(ch >= 'A' && ch <= 'Z'){
        cout << "Not Evaluated" << endl;
        exit(0);
	}
	return false;
}

bool Operator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
		return true;
	}
	return false;
}

int Operation(char operator_0, int operand_1, int operand_2)
{
	if(operator_0 == '+')
        return (operand_1 + operand_2);
	else if(operator_0 == '-')
        return (operand_1 - operand_2);
	else if(operator_0 == '*')
        return (operand_1 * operand_2);
	else if(operator_0 == '/')
        return (operand_1 / operand_2);
}

int Evaluate_Postfix(string exp)
{
	stack <int> S;
	for(int i = 0; i < exp.length(); i++){
		if(exp[i] == ' '){
            continue;
		}
		else if(Operator(exp[i])){
			int operand_2 = S.top();  S.pop();
			int operand_1 = S.top();  S.pop();
			int result = Operation(exp[i], operand_1, operand_2);
			S.push(result);
		}
		else if(Digit(exp[i])){
			int operand = 0;
			while(i < exp.length() && Digit(exp[i])){
				operand = (operand * 10) + (exp[i] - '0');
				i++;
			}
			i--;
			S.push(operand);
		}
	}
	return S.top();
}

int main()
{
	string exp;
	cout << "Enter Postfix expression" << endl;
	getline(cin, exp);
	int result = Evaluate_Postfix(exp);
	cout << "Output = " << result << endl;
}

