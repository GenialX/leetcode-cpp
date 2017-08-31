**Intuition**

If we want to output the result by reading line by line, we need to know the index of the each character. So how to find the specific index sequence of the characters which are read line by line is the what we focus on mainly.

**Algorithm**

Now we will try to resolve the problem as follow:

Firstly, we get the string `s`, such as "ABCDEFGHIJKLMNO...", and the three row `n`s each equals `3`, `4` and `5`, as shown below:


 - n = 3
```
A     E     I  
B  D  F  H  J
C     G     K
```

 - n = 4
```
A        G       M
B     F  H    L  N
C  E     I  K    O
D        J       P
```

 - n = 5
```
A         I         Q
B      H  J      P  R
C    G    K    O    S
D  F      L  N      T
E         M         U
```

Secondly, we need to find the index sequence while reading line by line. Obviously, the indexes of the firstly line are what as follow:

 - `0, 4, 8, 12` for `n = 3`;

 - `0, 6, 12` for `n = 4`;

 - `0, 8, 16` for `n = 5`.

Because:

 - For the `n = 3` case, the index of the `A` character equals `0`,  `E` equals `4`, `I` equals `8`;

 - For the `n = 4` case, the index of the `A` character equals `0`, `G` equals `6`, `M` equals `12`;

 - For the `n = 5` case, the index of the `A` character equals `0`, `I` equals `8`, `Q` equals `16`;

Now, we could get the conclusion that for the first line, the distance of numbers adjacent to each other is 2(n -1). So the index for the `k`th(k = 0, 1, 2...) element of the `i`th line could be expressed by expression that `2 * k (n - 1) + i`

Then, we could also get the same conclusion for the `n`th line, because the `n`th line is similar to the `0`th line.

Then, for the other lines(the `1`th to the `n - 1`th lines)， the difference between the `0`th or `n`th line case is that there is one more character, and the indexes of those are shown as follow:

For the `n = 4` case

 - The `2`th line, the `F` character's index equals `5`, `L` equals `11`;

 - The `3`th line, the `E` character's index equals `4`, `K` equals `10`;

So we could find the `one more` character's index is `2 * i` (`i` is the current line number, such as `2`, `3` and so one) less then the next number's.

Now, we could get the conclusion that for the `1`th to `n - 1`th lines, the index for the `k`th(k = 0, 1, 2...) element of the `i`th line could be expressed by expression that:

 - for the k % 2 == 0 case, the is similar to the `0`th or `n`th line, so the index is `k * (n - 1) + i`
 - for the k % 2 != 0 case, the index is `2 * i` less then the next element's. The next element's index is `(k + 1) * (n - 1) + i`, so the index of the current character which is before the next element is `(k + 1) * (n - 1) + i - 2 * i`, we get the expression that `(k + 1) * (n - 1) - i`;

Finally, the index of the characters which are read line by line `c_i` can be expressed as follow:

```c++
if (i == 0 || i == n - 1) {
  c_i = 2 * k * (n - 1) + i;
} else {
  c_i = (k % 2 == 0) ? k * (n - 1) + i : (k + 1) * (n - 1) - i;
}
```

**C++**

```c++
public class Solution {
    public string convert(string s, int n) {
      if (n == 1) return s;
      int l = s.length(), k = 0, c_i = 0;
      string r_s = "";
      for (int i = 0; i < n; ++i) {
          while(true) {
              if (i == 0 || i == n - 1) c_i = 2 * k * (n - 1) + i;
              else c_i = (k % 2 == 0) ? k * (n - 1) + i : (k + 1) * (n - 1) - i;
              if (c_i >= l) break;
              r_s.append(s, c_i, 1);
              ++k;
          }
          k = 0;
      }   
      return r_s;
    }
}
```

**Complexity Analysis**

* Time complexity : $O(n)$. The n is the length of the original string.

To calculate all the characters' index, we need to scan all of them. Thus, it costs $$O(n)$$ time.

* Space complexity : $O(n)$. The extra space required for storing the characters in String as well as returning them.
