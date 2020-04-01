### "Pure Virtual Function Called" Bug

`2020-03-21`

总结学习一下最近遇到的core问题，主要是启动ranking服务core掉，shell显示"pure virtual method called"的问题

> 参考资料：<https://www.artima.com/cppsource/pure_virtual.html>

1. 运行ranking遇到"pure virtual method called"的core，拉有哥看了小两天，极大联系了分析gdb信息，和model那是如何使用智能指针如何继承的，最后发现是在BUILD中，链接的是别的目录的子目录Model下，未实现对应函数的`.a`。
2. 借这个bug，通过参考资料学习了一下，首先复习了虚函数，纯虚函数，继承和虚表的概念。
3. 练习了 `"Pure Virtual Function called": An Explanation` 里面5种导致pure virtual method called的习题。
4. 最终对CPP的继承，虚函数和虚表有了更清晰的认识，对相关gdb信息有了了解，以后遇到相同问题应该会有经验了。

------