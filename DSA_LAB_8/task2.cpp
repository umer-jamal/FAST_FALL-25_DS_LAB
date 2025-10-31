#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Combatant {
public:
    string name;
    int health;
    int attack;

    Combatant(string n = "", int h = 0, int a = 0)
        : name(n), health(h), attack(a) {}
        void display(){
        cout<<"Combatant Name: "<<name<<endl;
        cout<<"Health : "<<health<<endl;
        cout<<"Attack power : "<<attack<<endl<<endl;
    }
};

class Node {
public:
    Combatant c;
    Node* left;
    Node* right;

    Node(Combatant combatant) {
        c = combatant;
        left = right = NULL;
    }

    
};

class BST {
public:
    Node* root;

    BST() { root = NULL; }

    Node* insert(Node* root, Combatant c) {
        if (root == NULL)
            return new Node(c);
        if (c.name < root->c.name)
            root->left = insert(root->left, c);
        else
            root->right = insert(root->right, c);
        return root;
    }

    void insert(Combatant c) {
        root = insert(root, c);
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* remove(Node* root, string name) {
        if (root == NULL) return root;

        if (name < root->c.name)
            root->left = remove(root->left, name);
        else if (name > root->c.name)
            root->right = remove(root->right, name);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->c = temp->c;
            root->right = remove(root->right, temp->c.name);
        }
        return root;
    }

    void remove(string name) {
        root = remove(root, name);
    }

        
    

    Node* getFrontline() {
        
    }

    void inorder(Node *root){
        if (root==NULL)
        {
            return;
        }
        
        inorder(root->left);
        root->c.display();
        inorder(root->right);
    }

    void display(Node* node) {
        node->c.display();
    }

    void displayTeam() {
        inorder(root);
        
    }
    bool isEmpty(){
        return root==NULL;
    }
    bool isAlive(Node *n){
        if (n->c.health>0)
        {
            return 1;
        }
        return 0;
        
    }
};
class Battle_Quest {
private:
    BST playerTeam;
    BST enemyTeam;

public:
    
    void initializeTeams() {
        Combatant c1 ("umer",50,50);
        Combatant c2 ("arif",50,50);
        Combatant c3("jamal",50,50);
        Combatant c4("kamil",50,50);
        Combatant c5("hadi",50,50);
        playerTeam.insert(c1);
        playerTeam.insert(c2);
        playerTeam.insert(c3);
        playerTeam.insert(c4);
        playerTeam.insert(c5);

        Combatant c6 ("waqar",89,55);
        Combatant c7 ("imran",52,53);
        Combatant c8("anas",51,60);
        Combatant c9("sajid",52,70);
        Combatant c10("bilal",52,45);
        enemyTeam.insert(c6);
        enemyTeam.insert(c7);
        enemyTeam.insert(c8);
        enemyTeam.insert(c9);
        enemyTeam.insert(c10);

    }
    Battle_Quest() {
        srand(time(0));
        initializeTeams();
    }

    void displayTeams() {
       cout<<"\n\tPlayer team\n";
       playerTeam.displayTeam();
       cout<<"---------------------------------\n";
       cout<<"\n\tEnemy team\n";
       enemyTeam.displayTeam();
       cout<<"---------------------------------\n";
       
    }

    void attack(Node* attacker, Node* defender, BST& defenderTeam) {
        int a = attacker->c.attack+rand()%5;
       defender->c.health -= a;
       cout<<"Damage dealt in the attack: "<<a<<endl;
        if (defender->c.health>0)
        {
            cout<<"Defender current health is : "<<defender->c.health<<endl;
            return;
        }

        defenderTeam.remove(defender->c.name);
        cout<<"Defender is eliminated\n\n";
        
    }
    void start_battle() {
        int round  = 1;
        while (!playerTeam.isEmpty() && !enemyTeam.isEmpty())
        {
            Node *n = playerTeam.findMin(playerTeam.root);
            Node *nn = enemyTeam.findMin(enemyTeam.root);
            cout<<"\n\tRound "<<round<<endl;

            displayTeams();
            cout<<"Attacker is \n";n->c.display();
            cout<<"Defender is \n";nn->c.display();

            attack(n,nn,enemyTeam);
            cout<<"----------------------------\n";
            if (playerTeam.isEmpty() || enemyTeam.isEmpty())
            {
                break;
            }
            
            n = playerTeam.findMin(playerTeam.root);
            nn = enemyTeam.findMin(enemyTeam.root);
            cout<<"Attacker is \n";nn->c.display();
            cout<<"Defender is \n";n->c.display();
            
            attack(nn,n,playerTeam);
            cout<<"----------------------------\n";
            

            round++;
        }

        if (playerTeam.isEmpty())
        {
            cout<<"\n\tEnemy Team has won the battle\n";
            return;
        }
        cout<<"\n\tPlayer Team has won the battle\n";

        
        
        
    }
};


int main() {
    Battle_Quest game;
    game.start_battle(); 
    return 0;
}
