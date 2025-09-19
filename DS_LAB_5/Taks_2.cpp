#include<iostream>
#include <cstdlib>
#include <ctime>

    

using namespace std;

int ind=0;
int game(int ans,int n=0)
{
    if(n==ans){
        return (ind%2==0)?2:1;
    }
    cout<<"Enter your guess player "<<((ind%2==0)?"1 ":"2 ");
    cin>>n;
    ind++;
    if (n>ans)
    {
        cout<<"Your guess is high\n";
    }
    else if (n<ans)
    {
        cout<<"Your guess is low\n";
    }
    
    return game(ans,n);
    
}

int main(){
    std::srand(std::time(0));  
    int randomNumber = std::rand() % 100 + 1;  
    int a = game(randomNumber);
    cout<<"Player "<<a<<" won \n";

}