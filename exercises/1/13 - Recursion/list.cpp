#include <iostream>
#include <utility>
#include <algorithm>

/*
[1, 2, 3, 4] -> head, tail
head: 1
tail [2, 3, 4]
int * first, int * last

head: *first
tail: firt+1, last
empty?: first == last

*/

int sum(const int * first, const int * last)
{
    if (first == last)
    {
        return 0;
    }

    return *first + sum(first + 1, last);
}

/*
sum(list)
sum([]) = 0
sum([head, tail]) = head + sum(tail)
*/

const int * find(const int * first, const int * last, int element)
{
    if (first == last)
    {
        return last;
    }

    if (*first == element)
    {
        return first;
    }

    return find(first + 1, last, element);
}

/*
find([], element) -> last (няма го)
find([head, tail], element)
 -> head == element -> return first
 -> head != element -> find(tail, element)

 find(1, [2,3], 2)
*/

bool equal(const int * first1, const int * last1, const int * first2)
{
    if (first1 == last1)
    {
        return true;
    }

    if (*first1 != *first2)
    {
        return false;
    }

    return equal(first1 + 1, last1, first2 + 1);
}

/*
equal([], []) -> true
equal([head1, tail1], [head2, tail2])
 -> head1 != head2 -> false
 -> head1 == head2 -> equal(tail1, tail2)

 (1:[2,3]), (1:[2,3])
*/

int * min_element(int * first, int * last)
{
    if (last - first < 2)
    {
        return first;
    }

    int * min_rest{
        min_element(first + 1, last)
    };

    return *first <= *min_rest ? first : min_rest;
}

/*
min_element(head:[]) -> head
min_element(head:tail) -> min(head, min_element(tail))
*/

void selection_sort(int * first, int * last)
{
    if (first != last)
    {
        std::iter_swap(first, min_element(first, last));
        selection_sort(first + 1, last);
    }
}

int * lower_bound(int * first, int * last, int element)
{
    if (first == last)
    {
        return first;
    }

    int * mid{
        first + (last - first) / 2
    };

    return *mid < element ?
        lower_bound(mid + 1, last, element) :
        lower_bound(first, mid, element);
}

void insertion_sort(int * first, int * last)
{
    if (first != last)
    {
        insertion_sort(first + 1, last);
        std::rotate(first, first + 1, lower_bound(first + 1, last, *first));
    }
}

int main()
{
    int arr[]{1, 0, 4, 2, 5, 3};
    insertion_sort(std::begin(arr), std::end(arr));

    for (int x : arr)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    return 0;
}