#include <cstddef>
#include <utility>
#include <cassert>

class Mtx {};

class Mtxs {
public:
    Mtxs();
    explicit Mtxs(size_t k);

    Mtxs(const Mtxs& rhs);
    Mtxs(Mtxs&& rhs) noexcept;

    ~Mtxs();

    Mtxs& operator=(const Mtxs& rhs);
    Mtxs& operator=(Mtxs&& rhs) noexcept;

private:
    size_t k_;
    Mtx* mtxs_;
};


Mtxs::Mtxs():
    k_(0),
    mtxs_(nullptr)
{}

Mtxs::Mtxs(size_t k):
    k_(k),
    mtxs_(new Mtx[k])
{}

Mtxs::Mtxs(const Mtxs& rhs):
    Mtxs(rhs.k_)
{
    for (size_t i = 0; i < k_; ++i) {
        mtxs_[i] = rhs.mtxs_[i];
    }
}

Mtxs::Mtxs(Mtxs&& rhs) noexcept:
    k_(rhs.k_),
    mtxs_(rhs.mtxs_)
{
    rhs.k_ = 0;
    rhs.mtxs_ = nullptr;
}

Mtxs::~Mtxs() {
    delete[] mtxs_;
}

Mtxs& Mtxs::operator=(const Mtxs& rhs) {
    if (this != &rhs) {
        Mtxs temp(rhs);
        swap(temp);
    }

    return *this;
}

Mtxs& Mtxs::operator=(Mtxs&& rhs) noexcept {
    if (this != &rhs) {
        delete[] mtxs_;

        k_ = rhs.k_;
        mtxs_ = rhs.mtxs_;

        rhs.k_ = 0;
        rhs.mtxs_ = nullptr;
    }

    return *this;
}