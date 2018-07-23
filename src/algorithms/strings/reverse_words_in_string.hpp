#ifndef REVERSE_WORDS_IN_STRING_HPP
#define REVERSE_WORDS_IN_STRING_HPP

/*
https://leetcode.com/problems/reverse-words-in-a-string/description/

Given an input string, reverse the string word by word.

Example:

Input: "the sky is blue",
Output: "blue is sky the".
Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed
string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the
reversed string.
Follow up: For C programmers, try to solve it in-place in O(1) space.
*/

#include <string>

namespace Algo::Strigns {

class ReverseWords {
public:
    static void Reverse(std::string& s) {
        if (s.empty()) {
            return;
        }

        // Reverse string
        for (size_t left = 0, right = s.size() - 1; left < right;
             ++left, --right)
        {
            std::swap(s[left], s[right]);
        }

        // Reverse words in reversed string
        for (size_t i = 0; i < s.size(); ++i) {
            size_t wordStart = i;
            while(wordStart < s.size() && s[wordStart] == ' ') {
                ++wordStart;
            }

            if (wordStart >= s.size()) {
                break;
            }

            size_t wordEnd = wordStart;
            while(wordEnd < s.size() && s[wordEnd] != ' ') {
                ++wordEnd;
            }

            for (size_t wLeft = wordStart, wRight = wordEnd - 1;
                 wLeft < wRight; ++wLeft, --wRight)
            {
                std::swap(s[wLeft], s[wRight]);
            }

            i = wordEnd - 1;
        }

        // Eliminate extra space
        size_t writePos = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            while(i < s.size() && s[i] == ' ') {
                ++i;
            }

            if (i >= s.size()) {
                break;
            }

            while(i < s.size() && s[i] != ' ') {
                if (writePos == i) {
                    ++writePos;
                    ++i;
                }
                else {
                    s[writePos++] = s[i];
                    s[i++] = ' ';
                }
            }

            --i;

            if (writePos < s.size()) {
                s[writePos++] = ' ';
            }
        }

        // Check that on the end of the string there is no white space
        size_t endPos = std::min(writePos, s.size() - 1);
        while (s[endPos] == ' ') {
            if (endPos == 0) {
                break;
            }

            --endPos;
        }

        if (endPos == 0) {
            s[endPos] != ' ' ? s.resize(1) : s.resize(0);
        }
        else {
            s.resize(endPos + 1);
        }
    }
};

}

#endif // REVERSE_WORDS_IN_STRING_HPP
