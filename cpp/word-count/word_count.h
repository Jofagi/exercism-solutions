#pragma once

#include <map>
#include <string>
#include <regex>
#include <boost/algorithm/string/case_conv.hpp>

namespace word_count
{
    typedef std::map<std::string, int> result_type;

    result_type words(const std::string & phrase)
    {
        result_type result;

        // Words may start with letters and numbers,
        // followed by at most one apostrophe and
        // optional further numbers and letters
        static const std::regex word("[[:alnum:]]+'?[[:alnum:]]*");

        auto i = std::sregex_iterator(phrase.begin(), phrase.end(), word);
        static const auto end = std::sregex_iterator();
        
        while (i != end)
        {
            const auto normalizedWord = boost::algorithm::to_lower_copy(i->str());
            result[normalizedWord]++;
            ++i;
        }
        

        return result;
    }
}