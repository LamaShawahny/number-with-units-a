
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


namespace ariel
{

    class NumberWithUnits
    {
        private:
            double number;
            string Measunit;  
    
        public:
            NumberWithUnits(double number , const string &Measunit);
        
            double getNum()const{
                return number;
            }

            string getUnit()const{
                return Measunit;
            }
            static void read_units(std::ifstream &units_file);
    
            
            friend NumberWithUnits operator+(const NumberWithUnits &x);
            friend NumberWithUnits operator+(const NumberWithUnits &x, const NumberWithUnits &y);
            friend NumberWithUnits operator+=(NumberWithUnits &x, const NumberWithUnits &y);

    
            friend NumberWithUnits operator-(const NumberWithUnits &x);
            friend NumberWithUnits operator-(const NumberWithUnits &x, const NumberWithUnits &y);
            friend NumberWithUnits operator-=(NumberWithUnits &x, const NumberWithUnits &y);

            
            friend bool operator>(const NumberWithUnits &x, const NumberWithUnits &y);
            friend bool operator>=(const NumberWithUnits &x, const NumberWithUnits &y);
            friend bool operator<(const NumberWithUnits &x, const NumberWithUnits &y);
            friend bool operator<=(const NumberWithUnits &x, const NumberWithUnits &y);
            friend bool operator==(const NumberWithUnits &x, const NumberWithUnits &y);
            friend bool operator!=(const NumberWithUnits &x, const NumberWithUnits &y);


          
            friend NumberWithUnits operator++(NumberWithUnits &y);
            friend NumberWithUnits operator++(NumberWithUnits &y , int);

            friend NumberWithUnits operator--(NumberWithUnits &y);
            friend NumberWithUnits operator--(NumberWithUnits &y , int);

           
            friend NumberWithUnits operator*(const double x, const NumberWithUnits &y);
            friend NumberWithUnits operator*(const NumberWithUnits &y, const double x);

            friend NumberWithUnits operator*=(const double x, const NumberWithUnits &y);
            friend NumberWithUnits operator*=(const NumberWithUnits &y, const double x);

           
            friend std::ostream &operator<<(std::ostream &OPstream, const NumberWithUnits &x);

            friend std::istream &operator>>(std::istream &INstream, NumberWithUnits &x);

    };
}