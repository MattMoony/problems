# Hotel Queries
_[Task 1143](https://cses.fi/problemset/task/1143) - 1.00s, 512MB_

---

## About

There are multiple hotels, each with an individual amount of free rooms, and multiple tourist groups, each with an individual demand for hotel rooms. The task is to assign every tourist group to the first hotel with enough free rooms to fulfill the group's requirements.

### Input

```txt
n m             // n -> the amount of hotels, m -> the amount of tourist groups
h1 h2 ... hn    // hi -> the number of free rooms for hotel i
r1 r2 ... rm    // ri -> the number of required rooms for tourist group i
```

### Output

The assigned hotel for every tourist group. If there is no hotel that meets the requirements (anymore), `0` should be printed instead.

### Example

Input:

```txt
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1
```

Output:

```txt
3 5 0 1 1
```

## Approach

The hotels and their number of free rooms can be represented using a `maximum segment tree`:

![Maximum Segment Tree](https://g.gravizo.com/svg?digraph%20G%20%7B%0A%20%20%20%20edge%20%5Bdir%3Dnone%5D%3B%0A%20%20%20%20a%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20b%20%5Blabel%3D%3C4%3CSUB%3E3%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20c%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20d%20%5Blabel%3D%3C3%3CSUB%3E1%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20e%20%5Blabel%3D%3C4%3CSUB%3E3%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20f%20%5Blabel%3D%3C5%3CSUB%3E5%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20g%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20h%20%5Blabel%3D%3C3%3CSUB%3E1%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20i%20%5Blabel%3D%3C2%3CSUB%3E2%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20j%20%5Blabel%3D%3C4%3CSUB%3E3%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20k%20%5Blabel%3D%3C1%3CSUB%3E4%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20l%20%5Blabel%3D%3C5%3CSUB%3E5%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20m%20%5Blabel%3D%3C5%3CSUB%3E6%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20n%20%5Blabel%3D%3C2%3CSUB%3E7%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20o%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20a%20-%3E%20b%20%5Blabel%3D%224%22%5D%3B%0A%20%20%20%20b%20-%3E%20d%20%5Blabel%3D%223%22%5D%3B%0A%20%20%20%20d%20-%3E%20h%20%5Blabel%3D%223%22%5D%3B%0A%20%20%20%20d%20-%3E%20i%20%5Blabel%3D%222%22%5D%3B%0A%20%20%20%20b%20-%3E%20e%20%5Blabel%3D%224%22%5D%3B%0A%20%20%20%20e%20-%3E%20j%20%5Blabel%3D%224%22%5D%3B%0A%20%20%20%20e%20-%3E%20k%20%5Blabel%3D%221%22%5D%3B%0A%20%20%20%20a%20-%3E%20c%20%5Blabel%3D%226%22%5D%3B%0A%20%20%20%20c%20-%3E%20f%20%5Blabel%3D%225%22%5D%3B%0A%20%20%20%20f%20-%3E%20l%20%5Blabel%3D%225%22%5D%3B%0A%20%20%20%20f%20-%3E%20m%20%5Blabel%3D%225%22%5D%3B%0A%20%20%20%20c%20-%3E%20g%20%5Blabel%3D%226%22%5D%3B%0A%20%20%20%20g%20-%3E%20n%20%5Blabel%3D%222%22%5D%3B%0A%20%20%20%20g%20-%3E%20o%20%5Blabel%3D%226%22%5D%3B%0A%7D)

Then, all one has to do in order to get the index of the hotel the group should be assigned to, is query the segment tree in the following way:

1. If the value of the root node is less than the group's requirement, print `0` - no hotel can provide the necessary amount of rooms
2. Start at the root node (here: `[value=6, index=8]`)
3. If the current value is equal to the group's requirement or the current node has no children, the hotel is the current index
4. Look at the children:
   1. If the left child's value is `>=` the group's requirement, continue at `2.` with the left child
   2. Otherwise, continue at `2.` with the right child

After such a query, the amount of required rooms has to be subtracted from the amount of available rooms and the segment tree has to be updated accordingly:

1. Start at the node to-be-updated
2. Subtract the amount of required rooms from the current value
3. Go to the parent node
4. Recompute the node's value and index by using the updated children
5. Continue at `5.`

### Example

* **Group size**: 4
* **Hotel rooms**: 3 2 4 1 5 5 2 6

Query for the hotel index ...

![Maximum Segment Tree Query](https://g.gravizo.com/svg?digraph%20G%20%7B%0A%20%20%20%20edge%20%5Bdir%3Dnone%5D%3B%0A%20%20%20%20a%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%2Ccolor%3Dred%5D%3B%0A%20%20%20%20b%20%5Blabel%3D%3C4%3CSUB%3E3%3C%2FSUB%3E%3E%2Ccolor%3Dred%5D%3B%0A%20%20%20%20c%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20d%20%5Blabel%3D%3C3%3CSUB%3E1%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20e%20%5Blabel%3D%3C4%3CSUB%3E3%3C%2FSUB%3E%3E%2Ccolor%3Dred%5D%3B%0A%20%20%20%20f%20%5Blabel%3D%3C5%3CSUB%3E5%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20g%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20h%20%5Blabel%3D%3C3%3CSUB%3E1%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20i%20%5Blabel%3D%3C2%3CSUB%3E2%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20j%20%5Blabel%3D%3C4%3CSUB%3E3%3C%2FSUB%3E%3E%2Ccolor%3Dred%5D%3B%0A%20%20%20%20k%20%5Blabel%3D%3C1%3CSUB%3E4%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20l%20%5Blabel%3D%3C5%3CSUB%3E5%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20m%20%5Blabel%3D%3C5%3CSUB%3E6%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20n%20%5Blabel%3D%3C2%3CSUB%3E7%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20o%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20a%20-%3E%20b%20%5Blabel%3D%224%22%2Ccolor%3Dred%5D%3B%0A%20%20%20%20b%20-%3E%20d%20%5Blabel%3D%223%22%5D%3B%0A%20%20%20%20d%20-%3E%20h%20%5Blabel%3D%223%22%5D%3B%0A%20%20%20%20d%20-%3E%20i%20%5Blabel%3D%222%22%5D%3B%0A%20%20%20%20b%20-%3E%20e%20%5Blabel%3D%224%22%2Ccolor%3Dred%5D%3B%0A%20%20%20%20e%20-%3E%20j%20%5Blabel%3D%224%22%2Ccolor%3Dred%5D%3B%0A%20%20%20%20e%20-%3E%20k%20%5Blabel%3D%221%22%5D%3B%0A%20%20%20%20a%20-%3E%20c%20%5Blabel%3D%226%22%5D%3B%0A%20%20%20%20c%20-%3E%20f%20%5Blabel%3D%225%22%5D%3B%0A%20%20%20%20f%20-%3E%20l%20%5Blabel%3D%225%22%5D%3B%0A%20%20%20%20f%20-%3E%20m%20%5Blabel%3D%225%22%5D%3B%0A%20%20%20%20c%20-%3E%20g%20%5Blabel%3D%226%22%5D%3B%0A%20%20%20%20g%20-%3E%20n%20%5Blabel%3D%222%22%5D%3B%0A%20%20%20%20g%20-%3E%20o%20%5Blabel%3D%226%22%5D%3B%0A%7D)

... by following the query algorithm specified above, hotel `3` will be chosen as the group's residence.

Update the segment tree ...

![Maximum Segment Tree Update](https://g.gravizo.com/svg?digraph%20G%20%7B%0A%20%20%20%20edge%20%5Bdir%3Dnone%5D%3B%0A%20%20%20%20a%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%2Ccolor%3Dred%5D%3B%0A%20%20%20%20b%20%5Blabel%3D%3C3%3CSUB%3E1%3C%2FSUB%3E%3E%2Ccolor%3Dred%5D%3B%0A%20%20%20%20c%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%2Ccolor%3Dblue%5D%3B%0A%20%20%20%20d%20%5Blabel%3D%3C3%3CSUB%3E1%3C%2FSUB%3E%3E%2Ccolor%3Dblue%5D%3B%0A%20%20%20%20e%20%5Blabel%3D%3C1%3CSUB%3E4%3C%2FSUB%3E%3E%2Ccolor%3Dred%5D%3B%0A%20%20%20%20f%20%5Blabel%3D%3C5%3CSUB%3E5%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20g%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20h%20%5Blabel%3D%3C3%3CSUB%3E1%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20i%20%5Blabel%3D%3C2%3CSUB%3E2%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20j%20%5Blabel%3D%3C0%3CSUB%3E3%3C%2FSUB%3E%3E%2Ccolor%3Dred%5D%3B%0A%20%20%20%20k%20%5Blabel%3D%3C1%3CSUB%3E4%3C%2FSUB%3E%3E%2Ccolor%3Dblue%5D%3B%0A%20%20%20%20l%20%5Blabel%3D%3C5%3CSUB%3E5%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20m%20%5Blabel%3D%3C5%3CSUB%3E6%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20n%20%5Blabel%3D%3C2%3CSUB%3E7%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20o%20%5Blabel%3D%3C6%3CSUB%3E8%3C%2FSUB%3E%3E%5D%3B%0A%20%20%20%20a%20-%3E%20b%20%5Blabel%3D%224%22%2Ccolor%3Dred%5D%3B%0A%20%20%20%20b%20-%3E%20d%20%5Blabel%3D%223%22%2Ccolor%3Dblue%5D%3B%0A%20%20%20%20d%20-%3E%20h%20%5Blabel%3D%223%22%5D%3B%0A%20%20%20%20d%20-%3E%20i%20%5Blabel%3D%222%22%5D%3B%0A%20%20%20%20b%20-%3E%20e%20%5Blabel%3D%224%22%2Ccolor%3Dred%5D%3B%0A%20%20%20%20e%20-%3E%20j%20%5Blabel%3D%224%22%2Ccolor%3Dred%5D%3B%0A%20%20%20%20e%20-%3E%20k%20%5Blabel%3D%221%22%2Ccolor%3Dblue%5D%3B%0A%20%20%20%20a%20-%3E%20c%20%5Blabel%3D%226%22%2Ccolor%3Dblue%5D%3B%0A%20%20%20%20c%20-%3E%20f%20%5Blabel%3D%225%22%5D%3B%0A%20%20%20%20f%20-%3E%20l%20%5Blabel%3D%225%22%5D%3B%0A%20%20%20%20f%20-%3E%20m%20%5Blabel%3D%225%22%5D%3B%0A%20%20%20%20c%20-%3E%20g%20%5Blabel%3D%226%22%5D%3B%0A%20%20%20%20g%20-%3E%20n%20%5Blabel%3D%222%22%5D%3B%0A%20%20%20%20g%20-%3E%20o%20%5Blabel%3D%226%22%5D%3B%0A%7D)

... by following the update algorithm above, the segment tree will be updated properly -> re-assigning the maxima for ranges `3-4` and `1-4`, the maximum of `1-8` stays the same.

## References

* [Gravizo](http://www.gravizo.com/) - For creating such lovely graphs in GitHub Markdown files.
* [CSES](https://cses.fi/problemset/task/1143) - For the original task description and other problems.
