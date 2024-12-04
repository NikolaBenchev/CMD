#include<iostream>
#include<cstddef>
#include<sstream>
#include<string>
#include<vector>
#include "../include/Folder.h"

void Folder::addFile(File* newFile) {
	innerFiles.push_back(newFile);
}

void Folder::addFolder(Folder* newFolder) {
	innerFolders.push_back(newFolder);
}

void Folder::removeFile(const std::string name) {
	for(std::vector<File*>::iterator it = innerFiles.begin();
			it != innerFiles.end(); it++) {
		if((*it)->getName() != name) continue;
		innerFiles.erase(it);
		return;	
	}
}

void Folder::removeFolder(const std::string name) {
	for(std::vector<Folder*>::iterator it = innerFolders.begin();
			it != this->innerFolders.end(); it++) {
		if((*it)->getName() != name) continue;
		innerFiles.erase(it);
		return;
	}
}

size_t Folder::getSize() const {
	size_t folderSize;
	for(Folder* curr : innerFolders) {
		folderSize += curr->getSize(); 
	}
	for(File* curr : innerFiles) {
		folderSize += curr->getSize();
	}
	return folderSize;
}

void Folder::printContent() const {
	for(Folder* curr : innerFolders) {
		std::cout << curr->getName() << std::endl;
	}

	for(File* curr : innerFiles) {
		std::cout << curr->getName() << std::endl;
	}
}

Folder* Folder::getFolder(std::string path) const {
	std::string::size_type slashIndex = path.find('/');
	std::string wantedFolderName = path.substr(0, slashIndex);
	Folder* wantedFolder = nullptr;

	for(Folder* curr : this->innerFolders) {
		if(curr->getName() != path) continue; 
		wantedFolder = curr;
		break;
	}

	if(!wantedFolder) return nullptr;

	if(slashIndex != std::string::npos) {
		path = path.substr(slashIndex + 1, path.length());
		wantedFolder = wantedFolder->getFolder(path);
	}		

	return wantedFolder;
}
