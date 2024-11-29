#include "../include/Terminal.h";

Terminal::~Terminal() {
	delete this->currFolder;
	delete this->root;
}


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
