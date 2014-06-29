 [https://oj.leetcode.com/problems/reverse-words-in-a-string/](https://oj.leetcode.com/problems/reverse-words-in-a-string/)

``` python
class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        return ' '.join([i for i in s.strip().split(' ') if i != ''][::-1])
```
