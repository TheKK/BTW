--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/jumping.lua
]]

local frame
local initJumpSpeed = -2.5
local accPeriod = 4

jumping = {}

jumping.onEnter = function()
	--GameActor.setSprite(Sprites.JUMPING)

	-- Jump from ground
	if (GameActor.isOnGround()) then
		frame = 0
		GameActor.setVelY(initJumpSpeed)
	end
end

jumping.onExit = function()
end

jumping.handleInput = function()
	if (Controller.ifButtonHeld(Buttons.RIGHT)) then
		GameActor.movingRight()
	end

	if (Controller.ifButtonHeld(Buttons.LEFT)) then
		GameActor.movingLeft()
	end

	if (Controller.ifButtonPressed(Buttons.DOWN)) then
		StateMachine.setNext('dive')
	end

	if (not Controller.ifButtonHeld(Buttons.JUMP)) then
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
