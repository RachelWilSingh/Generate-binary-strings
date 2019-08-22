#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

void IncrementString( vector<int>& arr, int digit )
{
    if ( digit == (int)arr.size() || digit == -1 ) { /* doesn't work */ return; }
    
    arr[digit]++;
    
    if ( arr[digit] == 2 ) // Need to carry over the number
    {
        arr[digit] = 0;
        IncrementString( arr, digit-1 );
    }
}

void DisplayArray( vector<int>& arr )
{
    for ( unsigned int i = 0; i < arr.size(); i++ )
    {
        cout << arr[i];
    }
    cout << endl;
}

int main()
{
    int size = 0;
    
    cout << "How many digits? ";
    cin >> size;
    
    vector<int> arr;
    
    // Set to all 0's
    for ( int i = 0; i < size; i++ )
    {
        arr.push_back( 0 );
    }
    DisplayArray( arr );
    
    // Generate 10 numbers
    int stringCount = pow(2, size);
    for ( int i = 0; i < stringCount; i++ )
    {
        // Change the right-most #
        IncrementString( arr, size-1 );
        
        DisplayArray( arr );
    }
    
    return 0;
}
