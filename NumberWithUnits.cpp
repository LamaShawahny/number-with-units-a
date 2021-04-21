  
#include <iostream>
#include <fstream>
#include "NumberWithUnits.hpp"
#include <map>
#define  DNULL NumberWithUnits(0,"cm");
using namespace std;


namespace ariel
{
    static map<string, map<string, double>> unitList; 

    NumberWithUnits::NumberWithUnits(double number , const string &Measunit)
    {

    }

    void NumberWithUnits::read_units(std::ifstream &units_file)
    {
        
    }   


    //+:
    NumberWithUnits operator+(const NumberWithUnits &x){
       
        return DNULL ;

    }
    NumberWithUnits operator+(const NumberWithUnits &x, const NumberWithUnits &y){
        
        return DNULL;

    }
    NumberWithUnits operator+=(NumberWithUnits &x, const NumberWithUnits &y){
        return DNULL;
    }

   // -:
    NumberWithUnits operator-(const NumberWithUnits &x)
    {
        
        return DNULL;

    }
    NumberWithUnits operator-(const NumberWithUnits &x, const NumberWithUnits &y)
    {
    
        return DNULL;

    }
    NumberWithUnits operator-=(NumberWithUnits &x, const NumberWithUnits &y)
    {
        return DNULL;
    }

    bool operator>(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return false;
    }
    bool operator>=(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return  false;

    }
    bool operator<(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return true;

    }
    bool operator<=(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return false;

    }
    bool operator==(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return  false;

    }
    bool operator!=(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return true;

    }



    //++ ,-- 

    NumberWithUnits operator++(NumberWithUnits &y)
    {
        return DNULL;
    }

    NumberWithUnits operator++(NumberWithUnits &y , int)
    {
        return DNULL;
    }

    NumberWithUnits operator--(NumberWithUnits &y)
    {
        return DNULL;
    }

    NumberWithUnits operator--(NumberWithUnits &y , int)
    {
        return DNULL;
    }


   

    // *:

    NumberWithUnits operator*(const double n, const NumberWithUnits &c)
    {
        return DNULL;
    }

    NumberWithUnits operator*(const NumberWithUnits &c, const double n)
    {
        return DNULL;

    }


    std::ostream &operator<<(std::ostream &os, const NumberWithUnits &o){
       
        return os;
    }

    std::istream &operator>>(std::istream &is, NumberWithUnits &o){
    
        return is;
    }

    
};
