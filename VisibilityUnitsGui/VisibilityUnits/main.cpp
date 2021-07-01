#include <iostream>
#include "listunits.h"

#include <fstream>
#include <random>
#include <ctime>

int main()
{   
    ListUnits units;
    units.readFileDataUnits("C:/1/data_units.txt");
    auto start = clock();
    units.calcVisibilityUnits();
    std::cout << clock() - start << std::endl;

//    std::cout << "-------" << std::endl;
//    for( const auto &i : units ){
//        std::cout << i.countVisibilyUnits() << std::endl;
//    }





//    std::cout << units.visibilityUnits( units[0], units[1] )<< std::endl;
//    std::cout << units.visibilityUnits( units[1], units[0] )<< std::endl;
//    for( const auto &i : units ){
//        std::cout << "-------" << std::endl;
//        std::cout << i.x() << std::endl;
//        std::cout << i.y() << std::endl;
//        std::cout << i.r_x() << std::endl;
//        std::cout << i.r_y() << std::endl;
//        std::cout << i.angle() << std::endl;
//        std::cout << i.distance() << std::endl;
//        std::cout << "-------" << std::endl;
//    }
    return 0;
}

//std::cout <<  << std::endl;
