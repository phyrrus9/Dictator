///////////////////////////////////////////////////////////////
//dictator main source file. No sense licensing it as all the//
//other ones already are (see any source file).  Do not build//
//with Xcode!!! It won't deploy to the device because it isnt//
//signed with a code signature (and does not need to be) and //
//will simply not even copy.  To build please open a terminal//
//and type 'make iphone' which will run through a build proc.//
//next you will need to run 'scp dictator_iphoneos.deb root@<//
//ip>:/var/root to copy the file then 'dpkg -i /var/root/dict//
//atorr_iphoneos.deb' to install  (will install libs as well)//
//to the device. Then you are free to ssh into the device and//
//run dictator [command] <option> as you wish. Thank you, rly//
//original code by Ethan Laur (phyrrus9) <phyrrus9@gmail.com>//
///////////////////////////////////////////////////////////////
#include "dictator.h"
#include "build.cpp"
int main(int argc, char**args) //literally, one file.
{    
    cout << "dictator by phyrrus9 " << endl; //copyright text
    cout << "Build: " << buildnum << endl;
    dictator * program = new dictator(argc, args); //this handles it all :P
    delete program; //unalloc it all
    return EXIT_SUCCESS; //it all went good
}