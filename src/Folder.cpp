#include "Folder.h"
#include "Node.hpp"

void Folder::add(AbstractFile* newFile) {
	Node<AbstractFile*>* newNode = new Node<AbstractFile*>(newFile);
	this->content.add(newNode);
}

void Folder::remove(const std::string& name) {
	std::vector<AbstractFile*> childNodes = this->content.getChildNodes();
	for(AbstractFile* curr : childNodes) {
		if(curr->getName() == name) {
			this->content.remove(curr);
			return;
		}
	}
}

size_t Folder::getSize() {
	size_t folderSize;
	for(AbstractFile* curr : childNodes) {
		folderSize += curr->getSize();
	}
	return folderSize;
}
