#pragma once
#include "state.h"
#include <memory>
#include <stack>

typedef std::unique_ptr<State> StateRef;

class StateMachine {
public:
	static void addState(StateRef newState, bool isReplacing = true);
	static void removeState();

	static void processStateChanges();

	static StateRef& getActiveState();

	static bool empty();
private:
	static bool m_isAdding, m_isReplacing, m_isRemoving;
	static StateRef m_newState;

	static std::stack<StateRef> m_states;
};