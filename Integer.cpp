#include "Integer.h"
#include <iostream>
#include <string>
#include <vector>
namespace cosc326 {

    std::vector<char> mNum;

    Integer::Integer() {
        mNum.push_back('0');
    }      

    Integer::Integer(const Integer& i) {
        
    }

    Integer::Integer(const std::string& s) {
        for (int i = 0; i < s.length(); i++) {
            mNum.push_back(s.at(i));
        }
	
    }


    Integer::~Integer() {
	
    }

    Integer& Integer::operator=(const Integer& i) {
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
        std::vector<char> l = lhs.mNum;
        std::vector<char> r = rhs.mNum;
        printf("In operator\n");
        bool rislonger = r.size() > l.size();
        if (rislonger) {
            int diff = r.size() - l.size();
            for (int i = 0; i < diff; i++) {
                l.insert(l.begin(), '0');
            }
        } else {
            int diff = l.size() - r.size();
            for (int i = 0; i < diff; i++) {
                r.insert(r.begin(), '0');
            }
        }
        for (int i = 0; i < l.size(); i++) {
            printf("%d", i);
            std::cout << l.at(i);
        }
        return lhs;
    }

    Integer operator-(const Integer& lhs, const Integer& rhs) {
        return lhs;
    }

    Integer operator*(const Integer& lhs, const Integer& rhs) {
        return lhs;
    }

    Integer operator/(const Integer& lhs, const Integer& rhs) {
        return lhs;
    }

    Integer operator%(const Integer& lhs, const Integer& rhs) {
        return lhs;
    }


    std::ostream& operator<<(std::ostream& os, const Integer& i) {
        return os;
    }

    std::istream& operator>>(std::istream& is, Integer& i) {
        return is;
    }

    bool operator<(const Integer& lhs, const Integer& rhs) {
        return true;
    }

    bool operator> (const Integer& lhs, const Integer& rhs) {
        return true;
    }

    bool operator<=(const Integer& lhs, const Integer& rhs) {
        return true;
    }

    bool operator>=(const Integer& lhs, const Integer& rhs) {
        return true;
    }

    bool operator==(const Integer& lhs, const Integer& rhs) {
        return true;
    }

    bool operator!=(const Integer& lhs, const Integer& rhs) {
        return true;
    }


    Integer gcd(const Integer& a, const Integer& b) {
        return a;
    }

}
