#include<bits/stdc++.h>
using namespace std;

struct node{

     int data;
     node *next;
};

class LinkedList{

      node *head;
      node *tail;

      public :

      LinkedList(){


          head=NULL;
          tail=NULL;


      }

      void insert(int x){


         node *newnode=new node;
         newnode->data=x;
         newnode->next=NULL;

         if(head==NULL){

            head=newnode;
            tail=newnode;

         }else{


              tail->next=newnode;
              tail=newnode;


         }
      }


         void display(){


             node *temp=head;
             while(temp!=NULL){

                cout<<temp->data<<" ";
                temp=temp->next;

             }


         }






};


int main(){


        LinkedList ls;
        ls.insert(2);
        ls.insert(6);
        ls.insert(9);
        ls.display();


}
