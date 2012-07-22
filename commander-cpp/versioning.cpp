	#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char**argv)
{
	fstream file;
	file.open("build.cf", ios::in);
	int v;
	file >> v;
	file.close();
	file.open("build.cf", ios::trunc | ios::out);
	file << v+1;
	file.close();
	file.open("./commander-cpp/build.cpp", ios::trunc | ios::out);
	file << "const int buildnum = " << v+1 << ";";
	file.close();
	if (argc > 1)
	{
		cout << "Writing DEBIAN control file" << endl;
		file.open("./dictator_iphoneos/DEBIAN/control", ios::trunc | ios::out);
		file << "Package: com.phyrrus9.dictator" << endl
	     	     << "Name: Dictator" << endl
	     	     << "version: " << v+1 << endl
	     	     << "Architecture: iphoneos-arm" << endl
	     	     << "Description: An essential iphone utility" << endl
	     	     << "Maintainer: Ethan Laur" << endl
	     	     << "Author: Ethan Laur" << endl
	     	     << "Section: Utilities" << endl;
		file.close();
	}
}
