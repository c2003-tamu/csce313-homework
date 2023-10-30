#include <iostream>
#include <string>
#include <unistd.h>


using std::string, std::cout, std::cin, std::endl;


int main(int argc, char* argv[]){
    pid_t child = fork();
    if(child == -1){
        cout << "could not open fork" << endl;
    }else if(child == 0){
        cout << "in child" << endl;
    }else{
        cout << "in parent" << endl;
    }
    

    return 0;

}