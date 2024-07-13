#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <utility>
# include <ctime>
# include <algorithm>
# include <deque>


using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::deque;

class PmergeMe
{

	public:

		PmergeMe();
		void start(char **av);
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

	private:
	// deque
		deque<deque<int> > _arrayv2;
		deque<int > _reminderv2;
		deque<int> _vecv2;
		deque<deque<int> > _pendv2;
		deque<deque<int> > _mainv2;
		size_t _multiplerv2;

		void _mergeSortv2();
		void _printd(const deque<int> &array);
		void _swapv2(std::deque<std::deque<int> > &pairVecv2);
		void _falttingDatav2(std::deque<std::deque<int> > &pairVec);
		void _printv2d(const std::deque<std::deque<int> >& _array);
		deque<deque<int> > _makePairv2();
		void _mergev2();
		void	_pendAndMainv2( deque<deque <int> > &PairVec );
		void _pendToMainv2();
		void _deque();

	//  vector
		vector<vector<int> > _array;
		vector<int > _reminder;
		vector<int> _vec;
		vector<vector<int> > _pend;
		vector<vector<int> > _main;
		size_t _multipler;



		void _vector();
		void _mergeSort();
		vector<vector<int> > _makePair();
		void _checknumber(string str);
		void _print(const vector<int> &array);
		void _printv2(const std::vector<std::vector<int> >& _array);
		void _swap(std::vector<std::vector<int> > &pairVec);
		void _falttingData(std::vector<std::vector<int> > &pairVec);
		void _merge();
		void _pendAndMain( vector<vector <int> > &PairVec );
		void _pendToMain();
};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */
