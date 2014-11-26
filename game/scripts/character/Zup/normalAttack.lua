--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/normalAttack.lua
]]

local frame;

normalAttack = {}

normalAttack.onEnter = function(actor)
	GameActor.setSprite(Sprites.NORMAL_ATTACK)

	frame = 0
end

normalAttack.onExit = function(actor)
end

normalAttack.handleInput = function(actor, controller)
	if (getButtonState(controller, Buttons.RIGHT)) then
		GameActor.moveRight()
	end

	if (getButtonState(controller, Buttons.LEFT)) then
		GameActor.moveLeft()
	end
end

normalAttack.update = function(actor)
	frame = frame + 1

	if (frame == 5) then
		GameActor.normalAttack()
		StateMachine.setNext('onGround')
	end
end
