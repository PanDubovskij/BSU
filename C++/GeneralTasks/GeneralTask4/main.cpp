#include "bidirectional_list_on_array.h"

int main()
{
	BiDirectionalListOnArray<int> list = { 1,2,3,4 };
	BiDirectionalListOnArray<int> list2 = { 5,6,7,8 };
	list.Print();
	std::cout << std::endl;
	list2.Erase(2);
	list2.Print();
	system("pause");
	return 0;
}