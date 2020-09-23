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





     void zizagDeque(node *root){


           if(root==NULL){
              return ;
           }

           deque<node *> dq;

           dq.push_back(root);

           int l=1;

           while(!dq.empty()){


                 int n=dq.size();

                    if(l%2!=0){

                     while(n--){

                  //  cout<<"here1";
                        node *top=dq.front();
                        dq.pop_front();

                        cout<<top->data<<" ";

                        if(top->left!=NULL){

                            dq.push_back(top->left);

                        }

                        if(top->right!=NULL){

                            dq.push_back(top->right);

                        }

                     }


                    }else{

                     while(n--){
                     //   cout<<"here2";
                        node *top=dq.back();
                        dq.pop_back();

                        cout<<top->data<<" ";

                        if(top->right!=NULL){

                            dq.push_front(top->right);

                        }

                        if(top->left!=NULL){

                            dq.push_front(top->left);

                        }

                    }

                    }





                 l=1-l;
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

    t.zizagDeque(root);

    cout<<endl;

    //t.zigzagUsing2stacks(root);

	//t.morrisPostorder(root);
	//t.morrisPreorder(root);

}
