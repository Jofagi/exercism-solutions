#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include<boost/algorithm/string/case_conv.hpp>

namespace anagram
{
    class matcher
    {
        std::string m_sorted;
        std::string m_original;

        bool is_anagram(const matcher & other) const
        {
            // It's an anagram if both sequences use the same letters.
            // Be strict though: Don't count a word as its own anagram.
            return m_sorted == other.m_sorted
                   && m_original != other.m_original;
        }

    public:
        explicit matcher(const std::string & input)
            : m_original(boost::to_lower_copy(input)) // Be case insensitive
        {
            m_sorted = m_original;
            std::sort(m_sorted.begin(), m_sorted.end());
        }


        typedef std::vector<std::string> stringlist;

        stringlist matches(const stringlist & input) const
        {
            stringlist result;

            for (const auto & s : input)
            {
                if (is_anagram(matcher(s))) { result.push_back(s); }
            }

            return result;
        }
    };

    inline matcher anagram(const std::string & input)
    {
        return matcher(input);
    }
}