- c++ basic: std::cout, std::cin, vector

```
struct rectange { //class
	double width, height;
	double area() { return width *height; }  //interface
};

namespace xxx {
	void f() {}
	///
}
namespace yyy {
	void f() {}
	///
}

int main() {
	xxx::f();
	yyy::f();

	rectange rect;
	rect.width = 12.5;
	rect.height = 2.4;
	double a = rect.area();

	vector<int> array;
	int s = array.size();
	std::cout << s << "\n"; //std 是标准名字空间，cout是std中的一个变量名

	array.push_back(1);
	array.push_back(2);
	array.push_back(3);
	s = array.size();
	std::cout << s << "\n"; //std 是标准名字空间，cout是std中的一个变量名

	for (int i = 0; i < array.size(); i++)
		std::cout << array[i] << "\n";   //  *(array+i)  array[i]


	return 0;
}
 
```