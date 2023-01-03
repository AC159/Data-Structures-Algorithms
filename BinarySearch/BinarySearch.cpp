#include <vector>
#include <iostream>

#include "BinarySearch.h"

using std::vector;
using std::cout;
using std::endl;

void BinarySearchMain()
{
    vector< int > values = { 1, 4, 6, 7, 8, 12, 15, 17, 18, 20 };
    int target = 3;

    int low = 0;
    int high = ( int ) values.size() - 1;
    bool found = false;

    while ( low <= high )
    {
        int middle = ( low + high ) / 2;
        int value = values[ middle ];

        if ( value == target )
        {
            found = true;
            cout << "Found target at index " << middle << endl;
            break;
        }
        else if ( value > target ) high = middle - 1;
        else low = middle + 1;
    }

    if ( !found )
    {
        cout << "Target cannot be found in the sequence!" << endl;
    }
}
