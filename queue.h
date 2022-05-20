#include <vector>
#include <iostream>
#include <string>
#include <iterator>

namespace queue
{

    class QOverflow
    {
        
    public:
        std::string getMessage() const { return (msg_); }

    private:
        std::string msg_ = "Queue Overflowed!";
    };

    class QUnderflow
    {
        
    public:
        std::string getMessage() const { return (msg_); }

    private:
        std::string msg_ = "Queue Underflowed!";
    };

    template <typename T, int N>
    class Queue
    {
    private:
        std::vector<T> elems;

    public:
        Queue()
        {
            elems.reserve(N);
        }

        ~Queue()
        {
            elems.clear();
        }

        void enqueue(T value)
        {
            if (elems.size() < N)
            {
                elems.push_back(value);
                return;
            }

            QOverflow q;
            throw(q);
        }

        T dequeue()
        {
            if (!isEmpty())
            {
                T value = elems.front();
                elems.erase(elems.begin());
                return value;
            }

            QUnderflow q;
            throw(q);
        }

        size_t size()
        {
            return elems.size();
        }

        bool isEmpty()
        {
            return elems.empty();
        }

        friend std::ostream &operator<<(std::ostream &os, const Queue<T, N> &q)
        {
            for (auto &i : q.elems)
            {
                std::cout << i << " ";
            }

            return os;
        }

        template <typename U>
        Queue<U, N> cast()
        {
            
            Queue<U, N> casted;

            for (int i = 0; i < N; i++)
            {
                casted.enqueue(static_cast<U>(this->elems[i]));
            }

            return casted;
        }
    };
}
