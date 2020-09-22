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


         void swapnodes(node *head,int x,int y){


                    node *prevx=NULL;
                    node *currx=head;


                    if(x==y){

                        return;
                    }

                    while(currx!=NULL && currx->data!=x){

                        prevx=currx;

                        currx=currx->next;


                    }

                    node *prevy=NULL;
                    node *curry=head;

                  while(curry!=NULL && curry->data!=y){

                        prevy=curry;

                        curry=curry->next;


                    }


                    if(currx==NULL || curry==NULL){


                        return;


                    }


                    if(prevx!=NULL){

                            prevx->next=curry;
                    }else{

                        //currx is head

                           head=curry;

                    }

                    if(prevy!=NULL){


                        prevy->next=currx;
                    }else{

                       head=currx;

                    }


                    node *temp=curry->next;

                    curry->next=currx->next;

                    currx->next=temp;








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

        ls.swapnodes(ls.gethead(),15,20);

      //cout<<ls.middleusing2pointers()<<" middle";

        cout<<endl;


        ls.display(ls.gethead());

     //   ls.display(ls.gethead());
        cout<<endl;

//        cout<<ls.lengthrec(ls.gethead());
        //cout<<"delete";


}