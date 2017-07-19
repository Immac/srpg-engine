local Table = {}
local Factory = {}
Factory.AddPiece = require("resources.scripts.piece-generic").AddPiece

local function AddPawn(root,owner,x,y,z)
print("Adding Pawn for: " .. owner .. " at x: " .. x .. " y:" .. y )
local name = "Pawn"
local resource_directory = "resources/"
local file_name_base = "pawn"
local file_name_extenesion = ".png"
local file_name_path = "";
local facing = ""
if owner == "white" then
	file_name_path = resource_directory .. file_name_base .. "-" .. owner .. file_name_extenesion
  facing = "south"
end
if owner == "black" then
	file_name_path = resource_directory .. file_name_base .. "-" .. owner .. file_name_extenesion
  facing = "north"
end

local p = Factory.AddPiece(root,owner,x,y,z,name,file_name_path,facing)
--[[root[#root+1] = pawn["game-object"];
root[#root+1] = pawn["s2dge"];
root[#root+1] = pawn["tilepos"];
--]]
end
print("OK")
Table.AddPawn = AddPawn
return Table