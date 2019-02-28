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


//Implementation of the stack with templates
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
		delete[] head;
		delete[] tail;
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
		delete[] list;
	}
};


// Task number four, parantheses balance checking
void balance_check(const char*s)
{
	Stack<char>*stack = new Stack<char>();
	int i = 0;
	int count = 0;
	while (s[i] != '\0')
	{
		stack->push(s[i]);
		++i;
	}
	//printf("%c\n", stack->pop());

	if (stack->size() == 0) return;

	if (stack->pop() == ')') --count;
	else
	{
		printf("Parentheses are unbalanced\n");
		return;
	}

	while (stack->size() != 1)
	{
		char val = stack->pop();
		if (val == '(') ++count;
		if (val == ')') --count;
	}

	if (stack->pop() == '('&&++count == 0)
		printf("Parentheses are balanced\n");
	else
	{
		printf("Parentheses are unbalanced\n");
	}
}

void printstack(Stack<int>*c)
{
	while (c->size() != 0)
	{
		printf("%i\n", c->pop());
	}
}


void printstack(Stack<char>*c)
{
	while (c->size() != 0)
	{
		printf("%c\n", c->pop());
	}
}


//Task number five, function to calculate postfix expression's result. For example 82+5*9+=
void postfix_calc(Stack<char>*s)
{
	Stack<int>*nums = new Stack<int>();

	int i = 0;
	int result = 0;


	/*while (s[i] != '\0')
	{
		if (s[i] != '+'&& s[i] != '*' && s[i] != '=')
		{
			nums->push(s[i] - '0');
		}
		input->push(s[i]);
		++i;
	}*/



	while (s->size() != 0)
	{
		char sign = s->pop();


		if (sign != '+'&&sign != '*'&&sign != '=')
		{
			nums->push(sign-'0');
			printf("Nums:%i\n", nums->list->head->val);
		}

		else if (sign == '+')
		{
			int a = nums->pop();
			int b = nums->pop();
			result = a + b;
			printf("a:%i\tb:%i\n", a, b);
			nums->push(result);
			printf("Head+:%i\n", nums->list->head->val);
		}
		else if (sign == '*')
		{
			int a = nums->pop();
			int b = nums->pop();
			printf("a:%i\tb:%i\n", a, b);
			result = a * b;
			nums->push(result);
			printf("Head*:%i\n", nums->list->head->val);
		}
		else if(sign=='=')
			printf("result:%i\n", nums->pop());
	}

}


int main()
{
	balance_check("()()())())()())()");
	
	Stack<char>*expr = new Stack<char>();
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
