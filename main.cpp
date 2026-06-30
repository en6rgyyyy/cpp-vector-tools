#include <iostream>
#include <vector>
#include <stdexcept>


template<class T>
class Tools
{
private:
	std::vector<T> arr;
public:
	Tools(std::vector<T> arr) : arr{ arr } {}

	void add(T n) { arr.push_back(n); }

	T max()
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

	T min()
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

	T sum()
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

	void conclusion()
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
};


int main()
{
	try
	{
		std::vector<float> arr;
		Tools<float> Arr{ arr };

		Arr.add(3.4f);
		Arr.add(5.8f);
		Arr.add(10.1f);

		std::cout << "Arr: "; Arr.conclusion();

		std::cout 
			<< "\n\nMax: " << Arr.max() << "\n"
			<< "Min: " << Arr.min() << "\n"
			<< "Sum: " << Arr.sum() << "\n";
	} 

	catch (const std::invalid_argument& e)
	{
		std::cout << "\n\n+ Error " << e.what() << " +\n";
	}
}
