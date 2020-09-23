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


     void zigzagUsingLevelorder(node *root){

                if(root==NULL){
                    return;
                }

                 queue<node *> q;

                 q.push(root);

                 int levelcount=1;

                 while(!q.empty()){



                vector<int> levelres;


                for(int i=q.size()-1;i>=0;i--){

                    node *front=q.front();
                    q.pop();

                    levelres.push_back(front->data);

                    if(front->left!=NULL){

                        q.push(front->left);
                    }

                     if(front->right!=NULL){

                        q.push(front->right);
                    }




                    }


                    if(levelcount%2==0){

                        reverse(levelres.begin(),levelres.end());
                        for(auto x:levelres){

                            cout<<x<<" ";
                        }

                    }else{

                        for(auto x:levelres){

                            cout<<x<<" ";
                        }
                    }


                    levelcount++;

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

    t.zigzagUsingLevelorder(root);

    cout<<endl;

  //  t.zigzagUsing2stacks(root);

	//t.morrisPostorder(root);
	//t.morrisPreorder(root);

}