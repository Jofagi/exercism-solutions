#pragma once

#include <string>

namespace hamming
{
    unsigned int compute(const std::string & a, const std::string & b)
    {
        if (a.size() != b.size()) 
        {
            throw std::domain_error("Inequal sequence lengths"); 
        }

        unsigned int result = 0;

        for (size_t idx = 0; idx < a.size(); ++idx)
        {
            if (a[idx] != b[idx]) { ++result; }
        }

        return result;
    }
}