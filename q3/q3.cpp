#include <iostream>
#include <string>
#include <unistd.h>
#include <fcntl.h>


using std::string, std::cout, std::cin, std::endl;


int main(int argc, char* argv[]){
    
    //bool complete = false;
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
        //cout << "in child" << endl;
        //close(myPipe[1]);

        while(true){
            bool receivedValue;
            char receivedByte;
            if (read(p[0], &receivedByte, sizeof(receivedByte)) == -1) {
                perror("read");
                return 1;
            }
            receivedValue = (receivedByte == 1);

            if(receivedValue){
                break;
            }
        }
        cout << "entering child"<<endl;

        string filename = "tests/testout.txt";
        int outFile = open(filename.c_str(), O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

        /*
        * sending data
        */
        ssize_t bytesRead;
        while ((bytesRead = read(file, buffer, sizeof(buffer))) > 0) {
            ssize_t bytesWritten = write(outFile, buffer, bytesRead);
            if (bytesWritten != bytesRead) {
                std::cerr << "Error: Incomplete write to the destination file." << std::endl;
                return 1;
            }
        }



    }else{
       // cout << "in parent" << endl;
        int deleted = unlink(argv[1]);
        if(deleted == -1){
            cout << "error deleting file" <<endl;
        }
        //close(myPipe[0]);  // Close the read end of the pipe in the parent

        bool valueToSend = true;

        // Convert the boolean value to a byte and write it to the pipe
        char byteToSend = valueToSend ? 1 : 0;
        if (write(p[1], &byteToSend, sizeof(byteToSend)) == -1) {
            perror("write");
            return 1;
        }
        cout << endl<< "Parent Complete!!!"<<endl;
        //close(myPipe[1]);  // Close the write end of the pipe in the parent


    }
    

    return 0;

}