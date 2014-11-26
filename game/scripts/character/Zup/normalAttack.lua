--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/normalAttack.lua
]]

local frame;

normalAttack = {}

normalAttack.onEnter = function()
	GameActor.setSprite(Sprites.NORMAL_ATTACK)

	frame = 0
end

normalAttack.onExit = function()
end

normalAttack.handleInput = function()
	if (Controller.getButtonState(Buttons.RIGHT)) then
		GameActor.moveRight()
	end

	if (Controller.getButtonState(Buttons.LEFT)) then
		GameActor.moveLeft()
	end
end

normalAttack.update = function()
	frame = frame + 1

	if (frame == 5) then
		GameActor.normalAttack()
		StateMachine.setNext('onGround')
	end
end
