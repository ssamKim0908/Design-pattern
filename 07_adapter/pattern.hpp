#pragma once

#include "../common_header.hpp"
#include <cstdint>

struct RustI32Vector;

extern "C"
{
    RustI32Vector*  rust_i32_vector_new();
    void            rust_i32_vector_delete(RustI32Vector*);
    void            rust_i32_vector_push(RustI32Vector*, int);
    int&            rust_i32_vector_get(RustI32Vector&, int);
    size_t          rust_i32_vector_len(RustI32Vector*);
    int*            rust_i32_vector_data_start(RustI32Vector*);
};

class RVectorI32
{
private:
    RustI32Vector* ptr;
public:
    RVectorI32();
    ~RVectorI32();

    void push_back(int value);
    int  size();
    int* begin();
    int* end();

    int& operator[](int index) const;
};