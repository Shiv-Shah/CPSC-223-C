#include "filter.h"
#include <stdio.h>
#include <ctype.h>



int toggle(int let)
{
    if(islower(let))
    {
        return toupper(let);
    }	
    else
    {
        return tolower(let);
    }
}

int to_upper(int upp)
{
    return toupper(upp);
    
}

int to_lower(int low)
{
    return tolower(low);
}

//void filter(FILE * fp, void * v) // so the void pointer is the part where we put in our value such as toogle or to_upper or to_lower
//{

//}
