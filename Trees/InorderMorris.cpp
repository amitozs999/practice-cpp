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





            void morrisInorder(node *root){


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
                            root=root->left;

                         }
                          if(pre->right==root){  //==root


                         cout<<root->data<<" ";
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