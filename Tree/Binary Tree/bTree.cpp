#include <bits/stdc++.h>
using namespace std ;

class node {
   
public:

    int data ;
    node* left ;
    node* right ;

    node( int n){
        this->data = n ;
        this->left = nullptr;
        this->right = nullptr;
    }

};

node * buildTree( node * root ){

    cout << "Enter data: " << endl; 
    int data ;
    cin >> data ;

    if( data == -1){
        return nullptr;
    }

    root = new node(data) ;

    cout << "Data for left of " << data  << endl;
    root->left = buildTree(root->left) ;
    cout << "Data for right of " << data  << endl;
    root->right = buildTree(root->right) ;

    return root ;

}

int main() {

    node* root = nullptr ;

    root = buildTree(root) ;

    return 0;
}