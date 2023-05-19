#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>
#include <memory>

template <typename DataType>
class Vector
{
    int size;
    std::unique_ptr<DataType[]> vector;

public:
    Vector() : vector(nullptr), size(0) {}

    Vector(Vector<DataType> &v)
    {
        size = v.size;
        vector = std::make_unique<DataType[]>(size);
        for (int i = 0; i < size; i++)
            vector[i] = v[i];
    }

    ~Vector() {}

    void push(DataType value)
    {
        auto vector2 = std::make_unique<DataType[]>(size + 1);
        for (int i = 0; i < size; i++)
            vector2[i] = vector[i];
        vector2[size] = value;
        size++;
        vector = std::move(vector2);
    }

    void operator=(Vector<DataType> &v)
    {
        size = v.size;
        vector = std::make_unique<DataType[]>(size);

        for (int i = 0; i < size; i++)
            vector[i] = v.vector[i];
    }

    DataType &operator[](int i) const
    {
        return vector[i];
    }

    DataType *begin()
    {
        return vector.get();
    }

    DataType *end()
    {
        return vector.get() + size;
    }

    bool operator<(const DataType &other) const
    {
        return (*this) < other;
    }

    template <typename T>
    friend std::ostream &operator<<(std::ostream &out, const Vector<T> &v);

    template <typename T>
    friend std::istream &operator>>(std::istream &in, Vector<T> &v);
};

template <typename DataType>
std::ostream &operator<<(std::ostream &out, const Vector<DataType> &v)
{
    for (int i = 0; i < v.size; i++)
        out << v.vector[i] << " ";
    out << std::endl;
    return out;
}

template <typename DataType>
std::istream &operator>>(std::istream &in, Vector<DataType> &v)
{
    in >> v.size;
    v.vector = std::make_unique<DataType[]>(v.size);

    for (int i = 0; i < v.size; i++)
        in >> v.vector[i];
    return in;
}

#endif