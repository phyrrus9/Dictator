///////////////////////////////////////////////////////////////
//Well look you have just arrived at the dictator header file//
//This file holds  the dictator class, and is responsible for//
//the entire execution of the program (as main just calls it)//
//This program is distributed in hopes that it will be useful//
//it is accompanied by absolutely no warranty it is up to the//
//programmer to provide, or not provide a sufficient warranty//
//This is free software: and it may be used in any way needed//
//the only specification required by this software is that it//
//always contains  this text  when distributed. This class is//
//pretty  simple, it takes in a set of arguments to the %ctor//
//and parses them, then performs the required action based on//
//what it has decided. The documentation with this class will//
//be maintained as best as possible, but I cannot do it all..//
//original code by Ethan Laur (phyrrus9) <phyrrus9@gmail.com>//
///////////////////////////////////////////////////////////////
#include <iostream>
#include <string.h>
#include <cstring>
#include <iomanip>
//#include "mobilerestorelib.h" //used in mobileupgrade
#ifndef commander_cpp_dictator_h
#define commander_cpp_dictator_h
using namespace std;
class dictator
{
    typedef std::string string; //because it is helpful
    int name; //width of name field
    int desc; //width of description field
    void usage(char*); //prints the help screen to the user
    int _go(int, char * *); //where all the magic happens
public:
    dictator(int, char * *); //don't look here for this
};
#endif
