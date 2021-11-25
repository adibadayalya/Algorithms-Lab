#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int color;
    int height;
    // 0 for black 1 for red
    Node* parent;
    Node* left;
    Node* right;

    Node *newNode(int k, Node*parent){
        Node* node = new Node();
        node->data = k;
        node->parent = parent;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return node;
    }

    int getHeight(Node * node){
        if(node==NULL){
            return 0;
        }
        return node->height;
    }

    int getBalance(Node * node){
        if(node==NULL){
            return 0;
        }
        return (getHeight(node->right)-getHeight(node->left));
    }
    
    Node *rotateRight(Node *y){
        //cout<<"testt\n";
        Node *p = y->parent;
        Node *x = y->left;
        Node *z = x->right;
        x->right =y;
        x->parent = p;
        y->parent = x;
        y->left = z;
        if(z)
        z->parent = y;
        y->height = max(getHeight(y->left),getHeight(y->right))+1;
        x->height = max(getHeight(x->left),getHeight(x->right))+1;
        return x;
    }

    Node *rotateLeft(Node *y){
        //cout<<"test\n";
        Node *x = y->right;
        Node* z = x->left;
        Node *p = y->parent;
        x->left = y;
        x->parent = p;
        y->right = z;
        y->parent = x;
        if(z)
        z->parent = y;
        y->height = max(getHeight(y->left),getHeight(y->right))+1;
        x->height = max(getHeight(x->left),getHeight(x->right))+1;
        return x;
    }

    Node* insert(Node* root,int n,Node *parent){
        if(root==NULL){
            return newNode(n,parent);
        }
        if(root->data<n){
            root->right = insert(root->right,n,root);
        } else if(root->data>n) {
            root->left = insert(root->left,n,root);
        } else return root;
        int balance = getBalance(root);
        //left left
        root->height = 1 + max(getHeight(root->left),getHeight(root->right));
        if(balance < - 1 && n<root->left->data){
            return rotateRight(root);
        }
        //right right
        if(balance > 1 && n > root->right->data){
            return rotateLeft(root);
        }
        //left right 
        if(balance<-1 && n>root->left->data){
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        //right left 
        if(balance > 1 && n<root->right->data){
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
        return root;
    }

    void preorder(Node *root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<' ';
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node *root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<' ';
        inorder(root->right);
    }
};

int main(){
    Node *tree=NULL,b;
    tree = b.insert(tree,10,NULL);
    tree = b.insert(tree,20,NULL);
    tree = b.insert(tree,30,NULL);
    tree = b.insert(tree,40,NULL);
    tree = b.insert(tree,50,NULL);
    tree = b.insert(tree,25,NULL);
    b.preorder(tree);
    cout<<'\n';
    b.inorder(tree);
    return 0;
}

