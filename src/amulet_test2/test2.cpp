#include <iostream>
#include <amulet_test1/test1.hpp>
#include "test2.hpp"

namespace Amulet {
    AMULET_TEST2_DLLX void test2_1(std::string s){
        test1_1(s);
        std::cout << s << std::endl;
        std::cout << "test2_1abcdefghijk" << std::endl;
    }
    AMULET_TEST2_DLLX void test2_2(const std::string& s){
        test1_2(s);
        std::cout << s << std::endl;
        std::cout << "test2_2abcdefghijk" << std::endl;
    }
}
