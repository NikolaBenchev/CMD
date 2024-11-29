#include "AbstractFile.h"
#include<string>

void AbstractFile::setName(std::string value) {
	this->name = value;
}

std::string AbstractFile::getName() const {
	return this->name;
}

size_t AbstractFile::getSize() const {
	return this->size;
}
