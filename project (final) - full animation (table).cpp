
                         /// Data Structure Project ///
                /// REDWAN + SHARAR + RAMIJ + HIMEL + SADIA  ///


//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <iterator>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

/// ========================================================================
///                             printing section
/// ========================================================================

void print(char exp, deque <char> S, string postfix)
{
    string str = "";
    cout << "       " << setw(6) << fixed << left << "|";
    cout << setw(6) << fixed << left << exp;
    cout << setw(6) << fixed << left << "|";
    for(deque <char> :: iterator it = S.begin(); it != S.end(); it++){
        str += *it;
    }
    cout << setw(30) << fixed << left << str;
    cout << setw(6) << fixed << left << "|";
    cout << setw(70) << fixed << left << postfix;
    cout << setw(2) << fixed << left << "|" << endl;
    cout << "       -----------------------------------------------------------------------------------------------------------------------------" << endl;
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
	return false;
}

string Infix_To_Postfix(string exp)
{
	deque <char> S;
	bool pr = false;
	string postfix = "";
	for(int i = 0; i < exp.length(); i++){
		if(exp[i] == ' '){
            continue;
		}
		else if(Operator(exp[i])){
            postfix += ' ';
			while(!S.empty() && S.back() != '(' && Precedence(S.back(), exp[i])){
                while(!S.empty() && S.back() != '('){      // sir
                    postfix += S.back();
                    postfix += ' ';
                    S.pop_back();
                }
			}
            S.push_back(exp[i]);
            print(exp[i], S, postfix);
		}
		else if(Operand(exp[i])){
			postfix += exp[i];
			print(exp[i], S, postfix);
		}
		else if (exp[i] == '('){
			S.push_back(exp[i]);
			print(exp[i], S, postfix);
		}
		else if(exp[i] == ')'){
			while(!S.empty() && S.back() != '('){
                postfix += ' ';
				postfix += S.back();
				S.pop_back();
			}
			S.pop_back();
			print(exp[i], S, postfix);
		}
		for(int j = 0; j < 70000000; j++);
	}
	while(!S.empty()){
        postfix += ' ';
		postfix += S.back();
		S.pop_back();
        pr = true;
	}
	if(pr){
        print( ' ' , S, postfix);
        for(int j = 0; j < 30000000; j++);
	}
	return postfix;
}

/// =============================================================================
///                             Infix To Prefix
/// =============================================================================

string Infix_To_Prefix(string exp)
{
    bool ck = false;
    reverse(exp.begin(), exp.end());
    string s14 = "Infix Expression Reverse       ==>   ";
    cout << "   ";
    for(int i = 0; i < s14.size(); i++){
        for(int j = 0; j < 30000000; j++);
            cout << s14[i];
    }
    for(int i = 0; i < exp.size(); i++){
         for(int j = 0; j < 30000000; j++);
            cout << exp[i];
        }
    cout << endl;
	for(int i = 0; i < exp.length(); i++){
        if(exp[i] == ')'){
            exp.replace(i, 1, "(");
            ck = true;
        }
        else if(exp[i] == '('){
            exp.replace(i, 1, ")");
            ck = true;
        }
	}
	if(ck){
        string s13 = "'(' will ')' and ')' will '('  ==>   ";
        cout << "   ";
        for(int i = 0; i < s13.size(); i++){
            for(int j = 0; j < 30000000; j++);
                cout << s13[i];
        }
        for(int i = 0; i < exp.size(); i++){
             for(int j = 0; j < 30000000; j++);
                cout << exp[i];
            }
        cout << endl;
	}
	cout << endl;
    string s12 = "Infix To Postfix Step by Step :";
    cout << "   ";
    for(int i = 0; i < s12.size(); i++){
        for(int j = 0; j < 30000000; j++);
        cout << s12[i];
    }
    cout << endl << endl;
	cout << "       -----------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "       |   Symbol  |               Stack               |                                Expression                                 |" << endl;
	cout << "       -----------------------------------------------------------------------------------------------------------------------------" << endl;
	exp = Infix_To_Postfix(exp);
	reverse(exp.begin(), exp.end());

	cout << endl;
	string s11 = "Reverse The Expression     ==>   ";
    cout << "   ";
    for(int i = 0; i < s11.size(); i++){
        for(int j = 0; j < 30000000; j++);
        cout << s11[i];
    }
    for(int i = 0; i < exp.size(); i++){
        for(int j = 0; j < 30000000; j++);
        cout << exp[i];
    }
    cout << endl;
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
        string s10 = "Parenthesis Not Balanced...!";
        cout << "   ";
        for(int i = 0; i < s10.size(); i++){
            for(int j = 0; j < 30000000; j++);
            cout << s10[i];
        }
        cout << endl;
        return false;
    }
    return (s.empty() ? true : false);
}

