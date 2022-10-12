#include <bits/stdc++.h>
#define ll long long int
#define ld long long double
#define endl '\n'
using namespace std;

string getString(char x) {
  string s(1, x);
  return s;
}

int main() {
  string s;
  cin >> s;
  string output;
  stack<string> st;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ']') {
      string ans;
      string temp;
      while (st.top() != "[") {
        temp = st.top() + temp;
        st.pop();
      }
      // To delete the "["
      st.pop();

      string num;
      while (st.empty() != true and st.top() >= "0" and st.top() <= "9") {
        num = st.top() + num;
        st.pop();
      }

      // reverse(temp.begin(), temp.end());
      // reverse(num.begin(), num.end());
      int n = stoi(num);

      for (int j = 0; j < n; j++) {
        ans = temp + ans;
      }
      st.push(ans);
    } else {
      st.push(getString(s[i]));
    }
  }
  while (st.empty() != true) {
    output += st.top();
    st.pop();
  }
  cout << output << endl;
}