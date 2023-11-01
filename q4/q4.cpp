#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <sys/stat.h>
#include <filesystem>


using std::string, std::cout, std::cin, std::endl, std::filesystem::is_regular_file, std::filesystem::is_fifo, std::filesystem::is_symlink;


int main(int argc, char* argv[]){
    struct stat fileStat;

    if(lstat(argv[1], &fileStat) == 0){
        // Successfully obtained file information
        cout << "File size: " << fileStat.st_size << " bytes" << endl;
        cout << "File permissions: " << (fileStat.st_mode & 0777) << endl;
        // Add more attributes as needed
        cout << "id of owner: " << fileStat.st_uid <<endl;

        cout << "type of file: ";
        if(is_regular_file(argv[1])){
            cout << "Regular File" << endl;
        }else if(is_fifo(argv[1])){
            cout<< "pipe" << endl;
        }else if(is_symlink(argv[1])){
            cout << "sym link" <<endl;
        }else{
            cout << "unknown file type"<<endl;
        }

    } else {
        std::cerr << "Error: Unable to obtain file information" << endl;
    }

    




    return 0;

}