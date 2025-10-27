#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    string name;
    int score;
    Node *next;
    Node(string s = "", int sc = 0)
    {
        name = s;
        score = sc;
        next = nullptr;
    }
};

class StudentRecord
{
    Node *head;
    Node *tail;

public:
    StudentRecord()
    {
        head = tail = nullptr;
    }

    void addStudent(string n, int sc)
    {
        Node *temp = new Node(n, sc);
        if (!head)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }

        radixSort(); // sorting at every insertion
    }

    void radixSort()
    {
        int max = 0;
        Node *temp = head;
        while (temp)
        {
            if (temp->score > max)
            {
                max = temp->score;
            }

            temp = temp->next;
        }
        vector<int> scores;
        temp = head;
        while (temp)
        {
            scores.push_back(temp->score);
            temp = temp->next;
        }
        for (int exp = 1; max / exp > 0; exp *= 10)
        {
            vector<int> output(scores.size());
            vector<int> count(10, 0);

            for (int s : scores)
                count[(s / exp) % 10]++;

            for (int i = 1; i < 10; i++)
                count[i] += count[i - 1];

            for (int i = scores.size() - 1; i >= 0; i--)
            {
                int digit = (scores[i] / exp) % 10;
                output[count[digit] - 1] = scores[i];
                count[digit]--;
            }

            scores = output;
        }

        temp = head;
        for (int s : scores)
        {
            temp->score = s;
            temp = temp->next;
        }
    }

    void display(){
        Node *temp = head;

        while (temp)
        {
            cout<<"Name : "<<temp->name<< "   Score: "<<temp->score<<endl;
            temp = temp->next;
        }
        
    }
    Node* findMiddle(Node* start, Node* end) {
    if (start == nullptr)
        return nullptr;

    Node* slow = start;
    Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

    Node* binarySearchList(Node* head, string name, int score) {
    Node* start = head;
    Node* end = nullptr;

    while (start != end) {
        Node* mid = findMiddle(start, end);

        if (mid->score == score && mid->name == name)
            return mid;
        else if (mid->score < score || 
                (mid->score == score && mid->name < name))
            start = mid->next;
        else
            end = mid;
    }
    return nullptr;
}
void deleteRecord(string name, int score) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp) {
            if (temp->name == name && temp->score == score) {
                if (prev)
                    prev->next = temp->next;
                else
                    head = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

    }

    Node* getHead(){
        return head;
    }

};

int main()
{
    StudentRecord s;
    s.addStudent("umer",43);
    s.addStudent("umer",4);
    s.addStudent("umer",13);
    s.addStudent("umer",3);
    s.display();
    cout<<"Enter name to search: ";
    string n;
    cin>>n;
    cout<<"Enter score: ";
    int sc;
    cin>>sc;
    Node *t = s.binarySearchList(s.getHead(),n,sc);
    if (t)
    {
        s.deleteRecord(t->name,t->score);
    }
    s.display();  
    return 0;
}