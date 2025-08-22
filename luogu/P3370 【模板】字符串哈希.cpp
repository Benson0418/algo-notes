#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    gp_hash_table<string,null_type> ht;
    string s;
    while (n--){
        cin>>s;
        ht.insert(s);
    }
    cout<<ht.size();


    return 0;
}
