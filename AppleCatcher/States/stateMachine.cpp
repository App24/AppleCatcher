#include "stateMachine.h"

bool StateMachine::m_isAdding;
bool StateMachine::m_isReplacing;
bool StateMachine::m_isRemoving;
StateRef StateMachine::m_newState;
std::stack<StateRef> StateMachine::m_states;

void StateMachine::addState(StateRef newState, bool isReplacing) {
	m_isAdding = true;
	m_isReplacing = isReplacing;
	m_newState = std::move(newState);
}

void StateMachine::removeState() {
	m_isRemoving = true;
}

void StateMachine::processStateChanges() {
	if (m_isRemoving && !empty()) {
		m_states.pop();

		if (!empty())
			getActiveState()->resume();

		m_isRemoving = false;
	}

	if (m_isAdding) {
		if (!empty()) {
			if (m_isReplacing) {
				m_states.pop();
			}
			else {
				getActiveState()->pause();
			}
		}

		m_states.push(std::move(m_newState));
		getActiveState()->init();
		m_isAdding = false;
	}
}

StateRef& StateMachine::getActiveState() {
	return m_states.top();
}

bool StateMachine::empty() {
	return m_states.empty();
}