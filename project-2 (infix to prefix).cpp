#include<bits/stdc++.h>
using namespace std;

int Weight(char ch)
{
    int power = 0;
    if(ch == '*' || ch == '/'){
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

	return (operator_1 >= operator_2 ?  true : false);
}

bool Operator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
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
           //     while(!S.empty() && S.top() != '('){      // ai loop ta dile sir er moto hobe.
                    postfix += S.top();
                    postfix += ' ';
                    S.pop();
           //     }
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

int main()
{
	string exp;
	cout << "Enter Infix expression" << endl;
	getline(cin, exp);
	reverse(exp.begin(), exp.end());
	for(int i = 0; i < exp.length(); i++){
        if(exp[i] == ')'){
            exp.replace(i, 1, "(");
        }
        else if(exp[i] == '('){
            exp.replace(i, 1, ")");
        }
	}
	string postfix = Infix_To_Postfix(exp);
	reverse(postfix.begin(), postfix.end());
	cout << "Output = " << postfix << endl;
}


