/*
	The State Machine allows the Game and Player to change between different
	states, with different behavior for each.
*/

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
			//delete StateRef;
		

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