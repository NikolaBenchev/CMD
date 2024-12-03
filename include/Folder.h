#pragma once

#include<cstddef>
#include<string>
#include<vector>
#include "./AbstractFile.h"

class Folder : public AbstractFile {
	public:
		Folder(std::string name, std::string path) : AbstractFile(name, path) {};

		void add(AbstractFile* newFile);

		void remove(const std::string& name);

		std::string getName();

		AbstractFile* getContent();

		size_t getSize();
	private:
		std::vector<AbstractFile*> innerFiles;
};
