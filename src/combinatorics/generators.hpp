

#include <cstddef>
#include <cstdint>
#include <iterator>
#include <stdexcept>
#include <type_traits>
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

        Combinations_iterator operator++();

        bool operator==(const Combinations_iterator& that);

        bool operator!=(const Combinations_iterator& that);
    };

    Combinations_iterator iterator{this};

   public:
    Combinations(uint64_t _n, uint64_t _r);

    Combinations_iterator& it() { return this->iterator; }

    Combinations_iterator end() { return Combinations_iterator(nullptr); }

   private:
    bool forward();
};

class Permutations {
   public:
    typedef std::vector<size_t> R_permutation;

   private:
    R_permutation current;
    Combinations comb;

    class Permutations_iterator
        : public std::iterator<std::forward_iterator_tag, const R_permutation> {
        Permutations* perm;
        friend class Permutations;

       private:
        explicit Permutations_iterator(Permutations* _perm) : perm(_perm) {}

       public:
        reference operator*() { return perm->current; }

        Permutations_iterator operator++();

        bool operator==(const Permutations_iterator& that);

        bool operator!=(const Permutations_iterator& that);
    };

    Permutations_iterator iterator{this};

    bool forward();

    void init_from_combination(const Combinations::R_combination& cb);

   public:
    Permutations(uint64_t _n, uint64_t _r);

    Permutations_iterator& it();

    Permutations_iterator end() { return Permutations_iterator{nullptr}; }
};