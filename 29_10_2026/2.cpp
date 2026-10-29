#include <iostream>
struct ints {};

struct int_view {
    int_view();
    int_view(int* b, size_t sz);
    int_view(int* b, int* e);
    ~int_view() = default;

    size_t get_size() const;

    private:
        int* begin;
        size_t size;
    
};

size_t int_view::get_size() const {
    return size;
}
int_view::int_view(int *b, size_t sz): begin(b), size(sz) {}
int_view::int_view(int *b, int *e): begin(b), size(e - b) {}
int_view::int_view(): begin(nullptr), size(0) {}

void count(int_view a) {}
int b[10] = {};
int main() {
    int a[10] = {};
    int* c = new int[10];

    int_view a1{a, 10};
    int_view a2{b, 10};
    int_view a3{c, 10};

    delete[] c;
}

