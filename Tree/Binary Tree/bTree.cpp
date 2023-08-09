#include <bits/stdc++.h>
using namespace std ;

class Node {
   
public:

    int data ;
    Node* left ;
    Node* right ;

    Node( int n){
        this->data = n ;
        this->left = nullptr;
        this->right = nullptr;
    }

};

Node * buildTree( Node * root ){

    cout << "Enter data: " << endl; 
    int data ;
    cin >> data ;

    if( data == -1){
        return nullptr;
    }

    root = new Node(data) ;

    cout << "Data for left of " << data  << endl;
    root->left = buildTree(root->left) ;
    cout << "Data for right of " << data  << endl;
    root->right = buildTree(root->right) ;

    return root ;

}

void levelOrderTraversal (Node * root){
    queue<Node*> q ;
    q.push(root) ;
    q.push(nullptr) ;

    while( !q.empty()){
        Node* temp = q.front() ;
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

void buildTreeLevelOrder(Node * &root){

    queue<Node*> q ;
    cout << "Root: ";
    int data ;
    cin >> data;
    root = new Node(data) ;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;

        cout << "Left Node for: " << temp->left << endl ;
        int leftD;
        cin >> leftD ;

        if( leftD != -1){
            temp->left = new Node(leftD);
            q.push(temp->left) ;
        }

        cout << "Right Node for: " << temp->right << endl ; ;
        int rightD;
        cin >> rightD ;

        if( rightD != -1){
            temp->right = new Node(rightD);
            q.push(temp->right);
        }

    }
    // return root ;
    

}

void inorderTraversal(Node* root){

    if(root == nullptr){
        return ;
    }

    inorderTraversal(root->left) ;
    cout << root->data << " " ;
    inorderTraversal(root->right) ;

}

void preorderTraversal(Node* root){

    if(root == nullptr){
        return ;
    }

    cout << root->data << " " ;
    preorderTraversal(root->left) ;
    preorderTraversal(root->right) ;

}

void postorderTraversal(Node* root){

    if(root == nullptr){
        return ;
    }

    postorderTraversal(root->left) ;
    postorderTraversal(root->right) ;
    cout << root->data << " " ;

}

int main() {

    Node* root = nullptr ;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    // root = buildTree(root) ;

    // levelOrderTraversal(root);
    // cout << "Inorder: " ;
    // inorderTraversal(root) ;
    // cout << endl;
    // cout << "Preorder: " ;
    // preorderTraversal(root) ;
    // cout << endl;
    // cout << "Postorder: " ;
    // postorderTraversal(root) ;
    // cout << endl;

    buildTreeLevelOrder(root) ;
    levelOrderTraversal(root);


    return 0;
}
