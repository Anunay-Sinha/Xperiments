
#   if defined(STACK_LIBRARY)
#      define STACK_DLL_EXPORT __declspec(dllexport)
#   else
#      define STACK_DLL_EXPORT __declspec(dllimport)
#   endif
#ifndef STACK_H
#define STACK_H
class STACK_DLL_EXPORT Stack
{
	long *arr;
	int top;
	int size;
public:
	bool push(long data);
	bool pop(long& data);
	bool peek(long& data);
	Stack(void);
	Stack(int);
	~Stack(void);
};
#endif
