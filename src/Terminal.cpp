#include<iostream>
#include<string>
#include "../include/Terminal.h"

Terminal::Terminal() {
	this->root = new Folder(".", "");
	this->currentFolder = this->root;	
}

Terminal::~Terminal() {
	free();
}

void Terminal::run() {
	while(isRunning) {
		std::cout << "Terminal:" << currentFolder->getPath() << "$ ";
		std::string command;
		std::cin >> command;
		processCommand(command);
	}
}

void Terminal::processCommand(std::string command) {
	
}

void Terminal::free() {
	delete root;
	delete currentFolder;
}
