--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/onGround.lua
]]

onGround = {}

onGround.onEnter = function(actor)
	GameActor.setSprite(Sprites.ON_GROUND)
end

onGround.onExit = function(actor)
end

onGround.handleInput = function(actor, controller)
	if (getButtonState(controller, Buttons.RIGHT)) then
		GameActor.moveRight()
	end

	if (getButtonState(controller, Buttons.LEFT)) then
		GameActor.moveLeft()
	end

	if (ifButtonPressed(controller, Buttons.NORMAL_ATTACK)) then
		StateMachine.setNext('normalAttack')
	end

	if (getButtonState(controller, Buttons.JUMP)) then
		StateMachine.setNext('jumping')
	end
end

onGround.update = function(actor)
end
