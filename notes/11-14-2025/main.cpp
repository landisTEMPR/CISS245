#include <iostream>

int max(int x[], int start, int end)
{
    if (start == end - 1)
    {
        // base case
        std::cout << "MAX: " << start << ' ' << end
                  << " ... base case ... return " << x[start] << '\n';
        return x[start];
    }
    else
    {
        // recursive case
         std::cout << "MAX: " << start << ' ' << end
                  << " ... recursive case ... " << '\n';
        int m = max(x, start + 1, end);
        std::cout << "MAX: " << start << ' ' << end
                  << " ... recursive case ... returning " <<
                   (x[start] >= m ? x[start] : m)<< '\n';
       
        return (x[start] >= m ? x[start] : m);
    }
}


int linsrch(int x[], int start, int end, int target)
{
    if (start == end)
    {
        // base case: i.e. x[start ... end - 1] is an empty array
        return -1;
    }
    else
    {
        // recursive case
        if (x[start] == target) return start;
        else return linsrch(x, start + 1, end, target);
    }
}

int sum(int x[], int start, int end)
{
    if (start == end) return 0;
    else
    {
        return sum(x, start + 1, end) + x[start];
    }
}


int count(int x[], int start, int end, int target)
{
    if (start == end) return 0;
    else
    {
        return count(x, start + 1, end, target) + (x[start] == target ? 1 : 0);
    }
}


bool ispalindrome(char x[], start, end)
{
    if (start >= end) return true;
    else
    {
        if (x[start] != x[end - 1]) return false;
        else ispalindrome(x, start + 1, end - 1);
    }
}
// SO ITS LIKE A HOUSE OF CARDS WHERE THE FUNCTION KEEPS CALLING ITSELF AND BUILDS LIKE A HOUSE OF CARDS AND THEN THE BASE CASE IS LIKE SOMEONE KNOCKING IT OVER AND THE SCOPES THAT WERE OPEN FOR EACH CALL OF THE FUNCTION START COLLAPSING FROM THE MOST RECENT TO OLDEST CALL.

int main()
{
    int x[] = {5, 3, 1, 2, 4, 6, 2, 2, 9, 8, 7, 2};
    int m = max(x, 1, 7);
    std::cout << "MAX: " << m << '\n';

    std::cout << "TARGET FOUND AT: " << linsrch(x, 1, 7, 2) << '\n';

    std::cout << "COUNTING: " << count(x, 0, 15, 2) << '\n';

    std::cout << "SUM: " << sum(x, 0, 11) << '\n';

    return 0;
}
