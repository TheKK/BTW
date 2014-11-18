--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/jumping.lua
]]

local frame
local initJumpSpeed = -8
local accPeriod = 5

jumping = {}

jumping.onEnter = function(actor)
	setSprite(actor, Sprites.JUMPING)

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
	if (getButtonState(controller, Buttons.BUTTON_RIGHT)) then
		moveRight(actor)
	end

	if (getButtonState(controller, Buttons.BUTTON_LEFT)) then
		moveLeft(actor)
	end

	if (ifButtonPressed(controller, Buttons.BUTTON_DOWN)) then
		StateMachine.setNext(FSM, 'dive')
	end

	if (not getButtonState(controller, Buttons.BUTTON_JUMP)) then
		frame = accPeriod
	end
end

jumping.update = function(actor)
	frame = frame + 1
	if (frame < accPeriod) then
		applyAcc(actor, 0, (-1 * (accPeriod - frame)))
	end

	if (isOnGround(actor)) then
		StateMachine.setNext(FSM, 'onGround');
	end
end