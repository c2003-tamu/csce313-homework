#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>


using std::string, std::cout, std::cin, std::endl;

int openr(const char *pathname){
    int file = open(pathname, O_RDONLY);
    if(file == -1){
        cout << "Error opening file" << endl;
        return file;
    }
    dup2(file, 0);

    string line;
    while(getline(cin, line)){
        cout << line << endl;
    }


    return file;

}

int main(int argc, char* argv[]){

    openr(argv[1]);

    return 0;

}