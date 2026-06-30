#include <iostream>
#include <vector>
#include <stdexcept>


template<class T>
class Tools
{
private:
	std::vector<T> arr;
public:
	Tools(std::vector<T> arr);
	void add(T n);
	T max();
	T min();
	T sum();
	void conclusion();
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


template<class T>
Tools<T>::Tools(std::vector<T> arr) : arr{ arr } {}

template<class T>
void Tools<T>::add(T n) { arr.push_back(n); }

template<class T>
T Tools<T>::max()
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

template<class T>
T Tools<T>::min()
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

template<class T>
T Tools<T>::sum()
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

template<class T>
void Tools<T>::conclusion()
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
