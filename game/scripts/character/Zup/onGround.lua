--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/onGround.lua
]]

onGround = {}

onGround.onEnter = function(actor)
	setSprite(actor, Sprites.ON_GROUND)
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
		--attack(actor)
	--end

	if (getButtonState(controller, Buttons.BUTTON_JUMP)) then
		StateMachine.setNext(FSM, 'jumping')
	end
end

onGround.update = function(actor)
end
