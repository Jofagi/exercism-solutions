#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include<boost/algorithm/string/case_conv.hpp>

namespace anagram
{
    class anagram
    {
        std::string m_sorted;
        std::string m_original;

        bool is_anagram(const anagram & other) const
        {
            // It's an anagram if both sequences use the same letters.
            // Be strict though: Don't count a word as its own anagram.
            return m_sorted == other.m_sorted
                   && m_original != other.m_original;
        }

    public:
        explicit anagram(const std::string & input)
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
                if (is_anagram(anagram(s))) { result.push_back(s); }
            }

            return result;
        }
    };
}