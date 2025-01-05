

#include <cstddef>
#include <cstdint>
#include <iterator>
#include <stdexcept>
#include <vector>

class Combinations {
   public:
    typedef std::vector<bool> R_combination;

   private:
    uint64_t n{0};
    uint64_t r{0};
    R_combination current{};

    class Combinations_iterator
        : public std::iterator<std::forward_iterator_tag, const R_combination> {
        Combinations* comb;
        friend class Combinations;

       private:
        explicit Combinations_iterator(Combinations* _comb) : comb(_comb) {}

       public:
        reference operator*() { return comb->current; }

        Combinations_iterator operator++(int) {
            if (!comb->forward()) {
                this->comb = nullptr;
            }
            return *this;
        }

        Combinations_iterator operator++() {
            (*this)++;
            return *this;
        }

        bool operator==(const Combinations_iterator& that) {
            return this->comb == that.comb;
        }

        bool operator!=(const Combinations_iterator& that) {
            return this->comb != that.comb;
        }
    };

    Combinations_iterator iterator{this};

   public:
    Combinations(uint64_t _n, uint64_t _r);

    Combinations_iterator begin() { return this->iterator; }

    Combinations_iterator end() { return Combinations_iterator(nullptr); }

   private:
    bool forward();
};