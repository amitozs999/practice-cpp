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


            void morrisPostorder(node *curr){



                 node *dummy=newnode(0);
                 dummy->left=curr;

                 node *root=dummy;




                 while(root!=NULL){


                    if(root->left==NULL){

                      root=root->right;

                    }
                    else
                        {

                         node *pre=root->left;

                         while(pre->right!=NULL && pre->right!=root){

                            pre=pre->right;

                         }

                         if(pre->right==NULL){

                            pre->right=root;
                            root=root->left;

                         }
                          if(pre->right==root){  //==root


                          //means we have traversed it already



                             node *spre=pre;

                             //Reverse from root.left to pre.
                             reverse(root->left,pre);

                             //traverse from pre to root.left and print the nodes.
                             while(spre!=root->left){

                               cout<<spre->data<<" ";
                                spre=spre->right;

                             }

                             cout<<spre->data<<" ";

                             //Re-reverse it back to normal.
                             reverse(pre,root->left);


                             pre->right=NULL;
                             root=root->right;

                         }



                    }


                 }

            }

            void reverse(node *start,node *end){

                if(start==end) return;

                node *prev=start;
                node *curr=start->right;


                while(prev!=end){

                    node *next=curr->right;

                    curr->right=prev;
                    prev=curr;
                    curr=next;

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


	t.postorder(root);

	cout<<endl;

	t.morrisPostorder(root);
	//t.morrisPreorder(root);

}