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

        node *gethead(){


            return head;


       }



      void insertpos(int pos,int x){

       node *newnode=new node;
         newnode->data=x;
         newnode->next=NULL;


       if(head==NULL){

             head=newnode;


         }else{


              node *temp=head;

              for(int i=1;i<pos-1;i++){

                temp=temp->next;

              }

              newnode->next=temp->next;
              temp->next=newnode;
         }

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


       void insertforloop(int x){


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

              newnode->next=head;



         }
      }





         void display(node *head){


            if(head==NULL){

                cout<<"NULL";

            }else{

               cout<<head->data<<" ";
               display(head->next);

            }


         }


        node *swapPairwiseNodes(node *head){


           node *dummy=new node;

           dummy->next=head;

           node *temp=dummy;


          while(temp->next!=NULL && temp->next->next!=NULL){


               node *n1=temp->next;

               node *n2=temp->next->next;

                  //1.


               n1->next=n2->next;        //2.
               temp->next=n2;



               n2->next=n1;  //3.

               temp=temp->next->next;


           }

           return dummy->next;




        }



};


int main(){


        LinkedList ls;
        ls.insert(10);
        ls.insert(15);
        ls.insert(12);
        ls.insert(13);
        ls.insert(20);
        ls.insert(14);



     ls.display(ls.gethead());


    // node *head=ls.reverse(ls.gethead());   //return head to reverse list

      //ls.display(head);
    // cout<<head->next->data;


        cout<<endl;


       node *x=ls.swapPairwiseNodes(ls.gethead());

      //cout<<ls.middleusing2pointers()<<" middle";

        cout<<endl;


        ls.display(x);

     //   ls.display(ls.gethead());
        cout<<endl;

//        cout<<ls.lengthrec(ls.gethead());
        //cout<<"delete";


}