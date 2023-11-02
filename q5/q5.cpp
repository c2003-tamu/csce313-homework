#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>


using std::string, std::cout, std::cin, std::endl;


int main(int argc, char* argv[]){

    int count = 0;
    // vector<int> openProcesses;
    while(true){
        int file = open(argv[1], O_RDONLY);
        if(file == -1){
            cout << "max reached: "<< count <<endl;
            break;
        }
        ++count;
        //cout << "count: "<<count<<endl;

    }

}