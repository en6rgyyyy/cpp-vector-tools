#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T> T max(const std::vector<T>& arr);
template<typename T> T min(const std::vector<T>& arr);
template<typename T> T sum(const std::vector<T>& arr);
template<typename T> void conclusion(const std::vector<T>& arr);

int main()
{
	try
	{
		std::vector<float> arr;

		arr.push_back(0.5f);
		arr.push_back(22.3f);
		arr.push_back(9.9f);

		std::cout << "Arr: "; conclusion(arr);

		std::cout << "\n\nMax: " << max(arr) << "\n"
			<< "Min: " << min(arr) << "\n"
			<< "Sum: " << sum(arr) << "\n";
	} 

	catch (const std::invalid_argument& e)
	{
		std::cout << "\n\n+ Error " << e.what() << " +\n";
	}
}

template<typename T> T max(const std::vector<T>& arr)
{
	if (arr.empty())
	{
		throw std::invalid_argument("Arr empty!");
	}

	else
	{
		auto maxN = arr[0];

		for (auto r : arr)
		{
			if (maxN < r)
				maxN = r;
		}

		return maxN;
	}
}

template<typename T> T min(const std::vector<T>& arr)
{
	if (arr.empty())
	{
		throw std::invalid_argument("Arr empty!");
	}

	else
	{
		auto minN = arr[0];

		for (auto r : arr)
		{
			if (minN > r)
				minN = r;
		}

		return minN;
	}
}

template<typename T> T sum(const std::vector<T>& arr)
{
	if (arr.empty())
	{
		throw std::invalid_argument("Arr empty!");
	}

	else
	{
		auto sum = T{};

		for (auto r : arr)
			sum += r;

		return sum;
	}
}

template<typename T> void conclusion(const std::vector<T>& arr)
{
	if (arr.empty())
	{
		throw std::invalid_argument("Arr empty!");
	}

	else
	{
		for (size_t i{}; i < arr.size(); i++)
		{
			if (i == arr.size() - 1)
				std::cout << arr[i];
			else
				std::cout << arr[i] << ", ";
		}
	}
}
