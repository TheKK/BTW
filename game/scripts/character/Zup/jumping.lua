--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/jumping.lua
]]

local frame

jumping = {}

jumping.onEnter = function(actor)
	if (isOnGround(actor)) then
		frame = 0
		setVelY(actor, 0)
		applyAcc(actor, 0, -10)
	end
end

jumping.onExit = function(actor)
end

jumping.handleInput = function(actor, controller)
	if (getButtonState(controller, Buttons.BUTTON_RIGHT)) then
		moveRight(actor)
	end

	if (getButtonState(controller, Buttons.BUTTON_LEFT)) then
		moveLeft(actor)
	end

	if (not getButtonState(controller, Buttons.BUTTON_JUMP)) then
		frame = 5
	end
end

jumping.update = function(actor)
	frame = frame + 1
	if (frame < 5) then
		applyAcc(actor, 0, (-1 * (5 - frame)))
	end

	if (isOnGround(actor)) then
		land(actor)
	end
end
