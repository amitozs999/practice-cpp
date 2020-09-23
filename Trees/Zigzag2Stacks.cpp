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



     void zigzagUsing2stacks(node *root){


           if(root==NULL){

               return;
           }

           stack<node *> s1,s2;  //s1 L->R
                                 //s2 L<-R

           s1.push(root);


           while(!s1.empty() || !s2.empty()){


                 while(!s1.empty()){

                    node *top=s1.top();
                    s1.pop();

                    cout<<top->data<<" ";

                    if(top->left!=NULL){

                        s2.push(top->left);

                    }
                    if(top->right!=NULL){

                        s2.push(top->right);  // put right right so that can be printed first while L<-R

                    }


                 }


                   while(!s2.empty()){

                    node *top=s2.top();
                    s2.pop();

                    cout<<top->data<<" ";

                    if(top->right!=NULL){

                        s1.push(top->right);

                    }

                    if(top->left!=NULL){

                        s1.push(top->left);     // put left last so that left can be printed first while L->R

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
           2       9
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
	root->right=t.newnode(9);

	root->left->left=t.newnode(4);
	root->right->left=t.newnode(5);
	root->right->right=t.newnode(6);

	root->right->left->left=t.newnode(7);
	root->right->left->right=t.newnode(8);


	//t.levelorder(root);

	cout<<endl;


    cout<<endl;

    t.zigzagUsing2stacks(root);

	//t.morrisPostorder(root);
	//t.morrisPreorder(root);

}