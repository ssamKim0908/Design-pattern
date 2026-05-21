#include "pattern.hpp"

RVectorI32::RVectorI32()
{
    ptr = rust_i32_vector_new();
}

RVectorI32::~RVectorI32()
{
    rust_i32_vector_delete(ptr);
}

void RVectorI32::push_back(int value)
{
    rust_i32_vector_push(ptr, value);
}

int RVectorI32::size()
{
    return static_cast<int>(rust_i32_vector_len(ptr));
}

int* RVectorI32::begin()
{
    return rust_i32_vector_data_start(ptr);
}

int* RVectorI32::end()
{
    return rust_i32_vector_data_start(ptr) + size();
}

int& RVectorI32::operator[](int index) const
{
    return rust_i32_vector_get(*ptr, index);
}