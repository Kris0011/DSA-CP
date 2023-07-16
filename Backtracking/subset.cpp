#include<bits/stdc++.h>

using namespace std ;


vector< vector<int> > ans  ;

void generate( vector <int> & subset , int index , vector <int> & arr){

    
    if( index == arr.size() ){
        ans.push_back(subset);
        return ;
    }

    generate(subset , index +1 , arr);  // Ignoring ith element 


    subset.push_back( arr[index] );    
    generate(subset , index +1 , arr);  // After including ith element  
    subset.pop_back();                  // Undo the changes for the Backtracking
    

}

int main(){
}