#include "json-parser.h"



int main() {


    auto data = json::fileRead("sample-data/sample.json").value_or("");
    std::cout << "JSON File Read" << std::endl;
    std::cout << data << std::endl;

    try {
        auto obj = json::parseJSON(data);
    } catch(const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

}