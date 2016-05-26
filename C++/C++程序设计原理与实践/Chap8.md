
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