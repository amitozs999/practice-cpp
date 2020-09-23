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

   void levrordHelper(node *root,int level,bool flag){


             if(root==NULL){
                return ;
             }

             if(level==1){

                cout<<root->data<<" ";

             }else{

                 if(flag){


                  levrordHelper(root->right,level-1,flag);
                  levrordHelper(root->left,level-1,flag);

                 }else{



                   levrordHelper(root->left,level-1,flag);
                   levrordHelper(root->right,level-1,flag);


                 }

             }

     }



     void levelorder(node *root){


        if(root==NULL){

            return;
        }

        int h=height(root);   //no of levels
        //cout<<h;

        bool flag=true;
        for(int i=1;i<=h;i++){

            levrordHelper(root,i,flag);
            flag=!flag;
        }


     }

       int height(node *root){

      if(root==NULL){
        return NULL;
      }

      return max(height(root->left),height(root->right))+1;

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


	t.levelorder(root);

	cout<<endl;

    //t.zizagDeque(root);

    cout<<endl;

    //t.zigzagUsing2stacks(root);

	//t.morrisPostorder(root);
	//t.morrisPreorder(root);

}
