#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr  = {-1,-2,-3,-4};
    cout << all_of(arr.begin(),arr.end() , [](int x){return x>0;}) << endl;    // [](...) { return ... }    called lambda function

    cout << any_of(arr.begin(),arr.end() , [](int x){return x>0;}) << endl;   // One should be matched
     
    cout << none_of(arr.begin(),arr.end() , [](int x){return x>0;}) << endl;      // when nothing is matched then true

}
