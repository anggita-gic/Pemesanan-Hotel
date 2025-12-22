#include <iostream>
#include "finalstd.h"

using namespace std;

int main()
{
    ListHotel LH;
    ListPemesan LP;

    createList_hotel(LH);
    createList_pemesan(LP);

    menu(LH, LP);

    return 0;
}
