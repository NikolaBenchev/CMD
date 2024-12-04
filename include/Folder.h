#pragma once

#include<cstddef>
#include<string>
#include<vector>
#include "./AbstractFile.h"
#include "./File.h"

class Folder : public AbstractFile {
	public:
		Folder(std::string name, AbstractFile* parent) : AbstractFile(name, parent) {};

		void addFile(File* newFile);
		void addFolder(Folder* newFolder);

		void removeFile(const std::string name);
		void removeFolder(const std::string name);

		size_t getSize() const;
		
		void printContent() const;

		Folder* getFolder(std::string path) const;
		File* getFile(std::string path) const;
	private:
		std::vector<File*> innerFiles;
		std::vector<Folder*> innerFolders;
};
