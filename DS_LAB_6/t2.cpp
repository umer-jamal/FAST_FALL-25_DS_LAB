#include <iostream>
#include <iomanip>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class Record
{
public:
    int id;
    double value;
    string note;
    bool isSale;

    Record(int i = 0, double v = 0, string n = "")
        : id(i), value(v), note(n), isSale(v >= 0) {}

    void show() const
    {
        cout<<"ID: " << id << endl;
        cout<<"Amount: " << fixed << setprecision(2) << value << endl;
        cout<<"Description: " << note << endl;
        cout<<"Type: " << (isSale ? "Sale" : "Refund") << endl;
        cout<<endl;
    }
};

struct Entry
{
    Record rec;
    Entry *next;
    Entry(const Record &r) : rec(r), next(nullptr) {}
};

class TransactionStack
{
    Entry *head;
    int nextID;

public:
    TransactionStack() : head(nullptr), nextID(1) {}

    void pushRecord(Record r)
    {
        r.id = nextID++;
        if (r.note.size() > 20)
            r.note = r.note.substr(0, 17) + "...";
        if (r.value > 0)
        {
            if (r.value >= 1500)
                r.value *= 0.7;
            else if (r.value >= 1000)
                r.value *= 0.85;
            else if (r.value >= 500)
                r.value *= 0.95;
        }
        r.isSale = r.value >= 0;
        Entry *e = new Entry(r);
        e->next = head;
        head = e;
    }

    Record popRecord()
    {
        if (!head)
            return Record();
        Entry *temp = head;
        Record r = temp->rec;
        head = head->next;
        delete temp;
        r.value *= -1;
        r.note += " [REVERSED]";
        r.isSale = r.value >= 0;
        return r;
    }

    bool empty() const { return head == nullptr; }
};

class ExpressionCalc
{
    static bool isOp(char c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
    static int prec(char c)
    {
        if (c == '+' || c == '-')
            return 1;
        if (c == '*' || c == '/')
            return 2;
        return 0;
    }

public:
    string toPostfix(const string &infix)
    {
        stack<char> ops;
        string post;
        for (size_t i = 0; i < infix.size(); i++)
        {
            char c = infix[i];
            if (c == ' ')
                continue;
            if (isdigit(c) || c == '.')
            {
                while (i < infix.size() && (isdigit(infix[i]) || infix[i] == '.'))
                    post += infix[i++];
                post += ' ';
                i--;
            }
            else if (c == '(')
                ops.push(c);
            else if (c == ')')
            {
                while (!ops.empty() && ops.top() != '(')
                {
                    post += ops.top();
                    post += ' ';
                    ops.pop();
                }
                if (!ops.empty())
                    ops.pop();
            }
            else if (isOp(c))
            {
                while (!ops.empty() && prec(ops.top()) >= prec(c))
                {
                    post += ops.top();
                    post += ' ';
                    ops.pop();
                }
                ops.push(c);
            }
        }
        while (!ops.empty())
        {
            post += ops.top();
            post += ' ';
            ops.pop();
        }
        return post;
    }

    double evalPostfix(const string &postfix)
    {
        stack<double> s;
        for (size_t i = 0; i < postfix.size(); i++)
        {
            char c = postfix[i];
            if (c == ' ')
                continue;
            if (isdigit(c) || c == '.')
            {
                string num;
                while (i < postfix.size() && (isdigit(postfix[i]) || postfix[i] == '.'))
                    num += postfix[i++];
                s.push(stod(num));
                i--;
            }
            else if (isOp(c))
            {
                double b = s.top();
                s.pop();
                double a = s.top();
                s.pop();
                if (c == '+')
                    s.push(a + b);
                else if (c == '-')
                    s.push(a - b);
                else if (c == '*')
                    s.push(a * b);
                else if (c == '/')
                    s.push(a / b);
            }
        }
        return s.top();
    }
};

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    TransactionStack stacker;

    Record all[7] = {
        {1, 1200, "Sale: Blue Jacket"},
        {2, 450, "Sale: Cotton Socks"},
        {3, -300, "Refund: Defective Shirt"},
        {4, 1700, "Sale: Leather Jacket"},
        {5, -150, "Refund: Color Fade Issue"},
        {6, 800, "Sale: Winter Gloves"},
        {7, -500, "Refund: Size Mismatch"}};

    const int N = 5;
    int chosen[N];
    for (int i = 0; i < N; i++)
    {
        int idx = rand() % 7;
        chosen[i] = idx;
        stacker.pushRecord(all[idx]);
    }

    Record reversed[N];
    int pos = N - 1;
    while (!stacker.empty())
    {
        reversed[pos--] = stacker.popRecord();
    }

    for (int i = 0; i < N; i++)
        all[chosen[i]].show();
    for (int i = 0; i < N; i++)
        reversed[i].show();

    ExpressionCalc calc;
    string inf = "(100 + 20) * 0.9 - 5";
    string post = calc.toPostfix(inf);
    double val = calc.evalPostfix(post);

    cout << "Original Expression (Infix): " << inf << endl;
    cout << "Compiled Expression (Postfix): " << post << endl;
    cout << fixed << setprecision(2) << "Evaluated Expression: " << val << endl;
    cout << endl;

    return 0;
}
