#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <array>
#include <tuple>
#include <C:\Users\User\source\repos\3.1\Timer.hpp>

int main()
{
	std::vector<std::tuple<int, int, int>> Score;
	std::size_t N[] = {10, 100, 1000, 10000, 100000, 1000000};
	for (auto i = 0; i < 6; i++)
	{

		std::size_t count = N[i];
		std::vector<int> vector(count);
		std::set<int> set;

		for (auto i = 0; i < count; i++)
			vector[i] = count - i;

		// /////           vector   ////////////////

		Timer t_vector("sort_vector");
		std::sort(std::begin(vector), std::end(vector));
		t_vector.Pause();

		// //////         set  /////////////////
		int c;
		Timer t_set("sort_set");
		t_set.Pause();
		for (auto i = 0; i < count; i++)
		{
			c = count - i;
			t_set.Continue();
			set.insert(c);
			t_set.Pause();
		}



		std::tuple<int, int, int> tuple(count, t_set.getMc(), t_vector.getMc());
		Score.push_back(tuple);
	}


	std::cout << std::endl << std::setw(10) << std::left << "Size:" << std::setw(10) << std::left << "set:" <<
		std::setw(10) << std::left << "vector:" << std::endl;


	for (auto& element : Score)
	{
		std::cout << std::setw(10) << std::left << std::get<0>(element) << std::setw(10) << std::left
			<< std::get<1>(element) << std::setw(10) << std::left << std::get<2>(element) << std::endl;
	}

	return 0;
}