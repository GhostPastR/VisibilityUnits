#include "unit.h"
#include <algorithm>
#include <iostream>

template<typename P, typename F>
bool setParametrUnit( P &parametr, const std::string &data,
                      std::string::const_iterator &begin, F func){
    while(true){
        auto item = std::find(begin, data.end(), ' ');
        if( item != data.end()){
            std::string s{begin, item};
            begin = ++item;
            if(s.empty()){
                continue;
            }
            parametr = func(s.data());
            return true;
        }
        else{
            std::string s{begin, item};
            if(s.empty()){
                break;
            }
            parametr = func(s.data());
            return true;
        }
    }
    return false;
}


Unit::Unit()
{

}

Unit::~Unit()
{

}

void Unit::setData(const std::string &data)
{
    auto begin = data.begin();
    if(!setParametrUnit(x_, data, begin, std::atoi)){
        std::cerr << "The parameter could not be read - x_" << std::endl;
    }
    if(!setParametrUnit(y_, data, begin, std::atoi)){
        std::cerr << "The parameter could not be read - y_" << std::endl;
    }
    if(!setParametrUnit(r_x_, data, begin, std::atof)){
        std::cerr << "The parameter could not be read - r_x_" << std::endl;
    }
    if(!setParametrUnit(r_y_, data, begin, std::atof)){
        std::cerr << "The parameter could not be read - r_y_" << std::endl;
    }
    radiusVector_ = atan2f( r_x_, r_y_ );
    if( radiusVector_ < 0 )
        radiusVector_ += 2 * M_PI;
    if(!setParametrUnit(distance_, data, begin, std::atoi)){
        std::cerr << "The parameter could not be read - distance_" << std::endl;
    }
    distance_2_ = distance_ * distance_;
    if(!setParametrUnit(angle_rad_, data, begin, std::atof)){
        std::cerr << "The parameter could not be read - angle_" << std::endl;
    }
    angle_rad_ *= M_PI / 180.;
}
