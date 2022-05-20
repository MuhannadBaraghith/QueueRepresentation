#include "queue.h"
#include <iostream>
int main()
{


    const int N = 2;

    queue::Queue<int, N> q;
    for (int i = 0; i < 4; i++)
    {
        try
        {
            q.enqueue(67 + i);
        }
        catch (queue::QOverflow &e)
        {
            std::cout << e.getMessage() << std::endl;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        try
        {
            std::cout << q.dequeue() << std::endl;
        }
        catch (queue::QUnderflow &e)
        {
            std::cout << e.getMessage() << std::endl;
        }
    }

    std::cout << q << std::endl;
    std::cout << q.size() << std::endl;

    q.enqueue(67);
    q.enqueue(68);
    
    int x = 5;
    x = cast(float);
    queue::Queue<double, N> casted = q.cast<double>();

    for (int i = 0; i < N; i++)
    {
        std::cout << casted.dequeue() << std::endl;
    }
}
