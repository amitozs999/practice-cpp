#include<bits/stdc++.h>
using namespace std;

struct node{

     int data;
     node *next;
};

class LinkedList{

public:
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


        node *intersectionList(node *a,node *b){


         node *output=NULL;
         node *outTail=NULL;

         while(a!=NULL && b!=NULL){


            if(a->data==b->data){

                 node *newnode=new node;
                 newnode->data=a->data;
                 newnode->next=NULL;

                 if(output==NULL){

                    output=newnode;
                    outTail=newnode;

                 }else{


                     outTail->next=newnode;
                     outTail=newnode;

                 }

                a=a->next;
                b=b->next;

            }else if(a->data<b->data){

                     a=a->next;

            }else{

                    b=b->next;

            }



         }


         return output;

        }

};


int main(){


        LinkedList ls1;
        ls1.insert(10);
        ls1.insert(11);
        ls1.insert(12);
        ls1.insert(13);
        ls1.insert(15);
        ls1.insert(19);


         LinkedList ls2;
        ls2.insert(10);
        ls2.insert(13);
        ls2.insert(17);
        ls2.insert(18);
        ls2.insert(19);
        ls2.insert(20);





     ls1.display(ls1.gethead());

     cout<<endl;

     ls2.display(ls2.gethead());


    // node *head=ls.reverse(ls.gethead());   //return head to reverse list

      //ls.display(head);
    // cout<<head->next->data;


        cout<<endl;

        LinkedList l;
        //node *head=l.intersectionList(ls1.gethead(),ls2.gethead());

      //  l.display(ls2.gethead());
        node *head=l.intersectionList(ls1.gethead(),ls2.gethead());
        l.display(head);

        cout<<endl;


//        ls.display(x);

     //   ls.display(ls.gethead());
        cout<<endl;

//        cout<<ls.lengthrec(ls.gethead());
        //cout<<"delete";


}
