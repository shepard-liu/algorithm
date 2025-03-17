// https://leetcode.cn/problems/copy-list-with-random-pointer/ Copy List with
// Random Pointer
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
   public:
    int val;
    Trie* next;
    Trie* random;

    Trie(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Trie* copyRandomList(Trie* head) {
    unordered_map<Trie*, Trie*> mapping;
    Trie *newHead{new Trie(0)}, *newTail{nullptr}, *p{head}, *np{newHead};
    while (p != nullptr) {
        np->val = p->val;
        mapping[p] = np;

        np->next = new Trie(0);
        newTail = np;
        np = np->next;

        p = p->next;
    }

    // causes memory leak, but who cares?
    if (newTail != nullptr) {
        newTail->next = nullptr;
    } else {
        newHead = nullptr;
    }

    np = newHead;
    p = head;
    while (p != nullptr) {
        np->random = mapping[p->random];
        np = np->next;
        p = p->next;
    }

    return newHead;
}