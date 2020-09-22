#include<bits/stdc++.h>
using namespace std;

struct node{

     int data;
     node *left;
     node *right;

     node(int x){

          data=x;
          left=right=NULL;

     }

};


class helper{

     public:

     void preorder(node *root){


        if(root==NULL){

            return;
        }

        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);

     }


};


int main(){



	/* Construct below tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
             /   \
            /     \
           7       8
	*/

	node *root=new node(1);
	root->left=new node(2);
	root->right=new node(3);

	root->left->left=new node(4);
	root->right->left=new node(5);
	root->right->right=new node(6);

	root->right->left->left=new node(7);
	root->right->left->right=new node(8);


    helper t;
	t.preorder(root);
	cout<<endl;
	//t.preorderIterative(root);
	

}