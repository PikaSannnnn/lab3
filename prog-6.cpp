#include <iostream>

struct array
{
    int * data;
    size_t n;

    array()
        :data(0), n(0)
    {
    }

    array(size_t size)
        :data(), n(size)
    {
        data = new int[n];
    }

    array& operator=(const array& cop) {
        n = cop.n;
        data = new int [n];

        for (size_t i = 0; i < n; i++) {
            data[i] = cop[i];
        }

        return *this;
    }

    const int& operator[](size_t i) const
    {
        return data[i];
    }

    int& operator[](size_t i)
    {
        return data[i];
    }
    
    const array operator + (const array& c) const
    {
        array r(n);
        for(size_t i = 0; i < n; i++)
            r[i] = data[i] + c[i];
        return r;
    }

    const array operator - (const array& c) const
    {
        array r(n);
        for(size_t i = 0; i < n; i++)
            r[i] = data[i] - c[i];
        return r;
    }
};

void print(const array& c)
{
    std::cout << "( ";
    for(size_t i = 0; i < c.n; i++)
        std::cout << c[i] << " ";
    std::cout << ")" << std::endl;
}

// template<class T>
void print(double x, std::string extra = "\n")
{
    std::cout << x << extra;
}

int main()
{
    array a(2);
    a[0] = 4;
    a[1] = 5;
    print(a);

    array b(2);
    b[0] = 7;
    b[1] = 9;
    print(b);

    array c = a + b;
    array d = c - a;

    print(c);
    print(d);
    std::cout <<  "f\n" << std::endl;

    print(0, ", ");
    print(1);

    return 0;
}

