#include<bits/stdc++.h>
using namespace std;
using ll= long long;

int main(){ }


//====================== STRING =====================

// 'b' is a suffix of 'a'
bool ends_with(string a,string b){ 
    return b.compare(b.length()-a.length(),a.length(),a)==0;
}

// 'b' is a prefix of 'a'
bool starts_with(string a,string b){
    return b.compare(0,a.length(),a)==0;
}
