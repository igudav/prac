#include <stack>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{

    stack<string> vars;

    char c;
    bool print = false;
    while ((c = getchar()) != EOF)
    {
        if (isspace(c) && print) {
            cout << vars.top() << endl;
            vars.pop();
            print = false;
        }else if (islower(c)) {
            vars.push(string(1, c));
            print = true;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            string right = vars.top();
            vars.pop();
            string left = vars.top();
            vars.pop();
            string res{"("};
            res.append(left);
            res.append(1, c);
            res.append(right);
            res.append(")");
            vars.push(res);
        }
    }
    if (print) {
        cout << vars.top() << endl;
    }
    return 0;
}