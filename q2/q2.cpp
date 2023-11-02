#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>

using std::string, std::cout, std::cin, std::endl, std::vector;

class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};



int getRandom(MyClass myObj){
    return myObj.myNum;
}

int main(int argc, char* argv[]){
    MyClass myObj;  // Create an object of MyClass

    // Access attributes and set values
    myObj.myNum = 15; 
    myObj.myString = "Some text";

    
    int totalTimeFunc = 0;
    int totalTimeSys = 0;
    for(int j =0;j<10;++j){
        int totalFunctionNs = 0;
        int totalSystemNs = 0;
        for(int i =0;i<30;i++){
            auto start = std::chrono::high_resolution_clock::now();

            getRandom(myObj);

            auto stop = std::chrono::high_resolution_clock::now();

            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);


            totalFunctionNs += duration.count();

            start = std::chrono::high_resolution_clock::now();

            getpid();

            stop = std::chrono::high_resolution_clock::now();

            auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);


            totalSystemNs += duration2.count();
        }



        totalTimeFunc += totalFunctionNs;
        totalTimeSys += totalSystemNs;
    }

    cout << "average time for 30 function calls over 10 trials: " << totalTimeFunc/10 <<endl;
    cout << "average time for 30 system calls over 10 trials: " << totalTimeSys/10 <<endl;
    

    return 0;

}