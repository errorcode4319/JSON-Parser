#include "json-parser.h"

namespace json {
    
    namespace {
        using bracket = std::pair<char, std::string::iterator>;
        using bracket_pair = std::pair<bracket,bracket>;
        using bracket_list = std::vector<bracket_pair>;

        std::tuple<bool, bracket_list> BracketSyntaxValid(std::string_view jstr);

        std::optional<std::any> parseValue(std::string_view jstr);

        Object parseObj(std::string_view jstr);
    }

    Object parseJSON(std::string_view jstr) {
        if(!BracketSyntaxValid(jstr)) {
            throw std::runtime_error("Invalid JSON Data");
        }

        Object obj;



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
        std::tuple<bool, bracket_list> BracketSyntaxValid(std::string_view jstr) {

            bracket_list brkl;
            auto brk_iter = std::begin(brkl);

            if(jstr.front() != '{' || jstr.back() != '}')
                return std::make_tuple(false, brkl); 

            std::stack<char> stk;

            for(const auto& ch: jstr) {
                if(ch == '[' || ch == '{') stk.push(ch);
                if(ch == '\"') {
                    if(stk.empty()) stk.push(ch);
                    else if(stk.top() == ch) stk.pop();
                    else stk.push(ch);
                }
                if(ch == ']') {
                    if(stk.empty()) return false;
                    else if(stk.top() != '[') return false;
                    else stk.pop();
                }
                if(ch == '}') {
                    if(stk.empty()) return false;
                    else if(stk.top() != '{') return false;
                    else stk.pop();
                }
            }
            if(!stk.empty())
                return std::make_tuple(false, brkl);
            return std::make_tuple(true, brkl);
        }

        std::optional<std::any> parseValue(std::string_view jstr) {
            

            return std::nullopt;
        }

        Object parseObj(std::string_view jstr) {
            return Object();
        }

        
    }

}