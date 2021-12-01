#include "json-parser.h"

namespace json {
    
    namespace {

        using strIter = std::string_view::iterator;
        using strItPair = std::pair<strIter, strIter>;
        using bracket = std::pair<char, strIter>;
        using bracket_pair = std::pair<bracket,bracket>;
        using bracket_tree = std::map<strIter, bracket_pair>;

        strItPair trimFull(std::string_view jstr);
        strItPair trimFront(std::string_view jstr);
        strItPair trimBack(std::string_view jstr);

        std::optional<bracket_tree> CreateBracketTree(std::string_view jstr);

        std::optional<std::any> parseValue(std::string_view jstr);

        std::vector<std::any> parseArr(std::string_view jstr);

        Object parseObj(std::string_view jstr);
    }

    Object parseJSON(std::string_view jstr) {
        auto brTree = CreateBracketTree(jstr);
        if(brTree.has_value() == false) {
            throw std::runtime_error("Invalid JSON Data");
        }
        
        Object obj;

        //for(auto iter=std::begin(jstr), )

        return obj;
    }

    std::string serializeJSON(const Object& obj) {
        return "";
    }

    std::optional<std::string> fileRead(std::string_view filepath) {
        std::ifstream file(filepath.data());
        if(!file) 
            return std::nullopt;
        std::stringstream ss;
        ss << file.rdbuf();
        return ss.str();
    }



    namespace {
        
        strItPair trimFull(std::string_view jstr) {
            auto begIter = std::cbegin(jstr);
            auto endIter = std::cend(jstr);
            while(*begIter == ' ' && begIter < endIter) begIter++;
            while(*endIter == ' ' && begIter < endIter) endIter--;
            return std::make_pair(begIter, endIter);
        }
        strItPair trimFront(std::string_view jstr) {
            auto begIter = std::cbegin(jstr);
            auto endIter = std::cend(jstr);
            while(*begIter == ' ' && begIter < endIter) begIter++;
            return std::make_pair(begIter, endIter);
        }
        strItPair trimBack(std::string_view jstr) {
            auto begIter = std::cbegin(jstr);
            auto endIter = std::cend(jstr);
            while(*endIter == ' ' && begIter < endIter) endIter--;
            return std::make_pair(begIter, endIter);
        }

        std::optional<bracket_tree> CreateBracketTree(std::string_view jstr) {

            bracket_tree brTree;

            if(jstr.front() != '{' || jstr.back() != '}')
                return std::nullopt;

            std::stack<char> stk;

            for(const auto& ch: jstr) {
                if(ch == '[' || ch == '{') stk.push(ch);
                if(ch == '\"') {
                    if(stk.empty()) stk.push(ch);
                    else if(stk.top() == ch) stk.pop();
                    else stk.push(ch);
                    
                }
                if(ch == ']') {
                    if(stk.empty()) return std::nullopt;
                    else if(stk.top() != '[') return std::nullopt;
                    else stk.pop();
                }
                if(ch == '}') {
                    if(stk.empty()) return std::nullopt;
                    else if(stk.top() != '{') return std::nullopt;
                    else stk.pop();
                }
            }
            if(!stk.empty())
                return std::nullopt;
            return brTree;
        }

        std::optional<std::any> parseValue(std::string_view jstr) {
            


            return std::nullopt;
        }

        std::vector<std::any> parseArr(std::string_view jstr) {
            std::vector<std::any> jarr;

            return jarr;
        }

        Object parseObj(std::string_view jstr) {
            return Object();
        }

        
    }

}