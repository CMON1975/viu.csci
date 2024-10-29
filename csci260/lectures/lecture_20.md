# Skip List

A **Skip List** is a data structure that implements a **Dictionary** (lookUp, insert, remove). It assumes that random numbers can be generated easily in any computer systems and uses randomization in its structure.

The expected worst case performance of a skip list is similar to that of an AVL tree.

A skip list S for dictionary D consists of a series of lists {$S_0, S_1, ..., S_h$} where $S_0$ constains every item of D plus the two special items with keys $-∞$ and $+∞$. For $1 \le i \le (h-1)$, list $S_i$ contains a randomly generated subset (usually half) of the items in list $S_{i-1}$ plus the two special items. List $S_h$ contains only the two special items.

Traversal operations in skip list:
- **`after(p)`:** goes to the position following `p` on the same level.
- **`before(p)`:** goes to the position preceding `p` on the same level.
- **`below(p)`:** goes to the position below `p` on the same level.
- **`above(p)`:** goes to the position above `p` on the same level.

Main operations:
- `Search(k)`
    ```cpp
    Position * SkipSearch(k)
    {
        initialize p to be the top-most and left position of the skip list
        (i.e., p is placed on the left node of S_h)
        while (p->below != nullptr) {
            p = p->below;
            while (p->after->key <= k) {
                p = p->after;
            }
        }
        return p;
    }
    ```
- `Lookup(k)`
    ```cpp
    Data SkipLookup(k)
    {
        p = SkipSearch(k);
        if (p->key == k)
            return p->data;
        else
            throw "no such item" exception;
    }
    ```
- `Insert(k, obj)`
    ```cpp
    void SkipInsert(k, obj)
    {
        p = SkipSearch(k);
        if (p->key == k)
            throw "duplicate key" exception;
        else {
            th = 0; // tree height
            q = insertAfterAbove(p, nullptr, (k, obj));
            while (th < k && random() < 0.5) {
                while (p->above == nullptr)
                    p = p->before;
                p = p->above;
                q = insertAfterAbove(p, q, (k, nullptr));
                ++th;
            }
            if (th == h) {
                add a new top list; // minus to positive infinity
                ++h;
            }
        }
    }
    ```

The probability that the height of the newly inserted tower rises to $h$ is $2^h$.

- `Remove(k)`
    ```cpp
    Data & SkipRemove(k)
    {
        p = SkipSearch(k);
        if (p->k != k)
            throw "no such item" exception;
        else {
            Data *temp = p->obj;
            Position *q;
            // delete the whole tower
            while (p != nullptr) {
                p->before->after = p->after;
                p->after->before = p->before;
                q = p;
                p = p->above;
                delete q;
            }
            return (*temp);
        }
    }