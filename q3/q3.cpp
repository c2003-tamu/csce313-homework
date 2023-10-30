#include <iostream>
#include <string>
#include <unistd.h>
#include <fcntl.h>


using std::string, std::cout, std::cin, std::endl;


int main(int argc, char* argv[]){
    
    int p[2];
    int myPipe = pipe(p);
    if(myPipe==-1){
        cout << "could not open pipe";
        return 1;
    }

    int file = open(argv[1], O_RDONLY);
    if(file == -1){
        cout << "Error opening file" << endl;
        return 1;
    }

    string line;
    char buffer[4096]; // Buffer for reading data

    pid_t child = fork();
    if(child == -1){
        cout << "could not fork" << endl;
    }else if(child == 0){
        cout << "in child" << endl;
        string filename = "tests/testout.txt";
        int outFile = open(filename.c_str(), O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

        ssize_t bytesRead;
        while ((bytesRead = read(file, buffer, sizeof(buffer))) > 0) {
            ssize_t bytesWritten = write(outFile, buffer, bytesRead);
            if (bytesWritten != bytesRead) {
                std::cerr << "Error: Incomplete write to the destination file." << std::endl;
                return 1;
            }
        }
    }else{
        cout << "in parent" << endl;
        int deleted = unlink(argv[1]);
        if(deleted == -1){
            cout << "error deleting file" <<endl;
        }

    }
    

    return 0;

}