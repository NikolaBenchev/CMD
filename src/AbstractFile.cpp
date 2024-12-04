#include "../include/AbstractFile.h"
#include<string>

AbstractFile::AbstractFile(std::string name, AbstractFile* parent) {
	this->name = name;
	this->parent = parent; 
}

void AbstractFile::setName(std::string value) {
	this->name = value;
}

std::string AbstractFile::getName() const {
	return this->name;
}

std::string AbstractFile::getPath() const {
	if(!this->parent)
		return this->name;
	return this->parent->getPath() + '/' + this->name; 
}
