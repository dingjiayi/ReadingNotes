# Chap9:类相关的技术细节 #
1. C++提供了两种用户自定义数据：类和枚举。
2. 有效值思想：构造对象时，保证内部数据有效。后续成员函数的输入为有效值，保证输出也是有效值。这样就能避免对象“坏了”，能够很大程度避免错误的发生。
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

	<u style="color:blue;font-size:20px;">我们倾向于使用方式2，因为：1. 保证了在其他的操作前已经初始化了数据 。
    	2. 方式1 其实是先用默认值(0)初始化了三个数据，然后再用参数赋值的，二者室友区别的.</u>
   

