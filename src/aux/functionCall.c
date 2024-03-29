#include "utilities.h"
#include "functionCall.h"

FunctionCall *_callStack = NULL;

/* Function: pushFunctionCall
 * Parameters: Symbol *function
 * Description: Pushes a function call onto the call stack.
 * Returns: The function call pushed.
 * Preconditions: The given function symbol is not NULL.
 */
FunctionCall *pushFunctionCall(Symbol *function) {
	FunctionCall *toInsert = NULL;
	
	if (!(toInsert = malloc(sizeof(FunctionCall))))
		ERROR("", __LINE__, TRUE);					// out of memory
	
	toInsert->identifier = function->identifier;
	toInsert->currParam = function->parameterListHead;
	
	toInsert->below = _callStack;
	_callStack = toInsert;
	
	return toInsert;
}

/* Function: popFunctionCall
 * Parameters: none
 * Description: Pops a function call from the call stack.
 * Returns: none
 * Preconditions: The call stack is not empty.
 */
void popFunctionCall() {
	if (!_callStack)
		ERROR("PopFunctionCall called on empty stack.", __LINE__, FALSE);
	
	FunctionCall *newTop = _callStack->below;
	
	free(_callStack);
	
	_callStack = newTop;
}