/// =============================================================================
/// =============================================================================

int main()
{

    if(true){
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
        int key = 0;

        string s1 = "=> Input Should Be 1 Character / Digit...";
        cout << endl << "   ";
        for(int i = 0; i < s1.size(); i++){
            for(int j = 0; j < 30000000; j++);
            cout << s1[i];
        }
        cout << endl;

        string s2 = "=> What you want...?";
        cout << endl << "   ";
        for(int i = 0; i < s2.size(); i++){
            for(int j = 0; j < 30000000; j++);
            cout << s2[i];
        }

        string s3 = "=> press \"1\" for \"Infix To Postfix\".";
        cout << endl << "   ";
        for(int i = 0; i < s3.size(); i++){
            for(int j = 0; j < 30000000; j++);
            cout << s3[i];
        }

        string s4 = "=> press \"2\" for \"Infix To Prefix\".";
        cout << endl << "   ";
        for(int i = 0; i < s4.size(); i++){
            for(int j = 0; j < 30000000; j++);
            cout << s4[i];
        }
        cout << endl;

        while(key != 1 && key != 2){
            string s5 = "=> Key : ";
            cout << "   ";
            for(int i = 0; i < s5.size(); i++){
                for(int j = 0; j < 30000000; j++);
                cout << s5[i];
            }

            cin >> key;
            cin.get();
            if(key != 1 && key != 2){
                continue;
            }
            cout << endl;

            while(!ck){
                string s6 = "Enter Infix expression : ";
                cout << "   ";
                for(int i = 0; i < s6.size(); i++){
                    for(int j = 0; j < 30000000; j++);
                    cout << s6[i];
                }
                getline(cin, exp);
                ck = Parenthesis_Balance(exp);
            }
            cout << endl;

            if(key == 1){
                string s7 = "Infix To Postfix Step by Step :";
                cout << endl;
                cout << "   ";
                for(int i = 0; i < s7.size(); i++){
                    for(int j = 0; j < 30000000; j++);
                    cout << s7[i];
                }
                cout << endl << endl;
                cout << "       -----------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "       |   Symbol  |               Stack               |                                Expression                                 |" << endl;
                cout << "       -----------------------------------------------------------------------------------------------------------------------------" << endl;
                string postfix = Infix_To_Postfix(exp);
                cout << endl;

                string s8 = "Infix To Postfix : ";
                cout << "   ";
                for(int i = 0; i < s8.size(); i++){
                    for(int j = 0; j < 30000000; j++);
                    cout << s8[i];
                }

                for(int i = 0; i < postfix.size(); i++){
                    for(int j = 0; j < 30000000; j++);
                    cout << postfix[i];
                }
                cout << endl;
            }
            else if(key == 2){
                string prefix = Infix_To_Prefix(exp);
                cout << endl;

                string s9 = "Infix To Prefix : ";
                cout << "   ";
                for(int i = 0; i < s9.size(); i++){
                    for(int j = 0; j < 30000000; j++);
                    cout << s9[i];
                }

                for(int i = 0; i < prefix.size(); i++){
                    for(int j = 0; j < 30000000; j++);
                    cout << prefix[i];
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}

