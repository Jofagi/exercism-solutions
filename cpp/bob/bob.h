#pragma once

#include <string>
#include <regex>

namespace bob
{
    inline const char* hey(const std::string & s)
    {
        static const std::regex endsInQuestionMark(R"'(.*\?[[:space:]]*$)'");
        static const std::regex onlyUppercaseLetters("[^a-z]*[A-Z]+[^a-z]*");
        static const std::regex onlyWhitespace("[[:space:]]*");

        std::smatch m;

        if (std::regex_match(s, m, onlyUppercaseLetters))
        {
            return "Whoa, chill out!";
        }
        else if (std::regex_match(s, m, endsInQuestionMark))
        {
            return "Sure.";
        }
        else if (std::regex_match(s, m, onlyWhitespace))
        {
            return "Fine. Be that way!";
        }

        return "Whatever.";
    }
}