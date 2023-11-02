#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <cerrno>


using std::string, std::cout, std::cin, std::endl;


int main(int argc, char* argv[]){

    int count = 0;
    // vector<int> openProcesses;
    while(true){
        int file = open(argv[1], O_RDONLY);
        if(file == -1){
            if(errno == EMFILE){
                cout << "max reached: "<< count <<endl;
                break;
            }else{
                cout << "unknown error" << endl;
                break;
            }
        }
        ++count;

    }

}