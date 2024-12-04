#pragma once

#include<cstddef>
#include<string>
#include "./AbstractFile.h"

class File : public AbstractFile{
	public:
		File(std::string name, AbstractFile* parent) : AbstractFile(name, parent) {};
		size_t getSize(); 
	private:
		std::string content;
};
