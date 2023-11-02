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


    float totalFunctionNs = 0;
    float totalSystemNs = 0;
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

    cout << "average time in nanoseconds for 30 function calls: " << totalFunctionNs/30 <<endl;
    cout << "average time in nanoseconds for 30 system calls: " << totalSystemNs/30 <<endl;

    

    return 0;

}