--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/onGround.lua
]]

onGround = {}

onGround.onEnter = function()
	GameActor.setSprite(Sprites.ON_GROUND)
end

onGround.onExit = function()
end

onGround.handleInput = function()
	if (Controller.getButtonState(Buttons.RIGHT)) then
		GameActor.moveRight()
	end

	if (Controller.getButtonState(Buttons.LEFT)) then
		GameActor.moveLeft()
	end

	if (Controller.ifButtonPressed(Buttons.NORMAL_ATTACK)) then
		StateMachine.setNext('normalAttack')
	end

	if (Controller.getButtonState(Buttons.JUMP)) then
		StateMachine.setNext('jumping')
	end
end

onGround.update = function()
end
