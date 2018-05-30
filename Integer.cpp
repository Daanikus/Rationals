#include "Integer.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

namespace cosc326 {


    Integer::Integer() {
        value_ = "0";
        sign = 1;
    }      

    Integer::Integer(const Integer& i) {
        value_ = i.value_;
        sign = i.sign;
    }

    Integer::Integer(const std::string& s) {
        sign = (s[0] == '-') ? 0 : 1;
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
        *this = *this + i;
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
        if (lhs.sign != rhs.sign) {
            std::cout << "In add: signs not same. lsh is " << lhs.sign << " and rhs is " << rhs.sign << '\n';
            return lhs - rhs;
        }
        if (rislonger) {
            int diff = r.length() - l.length();
            int start = 0;
            if (lhs.sign == 0) {
                std::cout << "alhs is neg\n";
                start += 1;        
            }
            for (int i = 0; i < diff; i++) {
                l.insert(start, 1, '0');
            }
            std::cout << "aif Start is " << start << '\n';
        } else {
            int diff = l.length() - r.length();
            int start = 0;
            if (rhs.sign == 0) {
                std::cout << "arhs is neg\n";
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
        if (carry != 0) {
            output.insert(output.begin(), carry + 48);
        }
        Integer result = Integer(output);
        return result;
    }

    Integer operator-(const Integer& lhs, const Integer& rhs) {
        return lhs;
    }

    Integer operator*(const Integer& lhs, const Integer& rhs) {
        std::cout << "In multi\n";
        std::string l = (lhs.value_.length() > rhs.value_.length()) ? lhs.value_ : rhs.value_;
        std::string r = (lhs.value_.length() <= rhs.value_.length()) ? lhs.value_ : rhs.value_;
        int carry = 0;
        bool rislonger = r.length() > l.length();
       /* if (lhs.sign != 0 && rhs.sign == 0 || lhs.sign == 0 && rhs.sign != 0) {
            std::cout << "WRONG SIGNS! L is " << lhs.sign << " R is " << rhs.sign << '\n';
            return lhs - rhs;
        }*/
        // TODO Neg nums
        if (rislonger) {
            int diff = r.length() - l.length();
            int start = 0;
            if (lhs.sign == 0) {
                std::cout << "lhs is neg\n";
                start += 1;        
            }
            for (int i = 0; i < diff; i++) {
                l.insert(start, 1, '0');
            }
            std::cout << "if Start is " << start << '\n';
        } else {
            int diff = l.length() - r.length();
            int start = 0;
            if (rhs.sign == 0) {
                std::cout << "rhs is neg\n";
                start += 1;        
            }
            for (int i = 0; i < diff; i++) {
                r.insert(0, 1, '0');
            }
            std::cout << "else Start is " << start << '\n';
        }

        std::cout << "Lx: " << l << "Rx: " << r << '\n';
        //std::reverse(l.begin(), l.end());
        //std::reverse(r.begin(), r.end());
        std::cout << "LxRev: " << l << "RxRev: " << r << '\n';
        int len = r.length();
        std::cout << "LEN is " << len << '\n';
        Integer b;
        Integer result;
        for (int i = 0; i < len; i++) {
            char x = l.at(i) - 48;
            Integer a;
            for (int j = 0; j < len; j++) {
                char y = (r.at(j) - 48);
                //int temp = x * (y * (j + 1));
                int temp = (int) x * y;
                std::cout << (int) x << " x " << (int) y << '\n';
                char tempstr[1000];
                sprintf(tempstr, "%d", temp);
                r.insert(strlen(tempstr), j, '0');
                b.setValue(tempstr);
                std::cout << "B is " << b.getValue() << '\n';
                std::cout << "A is " << a.getValue() << '\n';
                a += b;
                std::cout << "mA after add (A + B) is " << a.getValue() << '\n';
            }
            std::cout << "multi result is before " << result.getValue() << '\n';
            result += a;  
            std::cout << "multi result is after result += b " << result.getValue() << '\n';
        }
        
        return result;
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

    void Integer::setValue(std::string s) {
        this->value_ = s;
    }

}
