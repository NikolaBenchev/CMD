#include "../include/Terminal.h";

Terminal::Terminal() {
	this->root = new Folder();
	this->currentFolder = this->root;	
}

Terminal::~Terminal() {
	free();
}

Terminal::Terminal(const Terminal& other) = delete; 

Terminal& operator=(Terminal& other) = delete; 

void Terminal::run() const {
	while(this->isRunning) {
		std::cout << "Terminal:" << this->currFolder->getPath() << "$ ';
		std::string command;
		std::cin >> command;
		this->processCommand(command);
	}
}

void Terminal::processCommand(std::string command) {
}

void free() {
	delete this->root;
	delete this->currentFolder;
}
