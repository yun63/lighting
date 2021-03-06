
设计原则
========

## 1 单一职责原则(SRP)

一个类应该只有一个导致其变化的原因
 
> 一个职责就是一个独立变化的原因
> 一个类如果承担过多的职责，就等于把这些职责耦合在一起

## 2 开放封闭原则(OCP)

对扩展是开放的，对更改是封闭的

> 对扩展开放：应用需求变化时，可以对模块进行扩展，使其具有满足改变后的新行为，即我们可以改变模块的功能
> 对更改封闭：对模块进行扩展时，不必改动已有的源代码

## 3 里氏替换原则(LSP)

派生类对象任何时候都可以替换基类对象

> 基类能够通过的测试，派生类也要能够通过

著名的例子“正方形不是矩形”，正方形不能通过继承矩形来实现，因为矩形能通过的测试，正方形不一定能通过

## 4 依赖倒置原则(DIP)

高层模块不应该依赖于底层模块，二者应该依赖于抽象；抽象不应该依赖于细节，细节应该依赖于抽象

依赖不倒置的开发：

> 自顶向下首先设计整个软件, 并分解结构; －> 然后首先实现下层的功能; －> 再实现上层的功能，并使上层调用下层的函数；

依赖倒置的开发：

> 首先设计上层需要调用的接口, 并实现上层; －> 然后底层的类从上层接口中派生, 实现底层；

** 注意，在依赖倒置的开发中，接口属于上层 **

## 5 最少知识原则(LKP)

一个对象应该对其他对象有最少的了解

> 对其他对象知道的越少，对外部的依赖就越少，接口越简单，变化产生的影响就越少

## 6 接口隔离原则(ISP)

不应该强迫客户依赖于他们不用的方法

> 一个类的不内聚的“胖接口”应该被分解成多组，每一组方法都服务于一组不同的客户程序



