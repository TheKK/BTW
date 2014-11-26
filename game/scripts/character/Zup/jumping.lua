--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/jumping.lua
]]

local frame
local initJumpSpeed = -3
local accPeriod = 5

jumping = {}

jumping.onEnter = function(actor)
	--setSprite(actor, Sprites.JUMPING)

	-- Jump from ground
	if (isOnGround(actor)) then
		frame = 0
		setVelY(actor, 0)
		applyAcc(actor, 0, initJumpSpeed)
	end
end

jumping.onExit = function(actor)
end

jumping.handleInput = function(actor, controller)
	if (getButtonState(controller, Buttons.RIGHT)) then
		moveRight(actor)
	end

	if (getButtonState(controller, Buttons.LEFT)) then
		moveLeft(actor)
	end

	if (ifButtonPressed(controller, Buttons.DOWN)) then
		StateMachine.setNext('dive')
	end

	if (not getButtonState(controller, Buttons.JUMP)) then
		frame = accPeriod
	end
end

jumping.update = function(actor)
	frame = frame + 1
	if (frame < accPeriod) then
		applyAcc(actor, 0, (-1 * (accPeriod - frame)))
	end

	if (isOnGround(actor)) then
		StateMachine.setNext('onGround');
	end
end
