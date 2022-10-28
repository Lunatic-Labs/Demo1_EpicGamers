#pragma once

#include <memory>
#include <stack>

#include "../include/State.h"

namespace EpicGamers
{
	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:
		StateMachine() {}
		~StateMachine() {}

		void AddState(StateRef newState, bool isPlacing = true);
		void RemoveState();

		void ProcessStateChanges();

		StateRef& GetActiveState();

	private:
		std::stack <StateRef> states;
		StateRef newState;

		bool isRemoving;
		bool isAdding;
		bool isReplacing;
	};
}