#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>

using std::string, std::cout, std::cin, std::endl, std::vector;

int getRandom(){
    return 1;
}

int main(int argc, char* argv[]){

    vector<int> functionCallTimes;
    vector<int> systemCallTimes;

    for(int i =0;i<30;i++){
        auto start = std::chrono::high_resolution_clock::now();

        getRandom();

        auto stop = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

        //cout << "Time taken by function call: " << duration.count() << " microseconds" << endl;
        functionCallTimes.push_back(duration.count());

        start = std::chrono::high_resolution_clock::now();

        getpid();

        stop = std::chrono::high_resolution_clock::now();

        auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

        //cout << "Time taken by system call: " << duration2.count() << " microseconds" << endl;
        systemCallTimes.push_back(duration2.count());
    }


    int totalFunctionMs = 0;
    int totalSystemMs = 0;
    for(int i =0; i<30;i++){
        totalFunctionMs += functionCallTimes.at(i);
        totalSystemMs += systemCallTimes.at(i);
    }

    cout << "time for 30 function calls: " << totalFunctionMs << " nanoseconds" <<endl;
    cout << "time for 30 system calls: " << totalSystemMs << " nanoseconds" <<endl;
    

    return 0;

}