// File : LongInt.cpp
// Author : Brysen Landis

#include "LongInt.h"


static void normalize(LongInt & r)
{
    int s = r.size_;
    
    while (s > 1 && r.x_[s - 1] == 0) { --s; }
    r.size_ = (s >= 1) ? s : 1;
    if (r.size_ == 1 && r.x_[0] == 0) { r.sign_ = 1; }
}


// Compare absolute values. Return -1 if |a| < |b|, 0 if equal, +1 if |a| > |b|.
static int cmpAbs(const LongInt & a, const LongInt & b)
{
    if (a.size_ < b.size_) { return -1; }
    if (a.size_ > b.size_) { return 1; }
    
    for (int i = a.size_ - 1; i >= 0; --i)
    {
        if (a.x_[i] < b.x_[i]) { return -1; }
        if (a.x_[i] > b.x_[i]) { return 1; }
    }
    return 0;
}


// Compute r = |a| - |b| assuming |a| >= |b|. r.sign_ will not be set here.
static void subtractAbsInto(const LongInt & a, const LongInt & b, LongInt & r)
{
    int n = a.size_;
    r.size_ = n;
    int borrow = 0;
    for (int i = 0; i < n; ++i)
    {
        int av = a.x_[i];
        int bv = (i < b.size_) ? b.x_[i] : 0;
        int cur = av - bv - borrow;
        if (cur < 0)
        {
            cur += 10;
            borrow = 1;
        }
        else { borrow = 0; }
        r.x_[i] = cur;
    }
    normalize(r);
}


// Compute r = |a| + |b|.
static void addAbsInto(const LongInt & a, const LongInt & b, LongInt & r)
{
    int n = (a.size_ > b.size_) ? a.size_ : b.size_; // max
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
    if (carry) { r.x_[n] = carry; }
    normalize(r);
}


// finds length of int
static int strlen(const char * s)
{
    if (s == 0) { return 0; }
    int len = 0;
    while (s[len] != '\0') { ++len; }
    return len;
}


// takes user input and returns longint
LongInt get_LongInt(const char s[])
{
    LongInt ret;
    // initialize digits to zero
    for (int i = 0; i < 1000; ++i) { ret.x_[i] = 0; }
    ret.size_ = 1;
    ret.sign_ = 1;

    if (s == 0) { return ret; }

    int len = strlen(s);
    if (len == 0) { return ret; }

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

    // skip leading zeros
    while (idx < len && s[idx] == '0') { ++idx; }
    if (idx >= len)
    {
        // the number is zero
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
        if (p < 1000) { ret.x_[p++] = (c - '0'); }
    }
    ret.size_ = (p > 0) ? p : 1;
    normalize(ret);
    
    return ret;
}


LongInt get_LongInt(int v)
{
    LongInt ret;
    for (int i = 0; i < 1000; ++i) { ret.x_[i] = 0; }
    if (v == 0)
    {
        ret.size_ = 1; ret.sign_ = 1; ret.x_[0] = 0;
        return ret;
    }
    ret.sign_ = (v < 0) ? -1 : 1;
    long long av = v;
    if (av < 0) { av = -av; }
    int p = 0;
    while (av > 0 && p < 1000)
    {
        ret.x_[p++] = static_cast<int>(av % 10);
        av /= 10;
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
    if (I.sign_ < 0) out << '-';
    for (int i = I.size_ - 1; i >= 0; --i) { out << I.x_[i]; }
    return out;
}


// comparisons
bool operator==(const LongInt & a, const LongInt & b)
{
    if (a.sign_ != b.sign_)
    {
        bool za = (a.size_ == 1 && a.x_[0] == 0);
        bool zb = (b.size_ == 1 && b.x_[0] == 0);
        if (za && zb) { return true; }
        return false;
    }
    if (a.size_ != b.size_) { return false; }
    for (int i = 0; i < a.size_; ++i)
    {
        if (a.x_[i] != b.x_[i]) { return false; }
    }
    return true;
}


bool operator!=(const LongInt & a, const LongInt & b)
{
    return !(a == b);
}


bool operator<(const LongInt & a, const LongInt & b)
{
    if (a.sign_ != b.sign_) { return a.sign_ < b.sign_; }
    int absCmp = cmpAbs(a, b);
    if (a.sign_ > 0)
    {
        return absCmp < 0;
    }
    else
    {
        return absCmp > 0;
    }
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


// Arithmetic
LongInt operator+(const LongInt & a, const LongInt & b)
{
    LongInt r;
    for (int i = 0; i < 1000; ++i) { r.x_[i] = 0; }
    r.size_ = 1; r.sign_ = 1;

    if (a.sign_ == b.sign_)
    {
        addAbsInto(a, b, r);
        r.sign_ = a.sign_;
        normalize(r);
        return r;
    }

    int cmp = cmpAbs(a, b);
    if (cmp == 0)
    {
        // cancel out to zero
        r.size_ = 1; r.x_[0] = 0; r.sign_ = 1;
        return r;
    }
    if (cmp > 0)
    {
        subtractAbsInto(a, b, r);
        r.sign_ = a.sign_;
        normalize(r);
        return r;
    }
    else
    {
        subtractAbsInto(b, a, r);
        r.sign_ = b.sign_;
        normalize(r);
        return r;
    }
}


LongInt operator-(const LongInt & a, const LongInt & b)
{
    LongInt nb = b;
    nb.sign_ = -nb.sign_;
    return a + nb;
}


// int overloads
LongInt operator+(const LongInt & a, int b)
{
    return a + get_LongInt(b);
}


LongInt operator+(int a, const LongInt & b)
{
    return get_LongInt(a) + b;
}


LongInt operator-(const LongInt & a, int b)
{
    return a - get_LongInt(b);
}


LongInt operator-(int a, const LongInt & b)
{
    return get_LongInt(a) - b;
}
