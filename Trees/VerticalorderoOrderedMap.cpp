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


     void verticalorderHashing(node *root){


         if(root==NULL){
            return;
         }

         queue<pair<node *,int>> q;
         q.push(make_pair(root,0)); //root with hd=0;

         int hd=0;

         map<int,vector<int>> map;

         while(!q.empty()){


                pair<node *,int> frontpair=q.front();
                q.pop();

                node *front=frontpair.first;
                hd=frontpair.second;

                map[hd].push_back(front->data);

                if(front->left!=NULL){

                    q.push(make_pair(front->left,hd-1));

                }

                 if(front->right!=NULL){

                    q.push(make_pair(front->right,hd+1));

                }

         }


    


      for (auto x:map) {


           vector<int> v=x.second;

           for(auto a:v){
                cout<<a<<" ";
           }

           cout<<endl;
        }


    //    for (auto x=map.begin(); x!=map.end(); x++) {

      //      for (int i=0; i<x->second.size(); ++i) {

        //           cout << x->second[i] << " ";

          //  }

            //cout<<endl;
       //}


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


	t.verticalorderHashing(root);

	cout<<endl;

    //t.zizagDeque(root);

    cout<<endl;


	//t.morrisPostorder(root);
	//t.morrisPreorder(root);

}