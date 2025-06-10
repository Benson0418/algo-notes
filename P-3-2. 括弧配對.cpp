#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    vector<char> S;
    bool flag;

    while (cin>>s){
        S.clear();
        flag=1;
        for (size_t i=0;i<s.size();++i){
            if (s[i]=='(' || s[i]=='[' || s[i]=='{'){
                S.push_back(s[i]);
            }
            else if (s[i]==')'){
                if (!S.empty() && S.back()=='('){
                    S.pop_back();
                }
                else{
                    flag=0;
                    break;
                }
            }
            else if (s[i]==']'){
                if (!S.empty() && S.back()=='['){
                    S.pop_back();
                }
                else{
                    flag=0;
                    break;
                }
            }
            else if (s[i]=='}'){
                if (!S.empty() && S.back()=='{'){
                    S.pop_back();
                }
                else{
                    flag=0;
                    break;
                }
            }
        }
        if (S.empty() && flag){
            cout<<"yes"<<"\n";
        }
        else{
            cout<<"no"<<"\n";
        }
    }

    return 0;
}
