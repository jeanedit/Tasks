#include <stdio.h>

int strlen(const char*string)
{
	int length = 0;
	while (string[length] != '\0')
	{
		++length;
	}
	return length;
}

class Mystring
{
public:
	Mystring()
	{
		str = nullptr;
	}

	Mystring(char*st)
	{
		int length = strlen(st);
		str = new char[length + 1];
		for (int i = 0; i < length; ++i)
		{
			str[i] = st[i];
		}

		str[length] = '\0';
	}
	Mystring(const char*st)
	{
		int length = strlen(st);
		str = new char[length + 1];
		for (int i = 0; i < length; ++i)
		{
			str[i] = st[i];
		}

		str[length] = '\0';
	}

	~Mystring()
	{
		delete[] this->str;
	}

private:
	char* str;
};



template<class T>
struct Node
{
	T val;
	Node*next;
	Node(T value)
	{
		val = value;
		next = NULL;
	}
	~Node()
	{
		delete next;
	}
};

template<class T>
class List
{
public:
	Node<T>*head;
	Node<T>*tail;
	List()
	{
		head = NULL;
		tail = NULL;
	}
	~List()
	{
		delete head;
		delete tail;
	}
};

template<class T>
class Stack
{
public:
	List<T> * list;
	int stacksize;
	Stack()
	{
		list = new List<T>();
		stacksize = 0;
	}

	int size()
	{
		return stacksize;
	}

	T pop()
	{
		if (list->head == NULL) return -1;
		T value = list->head->val;
		list->head = list->head->next;
		--stacksize;
		return value;
	}

	void push(T val)
	{
		Node<T>*node = new Node<T>(val);
		if (list->head == NULL)
		{
			list->head = node;
		}
		else {
			node->next = list->head;
		}
		list->head = node;

		++stacksize;
	}

	T peek()
	{
		if (list->head != NULL)
		{
			return list->head->val;
		}
		else
			return -1;
	}
	~Stack()
	{
		delete list;
	}
};


//parentheses balance checking
void balance_check(const char*s)
{
	Stack<char>*parenth = new Stack<char>();
	int i = 0;
	int a = 0;
	while (s[i]!='\0')
	{
		if (s[0] == ')')
		{
			printf("Parentheses are unbalanced\n");
			return;
		}
		if (s[i] == '(') parenth->push(s[i]);
		if (s[i] == ')') a=parenth->pop();
		if (s[i] == '('&&parenth->size() == 0)
		{
			printf("Parentheses are unbalanced\n");
			return;
		}
		++i;
	}
	if(parenth->size()==0)
		printf("Parentheses are balanced\n");
	else 
		printf("Parentheses are unbalanced\n");
}


//Postfix calculator
void postfix_calc(Stack<char>*s)
{
	Stack<int>*nums = new Stack<int>();

	int i = 0;
	int result = 0;

	while (s->size() != 0)
	{
		char sign = s->pop();

		if (sign == '+'||sign=='*')
		{
			int a = nums->pop();
			int b = nums->pop();

			if(sign=='+')  result = a + b;

			else result = a * b;

			nums->push(result);
		}
		else if(sign=='=')
			printf("result:%i\n", nums->pop());
		else
		{
			nums->push(sign - '0');
		}
	}
	
}


int main()
{
	balance_check("((()))");
	/*Stack<char>*expr = new Stack<char>();
	expr->push('=');
	expr->push('+');
	expr->push('9');
	expr->push('*');
	expr->push('5');
	expr->push('+');
	expr->push('2');
	expr->push('8');
	postfix_calc(expr);

	/*Stack<char>*stack = new Stack<char>();
	stack->push('(');
	stack->push('(');
	stack->push(')');
	stack->push('(');
	stack->push('(');
	stack->push(')');
	*/
}
