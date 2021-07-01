#include <iostream>
#include <listunits.h>

int main()
{
    ListUnits units;
    units.readFileDataUnits("data_units.txt");
    units.calcVisibilityUnits();
    units.writeFileCount();
    return 0;
}
