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
#include "dictator.h"
//#include "mobilerestorelib.h"
#define argc(a) if (argc < a) usage(argv[0]) //simple argc check function
dictator::dictator(int argc, char * * args) //forwarder function (%ctor)
{
    name = 11; //set name width
    desc = 30; //set description width
    _go(argc, args); //do everything on main thread
}
void dictator::usage(char*s) //print usage
{
    cout << "USAGE: " << s << " [command] [args]" << endl
         << "Commandlist:"             << endl       << left
         << setw(name) << "help"       << setw(desc) << "[topic]" << endl
         << setw(name) << "sign"       << setw(desc) << "pseudo-codesign" << endl
         << setw(name) << "setenv"     << setw(desc) << "set an env var" << endl
         << setw(name) << "getenv"     << setw(desc) << "get an env var" << endl
         << setw(name) << "delenv"     << setw(desc) << "delete an env var" << endl
         << setw(name) << "power"      << setw(desc) << "power options:" << endl
         << setw(name) << "->respring" << setw(desc) << "restart springboard" << endl
         << setw(name) << "->off"      << setw(desc) << "power off" << endl
         << setw(name) << "->reb"      << setw(desc) << "reboot" << endl
         << setw(name) << "->rc"       << setw(desc) << "enable recovery" << endl
         << setw(name) << "->xrc"      << setw(desc) << "disable recovery" << endl
         << setw(name) << "mupgrade"   << setw(desc) << "mobile upgrade" << endl
         << setw(name) << "->upgrade"  << setw(desc) << "Upgrade device" << endl
         << setw(name) << "->restore"  << setw(desc) << "Restore device" << endl
         << setw(name) << "->create"   << setw(desc) << "Freeze device" << endl
         << setw(name) << "download"   << setw(desc) << "Download file" << endl;
    exit(-1); //EXIT_FAILRUE
}
int dictator::_go(int argc, char *argv[]) //parse and perform actions
{
    argc(2); //we need at least 1 argment to the program
    string arg1 = argv[1]; //since we are sure we have this one, set it to a usable value
    string arg2, arg3; //define the next two (optional arguments)
    if (argc > 2) //assuming we have another arg to get
        arg2 = argv[2]; //read it into the appropriate variable
    if (argc > 4) //if we have the last argument
        arg3 = argv[3]; //read it where it belongs
    if (arg1 == "help") //display detailed help
    {
        argc(2);
        if (arg2 == "sign")
            cout << "Codesign with saurik's ldid" << endl
                 << "USAGE: " << argv[0] << " sign <file>" << endl;
        if (arg2 == "setenv")
            cout << "Set an environment variable" << endl
                 << argv[0] << " setenv [variable=value]" << endl
                 << "Examples:" << endl
                 << argv[0] << " setenv auto-boot=true" << endl;
        if (arg2 == "getenv")
            cout << "Get an environment variable" << endl
            << "USAGE: " << argv[0] << " getenv [variable]" << endl
            << "[variable] is optional" << endl
            << "Examples:" << endl
            << argv[0] << " getenv" << endl
            << argv[0] << " getenv auto-boot" << endl;
        if (arg2 == "delenv")
            cout << "Delete an environment variable" << endl
            << "USAGE: " << argv[0] << " delenv [variable]" << endl
            << "Examples:" << endl
            << argv[0] << " delenv boot-path" << endl;
        if (arg2 == "power")
            cout << "Power management" << endl
                 << "USAGE: " << argv[0] << " power [command]" << endl
                 << "Commands:" << endl << left
                 << setw(name) << " respring" << setw(desc) << "Restart SpringBoard"         << endl
                 << setw(name) << " off"      << setw(desc) << "Power the device off (halt)" << endl
                 << setw(name) << " reb"      << setw(desc) << "Reboot the device"           << endl
                 << setw(name) << " rc"       << setw(desc) << "Sets auto-boot to false"     << endl
                 << setw(name) << " xrc"      << setw(desc) << "Sets auto-boot to true"      << endl
                 << "Examples:" << endl
                 << "None..sorry" << endl;
        if (arg2 == "mupgrade")
            cout << "Mobile Upgrade copyright © 2012 phyrrus9" << endl
                 << "No help available." << endl;
        if (arg2 == "download")
            cout << "Download file from http location" << endl
                 << "USAGE: " << argv[0] << " [file]" << endl
                 << "This will download file and save it as file" << endl;
    }
    if (arg1 == "power") //perform the power command
    {
        argc(2);
        if (arg2 == "respring")
            system("killall SpringBoard");
        if (arg2 == "off")
            system("halt");
        if (arg2 == "reb")
            system("reboot");
        if (arg2 == "rc")
            system("nvram auto-boot=false");
        if (arg2 == "xrc")
            system("nvram auto-boot=true");
    }
    if (arg1 == "mupgrade") //threaded version of mobileupgrade
    {
        argc(2);
        if (arg2 == "upgrade")
        {
            system("unzip -o /var/mobile/mupgrade/freeze -d /");
            cout << "Extracting:" << endl;
            cout << "->Applications" << endl;
            system("unzip -o /var/mobile/mupgrade/Applications.zip -d /");
            cout << "->etc" << endl;
            system("unzip -o /var/mobile/mupgrade/etc.zip -d /");
            cout << "->bin" << endl;
            system("unzip -o /var/mobile/mupgrade/bin.zip -d /");
            cout << "->usr" << endl;
            system("unzip -o /var/mobile/mupgrade/usr.zip -d /");
            cout << "->Library" << endl;
            system("unzip -o /var/mobile/mupgrade/usr.zip -d /");
            cout << "->System" << endl;
            //system("unzip -o /var/mobile/mupgrade/System.zip -d /");
        }
        if (arg2 == "restore")
        {
            system("unzip -o /var/mobile/mupgrade/freeze -d /");
            system("rm -rf /Applications");
            system("rm -rf /Library");
            system("unzip -o /var/mobile/mupgrade/*.zip -d /");
            //system("rm -rf /var/mobile/mupgrade");
        }
        if (arg2 == "create")
        {
            cout << "Patching infinite symlink" << endl;
            system("rm -rf /usr/lib/_ncurses");
            cout << "Creating directory" << endl;
            system("mkdir -p /var/mobile/mupgrade");
            cout << "Cleaning directory" << endl;
            system("rm -rf /var/mobile/mupgrade/*");
            cout << "Creating archives" << endl;
            cout << "->Applications" << endl;
            system("zip -rq /var/mobile/mupgrade/Applications /Applications");
            cout << "->etc" << endl;
            system("zip -rq /var/mobile/mupgrade/etc /etc");
            cout << "->bin" << endl;
            system("zip -rq /var/mobile/mupgrade/bin /bin");
            cout << "->usr" << endl;
            system("zip -rq /var/mobile/mupgrade/usr /usr");
            cout << "->Library" << endl;
            system("zip -rq /var/mobile/mupgrade/Library /Library");
            cout << "->System" << endl;
            //system("zip -rq /var/mobile/mupgrade/System /System");
            cout << "->Freeze" << endl;
            system("zip -q /var/mobile/mupgrade/freeze /var/mobile/mupgrade/*.zip");
            cout << "Cleaning up" << endl;
            system("mv /var/mobile/mupgrade/freeze.zip /var/mobile/mupgrade/freeze");
            system("rm -rf /var/mobile/mupgrade/*.zip");
        }
    }
    if (arg1 == "download")
    {
        argc(3);
        string s = "wget ";
        s += arg2; //add the url
        system(s.c_str());
    }
    if (arg1 == "sign") //pseudo-sign a file (iphone only)
    {
        argc(3);
        string s = "ldid -S ";
        s += arg2;
        system(s.c_str());
    }
    if (arg1 == "setenv") //set an environment variable
    {
        argc(3);
        string s = "nvram ";
        s += arg2;
        system(s.c_str());
    }
    if (arg1 == "getenv") //fetch an environment variable
    {
        argc(2);
        string s = "nvram ";
        if (argc >= 3)
            s += arg2;
        else
            s += "-p";
        system(s.c_str());
    }
    if (arg1 == "delenv") //delete an environment variable
    {
        string s = "nvram -d ";
        s += arg2;
        system(s.c_str());
    }
    return 0;
}
