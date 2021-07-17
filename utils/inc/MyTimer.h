#pragma once
#include <chrono>
#include <iostream>

class MyTimer {
private:
    decltype(std::chrono::steady_clock::now()) mBegin;

public:
    MyTimer() {
        mBegin = std::chrono::steady_clock::now();
    }
    ~MyTimer() {
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = end - mBegin;
        std::cout << "***********************************" << std::endl;
        std::cout << "Elapsed time: " << elapsed.count() << "s" << std::endl;
        std::cout << "***********************************" << std::endl;
    }
};