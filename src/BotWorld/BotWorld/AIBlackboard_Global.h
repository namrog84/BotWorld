#pragma once

//The game has a single global blackboard, which can be used as a central repository for
// information that should be available to every AI component, regardless of what character that
// component belongs to or what side that character is on.

// As described above, the global blackboard is a shared memory space that can be used to pass
// in formation between the game and the AI, and/or between AI components.It is a singleton so
// that it will be globally accessible, and also so that projects can implement their own version
// which is more tightly coupled with the data being shared from the game engine if they wish.
class AIBlackboard_Global
{
public:
	AIBlackboard_Global();
	~AIBlackboard_Global();
};

