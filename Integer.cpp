#include "Integer.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace cosc326 {

    std::vector<int> mNum;

    Integer::Integer() {
        mNum.push_back('0');
    }      

    Integer::Integer(const Integer& i) {
        
    }

    Integer::Integer(const std::string& s) {
        for (int i = 0; i < s.length(); i++) {
            mNum.push_back((int) s.at(i) - 48);
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
        std::vector<int> l = lhs.mNum;
        std::vector<int> r = rhs.mNum;
        std::vector<int> output;
        int carry = 0;
        bool rislonger = r.size() > l.size();
        if (rislonger) {
            int diff = r.size() - l.size();
            for (int i = 0; i < diff; i++) {
                l.insert(l.begin(), 0);
            }
        } else {
            int diff = l.size() - r.size();
            for (int i = 0; i < diff; i++) {
                r.insert(r.begin(), 0);
            }
        }

        std::reverse(l.begin(), l.end());
        std::reverse(r.begin(), r.end());

        for (int i = 0; i < l.size(); i++) {
            int x = l.at(i);
            int y = r.at(i);
            printf("x is %d y is %d", x, y);
            int a = x + y + carry;
            printf("A is %d", a);
            carry = a / 10;
            a = a % 10;
            output.insert(output.begin(), a);
        }
        printf("\n");
        for (int i = 0; i < output.size(); i++) {
            printf("%d", output.at(i));
        }
        Integer thing;
        return thing;
    }

    Integer operator-(const Integer& lhs, const Integer& rhs) {
        return lhs;
    }

    Integer operator*(const Integer& lhs, const Integer& rhs) {
        std::vector<int> l = lhs.mNum;
        std::vector<int> r = rhs.mNum;
        std::vector<int> output;
        int a = '5';
        int b = '2';
        std::string result(output.begin(), output.end());
        std::cout << result + "\n";
        Integer ans = Integer(result);
        return ans;
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
