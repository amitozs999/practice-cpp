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



     void leftview(node *root){


                 queue<node *> q;

                 q.push(root);

                 while(!q.empty()){

                 int i=0;

                 int n=q.size();

                 while(n--){

                    i++;

                    node *front=q.front();
                    q.pop();

                    if(i==1)

                    cout<<front->data<<" ";

                    if(front->left!=NULL){

                        q.push(front->left);
                    }

                    if(front->right!=NULL){

                        q.push(front->right);
                    }

                 }

                 cout<<endl;


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


	t.leftview(root);

	cout<<endl;

    //t.zizagDeque(root);

    cout<<endl;


	//t.morrisPostorder(root);
	//t.morrisPreorder(root);

}