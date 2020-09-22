#include<bits/stdc++.h>
using namespace std;

struct node{

     int data;
     node *left;
     node *right;

};


class helper{

     public:


     node *newnode(int x){

          node *a=new node;
          a->data=x;
          a->right=NULL;
          a->left=NULL;
          return a;
     }

     


     void inorderIterative(node *root){


           if(root==NULL){

            return;

           }

           stack<node *> s;

           while(root!=NULL  || !s.empty()){


                if(root!=NULL){

                   s.push(root);
                   root=root->left;

                }else{

                  root=s.top();
                  s.pop();

                  cout<<root->data<<" ";
                  root=root->right;

                }



           }


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


    helper t;
	node *root=t.newnode(1);
	root->left=t.newnode(2);
	root->right=t.newnode(3);

	root->left->left=t.newnode(4);
	root->right->left=t.newnode(5);
	root->right->right=t.newnode(6);

	root->right->left->left=t.newnode(7);
	root->right->left->right=t.newnode(8);


	t.inorder(root);
	cout<<endl;
	//t.inorderIterative(root);
	t.morrisInorder(root);

}