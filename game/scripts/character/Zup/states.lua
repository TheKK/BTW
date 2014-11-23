--[[
-- Author: KK <thumbd03803@gmail.com>
--
-- File: game/scripts/character/Zup/states.lua
]]

-- Use this script to inclue all the state this character need!
package.path = package.path .. ';./game/scripts/character/Zup/?.lua'

require 'onGround'
require 'jumping'
require 'dive'
require 'normalAttack'

-- Make a variable "ownerAddr" to store the finite state machine that own this
-- Lua script
ownerAddr = ''
