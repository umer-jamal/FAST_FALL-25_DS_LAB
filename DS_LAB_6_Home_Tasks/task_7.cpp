#include<iostream>
using namespace std;

class Patron{
    public:
    int books;
    string name;
    Patron(string s="",int d = 0){
        books = d;
        name = s;
    }

    
};
class Library{
    int staff;
    int size;
    Patron *p;
    int currentSize;
    int front;
    int rear;
    int processingTime;
    public:
    Library(int s,int st,int t=0){
        staff = st;
        size = s;
        p = new Patron[size];
        front = 0;
        rear = -1;
        currentSize = 0;
        processingTime = t;
    }
    bool isEmpty(){
        return currentSize==0;
    }
    void addPatron(Patron *p1){
        if (currentSize-1==size)
        {
            return;
        }
        rear = (rear+1)%size;
        p[rear] = *p1;
        currentSize++;
        
    }

    void removePatron(){
        if (isEmpty())
        {
            return;
        }

        cout<<"Processing patron ";
        for (int i = 0; i <(processingTime+p[front].books)-staff; i++)
        {
            cout<<".";  // total time req would be processing time + number of books and  - staff 
        }
        cout<<endl;
        front = (front+1)%size;
        currentSize--;
        
        
    }
    void display(){
        for (int i = front; i <= rear; i++)
        {
            cout<<"Patron "<<i+1<<"\t\b\b\b";
            cout<<p[i].name<<"\tNumber of books: "<<p[i].books<<endl; 
        }
        
    }
};

int main(){
    Library l(5,3,2); // size of list 5 , staff 3 processing time 2
    Patron p1("umer",4);
    Patron p2("arif",3);
    Patron p3("jamal",10);
    Patron p4("jamal",19);
    l.addPatron(&p1);
    l.addPatron(&p2);
    l.addPatron(&p3);
    l.addPatron(&p4);
    l.display();

    l.removePatron();
    l.removePatron();
    l.display();
}