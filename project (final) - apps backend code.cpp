
                         /// Data Structure Project ///
                /// REDWAN + SHARAR + RAMIJ + HIMEL + SADIA  ///

//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <iterator>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

/// ========================================================================
///                             Postfix Evaluate
/// ========================================================================

bool Digit(char ch)
{
	if(ch >= '0' && ch <= '9'){
        return true;
	}
	else if(ch >= 'a' && ch <= 'z'){
        cout << "   Evaluate : Not Evaluated" << endl;
        exit(0);
	}
	else if(ch >= 'A' && ch <= 'Z'){
        cout << "   Evaluate : Not Evaluated" << endl;
        exit(0);
	}
	return false;
}

bool Operator2(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
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
    else if(operator_0 == '^')
        return (pow(operand_1, operand_2));
}

int Evaluate_Postfix(string exp)
{
	stack <int> S;
	for(int i = 0; i < exp.length(); i++){
		if(exp[i] == ' '){
            continue;
		}
		else if(Operator2(exp[i])){
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

/// ==========================================================================
///                             Infix To Postfix
/// ==========================================================================

int Weight(char ch)
{
    int power = 0;
    if(ch == '*' || ch == '/' || ch == '^'){
        power = 2;
    }
    else if(ch == '+' || ch == '-'){
        power = 1;
    }
    return power;
}

bool Precedence(char ch1, char ch2)
{
	int operator_1 = Weight(ch1);
	int operator_2 = Weight(ch2);

	return (operator_1 > operator_2 ?  true : false);   // >= sir
}

bool Operator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
		return true;
	}
	return false;
}

bool Operand(char ch)
{
	if(ch >= '0' && ch <= '9'){
        return true;
	}
	else if(ch >= 'a' && ch <= 'z'){
        return true;
	}
	else if(ch >= 'A' && ch <= 'Z'){
        return true;
	}
//	else if(ch == '(' || ch == ')'){
//      return false;
//	}
//	else{
//      cout << "Math Error" << endl;
//      exit(0);
//	}
	return false;
}

string Infix_To_Postfix(string exp)
{
	stack <char> S;
	string postfix = "";
	for(int i = 0; i < exp.length(); i++){
		if(exp[i] == ' '){
            continue;
		}
		else if(Operator(exp[i])){
            postfix += ' ';
			while(!S.empty() && S.top() != '(' && Precedence(S.top(), exp[i])){
                while(!S.empty() && S.top() != '('){      // sir
                    postfix += S.top();
                    postfix += ' ';
                    S.pop();
                }
			}
            S.push(exp[i]);
		}
		else if(Operand(exp[i])){
			postfix += exp[i];
		}
		else if (exp[i] == '('){
			S.push(exp[i]);
		}
		else if(exp[i] == ')'){
			while(!S.empty() && S.top() != '('){
                postfix += ' ';
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}
	while(!S.empty()){
        postfix += ' ';
		postfix += S.top();
		S.pop();
	}
	return postfix;
}

/// =============================================================================
///                             Infix To Prefix
/// =============================================================================

string Infix_To_Prefix(string exp)
{
    reverse(exp.begin(), exp.end());
	for(int i = 0; i < exp.length(); i++){
        if(exp[i] == ')'){
            exp.replace(i, 1, "(");
        }
        else if(exp[i] == '('){
            exp.replace(i, 1, ")");
        }
	}
	exp = Infix_To_Postfix(exp);
	reverse(exp.begin(), exp.end());
	return exp;
}

/// =============================================================================
///                             Parenthesis Balance
/// =============================================================================

bool Parenthesis_Balance(string exp){
    stack <char> s;
    bool ck = true;
    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == '('){
            s.push(exp[i]);
        }
        else if(exp[i] == ')' && !s.empty()){
            if(s.top() == '('){
                s.pop();
            }
        }
        else if(exp[i] == ')' && s.empty()){
            ck = false;
            break;
        }
    }
    if(!ck || !s.empty()){
        cout << "   Parenthesis Not Balanced...!" << endl;
        return false;
    }
    return (s.empty() ? true : false);
}

int main()
{
    if(false){
        string s = "REDWAN + SHARAR + RAMIJ + HIMEL + SADIA";
        cout << endl;
        cout << setw(30) << fixed << right << "-";
        cout << "---------------------------------------------------" << endl;
        cout << setw(30) << fixed << right << "|";
        cout << setw(5) << fixed << left << " ";
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < 100000000; j++);
            cout << s[i];
        }
        cout << setw(7) << fixed << right << "|";
        cout << endl;
        cout << setw(30) << fixed << right << "-";
        cout << "---------------------------------------------------" << endl << endl;
    }

    while(1){
        string exp;
        bool ck = false;

        while(!ck){
            cout << "   Enter Infix expression : ";
            getline(cin, exp);
            ck = Parenthesis_Balance(exp);
        }

        string postfix = Infix_To_Postfix(exp);
        cout << "   Infix To Postfix : " << postfix << endl;

        string prefix = Infix_To_Prefix(exp);
        cout << "   Infix To Prefix  : " << prefix << endl;

        cout << "   Evaluate : " << Evaluate_Postfix(postfix) << endl;
        cout << endl;
    }
    return 0;
}

