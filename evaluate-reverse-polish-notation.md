 
 [https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/](https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/)

``` python
class Solution:
  # @param tokens, a list of string
  # @return an integer
  def evalRPN(self, tokens):
    stack = [];
    for item in tokens:
      if item.isdigit():
        stack.append(int(item))
      elif item[1:].isdigit() and item[0]=="-":
        stack.append(int(item))
      else:
        num2 = stack.pop()
        num1 = stack.pop()
        if item == "+":
          stack.append(num1+num2)
        elif item == "-":
          stack.append(num1-num2)
        elif item == "*":
          stack.append(num1*num2)
        elif item == "/":
          stack.append(int(float(num1)/num2))

    return stack[0]
```
