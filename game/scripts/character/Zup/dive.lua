--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/dive.lua
]]

local DIVE_DELAY = 5

local delayFrame

dive = {}

dive.onEnter = function(actor)
	GameActor.setVelX(0)
	GameActor.setVelY(10)

	delayFrame = 0;
end

dive.onExit = function(actor)
end

dive.handleInput = function(actor, controller)
end

dive.update = function(actor)
	if (GameActor.isOnGround()) then
		delayFrame = delayFrame + 1
		if (delayFrame == DIVE_DELAY) then
			StateMachine.setNext('onGround')
		end
	end
end
