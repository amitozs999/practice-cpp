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

  

            void morrisPreorder(node *root){


                 while(root!=NULL){


                    if(root->left==NULL){

                      cout<<root->data<<" ";
                      root=root->right;

                    }else{

                         node *pre=root->left;

                         while(pre->right!=NULL && pre->right!=root){

                            pre=pre->right;

                         }

                         if(pre->right==NULL){

                            pre->right=root;
                            cout<<root->data<<" ";
                            root=root->left;

                         }else{  //==root


                             pre->right=NULL;
                             root=root->right;

                         }



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
	t.morrisPreorder(root);

}