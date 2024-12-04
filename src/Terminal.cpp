#include<iostream>
#include<queue>
#include<sstream>
#include<string>
#include "../include/Terminal.h"
#include "../include/Folder.h"
#include "../include/File.h"


Terminal::Terminal() {
	root = new Folder(".", nullptr); 
	currentFolder = root;	
	isRunning = true;

	/*
	   runCommand["cd"] = enterFolder;
	   runCommand["touch"] = createFile;
	   runCommand["mkdir"] = createFolder;
	   runCommand["rm"] = removeFile;
	   runCommand["rmdir"] = removeFolder;
	   runCommand["cp"] = copy;
	   runCommand["du"] = getSize;
	   runCommand["cat"] = printContent;
	   runCommand["exit"] = quit;*/
}

Terminal::~Terminal() {
	free();
}

void Terminal::run() {
	while(isRunning) {
		std::cout << "Terminal:" << currentFolder->getPath() << "$ ";

		std::string commandLine;
		std::getline(std::cin, commandLine);
		processCommand(commandLine);
	}
}

void Terminal::free() {
	delete root;
	delete currentFolder;
}

void Terminal::processCommand(std::string commandLine) {
	std::stringstream ss(commandLine);
	std::string currParam;
	std::queue<std::string> params;

	while(getline(ss, currParam, ' ')) {
		params.push(currParam);	
	}

	std::string commandName = params.front();
	params.pop();

	if(commandName == "exit") quit();	
	if(commandName == "cd") enterFolder(params.front());
	if(commandName == "mkdir") createFolder(params.front());
	if(commandName == "touch") createFile(params.front());
}

void Terminal::enterFolder(std::string path) {
	Folder* wantedFolder = currentFolder->getFolder(path);
	if(!wantedFolder) {
		std::cout << "cd: Folder does not exist: " << path << std::endl;
		return;
	}
	currentFolder = wantedFolder;
}

void Terminal::createFile(std::string path) {
	File* newFile = new File(path, currentFolder);
	currentFolder->addFile(newFile);
}

void Terminal::createFolder(std::string path) {
	Folder* newFolder = new Folder(path, currentFolder);
	currentFolder->addFolder(newFolder);
}

void Terminal::quit() {
	isRunning = false;
}
