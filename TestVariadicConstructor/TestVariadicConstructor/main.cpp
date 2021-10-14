#include <iostream>
#include <array>

template<unsigned int R, unsigned int C, typename WeightType = float>
class StaticGrid
{
public:
	static_assert(R > 0 && C > 0, "Invalid column or row count !");
	StaticGrid() = default;

	WeightType get_diff_row_weight(uint32_t i)
	{
		if (i <= 0)
			return m_rowWeight[i];
		if (i >= R)
			return m_rowWeight[R - 1] - m_rowWeight[R - 2];
		return m_rowWeight[i] - m_rowWeight[i - 1];
	}

	WeightType get_total_row_weight(uint32_t i)
	{
		if (i <= 0)
			return m_rowWeight[i];
		if (i >= R)
			return m_rowWeight[R - 1];
		return m_rowWeight[i];
	}

	WeightType get_diff_column_weight(uint32_t i)
	{
		if (i <= 0)
			return m_columnWeight[i];
		if (i >= R)
			return m_columnWeight[R - 1] - m_columnWeight[R - 2];
		return m_columnWeight[i] - m_columnWeight[i - 1];
	}

	WeightType get_total_column_weight(uint32_t i)
	{
		if (i <= 0)
			return m_columnWeight[i];
		if (i >= R)
			return m_columnWeight[R - 1];
		return m_columnWeight[i];
	}

	template<typename... Args>
	void row_weight(Args... pack)
	{
		static_assert(sizeof...(pack) == R, "To many row weights are passed !");

		std::array<WeightType, sizeof...(pack)> temp = { pack... };
		m_rowWeight[0] = temp[0];
		for (int i = 1;i < temp.size();i++)
		{
			m_rowWeight[i] = m_rowWeight[i - 1] + temp[i];
		}
	}

	template<typename... Args>
	void column_weight(Args... pack)
	{
		static_assert(sizeof...(pack) == C, "To many column weights are passed !");

		std::array<WeightType, sizeof...(pack)> temp = { pack... };
		m_columnWeight[0] = temp[0];
		for (int i = 1; i < temp.size(); i++)
		{
			m_columnWeight[i] = m_columnWeight[i - 1] + temp[i];
		}
	}

	void print_weights()
	{
		std::cout << "row weights: " << std::endl;
		for (auto e : m_rowWeight)
		{
			std::cout << e << ", ";
		}
		std::cout << "\ncolumn weights: " << std::endl;
		for (auto e : m_columnWeight)
		{
			std::cout << e << ", ";
		}
	}

private:
	std::array<WeightType, R> m_rowWeight;
	std::array<WeightType, C> m_columnWeight;
};


int main()
{
	StaticGrid<3, 3> grid;
	grid.row_weight(0.4f, 0.3f, 0.3f);
	grid.column_weight(0.1f, 0.7f, 0.2f);

	grid.print_weights();

	std::cout << std::endl;
	std::cout << grid.get_total_row_weight(1) << std::endl;
}