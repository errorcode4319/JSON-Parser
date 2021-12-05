#include "json-parser.h"

namespace json {
    
    namespace {

        using strIter       = std::string_view::iterator;
        using strItPair     = std::pair<strIter, strIter>;
        using bracket       = std::pair<char, strIter>;
        using bracket_pair  = std::pair<bracket,bracket>;
        using bracket_tree  = std::map<strIter, bracket_pair>;
        //using bracket_table = std::vector<bracket_pair>;
        using bracket_table = std::vector<size_t>; // store offset info 

        strItPair trim(std::string_view jstr);
        strItPair trimFront(std::string_view jstr);
        strItPair trimBack(std::string_view jstr);

        std::optional<bracket_table> CreateBracketTree(strItPair jstr);

        std::optional<std::any> parseValue(strItPair jstr);

        std::vector<std::any> parseArr(strItPair jstr);

        Object parseObj(strItPair jstr);
    }


    Object parseJSON(std::string_view raw) {
        auto jstr = trim(raw);
        auto brTable_opt = CreateBracketTree(jstr);
        if(brTable_opt.has_value() == false) {
            throw std::runtime_error("Invalid JSON Data");
        }
        auto brTree = brTable_opt.value();
        Object obj;

        std::stack<bracket> stk;

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
        
        strItPair trim(std::string_view jstr) {
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

        std::optional<bracket_table> CreateBracketTree(strItPair jstr) {

            bracket_tree brTree;
            bracket_table brTable;
            
            std::stack<bracket> stk;
            auto[beg, end] = jstr;
            size_t len = size_t(end - beg);
            brTable.resize(len);

            for(auto iter=beg;iter<end;iter++) {
                char ch = *iter;
                if(ch == '[' || ch == '{') {
                    stk.emplace(ch, iter);
                }
                if(ch == '\"') {
                    if(stk.empty()) stk.emplace(ch, iter);
                    else if(stk.top().first == ch) stk.pop();
                    else stk.emplace(ch, iter);   
                }
                if(ch == ']') {
                    if(stk.empty()) return std::nullopt;
                    else if(stk.top().first != '[') return std::nullopt;
                    else stk.pop();
                }
                if(ch == '}') {
                    if(stk.empty()) return std::nullopt;
                    else if(stk.top().first != '{') return std::nullopt;
                    else stk.pop();
                }
            }
            if(!stk.empty())
                return std::nullopt;
            return brTable;
        }

        std::optional<std::any> parseValue(strItPair jstr) {
            


            return std::nullopt;
        }

        std::vector<std::any> parseArr(strItPair jstr) {
            std::vector<std::any> jarr;

            return jarr;
        }

        Object parseObj(strItPair jstr) {
            return Object();
        }

        
    }

}