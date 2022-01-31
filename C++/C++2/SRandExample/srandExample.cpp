#include <iostream>
using std::cout; 
using std::endl; 
#include <cstdlib>
using std::srand; 
using std::rand; 
#include <ctime>
using std::time; 

int main()
{
    int randval = 0; 
    // Need to seed the random number generator
    // We will use the current time
    srand(time(0)); 

    cout  << "Here are some random numbers between  0 and 10"  << endl; 
    for(int i = 0;  i < 10;  i++)
    {
        randval = rand() % 10; 
        cout  << randval << " "; 
    }
    
    cout << "\nHere are some random numbers between 0 and 50"  << endl; 
    for(int i = 0;  i < 10;  i++)
    {
        randval = rand() % 50; 
        cout  << randval << " "; 
    }

    cout  << endl; 

    return 0; 
}
