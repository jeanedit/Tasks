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


// Task number four, parantheses balance checking
// Balance checking function with using 3 stacks
void balance_check_v2(const char*s)
{
	int i = 0;
	
	Stack<char>*parenth = new Stack<char>();
	Stack<char>*parenth1 = new Stack<char>();
	Stack<char>*parenth2 = new Stack<char>();

	while (s[i] != '\0')
	{
		parenth->push(s[i]);
		++i;
	}

	if (parenth->peek() == '(') printf("Parentheses are unbalanced\n");


	while (parenth->size() != 1)
	{
		char prth = parenth->pop();
		printf("prth:%c\n", prth);
		if (prth == '(') parenth1->push(prth);
		else parenth2->push(prth);
	}

	if (parenth->pop() == '('&&parenth1->size()+1 == parenth2->size())
		printf("Parentheses are balanced\n");
	else printf("Parentheses are unbalanced\n");

}

//Balance checking function with using 2 stacks and checking first and last elements of the char's array
void balance_check(const char*s)
{
	int i = 0;

	Stack<char>*parenth1 = new Stack<char>();
	Stack<char>*parenth2 = new Stack<char>();

	if (s[0] == ')' || s[strlen(s) - 1] == '(')
	{
		printf("parentheses are unbalanced\n");
		return;
	}
	while (s[i] != '\0')
	{
		if (s[i] == '(') parenth1->push(s[i]);
		else parenth2->push(s[i]);
		++i;
	}

	if (parenth1->size() == parenth2->size()) 
		printf("parentheses are balanced\n");

	else  
		printf("parentheses are unbalanced\n");
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
	int main()
{
	balance_check("(()))");
	balance_check_v2("((())");
		
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

	
}
