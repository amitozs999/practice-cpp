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


      void deleteatpos(int pos){



              node *temp=head;

              for(int i=1;i<pos-1;i++){

                temp=temp->next;

              }
              node *tobedel=temp->next;
            temp->next=tobedel->next;

             free(tobedel);


      }

      void deletewholell(){



         node *curr=head;
         node *after;


         while(curr!=NULL){


            after=curr->next;
            free(curr);
            curr=after;
         }

         head=NULL;

         cout<<"deleted";

      }

       void deletewholellrecursively(node *temp){



         if(temp==NULL){

               head=NULL;
              return;

         }else{


              deletewholellrecursively(temp->next);

              free(temp);

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



        ls.insertfront(8);   //8 2 6 9

        ls.insertpos(3,5);    // 8 2 5 6 9

        ls.deleteatpos(4);     //8 2 5 9
        ls.display(ls.gethead());


        ls.deletewholellrecursively(ls.gethead());
        ls.display(ls.gethead());
        cout<<"delete";


}