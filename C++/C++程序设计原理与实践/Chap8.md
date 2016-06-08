
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
6. 使用参数的几个原则

        6.1 使用传值方式传递非常小的对象。
    	6.2 使用传常量引用方式传递你不需要修改的大对象。
    	6.3 让函数返回一个值，而不是通过修改引用参数传递来的对象。
    	6.4 只有迫不得已时才使用传引用方式。
    
    	补充说明：
    	（1）如果我们发现一个参数是以非常量引用方式传递的，我们必须假设被调用的函数会修改这个参数。
    	（2）使用非 常量引用的常见主要原因：
    		用于操作容器（向量）。
    		用于改变多个对象的函数（函数只能有一个返回值。我们也可以通过返回对象的方式达到返回多个值得目的）

7. 使用类型转换应该是显式的, 这样可以让后续阅读一眼看到类型转换。
	
    	double a = 2.33;
     	int x = int(a);

8. 看例学习。

    	int test(char c)         
    	{
    		int x;
    		//...
    		return 0;
    	}
	
	调用函数时，一般编译器栈的方式如下：先是形参，后是局部变量，最后是返回上层函数所需的一些信息。

	![](http://i.imgur.com/hm0yTXU.png)

9. 变量的创建和销毁时机
	
    	int test()
    		int a;
    		string b;
    		//...
    	end

	创建顺序 a-->b, 销毁顺序 b-->a.
	全局变量也是如此。

10. 全局的初始化

    	（1）假设有 f1.cpp
    	// 全局变量
    
    	int x1 = 1;
    	int y1 = x1 + 1;
    	
    	文件 f2.cpp.
    	
    	extern int y1;
    	int y2 = y1 + 1; //y2 = 1 or 3
    
    	由于编译单元 f1.cpp 和 f2.cpp 编译顺序无序，所以y2无法确定。

    	（2）能不用全局变量就不用全局变量。因为无法知道在哪儿进行了全局变量的改动。
    
	
	（3）对于一些必须需要的全局变量，常用技术有2.
		假设有一个全局变量，标识了开服时间。 
		对象类型 DATE. 
	a) 方式1：编写函数，返回我们需要的值。
		const DATE GetOpenTime("20160608")
		{
			//...
			return DATE(2016, 6, 8)
		}

		但是这样每次使用开服时间，都需要创建一个对象。

	b) 方式2：利用方式1 + 静态局部变量的特性：只在函数首次调用时才被创建。
		const DATE& GetOpenTime("20160608")
		{
			//...
			static const DATE a(2016, 6, 8);
			return a;
		}

	注意两点：返回的是引用，防止被修改。

