/*  Task 3: Queue Implementation
    Write a C++ program to Implement Queue using Array. Perform the following operations:
    1. Enqueue
    2. Dequeue
    3. Display
    4. Exit
    Handle overflow and underflow conditions.
*/

//header files
#include<iostream>
using namespace std;
   
class Queue{            //class
    private:     //data members
        int front, rear, size, count,element;
        int* arr;
    public:
        Queue(){         //constructor
            cout<<"Enter the size of Queue : ";
            cin>>size;          //input size

            front=-1;
            rear=-1;
            count=0;

            arr=new int[size];
        }

        void enqueue(){               //enqueue function
            if(rear==size-1){              //overflow condition
                cout<<"- - - - - - - - - - - - - - - - - - - QUEUE IS OVERFLOW - - - - - - - - - - - - - - - - - -"<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - - - - - - - - - - - - - ENQUEUE OPERATION - - - - - - - - - - - - - - - - - -"<<endl;
                cout<<"Enter element : ";
                cin>>element;
                if(front==-1 && rear==-1){
                    front++;
                    rear++;
                    arr[rear]=element;
                }
                else{
                    rear++;
                    arr[rear]=element;
                }
                count++;
                cout<<"ELEMENT INSERTED IN THE QUEUE"<<endl;
                cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
            }
        }

        void dequeue(){          //dequeue function
            if((front==-1 && rear==-1) || front==rear+1){          //underflow condition
                cout<<"- - - - - - - - - - - - - - - - - - - QUEUE IS UNDERFLOW - - - - - - - - - - - - - - - - - "<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - - - - - - - - - - - - - DEQUEUE OPERATION - - - - - - - - - - - - - - - - - -"<<endl;
                int temp;
                temp=arr[front];
                front++;
                count--;
                cout<<"FRONT ELEMENT "<<temp<<" DELETED"<<endl;
                if(front>rear){   // reset queue
                    front = rear = -1;
                }
                cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
            }
        }

        void displayQueue(){                 //display function
            if((front==-1 && rear==-1) || front>rear){           ////underflow condition
                cout<<"- - - - - - - - - - - - - - - - - - - QUEUE IS UNDERFLOW - - - - - - - - - - - - - - - - - "<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - - - - - - - - - - - - DISPLAY OPERATION - - - - - - - - - - - - - - - - - - -"<<endl;
                cout<<"QUEUE ELEMENTS : ";
                for(int i=front; i<=rear; i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
            }
        }

        ~Queue(){              //destructor
            delete[] arr;
        }
};

int main(){        //main function
    int choice;        //variable
    Queue s;             //object

    //do while loop
    do{
        cout<<endl<<"------------------------------------- QUEUE OPERATIONS ------------------------------------"<<endl<<endl;
        cout<<"   1. ENQUEUE              2. DEQUEUE              3. DISPLAY QUEUE              4. EXIT"<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;    //input choice
        cout<<endl;

        //switch case for menu
        switch(choice){
            case 1:{          //Insert element in the queue
                s.enqueue();
                break;
            }
            case 2:{          //Delete element from the queue
                s.dequeue();
                break;
            }
            case 3:{         //Display Queue
                s.displayQueue();
                break;
            }
            case 4:{          //exit case
                cout<<endl<<"----------------------------------------- THANK YOU ---------------------------------------"<<endl;
                break;
            }
            default:{            //default case
                cout<<"- - - - - - - - - - - - - - - - - - - INVALID CHOICE - - - - - - - - - - - - - - - - - - - "<<endl<<endl;
                break;
            }
        }
    }
    while(choice!=4);

    return 0;
}
