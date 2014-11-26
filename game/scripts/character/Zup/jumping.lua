--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/jumping.lua
]]

local frame
local initJumpSpeed = -3
local accPeriod = 5

jumping = {}

jumping.onEnter = function()
	GameActor.setSprite(Sprites.JUMPING)

	-- Jump from ground
	if (GameActor.isOnGround()) then
		frame = 0
		GameActor.setVelY(0)
		GameActor.applyAcc(0, initJumpSpeed)
	end
end

jumping.onExit = function()
end

jumping.handleInput = function()
	if (Controller.getButtonState(Buttons.RIGHT)) then
		GameActor.moveRight()
	end

	if (Controller.getButtonState(Buttons.LEFT)) then
		GameActor.moveLeft()
	end

	if (Controller.ifButtonPressed(Buttons.DOWN)) then
		StateMachine.setNext('dive')
	end

	if (not Controller.getButtonState(Buttons.JUMP)) then
		frame = accPeriod
	end
end

jumping.update = function()
	frame = frame + 1
	if (frame < accPeriod) then
		GameActor.applyAcc(0, (-1 * (accPeriod - frame)))
	end

	if (GameActor.isOnGround()) then
		StateMachine.setNext('onGround');
	end
end
