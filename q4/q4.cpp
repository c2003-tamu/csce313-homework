#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <sys/stat.h>


using std::string, std::cout, std::cin, std::endl;


int main(int argc, char* argv[]){
    struct stat fileStat;

    if(lstat(argv[1], &fileStat) == 0){
        // Successfully obtained file information
        cout << "File size: " << fileStat.st_size << " bytes" << endl;
        cout << "File permissions: " << (fileStat.st_mode & 0777) << endl;
        // Add more attributes as needed
        cout << "id of owner: " << fileStat.st_uid <<endl;
    } else {
        std::cerr << "Error: Unable to obtain file information" << endl;
    }

    




    return 0;

}