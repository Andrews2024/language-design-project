#ifndef INTEGER_H
#define INTEGER_H

#include <boost/spirit/home/x3.hpp>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Integer {
    public:
        template <typename Iterator>
        bool arrayOfIntegersParser(Iterator first, Iterator last) {
            using boost::spirit::x3::int_;
            using boost::spirit::x3::phrase_parse;
            using boost::spirit::x3::ascii::space;

            bool result = phrase_parse(
                first,                          //  Start Iterator
                last,                           //  End Iterator
                (
                        '[' >> int_
                        >> *(',' >> int_) >> ']'
                    |   "[]"
                ),
                space                           //  The Skip-Parser
            );
            if (first != last) // fail if we did not get a full match
                return false;
            return result;
        }

        void storeArray(string str);
        void printResult(int[],int);
};

#endif