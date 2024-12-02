#include "../include/AbstractFile.h"
#include<string>

AbstractFile::AbstractFile(std::string name, std::string path) {
	this->name = name;
	this->path = path;
}

void AbstractFile::setName(std::string value) {
	this->name = value;
}

std::string AbstractFile::getName() const {
	return this->name;
}

size_t AbstractFile::getSize() const {
	return this->size;
}

std::string AbstractFile::getPath() const {
	return this->path + this->name; 
}
