
# Chap8:函数相关的技术细节(Technicalities: Functions, etc.) #

1. 学习编程语言的思想：

    	1.1 我们学习的是程序设计。
    	1.2 我们产生的是程序、系统。
    	1.3 编程语言知识工具。
    
    	• Our primary study is programming.
    	• Our output is programs/systems.  
    	• A programming language is (only) a tool.

2. 定义和声明(Declarations and definitions)

	2.1 声明是将名字引入作用域。

	2.2 定义：给出声明实体的完整描述。
	
	由2.1 和 2.2 可知，定义也是一种声明，只不过定义会分配内存。但是我们一般说声明的时候只是指“非定义的声明”。（declarations that are not definitions）

    	int x = 110;
    	int x = 110;
    	这个是错误的，因为定义了两次，而定义会分配内存。
    	
    	extern int x;
    	extern int x;
    
    	double test(int x);
    	double test(int x);
		这个声明是没有问题的。

	2.3 定义函数体，函数体作为程序的一部分保存在内存中。

	2.4 我们可以利用声明去分开编译程序。

	2.5 字符串和向量有默认构造函数，可以不初始化。

3. 头文件
    
    3.1 我们一般将类的函数声明放在 .h文件，将类的定义放在 .cpp文件。

4. 函数调用和返回

	4.1 声明和定义中的形参都可以不命名。如 int test (vector<string>, string, int)

5. 看例学习
    	
    	函数： void test(int x, int &y, const int &z)
    	调用方式： test(1, 2, 3)  ①
				  int x = 100;
    	          test(1, x, 3)  ②
		其中①错误，②正确。 int & 必须引用， const int & 可以为常量。
6. 
