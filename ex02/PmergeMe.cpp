#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
	_multipler = 1;
	_multiplerv2 = 1;
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->_multipler = rhs._multipler;
		this->_multiplerv2 = rhs._multiplerv2;
		this->_vec = rhs._vec;
		this->_vecv2 = rhs._vecv2;
		this->_array = rhs._array;
		this->_arrayv2 = rhs._arrayv2;
		this->_reminder = rhs._reminder;
		this->_reminderv2 = rhs._reminderv2;
		this->_pend = rhs._pend;
		this->_pendv2 = rhs._pendv2;
		this->_main = rhs._main;
		this->_mainv2 = rhs._mainv2;		
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void PmergeMe::_vector()
{
	cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); i++)
	{
		 cout << _vec[i] << " ";
	}
	cout << endl;
	cout << "After : ";
	std::clock_t start = std::clock();
	_mergeSort();
	for (size_t i = 0; i < _vec.size(); i++)
	{
		 cout << _vec[i] << " ";
	}
	cout << endl;
	std::clock_t end = std::clock();
	double sec = double(end - start) / CLOCKS_PER_SEC;
	double us =  sec * 1e6;
	cout << "Time To process a range of " << _vec.size() << " elements with std::vector : " << us <<  " us"<<  endl;
}

void PmergeMe::_deque()
{
	cout << "Before: ";
	for (size_t i = 0; i < _vecv2.size(); i++)
	{
		 cout << _vecv2[i] << " ";
	}
	cout << endl;
	cout << "After : ";
	std::clock_t start = std::clock();
	_mergeSortv2();
	std::clock_t end = std::clock();
	for (size_t i = 0; i < _vecv2.size(); i++)
	{
		 cout << _vecv2[i] << " ";
	}
	cout << endl;
	double sec = double(end - start) / CLOCKS_PER_SEC;
	double us =  sec * 1e6;
	cout << "Time To process a range of " << _vec.size() << " elements with std::deque : " << us <<  " us"<<  endl;
}

void PmergeMe::start(char **av)
{
	for (size_t i = 1; av[i] != NULL; i++)
	{
		string str = av[i];
		std::stringstream iss(str);
		_checknumber(str);
		_vec.push_back(strtod(str.c_str(), NULL));
		_vecv2.push_back(strtod(str.c_str(), NULL));
	}
	_vector();
	_deque();
}


void PmergeMe::_mergeSort()
{
	std::vector<std::vector<int> > pairVec = _makePair();
	_swap(pairVec);
	if (pairVec[0].size() == _multipler && pairVec[1].size() == _multipler && pairVec[2].size() == _multipler && pairVec[3].size() == _multipler)
	{
		_multipler *= 2;
		_mergeSort();
		// _printv2(pairVec);
	}
	_merge();
}

vector<vector<int> > PmergeMe::_makePair()
{
	vector<int> number;
	vector<vector<int> > array;
	for (size_t i = 0; i < _vec.size();)
	{
		for (size_t j = 0; j < _multipler && i < _vec.size(); j++)
		{

			number.push_back(_vec[i]);
			i++;
		}
		array.push_back(number);
		number.clear();
	}
	return array;
}

void PmergeMe::_swap(std::vector<std::vector<int> > &pairVec)
{
	for (size_t i = 0; i < pairVec.size() - 1;i+=2)
	{
		std::vector<int> tmp;
		if (pairVec[i].size() != _multipler && pairVec[i + 1].size() != _multipler)
			break;
		if (pairVec[i].back() > pairVec[i + 1].back())
		{
			tmp = pairVec[i];
			pairVec[i] = pairVec[i + 1];
			pairVec[i + 1] = tmp;
		}
	}
	// _printv2(pairVec); 
	_falttingData(pairVec);
	// _print(_vec)
}
void PmergeMe::_checknumber(string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '+')
		{
			cout << "Error" << endl;
			exit(EXIT_FAILURE);
		}
	}

}

void PmergeMe::_falttingData(std::vector<std::vector<int> > &pairVec)
{
	// _print(_vec);
	// cout << _multipler << endl;
	_vec.clear();
	size_t i = 0;
	while (i < pairVec.size())
	{
		size_t j = 0;
		while (j < pairVec[i].size())
		{
			_vec.push_back(pairVec[i][j]);
			j++; 
		}
		i++;
	}

}

void PmergeMe::_merge()
{
	vector<vector <int> > PairVec;

	PairVec = _makePair();

	_pendAndMain(PairVec);
	// _printv2(PairVec);
}
void	PmergeMe::_pendAndMain( vector<vector <int> > &PairVec )
{
	_main.clear();
	_pend.clear();
	size_t i = 0;
	while (i < PairVec.size())
	{
		vector<int> numbers;
		for (size_t j = 0; j < PairVec[i].size(); j++)
		{
			numbers.push_back(PairVec[i][j]);
		}

		if (((i + 1 ) % 2) == 0)
		{
			_main.push_back(numbers);
		}	
		else
			_pend.push_back(numbers);
		i++;
	}
	if (PairVec.back().size() != _multipler){
		_reminder = PairVec.back();
		PairVec.pop_back();
	}
	_pendToMain();
	_multipler /=2;
}
bool compare(std::vector<int > const &v1, std::vector<int> const &v2){
	if (v1.back() <= v2.back())
		return true;
	return false;
}
void PmergeMe::_pendToMain()
{
	for (size_t i = 0; i < _pend.size(); i++)
	{
		vector<vector<int> >::iterator pos = std::lower_bound(_main.begin(), _main.end(), _pend[i], compare);
		_main.insert(pos , _pend[i]);
		_pend[i].clear();
	}
	_falttingData(_main);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void PmergeMe::_printv2(const std::vector<std::vector<int> >& _array)
{


	cout << "=============================================================" << endl;
	for (vector<vector<int> >::const_iterator it = _array.begin(); it != _array.end(); ++it)
	{
		cout << "[";
		for (vector<int>::const_iterator innerit = it->begin(); innerit != it->end(); ++innerit)
			cout << *innerit << " ";
		cout << "]\n";
	}
	cout << "=============================================================" << endl;
}

void PmergeMe::_printv2d(const std::deque<std::deque<int> >& _array)
{


	cout << "=============================================================" << endl;
	for (deque<deque<int> >::const_iterator it = _array.begin(); it != _array.end(); ++it)
	{
		cout << "[";
		for (deque<int>::const_iterator innerit = it->begin(); innerit != it->end(); ++innerit)
			cout << *innerit << " ";
		cout << "]\n";
	}
	cout << "=============================================================" << endl;
}

void PmergeMe::_print(const vector<int> &array)
{
	cout << "=============================" << endl;
	for (size_t i = 0; i < array.size(); i++)
	{
		cout << "index |" << i  << "| :"<<  array[i] << endl;
	}
	cout << "=============================" << endl;
}

void PmergeMe::_printd(const deque<int> &array)
{
	cout << "=============================" << endl;
	for (size_t i = 0; i < array.size(); i++)
	{
		cout << "index |" << i  << "| :"<<  array[i] << endl;
	}
	cout << "=============================" << endl;
}

// vecofvec makepairs(vec){
	//elementsize == 1
	// vec >> filldata >> vecofvec
// }
// int main (){

	// vec << args

	//vecofvec = makepairs(vec);

// }
/* ************************************************************************** */
