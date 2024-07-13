#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN( const RPN & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
	{
		this->_stack = rhs._stack;

	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RPN const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void RPN::start(std::string expression)
{
	std::stringstream iss(expression);
	std::string str;
	while (iss >> str)
	{

		if (std::isdigit(str[0]))
		{
			_stack.push(std::strtod(str.c_str(), NULL));
		}
		if (str.size() == 1 && _checkOperator(str))
		{
			_preformOperator(str.c_str()[0]);
		}
		if (str.size() > 1)
		{
			if (_checkOperator(str.substr(str.size() - 1)))
			{
				string lastChar  = str.substr(str.size() - 1);
				if (_checkOperator(lastChar))
				{
					string number = str.substr(0, str.size() - 1);
					_stack.push(std::strtod(number.c_str(), NULL));
					_preformOperator(lastChar.c_str()[0]);
				}
			}
			else
			{
				std::cerr << "Error" << endl;
				exit(1);
			}

		}
	}
	cout << _stack.top() << endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

bool RPN::_checkOperator(const std::string &opera)
{
	if(opera[0] == '+' || opera[0] == '-' || opera[0] == '/' || opera[0] == '*')
		return true;
	return false;
}

int RPN::_getResult(const int a, const int b, char operate)
{
	int res = 0;
	if (operate == '+')
		res = b + a;
	else if (operate == '-')
		res = b - a;
	else if (operate == '*')
		res = b * a;
	if (operate == '/')
	{
		if (a == 0)
			throw std::invalid_argument("Plus Infiny +∞");
		else res = b / a;
	}
	return res;
}

void RPN::_preformOperator(const char operate)
{
	int a = 0;
	if (!_stack.empty())
	{
		a = _stack.top();
		_stack.pop();
	}
	int b = 0;;
	if (!_stack.empty())
	{
		b = _stack.top();
		_stack.pop();
	}
	int result;
	result = _getResult(a , b , operate);
	_stack.push(result);
}

void 	 RPN::_holdOperation()
{
}
/* ************************************************************************** */

void RPN::printstack()
{
		cout << "=============" << endl;
	std::stack<int> tmp = _stack;
	while (!tmp.empty())
	{
		int value = tmp.top();
		cout << "The Value :" << value << "|" << endl;
		tmp.pop();
	}
	cout << "=============" << endl;
}
