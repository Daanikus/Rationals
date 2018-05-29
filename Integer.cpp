#include "Integer.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

namespace cosc326 {

    

    Integer::Integer() {
        value_ = "0";
        sign = true;
    }      

    Integer::Integer(const Integer& i) {
        value_ = i.value_;
    }

    Integer::Integer(const std::string& s) {
        if (s[0] == '-') {
            sign = false;
        }
        value_ = s;
    }


    Integer::~Integer() {
	
    }

    Integer& Integer::operator=(const Integer& i) {
        value_ = i.value_;
        return *this;
    }

    Integer Integer::operator-() const {
        return Integer(*this);
    }

    Integer Integer::operator+() const {
        return Integer(*this);
    }

    Integer& Integer::operator+=(const Integer& i) {
        return *this;
    }

    Integer& Integer::operator-=(const Integer& i) {
        return *this;
    }

    Integer& Integer::operator*=(const Integer& i) {

        return *this;
    }

    Integer& Integer::operator/=(const Integer& i) {
        return *this;
    }

    Integer& Integer::operator%=(const Integer& i) {
        return *this;
    }

    Integer operator+(const Integer& lhs, const Integer& rhs) {
        std::string l = lhs.value_;
        std::string r = rhs.value_;
        std::string output;
        int carry = 0;
        bool rislonger = r.length() > l.length();
        if (!lhs.sign == rhs.sign) {
            return lhs - rhs;
        }
        if (rislonger) {
            int diff = r.length() - l.length();
            int start = 0;
            if (!lhs.sign) {
                start += 1;        
            }
            for (int i = 0; i < diff; i++) {
                l.insert(start, 1, '0');
            }
        } else {
            int diff = l.length() - r.length();
            int start = 0;
            if (!rhs.sign) {
                start += 1;        
            }
            for (int i = 0; i < diff; i++) {
                r.insert(0, 1, '0');
            }
        }

        std::cout << "L: " << l << "R: " << r << '\n';
        std::reverse(l.begin(), l.end());
        std::reverse(r.begin(), r.end());
        int len = l.length();
        for (int i = 0; i < len; i++) {
            char x = l.at(i) - 48;
            char y = r.at(i) - 48;
            if (x != '-' && y != '-') {
                char a = x + y + carry;
                carry = a / 10;
                a = a % 10;
                output.insert(output.begin(), a + 48);
            } else {
                output.insert(output.begin(), '-');
            }
        }
        Integer result = Integer(output);
        return result;
    }

    Integer operator-(const Integer& lhs, const Integer& rhs) {
        return lhs;
    }

    Integer operator*(const Integer& lhs, const Integer& rhs) {
        /*std::vector<int> l = lhs.mNum;
        std::vector<int> r = rhs.mNum;
        std::vector<int> output;
        int a = '5';
        int b = '2';
        std::string result(output.begin(), output.end());
      //  std::cout << result + "\n";
        Integer ans = Integer(result);*/
        return lhs;
    }

    Integer operator/(const Integer& lhs, const Integer& rhs) {
        return lhs;
    }

    Integer operator%(const Integer& lhs, const Integer& rhs) {
        return lhs;
    }


    std::ostream& operator<<(std::ostream& os, const Integer& i) {
        os << i.value_ << '0';
        return os;
    }

    std::istream& operator>>(std::istream& is, Integer& i) {
        return is;
    }

    bool operator<(const Integer& lhs, const Integer& rhs) {
        if (lhs.sign == false && rhs.sign == true) return true;
        if (lhs.sign == true && rhs.sign == false) return false;
        if (lhs.value_.length() > rhs.value_.length()) return false;
        if (lhs.value_.length() < rhs.value_.length()) return true;
        unsigned long long l, r;
        std::string lstring = lhs.value_;
        std::string rstring = rhs.value_;
        l = std::atol(lstring.c_str());
        r = std::atol(rstring.c_str());

        return l < r;
    }

    bool operator> (const Integer& lhs, const Integer& rhs) {
        return !(lhs < rhs);
    }

    bool operator<=(const Integer& lhs, const Integer& rhs) {
        if (lhs == rhs) return true;
        return lhs < rhs;
    }

    bool operator>=(const Integer& lhs, const Integer& rhs) {
        if (lhs == rhs) return true;
        return lhs > rhs;
    }

    bool operator==(const Integer& lhs, const Integer& rhs) {
        int res = strcmp(lhs.value_.c_str(), rhs.value_.c_str());
        return res == 0;
    }

    bool operator!=(const Integer& lhs, const Integer& rhs) {
        return lhs == rhs;
    }


    Integer gcd(const Integer& a, const Integer& b) {
        return a;
    }

    const std::string Integer::getValue() {
            return this->value_;
    }

}
