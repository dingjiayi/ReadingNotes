# Chap9:类相关的技术细节 #
1. C++提供了两种用户自定义数据：类和枚举。
2. 有效值思想：构造对象时，保证内部数据有效。后续成员函数的输入为有效值，保证输出也是有效值。这样就能避免对	象“坏了”，能够很大程度避免错误的发生。
3. 一个类的数据描述一般不暴露（私有）。
4. 类成员初始化：两种方式

    	class Date {
    	private:
    	int year;
    	int month;
    	int day;
    	public:
    	Date(int y, int m, int d);
    	};
    
    	//初始化方式1
    	Date::Date(int y, int m, int d){
    	this->year = y;
    	this->month = m;
    	this->day = d;
    	};
    
    	//初始化方式2
    	Date::Date(int y, int m, int d):year(y), month(m), day(d){};

	_我们倾向于使用方式2，因为：1. 保证了在其他的操作前已经初始化了数据 。2. 方式1 其实是先用默认值(0)初始化了三个数据，然后再用参数赋值的，二者是有区别的._


5. 内联函数：

    5.1 内联函数的编译：编译器内联函数的调用生成代码时，不生成真正的函数调用，而是将其代码嵌入到调用者的代码中。对于代码行数在5行内，又被频繁调用的函数，这种编译方式会带来很大的性能提升。
    
	5.2 内联函数的缺点：对内联函数做出修改时，所有使用这个类的程序都不得不重新编译。如果函数体位于类声明之外的话，就不必这样，只在类接口改变时才需要重新编译用户程序。
	
	5.3 内联函数的使用原则：除非确定需要从小函数的内联中获得性能提升，否则不要将成员函数体放在类声明中。对于5行以上的代码，不会从内联中获益。其实就是能不用就不用。

6. 枚举类型：
	
	
> 6.1 默认从0开始初始化第一个枚举量（如果我们没有初始化），每次增加1。

> 6.2 中间如果省略了几个的声明，也是从开始声明的地方加一的。比如

	enum Week {Mon = 1, Tue =2, Wed, Thu, Fri = 6, Sat, Sun};
	从左到右依次为 1， 2， 3， 4， 6， 7， 8
> 6.3 枚举类型可以隐式转换为整型，但是整型不能隐式转换为枚举类型。因为整型---->枚举，可能超出范围。

	    Week w = Mon;  w = 123; //error  int to enum
    	Week w = Mon;  int a = 123; int b = Mon; //ok convert enum to int
    	Week w = Week(123); // OK 编译器此时相信程序员。

> 6.4 枚举类型中的 Mon， Tue， 。。。等元素的作用域和Week相同。为了避免和其他变量命名冲突，使用枚举类（C++ 11标准）。 enum class Week {Mon, Tue ...}，那么 可以使用为
Week a = Week::Mon;

> 6.5 类中枚举的使用举例

```
****class Date {
    int year;
    int month;
    int day;
public:
    enum Week {Mon = 1, Tue, Wen, Thu, Fri, Sat};
    void show();
    Date(int y, int m, int d);
};
//...
Date d1(2006, _Date::Sat_, 1);
```


7.运算符重载


> 7.1 只能对C++ 已有的运算符进行重载且不能修改原运算符的元数目。
	比如可以对 ＋，＊，＋＋，<< 运算符进行重载，但是不能对 ＋＊， ／＊等进行重载，因为C＋＋标准中没有这些运算符。
	＋ 重载后依旧只能时二元运算，而不能时一元运算。

> 7.2 重载的运算符必须作用于至少一个用户自定义类型的运算对象。

> 7.3 看懂例子


```
enum Week { Mon =1, Tue, Wen, Thu, Fri, Sat};
string week_names[] = {"Mon", "Tue", "Wen", "Thu", "Fri", "Sat"};
ostream& operator<< (ostream& os, Week w)
{
    return os << week_names[w] << '\n';
}

int main(int argc, const char * argv[]) {
   

    Week w(Mon);
    
    cout << w;
    
    return 0;
}
```

> 7.4 重载运算符的一般性原则：除非能够确定运算符能够大大改善代码，否则不要为你的类型定义运算符。


