#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>


using std::string, std::cout, std::cin, std::endl, std::vector;


int main(int argc, char* argv[]){

    int count = 1;
    vector<int> openProcesses;
    while(true){
        openProcesses.push_back(open(argv[1], O_RDONLY));

        cout << "count: "<<count<<endl;
        count++;

    }

}