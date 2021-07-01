#include "listunits.h"
#include <fstream>
#include <cmath>
#include <iostream>
#include <thread>
#include <future>

const float pi_2 = 2. * M_PI;

ListUnits::ListUnits() : std::vector<Unit>()
{

}

ListUnits::~ListUnits()
{

}

void ListUnits::readFileDataUnits( const std::string &nameFile )
{
    clear();
    std::ifstream in(nameFile);
    if (in.is_open()){
        std::string line;
        while (getline(in, line)){
            Unit unit;
            unit.setData(line);
            push_back(std::move(unit));
        }
    }
    in.close();
}

void ListUnits::writeFileCount()
{
    std::ofstream out("result.txt");
    if (out.is_open()){
        for(const auto &i : *this){
            out << i.countVisibilyUnits() << std::endl;
        }

    }
    out.close();
}

void ListUnits::calcVisibilityUnits()
{
    auto c_pthread = std::thread::hardware_concurrency();
    std::vector<std::future<void>> asyncVector;
    for(size_t i = 0; i < c_pthread; ++i){
        asyncVector.push_back(std::async(&ListUnits::calc, this, i, c_pthread));
    }
    for(size_t i = 0; i < c_pthread; ++i){
        asyncVector[i].get();
    }


//    for(size_t i = 0, size_this = size(); i < size_this; ++i){
//        int count = 0;
//        for(size_t j = 0; j < size_this; ++j){
//            if( (i != j) && visibilityUnits((*this)[i], (*this)[j])){
//                ++count;
//            }
//        }
//        (*this)[i].setCountVisibilyUnits(count);
//    }
}

bool ListUnits::visibilityUnits(const Unit &u1, const Unit &u2)
{
    if(checkCircle(u1, u2)){
        auto _angle = angle(u1.x(),u1.y(), u2.x(), u2.y());
        return fabsf( _angle - u1.radiusVector() ) < ( u1.angle() / 2. );
    }
    return false;
}

float ListUnits::angle( int xb, int yb, int xe, int ye )
{
    auto angle = atan2f( xe - xb, ye - yb );
    if( angle < 0 ){
        angle += pi_2;
    }
    return angle;
}

void ListUnits::calc( size_t index, size_t distance_index )
{
    for(auto i = index, size_this = size(); i < size_this; i += distance_index){
        int count = 0;
        for(size_t j = 0; j < size_this; ++j){
            if( (i != j) && visibilityUnits((*this)[i], (*this)[j])){
                ++count;
            }
        }
        (*this)[i].setCountVisibilyUnits(count);
    }
}

bool ListUnits::checkCircle(const Unit &u1, const Unit &u2)
{
    int dx = u2.x() - u1.x();
    int dy = u2.y() - u1.y();
    return dx * dx + dy * dy <= u1.distance_2();
}
