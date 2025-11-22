#include<iostream>
using namespace std;

class Student{
    public:
    int rollNumber;
    string  name;
    Student* next;
    Student(int r,string n){
        name = n;
        rollNumber = r;
    }


};

class StudentHashTable{
    int size;
    Student **array;
    int *keys;
    bool *occupied;
    public:
    StudentHashTable(int s=15){
        size = s;
        array = new Student*[size];
        keys = new int[size];
        occupied = new bool[size];
        for (int i = 0; i <size; i++)
        {
            array[i] = NULL;
            keys[i] = 0;
            occupied[i] = false;
        }
        
    }
    void search(int r){
        int hash = r%size;
        int index;
        int i = 0;

        while (i < size) {
            index = (hash + i * i) % size;

            if (!occupied[index])
            {   cout<< "NOT FOUND"; 
                return;
            }// empty slot ? key not present
            if (keys[index] == r) 
            {   cout<<array[index]->name;
                return;
            }

            i++;
        }

        cout<< "NOT FOUND"; // searched all slots
    
    }
    void insert(int r,string s){
        Student *n = new Student(r,s);
        int hash = r%size;
        int ind;
        int i=0;
        while (i<size)
        {
            ind = (hash+ i*i)%size;
            if (!occupied[ind] || keys[ind]==r)
            {
                keys[ind] = r;
                occupied[ind] = 1;
                array[ind] = n;
                return;
            }
            i++;
            
        }
        
    }

    void display() {
        cout << "Index\tRollNumber\tName\n";
        for (int i = 0; i < size; i++) {
            if (occupied[i])
                cout << i << "\t" << keys[i] << "\t" << array[i]->name << "\n";
            else
                cout << i << "\t-\t-\n";
        }
    }
};



int main(){
    StudentHashTable s;
    s.insert(14,"umer");
    s.insert(4,"arif");
    s.insert(13,"jamal");
    s.insert(12,"asad");
    s.search(4);
    cout<<endl;
    s.display();
}