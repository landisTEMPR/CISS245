🧠 MEMORIZATION GUIDE — CISS245 Advanced Programming (Test t01)
Q1. Palindrome Function

Concept: String traversal and comparison.
Core idea: Compare s[i] with s[len-1-i].
Memory trick:

“Start at both ends, move to the middle, stop if mismatch.”

    Template:

    bool is_palindrome(const char s[]) {
        int n = strlen(s);
        for (int i = 0; i < n / 2; ++i)
            if (s[i] != s[n - 1 - i])
                return false;
        return true;
    }

Q2. Array Concatenation

Concept: Copying elements from one array into another.
Mental cue:

“Start writing Y right after X ends.”

Template:

void array_concat(int x[], int &x_len, int y[], int y_len) {
    for (int i = 0; i < y_len; ++i)
        x[x_len + i] = y[i];
    x_len += y_len;
}

Q3. Merge Two Sorted Arrays

Concept: Two-pointer merge technique.
Tip:

“Compare y[i] and z[j], put smaller in x.”

    Template:

    void merge(int x[], int &x_len, int y[], int y_len, int z[], int z_len) {
        int i = 0, j = 0, k = 0;
        while (i < y_len && j < z_len)
            x[k++] = (y[i] < z[j]) ? y[i++] : z[j++];
        while (i < y_len) x[k++] = y[i++];
        while (j < z_len) x[k++] = z[j++];
        x_len = k;
    }

Q4. Bubblesort (Pointers)

Concept: Repeated swapping via pointer traversal.
Memory line:

“Walk until end–1, swap if out of order.”

    Template:

    void bubblesort(int *start, int *end) {
        for (int *p = end; p != start; --p)
            for (int *q = start; q < p - 1; ++q)
                if (*q > *(q + 1))
                    std::swap(*q, *(q + 1));
    }

Q5. Binary Search (Pointers)

Concept: Divide-and-conquer with pointers.
Mnemonic:

“While still space, check middle.”

    Template:

    int *binarysearch(int *start, int *end, int target) {
    while (start < end) {
        int *mid = start + (end - start) / 2;
        if (*mid == target) return mid;
        else if (*mid < target) start = mid + 1;
        else end = mid;
    }
    return NULL;
    }

Q6. Function Overloading

Concept: Type ambiguity.
Shortcut:

“If all doubles, but only ints exist → ambiguous.”
    In this case, f(1.1, 3.3, 4.4) is ambiguous because no exact match.

    Q7. Pointer Dereference

    Program Flow:

    *p = *p + 2 * *q;


If a=2, b=3, → a = 2 + 2*3 = 8 → Output: 8 3

    Q8. Next Prime

    Concept: Increment until prime.
    Tip:

    “Add 1, test divisibility from 2 to √n.”

    Template:

    bool isPrime(int n) {
        for (int i = 2; i*i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }
    void nextprime(int *p) {
        int x = *p + 1;
        while (!isPrime(x)) ++x;
        *p = x;
    }

Q9. Function Overload with Pointer Return

Output reasoning:
*f(&i) returns 21, f(i) returns 21.
        *f(&i) + f(i) = 21 + 21 = 42.

        Q10. Pointer Chain Logic

        Use diagrams to track each pointer change.
        Tip: Write variables, arrows, update step by step.

        Q11. Fixing Memory Leaks

        Always delete what you new.
        Mnemonic:

        “Every ‘new’ must have a matching ‘delete’.”

        Q12. Ternary Pointer Check

        f(&a) → 42, f(NULL) → (x != NULL ? 42 : *x) = 42.
        Output: 42 42.

        Q13–Q15:

        All test pointer allocation and function call semantics:

        Always use int ** when passing pointer references.

        Always delete allocated memory after use.

        Remember: void my_new_operator(int **p) modifies the actual pointer.

        Q16. Fraction Addition Operator

        Formula:

        𝑎
        𝑏
        +
        𝑐
        𝑑
        =
        𝑎
        𝑑
        +
        𝑏
        𝑐
        𝑏
        𝑑
        b
        a
	​

        +
        d
        c
	​

        =
        bd
        ad+bc
	​


        Template:

        Fraction operator+(Fraction f, Fraction g) {
    Fraction r;
    r.n = f.n * g.d + g.n * f.d;
    r.d = f.d * g.d;
    return r;
}

Q17–Q19:

Emphasize struct syntax, memory safety, loop logic, and swap-by-pointer patterns.

    🔁 MASTER MEMORY THEMES

    Pointer = Address Manipulation

    *p → value

    &x → address

    p = &x → point to x

    *p = 42 → change x.

    Pass-by-Reference vs Pass-by-Pointer

    void f(int &x) → modifies directly.

    void f(int *p) → modifies via dereference.

    Dynamic Memory

    Allocate → new Type[size]

    Deallocate → delete[] ptr

    Arrays & Pointers

    x[i] == *(x+i)

    Use start and end pointers for iteration.

    Loops & Algorithms

    Bubble sort, merge, and binary search all rely on iteration and comparison.
