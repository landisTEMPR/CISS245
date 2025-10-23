// File : LongInt.cpp
// Author : Brysen Landis

#include "LongInt.h"


int strlen(const char * s)
{
    if (s == 0)
    {
        return 0;
    }

    int n = 0;

    while (s[n] != '\0')
    {
        ++n;
    }

    return n;
}


void normalize(LongInt & r)
{
    int s = r.size_;

    while (s > 1 && r.x_[s - 1] == 0)
    {
        --s;
    }

    r.size_ = (s >= 1) ? s : 1;

    if (r.size_ == 1 && r.x_[0] == 0)
    {
        r.sign_ = 1;
    }
}


LongInt get_longint(const char s[])
{
    LongInt ret;

    for (int i = 0; i < 1000; ++i)
    {
        ret.x_[i] = 0;
    }

    ret.size_ = 1;
    ret.sign_ = 1;

    if (s == 0)
    {
        return ret;
    }

    int len = strlen(s);

    if (len == 0)
    {
        return ret;
    }

    int idx = 0;

    if (s[0] == '-')
    {
        ret.sign_ = -1;
        idx = 1;
    }
    else if (s[0] == '+')
    {
        ret.sign_ = 1;
        idx = 1;
    }

    while (idx < len && s[idx] == '0')
    {
        ++idx;
    }

    if (idx >= len)
    {
        ret.size_ = 1;
        ret.x_[0] = 0;
        ret.sign_ = 1;
        return ret;
    }

    int p = 0;

    for (int i = len - 1; i >= idx; --i)
    {
        char c = s[i];

        if (c < '0' || c > '9')
        {
            continue;
        }

        if (p < 1000)
        {
            ret.x_[p++] = c - '0';
        }
    }

    ret.size_ = (p > 0) ? p : 1;
    normalize(ret);

    return ret;
}


LongInt get_longint(int v)
{
    LongInt ret;

    for (int i = 0; i < 1000; ++i)
    {
        ret.x_[i] = 0;
    }

    if (v == 0)
    {
        ret.size_ = 1;
        ret.sign_ = 1;
        ret.x_[0] = 0;
        return ret;
    }

    ret.sign_ = (v < 0) ? -1 : 1;

    long long av = v;

    if (av < 0)
    {
        av = -av;
    }

    int p = 0;

    while (av > 0 && p < 1000)
    {
        ret.x_[p++] = av % 10;
        av = av / 10;
    }

    ret.size_ = p;
    normalize(ret);
    return ret;
}


std::ostream & operator<<(std::ostream & out, const LongInt & I)
{
    if (I.size_ <= 0)
    {
        out << '0';
        return out;
    }

    if (I.size_ == 1 && I.x_[0] == 0)
    {
        out << '0';
        return out;
    }

    if (I.sign_ < 0)
    {
        out << '-';
    }

    for (int i = I.size_ - 1; i >= 0; --i)
    {
        out << I.x_[i];
    }

    return out;
}


bool operator==(const LongInt & a, const LongInt & b)
{
    if (a.sign_ != b.sign_)
    {
        bool za = (a.size_ == 1 && a.x_[0] == 0);
        bool zb = (b.size_ == 1 && b.x_[0] == 0);

        if (za && zb)
        {
            return true;
        }

        return false;
    }

    if (a.size_ != b.size_)
    {
        return false;
    }

    for (int i = 0; i < a.size_; ++i)
    {
        if (a.x_[i] != b.x_[i])
        {
            return false;
        }
    }

    return true;
}


bool operator!=(const LongInt & a, const LongInt & b)
{
    return !(a == b);
}


bool operator<(const LongInt & a, const LongInt & b)
{
    if (a.sign_ != b.sign_)
    {
        return a.sign_ < b.sign_;
    }

    if (a.size_ != b.size_)
    {
        if (a.sign_ > 0)
        {
            return a.size_ < b.size_;
        }
        else
        {
            return a.size_ > b.size_;
        }
    }

    for (int i = a.size_ - 1; i >= 0; --i)
    {
        if (a.x_[i] != b.x_[i])
        {
            if (a.sign_ > 0)
            {
                return a.x_[i] < b.x_[i];
            }
            else
            {
                return a.x_[i] > b.x_[i];
            }
        }
    }

    return false;
}


bool operator<=(const LongInt & a, const LongInt & b)
{
    return (a < b) || (a == b);
}


bool operator>(const LongInt & a, const LongInt & b)
{
    return !(a <= b);
}


bool operator>=(const LongInt & a, const LongInt & b)
{
    return !(a < b);
}


LongInt operator+(const LongInt & a, const LongInt & b)
{
    LongInt r;

    for (int i = 0; i < 1000; ++i)
    {
        r.x_[i] = 0;
    }

    r.size_ = 1;
    r.sign_ = 1;

    if (a.sign_ == b.sign_)
    {
        int n = (a.size_ > b.size_) ? a.size_ : b.size_;
        int carry = 0;

        for (int i = 0; i < n; ++i)
        {
            int av = (i < a.size_) ? a.x_[i] : 0;
            int bv = (i < b.size_) ? b.x_[i] : 0;
            int cur = av + bv + carry;

            r.x_[i] = cur % 10;
            carry = cur / 10;
        }

        r.size_ = n + (carry ? 1 : 0);

        if (carry)
        {
            r.x_[n] = carry;
        }

        r.sign_ = a.sign_;
        normalize(r);
        return r;
    }

    int cmp = 0;

    if (a.size_ < b.size_)
    {
        cmp = -1;
    }
    else if (a.size_ > b.size_)
    {
        cmp = 1;
    }
    else
    {
        for (int i = a.size_ - 1; i >= 0; --i)
        {
            if (a.x_[i] < b.x_[i])
            {
                cmp = -1;
                break;
            }

            if (a.x_[i] > b.x_[i])
            {
                cmp = 1;
                break;
            }
        }
    }

    if (cmp == 0)
    {
        r.size_ = 1;
        r.x_[0] = 0;
        r.sign_ = 1;
        return r;
    }

    const LongInt * larger = nullptr;
    const LongInt * smaller = nullptr;
    int result_sign = 1;

    if (cmp > 0)
    {
        larger = &a;
        smaller = &b;
        result_sign = a.sign_;
    }
    else
    {
        larger = &b;
        smaller = &a;
        result_sign = b.sign_;
    }

    int n = larger->size_;
    int borrow = 0;

    for (int i = 0; i < n; ++i)
    {
        int lv = larger->x_[i];
        int sv = (i < smaller->size_) ? smaller->x_[i] : 0;
        int cur = lv - sv - borrow;

        if (cur < 0)
        {
            cur += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        r.x_[i] = cur;
    }

    r.size_ = n;
    r.sign_ = result_sign;
    normalize(r);
    return r;
}


LongInt operator-(const LongInt & a, const LongInt & b)
{
    LongInt nb = b;
    nb.sign_ = -nb.sign_;
    return a + nb;
}


LongInt operator+(const LongInt & a, int b)
{
    return a + get_longint(b);
}


LongInt operator+(int a, const LongInt & b)
{
    return get_longint(a) + b;
}


LongInt operator-(const LongInt & a, int b)
{
    return a - get_longint(b);
}


LongInt operator-(int a, const LongInt & b)
{
    return get_longint(a) - b;
}
