#include<string>
#include "./AbstractFile.h"

class File : public AbstractFile{
	public:
		File(std::string name, std::string path) : AbstractFile(name, path) {}; 
	private:
		std::string content;
};
