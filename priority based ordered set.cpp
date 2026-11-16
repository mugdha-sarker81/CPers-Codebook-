#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>,
rb_tree_tag,tree_order_statistics_node_update>;

template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>,
rb_tree_tag,tree_order_statistics_node_update>;

using ll=long long;

int main(){

// ================= ORDERED SET =================
    ordered_set<ll> oset;

    int x; auto itr=NULL;
    //========= works same as set=========
    oset.insert(x);
    oset.erase(x);
    oset.erase(itr);
    oset.find(x);             //returns an iterator
    oset.lower_bound(x);
    oset.upper_bound(x);
    oset.size();
    oset.empty();
    oset.begin();  oset.end();
    oset.rbegin();  oset.rend();

    // Number of elements strictly smaller than x
    oset.order_of_key(25);

    // 0-based k-th smallest
    oset.find_by_order(1);      //returns an iterator


// ================= ORDERED MULTISET =================

    ordered_multiset<ll> os; //declare the tree with less_equal<T> instead of less<T>

    //========== works as usual ==========
    os.insert(x);
    os.size();
    os.empty();
    os.begin();  os.end();
    os.rbegin(); os.rend();

    //========== these properties are brocken ===
    os.find(x);             //always return end()
    os.erase(x);            //does nothing.
    os.erase(itr);
    os.lower_bound(x);
    os.upper_bound(x);
    //========== we can fix that issue using pair multiset======

    ordered_set<pair<int,int>> oms; //The Safer Alternative: pair<T, int> with less

    int id = 0;                             // Insert (value, unique_id)
    oms.insert({10, id++});                 //taking pair only to erase a
    oms.insert({10, id++});                 // value using erase operation.
    oms.insert({20, id++});

    oms.begin()->first;     // Minimum and maximum
    oms.rbegin()->first;
    

    // Count elements strictly smaller than x
    oms.order_of_key({10, -1});

    // Count elements <= x
    oms.order_of_key({10, INT_MAX});

    // k-th smallest value (0-based)
    oms.find_by_order(1)->first;

    auto it = oms.lower_bound({10, -1});        // Erase ONE occurrence of x
    if (it != oms.end() && it->first == 10)
        oms.erase(it);

    auto l = oms.lower_bound({10, -1});         // Erase ALL occurrences of x
    auto r = oms.upper_bound({10, INT_MAX});
    for (auto it = l; it != r; ){
        
        auto nxt = it;  ++nxt;
        oms.erase(it);  it = nxt;
    }

    auto f = oms.lower_bound({20, -1});        // Find an occurrence of x
    if (f != oms.end() && f->first == 20)
        cout << "Found\n";



    return 0;
}