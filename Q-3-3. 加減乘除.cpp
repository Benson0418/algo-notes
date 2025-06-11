#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;
    vector<int> nums;
    vector<char> op;
    int x;

    for (size_t i=0;i<s.size();++i){
        if (s[i]=='+' || s[i]=='-'){
            op.push_back(s[i]);
        }
        else if (s[i]=='*'){
            x=nums.back();
            nums.pop_back();
            ++i;
            x*=(s[i]-'0');
            nums.push_back(x);

        }
        else if (s[i]=='/'){
            x=nums.back();
            nums.pop_back();
            ++i;
            x/=(s[i]-'0');
            nums.push_back(x);
        }
        else{
            nums.push_back(s[i]-'0');
        }
    }

    x=nums[0];
    size_t i=1,j=0;
    while (i<nums.size()){
        if (op[j]=='+'){
            x+=nums[i];
        }
        else{
            x-=nums[i];
        }
        ++j;
        ++i;
    }
    cout<<x<<"\n";


    return 0;
}
