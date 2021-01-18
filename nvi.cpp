#include <iostream>

struct base
{
    void read_from(std::istream &in)
    {
        read_from_impl(in);
    }

    void write_to(std::ostream &out)
    {
        write_to_impl(out);
    }

    virtual ~base() = default;

private:
    virtual void read_from_impl(std::istream &) = 0;
    virtual void write_to_impl(std::ostream &) = 0;
};

struct derived : base
{
private:
    void read_from_impl(std::istream &in) override
    {
        std::cout << "read_from_derived_impl" << std::endl;
    }

    void write_to_impl(std::ostream &out) override
    {
        std::cout << "write_to_derived_impl" << std::endl;
    }
};

int main()
{
    derived d;
    d.read_from(std::cin);
    d.write_to(std::cout);
}