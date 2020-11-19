#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "TeamProject.h"

//#include <iostream>
//#include <string>
//#nclude <vector>
#include <set>
#include <ctime>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
//Reference1 : https://bit.ly/3lxJQfJ
//Reference2 : https://bit.ly/2ICd4M9


// Example File Structure
// Test_Folder
// ├─── Sub1
// │    ├─── Sub1_Sub
// │    │    └─── Sub1_Sub_1.txt
// │    │         Sub1_Sub_2.txt
// │    └─── Sub1_1.txt
// │         Sub1_2.txt
// ├─── Sub2
// │    └─── Sub2_1.txt
// │         ...
// │         Sub2_4.txt
// └─── a.txt
//      ...
//      i.txt
//      Untitled.mov
        
// Example Eternal Data Structure


//Constructor
MemoList::MemoList() {
    std::string defaultFileName = "text.txt";
    std::string path = defaultPath;
    std::string temp1, temp2;
    // temp1 will be put into vector wholePath
    // temp2 will be put into vector fileList 
    std::string kind_of_path;
    // Variable Element which will put in map pathType
    
    int found{ 0 };
    // Index of the most right side of '\' 
    int Num{ 1 };
    // Map Key Value Count
    bool check;
    //

    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        temp1 = entry.path().string(); // search path
        temp2 = entry.path().filename().string(); // search file
        found = temp1.rfind("\\"); // index of right '\'
        kind_of_path = temp1; // Folder path  
        kind_of_path = kind_of_path.erase(found);

        // For now, About Only Text File Case
        // File Path
        if (temp1.substr(temp1.find_last_of(".") + 1) == "txt") {
            wholePath.push_back(temp1);}
            // If file extension type is txt, the whole path is pushed back into wholePath
        
        // File Name
        if (temp2.substr(temp2.find_last_of(".") + 1) == "txt"){
            fileList.push_back(temp2);}
            // If file extension type is txt, the file is pushed back into fileList


        // Collect The Type of File Paths
        if (pathType.size() == 0) {
            // If pathType is empty,
            pathType[1] = kind_of_path;
            ++Num;
            // In map, kind_of_path is matched to 1.
            check = true;
        }
        else {
            found = 0;
            // Variable found will temporarily have a function to check overlap of path types.
            for (size_t i = 0; i < pathType.size(); ++i) {
                if (pathType[i+1] == kind_of_path) { ++found; break; }
            }

            // If found is not 0, there is already same path type in map(pathType).
            if (found == 0) { pathType[Num] = kind_of_path; ++Num; check=true; }
        }

        // From wholePath, if an element of wholePath includes a file List
        // Return the path except for file name (including file type).
    }
}
//Destructor
MemoList::~MemoList() {}

