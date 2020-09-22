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

              temp->next=head;



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

         void display(node *head){


            if(head==NULL){

                cout<<"NULL";

            }else{

               cout<<head->data<<" ";
               display(head->next);

            }


         }


         int length(){


          node *temp=head;
          int count=0;

          while(temp!=NULL){

            count++;
            temp=temp->next;

          }

          return count;

         }


          int lengthrec(node *temp){


             if(temp==NULL){

                  return 0;
             }else{


                return lengthrec(temp->next)+1;

             }

         }



         int middleusing2pointers(){

          node *slow=head;
          node *fast=head;

          while(fast!=NULL && fast->next!=NULL){


               fast=fast->next->next;
               slow=slow->next;

          }

          return slow->data;

         }



         bool detectloopHashing(){


         unordered_set<node*> s;

         node *temp=head;

         while(temp!=NULL){


            if(s.find(temp)!=s.end()){  //if eqial to end means nahi mila else kahi between me he

                return true;
            }

            s.insert(temp);

            temp=temp->next;
         }

         return false;

         }

         bool detectloop2pointr(){

             node *slow=head;
             node *fast=head;

             while(fast!=NULL && fast->next!=NULL){


                    slow=slow->next;
                    fast=fast->next->next;


                    if(slow==fast){


                        return true;
                    }

             }

             return false;

         }

};


int main(){


        LinkedList ls;
        ls.insert(2);
        ls.insert(6);
        ls.insert(9);



        ls.insertfront(8);   //8 2 6 9

        ls.insertpos(3,5);    // 8 2 5 6 9


        ls.insertforloop(7);

//        ls.display(ls.gethead());


        cout<<endl;


      //cout<<ls.middleusing2pointers()<<" middle";

        cout<<endl;



          if(ls.detectloop2pointr()){

             cout<<"cycle";
          }else{

           cout<<"no cycle";
          }

       cout<<endl;

     //   ls.display(ls.gethead());
        cout<<endl;

//        cout<<ls.lengthrec(ls.gethead());
        //cout<<"delete";


}