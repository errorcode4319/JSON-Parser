#include "json-parser.h"


int main() {
    json::Object obj;
    obj.set<std::string>("Key1", "12345");
    obj.set<int>("Key2", int(12345));
    obj.setArr<int>("Key3", {1,2,3,4,5});

    auto Val1 = obj.get<std::string>("Key1");
    auto Val2 = obj.get<int>("Key2");
    auto Val3 = obj.getArr<int>("Key3");

    std::cout << Val1.value_or("") << std::endl;
    std::cout << Val2.value_or(0) << std::endl;
    
}