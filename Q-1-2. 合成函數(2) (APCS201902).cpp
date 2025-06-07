#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> L;
    vector<int> ee;
    string a;
    int x,y,z;
    while (cin>>a){
        L.push_back(a);
    }
    while (!L.empty()){
        a=L.back();
        L.pop_back();
        if (a=="f"){
            x=ee.back();
            ee.pop_back();
            ee.push_back(2*x-3);
        }
        else if (a=="g"){
            x=ee.back();
            ee.pop_back();
            y=ee.back();
            ee.pop_back();
            ee.push_back(2*x+y-7);
        }
        else if (a=="h"){
            x=ee.back();
            ee.pop_back();
            y=ee.back();
            ee.pop_back();
            z=ee.back();
            ee.pop_back();
            ee.push_back(3*x-2*y+z);
        }
        else{
            ee.push_back(stoi(a));
        }
    }
    cout<<ee.back()<<endl;
    return 0;
}
