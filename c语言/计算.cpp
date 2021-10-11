 #include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/* --- Function declaration --- */
int cmp(char op);
int eval(string s);

/* --- Main function --- */
int main() {
    string s;
    cin >> s;
    cout << eval(s) << endl;
    return 0;
}

/* --- Function definition --- */
int cmp(char op) {
    if (op == '#') {
        return 0;
    } else if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return -1;
    }
}

int eval(string s) {
    stack<int> st_num;
    stack<char> st_ope;
    st_ope.push('#');
    string tmp;
    int i = 0;
    bool flag = false;
    while (true) {
        if (isdigit(s[i])) {
            tmp += s[i++];
            flag = true;
            continue;
        } else {
            if (flag) {
                st_num.push(strtol(tmp.c_str(), nullptr, 10));
                tmp.clear();
                flag = false;
            }
            if (cmp(st_ope.top()) < cmp(s[i])) {
                st_ope.push(s[i++]);
            } else {
                int b = st_num.top();
                st_num.pop();
                int a = st_num.top();
                st_num.pop();
                char op = st_ope.top();
                st_ope.pop();
                switch (op) {
                    case '+':
                        st_num.push(a + b);
                        break;
                    case '-':
                        st_num.push(a - b);
                        break;
                    case '*':
                        st_num.push(a * b);
                        break;
                    case '/':
                        st_num.push(a / b);
                        break;
                    default:
                        break;
                }
                if (s[i] == '#' && st_num.size() == 1) {
                    break;
                }
            }
        }
    }
    return st_num.top();
}
