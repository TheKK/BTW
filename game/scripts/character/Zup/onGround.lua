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
	if (Controller.ifButtonHeld(Buttons.RIGHT) and Controller.ifButtonHeld(Buttons.LEFT)) then
		GameActor.stopMoving()
	else if (Controller.ifButtonHeld(Buttons.RIGHT)) then
		GameActor.movingRight()
	else if (Controller.ifButtonHeld(Buttons.LEFT)) then
		GameActor.movingLeft()
	else
		GameActor.stopMoving()
	end
end
end

	--if (Controller.ifButtonPressed(Buttons.NORMAL_ATTACK)) then
		--StateMachine.setNext('normalAttack')
	--end

	--if (Controller.ifButtonHeld(Buttons.JUMP)) then
		--StateMachine.setNext('jumping')
	--end
end

onGround.update = function()
end