// Functions
bool MemoList::OpenList() {
	std::cout << "\n######### Open List: START ########" << std::endl;
    
    // false가 return 되면, 루트 변경 묻기 
    // txt file 만??

    int size = wholePath.size();
    // There is not any whole paths, size will be zero.
    if (size == 0) {
        std::cout << "ERROR: There Is No Any File." << std::endl;
        std::cout << "######### Open List: END ########\n" << std::endl;
        return false;
    }
    else {
        //
        for (std::size_t i = 0; i < size; ++i) {
            std::cout << wholePath[i] << std::endl;
            // Print whole paths : ex) C:\Users\USER\Desktop\Test_Folder\a.txt
            std::cout << fileList[i] << std::endl;
            // Print File Lists : ex) a.txt
            //std::cout << typeid(fileList[i]).name() << std::endl;
        }

        std::cout << "\nPath Type List" << std::endl;
        for (std::size_t i = 0; i < pathType.size(); ++i) {
            std::cout << pathType[i+1] << std::endl;
            // Print Path Types : ex) C:\Users\USER\Desktop\Test_Folder
        }

        // Printing Sequence should be determined by debating about this issue.

        std::cout << "######### Open List: END ########\n" << std::endl;
        return true;
    }
    

    //////////////   Ignore Here : Begin   //////////////////
    if (false) {
        std::string path = "C:/Users/USER/Desktop/Test_Folder";
        for (const auto& entry : fs::directory_iterator(path)) {
            std::cout << entry.path() << std::endl;
        }
    }
    if (false) {
        // given file list
        std::string path = "C:/Users/USER/Desktop/Test_Folder";
        for (auto& p : fs::recursive_directory_iterator(path)) {
            std::cout << p << std::endl; //결과: root/dir1/text.txt
            std::cout << p.path().filename() << std::endl; //결과: "test.txt"
            std::cout << p.path().filename().string() << std::endl; //결과: test.txt
        }
    }
    //////////////   Ignore Here :  End    //////////////////
}
bool MemoList::MakeFile(std::string filename = "text.txt") {
    std::cout << "\n######### Make File: START ########" << std::endl;

	std::cout << "Make File : " << filename << std::endl;

    std::string extensionType = ".txt";
    int errorNum1{ 0 }; // dot point number
    int errorNum2{ 0 }; // slash number
    int dotIndex{ 0 };

    if (filename == defaultFileName) {
        // 
        std::cout << "######### Make File: END ########\n" << std::endl;
        return true;
    }
    else {
        for (size_t i = 0; i < filename.size(); ++i) {
            if (filename[i] == ' ') {
                std::cout << "ERROR: INVALID VALUE" << std::endl;
                return false;
            }
            if (filename[i] == '.') {
                ++errorNum1;
                dotIndex = i;}
            if (filename[i] == '/' || filename[i] == '\\') { ++errorNum2; }
        }
        //
        if (errorNum2 > 0) { // slash exists
            std::cout << "ERROR: INVALID VALUE" << std::endl;
            return false; }
        
        //
        if (errorNum1 > 1) { // too many dot points
            std::cout << "ERROR: INVALID VALUE" << std::endl;
            return false; }
        else if (errorNum1 == 1) { // check the extension type
            // The case that there is one dot point.
            // Check if the form of back end of dot is correct. 
            std::cout << "######### Make File: END ########\n" << std::endl;
            return true;
        }
        else { // Make a file as the default type
            // The case that there is no dot.
            // Add the default file extension type.

            filename = filename + extensionType;

            std::cout << "File Name : " << filename << std::endl;
            std::cout << "######### Make File: END ########\n" << std::endl;
            return true;
        }
    }
}
void MemoList::ChangeDefaultFileName(std::string input_default) {
    std::cout << "\n######### Change Default File Name: START ########" << std::endl;
    //try {
    //    check(input_default);
    //} catch (int exception) {
    //    return false;
    //} // Exception Checking
    

    // Change defaultFileName as input_default
    defaultFileName = input_default;
    std::cout << "Default File Name : " << defaultFileName << std::endl;
    std::cout << "######### Change Default File Name: END ########\n" << std::endl;
    // 'input_default' should be entered as 'getline'
}

template <typename Route>
bool MemoList::ChangeDefaultRoute() {
    // Problem : Route will be initialized whenever this program is executed.
    // How to deal with this problem.

    // Solution : First, check a text data file for the file paths using 'default path'.
    // And, if the file is empty(this case doesn't exist according to theorem)
    // or some error about route happens,
    // then, at default path, store the default path as a text file.
    // So, if I execute the function of 'ChangeDefaultRoute',
    // the program will modify the text file.

    // Folder Creation

    // If not the program execution is the first -> Enter the changed path
    // -> Checking the path (format, lacation) -> If there is the pre-determined path file
    // -> Modifying the written content in the text file -> If there is no error
    // -> OK, Modification Complete

    // 프로그램 실행이 최초가 아니라면 -> 바꾼 경로를 입력 -> 경로 확인(형식, 위치)
    // -> 정해진 파일 이름을 찾을 수 있다면, -> 파일 내에 작성된 내용을 수정
    // -> 오류없이 잘 수정 됐다면, -> OK, 수정 완료
}



int main() {
	//std::cout << "Hello, World\n";
	MemoList T;

	T.MakeFile("Hello");
	T.OpenList();
    T.ChangeDefaultFileName("Hello");

	//delete T;
}

////////////   IGNORE HERE : Begin   /////////////
#ifdef DEBUG

typedef std::vector<std::string> stringvec;

void read_directory(const std::string& name, stringvec& v)
{
    std::string pattern(name);
    pattern.append("\\*");
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
        do {
            v.push_back(data.cFileName);
        } while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
}

int main()
{
    stringvec v;
    read_directory(".", v);
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<std::string>(std::cout, "\n"));
}


#endif // DEBUG
////////////   IGNORE HERE :  End   /////////////
