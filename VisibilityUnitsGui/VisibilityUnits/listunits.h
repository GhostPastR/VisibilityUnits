#ifndef LISTUNITS_H
#define LISTUNITS_H

#include <vector>
#include <string>
#include "unit.h"

class ListUnits : public std::vector<Unit>
{
public:
    ListUnits();
    ~ListUnits();

    void readFileDataUnits( const std::string &nameFile );
    void writeFileCount();

    void calcVisibilityUnits();

    bool visibilityUnits( const Unit &u1, const Unit &u2 );

private:
    float angle(int xb, int yb, int xe, int ye);
    void calc( size_t index, size_t distance_index );
    bool checkCircle(const Unit &u1, const Unit &u2);
};

#endif // LISTUNITS_H
