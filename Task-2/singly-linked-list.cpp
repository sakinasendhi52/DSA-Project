/*  Task 2: Singly Linked List
    Write a C++ program to : Create a Singly Linked List
    1. Insert node at: Beginning, End
    2. Delete node from beginning
    3. Display the list
*/

//header files
#include<iostream>
using namespace std;

class Node{             //class
    public:         //data members
        int data;     
        Node *next;
        Node(int data){             //constructor
            this->data=data; 
            next=NULL;            
        }
};

class LinkedList{                //class
    public:           //data members
        Node *Head;
        int count=0;

        LinkedList(){       //default constructor
            this->Head=NULL;
        }
        void insertElement(){       //insertion operation function
            int element,choice;

            do{
                cout<<endl<<"- - - - - - - - - - - - - - - - INSERTION OPERATION - - - - - - - - - - - - - - - - -"<<endl;
                cout<<"1. INSERT ELEMENT IN BEGINNING"<<endl;
                cout<<"2. INSERT ELEMENT IN END"<<endl;
                cout<<"3. EXIT"<<endl<<endl;
                cout<<"Enter your choice : ";
                cin>>choice;
                cout<<endl;

                switch(choice){
                    case 1:{          //insert element in beginning
                        cout<<"Enter the element to insert in the Beginning : ";
                        cin>>element;
                        Node *n=new Node(element);

                        n->next=Head;
                        Head=n;
                        count++;
                        cout<<endl<<"- - - - - - - - - - - - - - - - - ELEMENT INSERTED - - - - - - - - - - - - - - - - - "<<endl<<endl;
                        break;
                    }
                    case 2:{          //insert element in end
                        cout<<"Enter the element to insert at the End : ";
                        cin>>element;
                        Node *n=new Node(element);

                        if(Head==NULL){
                            Head=n;
                        }
                        else{
                            Node *ptr=Head;
                            while(ptr->next!=NULL){
                                ptr=ptr->next;
                            }
                            ptr->next=n;
                        }
                        count++;
                        cout<<endl<<"- - - - - - - - - - - - - - - - - ELEMENT INSERTED - - - - - - - - - - - - - - - - - "<<endl<<endl;
                        break;
                    }
                    case 3:{          //exit case
                        cout<<endl<<"- - - - - - - - - - - - - - - - EXIT FROM INSERTION - - - - - - - - - - - - - - - - -"<<endl;
                        break;
                    }
                    default:{            //default case
                        cout<<"- - - - - - - - - - - - - - - - - - INVALID CHOICE - - - - - - - - - - - - - - - - - "<<endl<<endl;
                        break;
                    }
                }
            }
            while(choice!=3);
                
        }

        void deleteElement(){       //delete operation function
            int choice;

            if(Head!=NULL){
                cout<<endl<<"- - - - - - - - - - - - - - - - - DELETION OPERATION - - - - - - - - - - - - - - - - "<<endl;
                //delete element from beginning
                Node *ptr=Head;
                Head=ptr->next;
                cout<<"ELEMENT "<<ptr->data<<" IS DELETED"<<endl;
                delete ptr;
                ptr=NULL;
                count--;
                cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
            }
            else{
                cout<<endl<<"- - - - - - - - - - - - - - - - LINKED LIST IS EMPTY - - - - - - - - - - - - - - - - "<<endl;
            }
        }

        void displayLinkedList(){       //display operation function
            if(Head==NULL){
                cout<<endl<<"- - - - - - - - - - - - - - - - LINKED LIST IS EMPTY - - - - - - - - - - - - - - - -"<<endl;
            }
            else{
                Node *ptr=NULL;
                ptr=Head;
                cout<<endl<<"- - - - - - - - - - - - - - - - - DISPLAY OPERATION - - - - - - - - - - - - - - - - -"<<endl;
                cout<<"LINKED LIST ELEMENTS : ";
                while(ptr!=NULL){
                    cout<<ptr->data<<" ";
                    ptr=ptr->next;
                }
                cout<<endl<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
            }
        }

        ~LinkedList() {            //destructor
            Node *current = Head;
            while (current != NULL) {
                Node *next = current->next;
                delete current;
                current = next;
            }
        }
};
        
int main(){        //main function
    int choice;
    LinkedList list;

    do{
        cout<<endl<<endl<<"---------------------------- LINKED LIST CRUD OPERATIONS ----------------------------"<<endl<<endl;
        cout<<"1. INSERT ELEMENT       2. DELETE ELEMENT       3. DISPLAY LINKED LIST       4. EXIT"<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;        //input choice
        cout<<endl;

        switch(choice){
            case 1:{          //insert
                list.insertElement();
                break;
            }
            case 2:{          //delete
                list.deleteElement();
                break;
            }
            case 3:{          //display
                list.displayLinkedList();
                break;
            }
            case 4:{              //exit case
                cout<<endl<<"------------------------------------- THANK YOU -------------------------------------"<<endl;
                break;
            }
            default:{            //default case
                cout<<"- - - - - - - - - - - - - - - - - - INVALID CHOICE - - - - - - - - - - - - - - - - - "<<endl;
                break;
            }
        }
    }
    while(choice!=4);

    return 0;
}