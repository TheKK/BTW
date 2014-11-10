--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/onGround.lua
]]

onGround = {}

onGround.onEnter = function(actor)
end

onGround.onExit = function(actor)
end

onGround.handleInput = function(actor, controller)
	if (getButtonState(controller, Buttons.BUTTON_RIGHT)) then
		moveRight(actor)
	end

	if (getButtonState(controller, Buttons.BUTTON_LEFT)) then
		moveLeft(actor)
	end

	--if (ifButtonPressed(controller, Buttons.BUTTON_NORMAL_ATTACK)) then
		--moveRight(actor)

	--if (getButtonState(controller, Buttons.BUTTON_RIGHT)) then
		--moveRight(actor)
end

onGround.update = function(actor)
end
