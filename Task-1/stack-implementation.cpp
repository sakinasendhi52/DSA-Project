/* Task 1: Stack Implementation
   Write a C++ program to : Implement Stack using Array. Perform the following operations using menu:
   1. Push
   2. Pop
   3. Display
   4. Exit
   Handle overflow and underflow conditions.
*/

//header files
#include<iostream>
using namespace std;
   
class Stack{           //class
    private:      //private attributes
        int top, size,element;
        int* arr;       //array
    public:
        Stack(){     //constructor
            cout<<"Enter the size of Stack : ";
            cin>>size;

            top=-1;

            arr=new int[size];
        }

        void pushInStack(){           //push operation
            if(top>=size-1){       //overflow condition
                cout<<"- - - - - - - - - - - - - - - - - - STACK IS OVERFLOW - - - - - - - - - - - - - - - - - - - "<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - - - - - - - - - - - - - PUSH OPERATION - - - - - - - - - - - - - - - - - - - "<<endl;
                cout<<"Enter element : ";
                cin>>element;
                top++;
                arr[top]=element;      //element inserted
                cout<<"ELEMENT INSERTED"<<endl;
                cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<endl<<endl;
            }
        }

        void popFromStack(){           //pop operation
            if(top==-1){       //underflow condition
                cout<<"- - - - - - - - - - - - - - - - - - STACK IS UNDERFLOW - - - - - - - - - - - - - - - - - - "<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - - - - - - - - - - - - - POP OPERATION - - - - - - - - - - - - - - - - - - - -"<<endl;
                int temp;
                temp=arr[top];
                top--;       //element removed
                cout<<"TOP ELEMENT "<<temp<<" DELETED"<<endl;
                cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<endl<<endl;                
            }
        }

        void displayStack(){          //display operation
            if(top==-1){        //underflow condition
                cout<<"- - - - - - - - - - - - - - - - - - STACK IS UNDERFLOW - - - - - - - - - - - - - - - - - - "<<endl<<endl;
            }
            else{
                cout<<"- - - - - - - - - - - - - - - - - - DISPLAY OPERATION - - - - - - - - - - - - - - - - - - -"<<endl;
                for(int i=top; i>=0; i--){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<<endl<<endl;
            }
        }

        ~Stack(){         //destructor
            delete[] arr;
            arr=nullptr;
        }
};

int main(){               //main function
    int choice;        //variable
    Stack s;          //class object 

    //do while loop
    do{
        cout<<endl<<"------------------------------------- STACK OPERATIONS ------------------------------------"<<endl;
        cout<<" 1. PUSH ELEMENT            2. POP ELEMENT            3. DISPLAY STACK            4. EXIT"<<endl;
        cout<<"-------------------------------------------------------------------------------------------"<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;      //input choice
        cout<<endl;

        //switch case for menu
        switch(choice){
            case 1:{          //push element in the stack
                s.pushInStack();
                break;
            }
            case 2:{          //pop element from the stack
                s.popFromStack();
                break;
            }
            case 3:{          //display element in the Stack
                s.displayStack();
                break;
            }
            case 4:{              //exit case
                cout<<"---------------------------------------- THANK YOU ----------------------------------------"<<endl;
                break;
            }
            default:{            //default case
                cout<<endl<<"- - - - - - - - - - - - - - - - - - - INVALID CHOICE - - - - - - - - - - - - - - - - - - - "<<endl<<endl;
                break;
            }
        }
    }
    while(choice!=4);

    return 0;
}
