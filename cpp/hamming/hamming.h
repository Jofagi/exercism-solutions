#pragma once

#include <string>

#include <boost/range/combine.hpp>
#include <boost/foreach.hpp>

namespace hamming
{
    unsigned int compute(const std::string & seqA, const std::string & seqB)
    {
        if (seqA.size() != seqB.size()) 
        {
            throw std::domain_error("Inequal sequence lengths"); 
        }

        unsigned int result = 0;

        // Iterate over both ranges simultaneously
        std::string::value_type a, b;
        BOOST_FOREACH(boost::tie(a, b), boost::combine(seqA, seqB))
        {
            if (a != b) { ++result; }
        }

        return result;
    }
}