local Table = {}
local Factory = {}
Factory.AddPiece = require("resources.scripts.piece-generic").AddPiece

local function AddKing(root,owner,x,y,z)
print("Adding King for: " .. owner .. " at x: " .. x .. " y:" .. y )
local name = "King"
local resource_directory = "resources/"
local file_name_base = "king"
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
Table.AddKing = AddKing
return Table