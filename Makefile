noarg:
iphone: clean
	./versioning -iphone
	xcodebuild
	cp ./commander-cpp.app/commander-cpp ./dictator
	cp ./dictator ./dictator_iphoneos/bin
	chmod +s ./dictator_iphoneos/bin
	dpkg -b ./dictator_iphoneos
	rm -rf ./commander-cpp.app
	rm -rf ./commander-cpp.app.dSYM
	rm -rf ./commander-cppTests
osx: clean
	./versioning
	g++ ./commander-cpp/main.cpp ./commander-cpp/dictator.cpp ./commander-cpp/Thread.cpp  -o ./dictator -pthread
osxinstall: osx
	sudo cp ./dictator /bin
clean:
	rm -rf ./dictator
	rm -rf ./dictator_iphoneos/bin/*
