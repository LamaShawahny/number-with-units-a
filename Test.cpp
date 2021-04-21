 #include "doctest.h"
#include <string>
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;


// +:
TEST_CASE("operator +"){
    CHECK((NumberWithUnits(1,"m")+NumberWithUnits(33,"m"))==NumberWithUnits(34,"m"));
    CHECK((NumberWithUnits(20,"cm")+NumberWithUnits(33,"cm"))==NumberWithUnits(53,"cm"));
    CHECK((NumberWithUnits(5,"kg")+NumberWithUnits(100,"g"))==NumberWithUnits(5.100,"kg"));
    CHECK((NumberWithUnits(1,"g")+NumberWithUnits(1,"kg"))==NumberWithUnits(1001,"g"));
    CHECK((NumberWithUnits(98,"g")+NumberWithUnits(1,"ton"))==NumberWithUnits(1000098,"g"));
    CHECK((NumberWithUnits(2,"min")+NumberWithUnits(60,"sec"))==NumberWithUnits(3,"min"));
    CHECK_THROWS_MESSAGE(NumberWithUnits(1,"m")+NumberWithUnits(5,"sec"),"Units are not the same system");
    CHECK_THROWS_MESSAGE(NumberWithUnits(55,"sec")+NumberWithUnits(20,"m"),"Units are not the same system");
    CHECK_THROWS_MESSAGE(NumberWithUnits(10,"g")+NumberWithUnits(5,"sec"),"Units are not the same system");
    CHECK_THROWS_MESSAGE(NumberWithUnits(20,"sec")+NumberWithUnits(30,"m"),"Units are not the same system");
}

TEST_CASE(" +"){
    NumberWithUnits x(1,"m");
    CHECK((+x).getUnit()=="m");
    CHECK((+x).getNum()==1);
    

    NumberWithUnits y(33,"m");
    CHECK((+y).getUnit()=="m");
    CHECK((+y).getNum()==33);
   

    NumberWithUnits z(20,"cm");
    CHECK((+z).getUnit()=="cm");
    CHECK((+z).getNum()==33);
   


    NumberWithUnits w(60,"sec");
    CHECK((+w).getUnit()=="sec");
    CHECK((+w).getNum()==60);
}




TEST_CASE("OPERTOR +="){
    
    NumberWithUnits a(47,"m") , b(50,"cm") , c(35.5,"m");
    CHECK((a+=b)==c);

    NumberWithUnits x(3,"m") , y(110,"cm") , z(4.1,"m");
    CHECK((x+=y)==z);

    NumberWithUnits aa(1,"kg") , bb(1,"g"), cc(1001,"g");
    CHECK((aa+=bb)==cc);

    NumberWithUnits x1(3,"m") , y2(110,"cm") , z3(4.1,"m");
    CHECK((x1+=y2)==z3);

     NumberWithUnits a1(2,"kg") , a2(1000,"g"), a3(3,"kg");
    CHECK((a1+=a2)==a3);

    NumberWithUnits a4(5000,"g") , a5(1,"ton"), a6(1005000,"g");
    CHECK((a4+=a5)==a6);

    

    NumberWithUnits f1(55,"m") , f2(5,"g");
    CHECK_THROWS_MESSAGE(f1+=f2,"Units are not the same system");
}

// - :


TEST_CASE("-"){
    
    CHECK((NumberWithUnits(2,"m")-NumberWithUnits(50,"cm"))==NumberWithUnits(1.5,"m"));
    CHECK((NumberWithUnits(5,"kg")-NumberWithUnits(3,"g"))==NumberWithUnits(4.997,"kg"));
    CHECK((NumberWithUnits(5,"m")-NumberWithUnits(30,"cm"))==NumberWithUnits(4.7,"kg"));
    CHECK((NumberWithUnits(1,"g")-NumberWithUnits(1,"kg"))==NumberWithUnits(-999,"g"));
    CHECK((NumberWithUnits(3,"ton")-NumberWithUnits(1,"ton"))==NumberWithUnits(2,"ton"));
    CHECK_THROWS_MESSAGE(NumberWithUnits(55,"m")-NumberWithUnits(5,"sec"),"Units are not the same system");
    CHECK_THROWS_MESSAGE(NumberWithUnits(5,"g")-NumberWithUnits(5,"km"),"Units are not the same system");
    CHECK_THROWS_MESSAGE(NumberWithUnits(5,"sec")-NumberWithUnits(100,"m"),"Units are not the same system");

}

TEST_CASE("-"){
    NumberWithUnits x(3,"m");
    CHECK((-x).getNum()==-3);
    CHECK((-x).getUnit()=="m");

    NumberWithUnits y(33,"m");
    CHECK((-y).getUnit()=="m");
    CHECK((-y).getNum()==33);



    NumberWithUnits w(-40,"cm");
    CHECK((-w).getNum()==40);
    CHECK((-w).getUnit()=="cm");

    NumberWithUnits z(-5,"sec");
    CHECK((-z).getNum()==-5);
    CHECK((-z).getUnit()=="sec");
}



