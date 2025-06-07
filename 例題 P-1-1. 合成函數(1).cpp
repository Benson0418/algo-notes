#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> L;
    vector<int> ee;
    string a;
    while (cin>>a){
        L.push_back(a);
    }
    string l;
    int x,y;

    while (!L.empty()){
        l=L.back();
        L.pop_back();
        if (l=="f"){
            x=ee.back();
            ee.pop_back();
            ee.push_back(2*x-1);
        }
        else if (l=="g"){
            x=ee.back();
            ee.pop_back();
            y=ee.back();
            ee.pop_back();
            ee.push_back(x+2*y-3);
        }
        else{
            ee.push_back(stoi(l));
        }
    }
    cout<<ee.back()<<endl;
    return 0;
}
