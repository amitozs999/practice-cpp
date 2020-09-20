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

         node* reverse(node *curr){


           if(curr==NULL || curr->next==NULL){

                     return curr;
           }

           node *revhead=reverse(curr->next);

           curr->next->next=curr;
           curr->next=NULL;


                  return revhead;


         }





         void remDupUnsorted(node *head){

           node* temp1=head;
           node* temp2;

           while(temp1!=NULL && temp1->next!=NULL){

                  temp2=temp1;

                  while(temp2->next!=NULL){


                        if(temp1->data==temp2->next->data){

                            node *a=temp2->next;
                            temp1->next=temp2->next->next;
                            free(a);

                        }else{


                            temp2=temp2->next;

                        }
                   }

                   temp1=temp1->next;


           }

         }


          node* remDupUnsortedHashing(node *head){

           node* temp=head;

           unordered_set<int> s;

           node *prev=NULL;

           while(temp!=NULL){


               if(s.find(temp->data)!=s.end()){


                  prev->next=temp->next;
                  free(temp);

                  temp=prev->next;






               }else{


                  s.insert(temp->data);

                  prev=temp;
                  temp=prev->next;

               }







           }

           return head;



         }


};


int main(){


        LinkedList ls;
        ls.insert(6);
        ls.insert(2);
        ls.insert(2);
        ls.insert(10);



     ls.display(ls.gethead());


    // node *head=ls.reverse(ls.gethead());   //return head to reverse list

      //ls.display(head);
    // cout<<head->next->data;


        cout<<endl;

        node *head=ls.remDupUnsortedHashing(ls.gethead());

        ls.display(head);

      //cout<<ls.middleusing2pointers()<<" middle";

        cout<<endl;




     //   ls.display(ls.gethead());
        cout<<endl;

//        cout<<ls.lengthrec(ls.gethead());
        //cout<<"delete";


}
