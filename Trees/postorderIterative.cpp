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

     
     void postorderIterative(node *root){


            if(root==NULL){

                return ;

            }

            stack<node *> s;

            s.push(root);


            while(!s.empty()){


                node *top=s.top();
                cout<<top->data<< " ";
                s.pop();



                if(top->left)
                s.push(top->left);

                if(top->right)
                   s.push(top->right);


            }




     }


     void postorderIterative1stack(node *root){


           if(root==NULL){ return;    }

           stack<node *> s;

           node *prev;

           while(root!=NULL  || !s.empty()){


                while(root!=NULL){

                   s.push(root);
                   root=root->left;


                }


                  root=s.top();

                  if(root->right==NULL || root->right==prev){

                    cout<<root->data<<" ";
                    prev=root;
                    s.pop();
                    root=NULL;

                  }else{

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


	t.postorder(root);

	cout<<endl;


}