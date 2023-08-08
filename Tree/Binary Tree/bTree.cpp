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

void levelOrderTraversal (node * root){
    queue<node*> q ;
    q.push(root) ;
    q.push(nullptr) ;

    while( !q.empty()){
        node* temp = q.front() ;
        q.pop() ;


        if( temp == nullptr){
            cout << endl;
            if( !q.empty()){
                q.push(nullptr) ;
            }
        }
        else{
             cout << temp->data << " ";

            if( temp->left){
                q.push(temp->left) ;
            }

            if( temp->right){
                q.push(temp->right) ;
            }
            
        }
       
    }
}

int main() {

    node* root = nullptr ;
    // 1 2 6 -1 -1 7 -1 -1 3 4 -1 -1 5 -1 -1

    root = buildTree(root) ;

    levelOrderTraversal(root);
    return 0;
}
