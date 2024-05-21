/*

A simple infix to postfix converter using "Shunting Yard Algorithm"

*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precd(char c)
{
    switch (c)
    {
    case '^':
        return 4;
        break;
    case '*':
        return 3;
        break;

    case '/':
        return 3;
        break;
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    default:
        return -1;
        break;
    }
}

string toPost(string in)
{
    stack<char> st;
    st.push('N');
    string ret = "";
    int len = in.length();
    for (int i = 0; i < len; i++)
    {
        char temp = in[i];
        if ((temp >= 'a' && temp <= 'z'))
        {
            ret += temp;
        }
        else if (temp == '(')
        {
            st.push(temp);
        }
        else if (temp == ')')
        {
            while (st.top() != 'N' && st.top() != '(')
            {
                temp = st.top();
                st.pop();
                ret += temp;
            }
            if (st.top() == '(')
            {
                st.pop();
            }
        }
        else
        {
            while (st.top() != 'N' && precd(temp) <= precd(st.top()))
            {
                char c = st.top();
                st.pop();
                ret += c;
            }
            st.push(in[i]);
        }
    }
    while (st.size() != 1)
    {
        ret += st.top();
        st.pop();
    }
    return ret;
}

int main()
{
    string read;
    cin >> read;
    cout << toPost(read);
}