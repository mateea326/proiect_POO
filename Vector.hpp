#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>

template <typename DataType>
class Vector
{
    int size;
    DataType *vector;

public:
    Vector()
    {
        vector = nullptr;
        size = 0;
    }

    Vector(Vector<DataType> &v)
    {
        size = v.size;
        vector = new DataType[size];
        for (int i = 0; i < size; i++)
            vector[i] = v[i];
    }

    ~Vector()
    {
        delete[] vector;
    }

    void push(DataType value)
    {
        DataType *vector2 = new DataType[size + 1];
        for (int i = 0; i < size; i++)
            vector2[i] = vector[i];
        vector2[size] = value;
        size++;
        delete[] vector;
        vector = vector2;
    }

    void operator=(Vector<DataType> &v)
    {
        if (vector != nullptr)
            delete[] vector;

        size = v.size;
        vector = new DataType[size];

        for (int i = 0; i < size; i++)
            vector[i] = v.vector[i];
    }

    DataType &operator[](int i) const
    {
        return vector[i];
    }

    template <typename T>
    friend std::ostream &operator<<(std::ostream &out, const Vector<T> &v);

    template <typename T>
    friend std::istream &operator>>(std::istream &in, Vector<T> &v);

    friend class Playlist;
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
    delete[] v.vector;
    v.vector = new DataType[v.size];
    for (int i = 0; i < v.size; i++)
        in >> v.vector[i];
    return in;
}

#endif