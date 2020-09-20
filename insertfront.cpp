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

         }else{


              node *temp=head;
              while(temp->next!=NULL){

                temp=temp->next;

              }

              temp->next=newnode;



         }
      }


      void insertfront(int x){

         node *newnode=new node;
         newnode->data=x;
         newnode->next=NULL;

         if(head==NULL){

             head=newnode;


         }else{


               newnode->next=head;
               head=newnode;
         }


      }





       node *gethead(){

            return head;

       }

         void display(node *head){


            if(head==NULL){

                cout<<"NULL";

            }else{

               cout<<head->data<<" ";
               display(head->next);

            }


         }






};


int main(){


        LinkedList ls;
        ls.insert(2);
        ls.insert(6);
        ls.insert(9);

        ls.insertfront(8);
        ls.display(ls.gethead());


}
