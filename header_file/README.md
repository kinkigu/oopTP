# Add Header Files Here


## MemoList
```
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#ifndef __oopTP__
#define __oopTp__

class MemoList {
	//std::vector<std::experimental::filesystem::v1::path> wholePath;
	std::vector<std::string> wholePath;
	std::vector<std::string> fileList;
	std::map<int, std::string> pathType;

public:
	std::string defaultFileName = "\0";
	std::string defaultPath = "C:/Users/USER/Desktop/Test_Folder";

public:
	// Constructor
	MemoList();
	// Destructor
	~MemoList();

	// Functions
	bool OpenList();
	bool MakeFile(std::string filename);
	void ChangeDefaultFileName(std::string input_default);

public:
	template <typename Route>
	bool ChangeDefaultRoute();

private:


public:

};


#endif // !oopTP
```
2020.11.17 22:41 김진휘
