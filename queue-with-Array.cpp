#include <iostream>
using namespace std;
class Queue
{
    private:
    int *qu;
    int front;
    int rear;
    int capacity;
    public:
    Queue(int s);         // constructor
    ~Queue();        // destructor
    bool is_empty();
    bool is_full();
    void enqueue(int x);
    int dequeue();
    int retrieve();
};
Queue::Queue(int s)
{
    qu=new int [s];
    front=0;
    rear=-1;
    capacity=s;
}
Queue::~Queue()
{
    delete [] qu;
}
bool Queue::is_empty()
{
    if (front>rear) return true;
    else return false;
}
bool Queue::is_full()
{
    if(capacity-1==rear) return true;
    else return false;
}
void Queue::enqueue(int x)
{
    
        rear++;
        qu[rear]=x;
    
}
int Queue::dequeue()
{
    if(is_empty())
    {
        cout<<"This queue is empty.\n";
        return -1;
    }
    else
    {
        int temp;
        temp=qu[front];
        front++;
        return temp;
    }
}
int Queue::retrieve()
{
    if(is_empty())
    {
        cout<<"This queue is empty.\n";
        return -1;
    }
    else
    {
        return qu[front];
    }
}
int main()
{
    int s;
    cout<<"please enter the size of queue: ";
    cin>>s;
    Queue que(s);
    int c,x,temp;
    bool cont=true;
    char co;
    cout << "\n+++++++ Guide: +++++++\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Retrieve\n";
    cout << "4. Is queue empty?\n";
    while (cont)
    {
        cout<<"Please enter your choice: ";
        cin>>c;
        switch (c)
        {
        case 1:
            if(que.is_full())
            {
            cout<<"This queue is full.\n";
            }
            else
            {
            cout<<"\nEnter your integer: ";
            cin>>x;
            que.enqueue(x);
            }
            break;
        case 2:
            temp=que.dequeue();
            if(temp!=-1)
            {cout<<"\n Front element is "<<temp<<" and dequeue.";}
            break;
        case 3:
            temp=que.retrieve();
            if(temp!=-1)
            {cout<<"\n Front element is "<<temp;}
            break;
        case 4:
            if(que.is_empty())
            {
                cout<<"\n Queue is empty.";
            }
            else
            {
                cout<<"\n Queue is not empty.";
            }
            break;
        default:
            cout << "\n Invalid choice! Please try again.\n";
            break;
        }
        cout << "\nDo you want to continue? (Y/N): ";
        cin >> co;
        cont = (co == 'y' || co == 'Y');
    }
    cout << "Exiting program.\n";
    return 0;
}