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



      bool search(int x){

          node *temp=head;

          while(temp!=NULL){


            if(temp->data==x){

              return true;

            }

            temp=temp->next;


          }

          return false;


      }


       bool searchrec(node *temp,int x){

            if(temp==NULL){

                return false;
            }

            if(temp->data==x){

                return true;

            }else{

              searchrec(temp->next,x);

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

         int nthelement(int n){


                node *temp=head;

                int count=0;

                while(temp!=NULL){

                    count++;

                    if(count==n){

                        return temp->data;

                    }
                    temp=temp->next;


                }


                assert(0);


         }

         int nthelementrec(node *temp,int n){


            int count=1;

            if(temp==NULL){

                assert(0);
            }
            if(count==n){

                return temp->data;

            }else{

                nthelementrec(temp->next,n-1);

            }

          //  assert(0);


         }


         int nthfromend(int n){


             node *temp=head;

             int len=0;

             while(temp!=NULL){

                len++;
                temp=temp->next;

             }

             // 1 2 3 4 5
             // 2nd from end=4;  5-2+1

             temp=head;

             for(int i=1;i<len-n+1;i++){

              temp=temp->next;

             }


             return temp->data;

         }


         void nthfromendRec(node *temp,int n){

             static int i=1;

            if(temp==NULL){

            return;


            }else{


                nthfromendRec(temp->next,n);


            }



            if(i==n){

                cout<<temp->data;
            }

              i++;




         }


         int nthFromEndUsing2pointers(int n){

           node *first=head;

           for(int i=1;i<=n;i++){

               first=first->next;

           }

           node *second=head;
           while(first!=NULL){

                first=first->next;
                second=second->next;
           }

           return second->data;

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


};


int main(){


        LinkedList ls;
        ls.insert(2);
        ls.insert(6);
        ls.insert(9);



        ls.insertfront(8);   //8 2 6 9

        ls.insertpos(3,5);    // 8 2 5 6 9



        //ls.deleteatpos(4);     //8 2 5 9
        ls.display(ls.gethead());


        cout<<endl;

       // cout<<ls.nthfromend(2)<<" 2nd from end";

      // cout<<ls.nthFromEndUsing2pointers(3)<<" last";

      cout<<ls.middleusing2pointers()<<" middle";

        cout<<endl;
        bool prsnt=ls.searchrec(ls.gethead(),3);
        if(prsnt){

           cout<<"present";

        }else{

          cout<<"not present";
        }

        cout<<endl;


        //cout<<ls.nthelement(9);

     //   cout<<ls.nthelementrec(ls.gethead(),6)<<" n th";



       // ls.deletewholellrecursively(ls.gethead());

       cout<<endl;

        ls.display(ls.gethead());
        cout<<endl;

        cout<<ls.lengthrec(ls.gethead());
        //cout<<"delete";


}