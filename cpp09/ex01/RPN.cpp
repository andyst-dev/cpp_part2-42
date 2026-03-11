#include "RPN.hpp"
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expr) const
{
	std::istringstream iss(expr);
	std::stack<int> st;
	std::string tok;

	while (iss >> tok)
	{
		if (tok == "+" || tok == "-" || tok == "*" || tok == "/")
		{
			if (st.size() < 2)
				throw InvalidExpressionException();

			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();

			if (tok == "+")
				st.push(a + b);
			else if (tok == "-")
				st.push(a - b);
			else if (tok == "*")
				st.push(a * b);
			else if (tok == "/")
			{
				if (b == 0)
					throw InvalidExpressionException();
				st.push(a / b);
			}
		}
		else
		{
			if (tok.size() != 1 || tok[0] < '0' || tok[0] > '9')
				throw InvalidExpressionException();

			st.push(tok[0] - '0');
		}
	}

	if (st.size() != 1)
		throw InvalidExpressionException();

	return st.top();
}

const char* RPN::InvalidExpressionException::what() const throw()
{
	return "Error";
}