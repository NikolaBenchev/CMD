#include<iostream>
#include<string>
#include "../include/Terminal.h"

Terminal::Terminal() {
	root = new Folder(".", "");
	currentFolder = root;	
	isRunning = true;
}

Terminal::~Terminal() {
	free();
}

void Terminal::run() {
	while(isRunning) {
		std::cout << "Terminal:" << currentFolder->getPath() << "$ ";
		std::string commandLine;
		std::getline(std::cin, commandLine);
		std::cout << commandLine << std::endl;	
	}
}

void Terminal::free() {
	delete root;
	delete currentFolder;
}