TEST_CASE("-="){
    
    NumberWithUnits x1(8,"m") , x2(40,"cm") , x3(7.6,"m");
    CHECK((x1-=x2)==x3);

    NumberWithUnits y1(1,"g") , y2(1,"kg"), y3(-999,"g");
    CHECK((y1-=y2)==y3);

    NumberWithUnits z1(2,"kg") , z2(7,"g"), z3(0.997,"kg");
    CHECK((z1-=z2)==z3);

    NumberWithUnits f1(5,"g") , f2(5,"sec");
    CHECK_THROWS_MESSAGE(f1-=f2,"Units are not the same system");


}



//<,>,<=,>=,==,!=

TEST_CASE(">"){
    CHECK(NumberWithUnits(10,"kg")>NumberWithUnits(5,"kg"));
    CHECK(NumberWithUnits(5.5,"ton")>NumberWithUnits(5000,"kg"));
    CHECK(NumberWithUnits(7000,"m")>NumberWithUnits(6,"km"));
    CHECK(NumberWithUnits(7005,"g")>NumberWithUnits(7,"kg"));
    CHECK_FALSE(NumberWithUnits(1,"hour")>NumberWithUnits(60.7,"min"));
    CHECK_FALSE(NumberWithUnits(1,"hour")>NumberWithUnits(60.5,"min"));
}


TEST_CASE(">="){
   
    CHECK(NumberWithUnits(6,"kg")>=NumberWithUnits(5,"kg"));
    CHECK(NumberWithUnits(5,"ton")>=NumberWithUnits(5000,"kg"));
    CHECK(NumberWithUnits(9000,"m")>=NumberWithUnits(6,"km"));
    CHECK(NumberWithUnits(5005,"g")>=NumberWithUnits(5,"kg"));
    CHECK(NumberWithUnits(2,"hour")>=NumberWithUnits(120,"min"));
    CHECK_FALSE(NumberWithUnits(3,"hour")>=NumberWithUnits(180.12,"min"));
}

TEST_CASE("<"){

    CHECK(NumberWithUnits(5,"kg")<NumberWithUnits(10,"kg"));
    CHECK(NumberWithUnits(9,"kg")<NumberWithUnits(9001,"g"));
    CHECK(NumberWithUnits(3000,"kg")<NumberWithUnits(3.5,"ton"));
    CHECK(NumberWithUnits(7,"km")<NumberWithUnits(8000,"m"));
    CHECK_FALSE(NumberWithUnits(60.1,"sec")<NumberWithUnits(1,"min"));
}

TEST_CASE("<="){
   
    CHECK(NumberWithUnits(5,"kg")<=NumberWithUnits(10,"kg"));
    CHECK(NumberWithUnits(5,"kg")<=NumberWithUnits(5,"kg"));
    CHECK(NumberWithUnits(6,"km")<=NumberWithUnits(8000,"m"));
    CHECK(NumberWithUnits(5,"kg")<=NumberWithUnits(5000,"g"));
    CHECK_FALSE(NumberWithUnits(8,"kg")<=NumberWithUnits(7,"kg"));

}

TEST_CASE("=="){
   
    CHECK(NumberWithUnits(5,"m")==NumberWithUnits(5,"m"));
    CHECK(NumberWithUnits(9,"m")==NumberWithUnits(9,"m"));
    CHECK(NumberWithUnits(5,"km")==NumberWithUnits(5000,"m"));
    CHECK(NumberWithUnits(1,"hour")==NumberWithUnits(60,"min"));

}

TEST_CASE("!="){
    
    CHECK(NumberWithUnits(1,"hour")!=NumberWithUnits(65,"min"));
    CHECK(NumberWithUnits(5,"km")!=NumberWithUnits(4998,"m"));
    CHECK(NumberWithUnits(1,"ton")!=NumberWithUnits(50,"kg"));


}



// ++ , -- :
TEST_CASE("++"){
    NumberWithUnits x(50,"kg");
    NumberWithUnits y= ++x;
    CHECK(y.getNum()==51);
    CHECK(y.getUnit()=="kg");
    CHECK(x.getNum()==51);
    CHECK(x.getUnit()=="kg");    
}

TEST_CASE("++"){
    NumberWithUnits x(10,"ton");
    NumberWithUnits y = x++;
    CHECK(y.getNum()==10);
    CHECK(y.getUnit()=="ton");
    CHECK(x.getNum()==11);
    CHECK(x.getUnit()=="ton");
    
}

TEST_CASE("--"){
    NumberWithUnits x(56,"min");
    NumberWithUnits y = --x;
    CHECK(y.getNum()==55);
    CHECK(y.getUnit()=="min");
    CHECK(x.getNum()==55);
    CHECK(x.getUnit()=="min");
}

TEST_CASE("--"){
  
    NumberWithUnits x(10,"kg");
    NumberWithUnits y = x--;
    CHECK(y.getNum()==10);
    CHECK(y.getUnit()=="kg");
    CHECK(x.getNum()==9);
    CHECK(x.getUnit()=="kg");
}
