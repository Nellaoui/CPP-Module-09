#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
using std::cout;
using std::endl;
using std::string;
class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		void start(std::string expression);
		~RPN();

		RPN &		operator=( RPN const & rhs );

	private:
		std::stack<int> _stack;
		bool _checkOperator(const std::string &oepra);
		void _preformOperator(const char operate);
		int _getResult(const int a, const int b, char operate);
		void printstack();
		void _holdOperation();

};

std::ostream &			operator<<( std::ostream & o, RPN const & i );

#endif /* ************************************************************* RPN_H */
