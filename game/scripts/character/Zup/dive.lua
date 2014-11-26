--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/dive.lua
]]

local DIVE_DELAY = 5

local delayFrame

dive = {}

dive.onEnter = function()
	--GameActor.setSprite(Sprites.DIVE)

	GameActor.setVelX(0)
	GameActor.setVelY(20)

	delayFrame = 0;
end

dive.onExit = function()
end

dive.handleInput = function()
end

dive.update = function()
	if (GameActor.isOnGround()) then
		delayFrame = delayFrame + 1
		if (delayFrame == DIVE_DELAY) then
			StateMachine.setNext('onGround')
		end
	end
end
