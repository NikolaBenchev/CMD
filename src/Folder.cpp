#include "../include/Folder.h"
#include<cstddef>

void Folder::add(AbstractFile* newFile) {
	this->innerFiles.push_back(newFile);
}

void Folder::remove(const std::string& name) {
	for(std::vector<AbstractFile*>::iterator it = this->innerFiles.begin();
		it != this->innerFiles.end(); it++) {
		if((*it)->getName() == name) {
			this->innerFiles.erase(it);
			return;	
		}	
	}
}

size_t Folder::getSize() {
	size_t folderSize;
	for(AbstractFile* curr : this->innerFiles) {
		folderSize += curr->getSize();
	}
	return folderSize;
}
