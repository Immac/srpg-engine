local Table = {}
local Factory = {}
Factory.AddPiece = require("resources.scripts.piece-generic").AddPiece

local function AddKnight(root,owner,x,y,z)
print("Adding Knight for: " .. owner .. " at x: " .. x .. " y:" .. y )
local name = "Knight"
local resource_directory = "resources/"
local file_name_base = "knight"
local file_name_extenesion = ".png"
local file_name_path = "";
if owner == "white" then
	file_name_path = resource_directory .. file_name_base .. "-" .. owner .. file_name_extenesion
end
if owner == "black" then
	file_name_path = resource_directory .. file_name_base .. "-" .. owner .. file_name_extenesion
end

Factory.AddPiece(root,owner,x,y,z,name,file_name_path)
end
print("OK")
Table.AddKnight = AddKnight
return Table