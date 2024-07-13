#include "PmergeMe.hpp"

void PmergeMe::_falttingDatav2(std::deque<std::deque<int> > &pairVec)
{
	_vecv2.clear();
	size_t i = 0;
	while (i < pairVec.size())
	{
		size_t j = 0;
		while (j < pairVec[i].size())
		{
			_vecv2.push_back(pairVec[i][j]);
			j++; 
		}
		i++;
	}

}

void PmergeMe::_mergev2()
{
	deque<deque <int> > PairVec;

	PairVec = _makePairv2();

	_pendAndMainv2(PairVec);
	// _printv2(PairVec);
}

bool comparev2(std::deque<int > const &v1, std::deque<int> const &v2){
	if (v1.back() <= v2.back())
		return true;
	return false;
}

void PmergeMe::_pendToMainv2()
{
	for (size_t i = 0; i < _pendv2.size(); i++)
	{
		deque<deque<int> >::iterator pos = std::lower_bound(_mainv2.begin(), _mainv2.end(), _pendv2[i], comparev2);
		_mainv2.insert(pos , _pendv2[i]);
		_pendv2[i].clear();
	}
	_falttingDatav2(_mainv2);
}

void	PmergeMe::_pendAndMainv2( deque<deque <int> > &PairVec )
{
	_mainv2.clear();
	_pendv2.clear();
	size_t i = 0;
	while (i < PairVec.size())
	{
		deque<int> numbers;
		for (size_t j = 0; j < PairVec[i].size(); j++)
		{
			numbers.push_back(PairVec[i][j]);
		}

		if (((i + 1 ) % 2) == 0)
		{
			_mainv2.push_back(numbers);
		}	
		else
			_pendv2.push_back(numbers);
		i++;
	}
	if (PairVec.back().size() != _multiplerv2){
		_reminderv2 = PairVec.back();
		PairVec.pop_back();
	}
	_pendToMainv2();
	_multiplerv2 /=2;
}

void PmergeMe::_swapv2(std::deque<std::deque<int> > &pairVecv2)
{
	for (size_t i = 0; i < pairVecv2.size() - 1; i+=2)
	{
		std::deque<int> tmp;
		if (pairVecv2[i].size() != _multiplerv2 && pairVecv2[i + 1].size() != _multiplerv2)
        	break;
		if (pairVecv2[i].back() > pairVecv2[i + 1].back())
		{
			tmp = pairVecv2[i];
			pairVecv2[i] = pairVecv2[i + 1];
			pairVecv2[i + 1] = tmp;
		}
	}
	_falttingDatav2(pairVecv2);
}

deque<deque<int> > PmergeMe::_makePairv2()
{
	deque<int> number;
	deque<deque<int> > array;
	for (size_t i = 0; i < _vecv2.size();)
	{
		for (size_t j = 0; j < _multiplerv2 && i < _vecv2.size(); j++)
		{
			number.push_back(_vecv2[i]);
			i++;
		}
		array.push_back(number);
		number.clear();
	}
	return array;
}

void PmergeMe::_mergeSortv2()
{
	std::deque<std::deque<int> > pairVec = _makePairv2();
	_swapv2(pairVec);
	if (pairVec[0].size() == _multiplerv2 && pairVec[1].size() == _multiplerv2 && pairVec[2].size() == _multiplerv2 && pairVec[3].size() == _multiplerv2)
	{
		_multiplerv2 *= 2;
		_mergeSortv2();
		// _printv2d(pairVec);
		// cout << _multiplerv2 << endl;
	}
	_mergev2();
}