local Table = {}
local Factory = {}
Factory.AddPawn = require("resources.scripts.piece-pawn").AddPawn
Factory.AddKnight = require("resources.scripts.piece-knight").AddKnight
Factory.AddBishop = require("resources.scripts.piece-bishop").AddBishop
Factory.AddQueen = require("resources.scripts.piece-queen").AddQueen
Factory.AddRook = require("resources.scripts.piece-rook").AddRook
Factory.AddKing = require("resources.scripts.piece-king").AddKing

local function AddUnits(root)

print("Adding units.")
local player1 = "white"
local player2 = "black"
local object_layer_index = 2;
local white_y = 1
local black_y = 6
	
for x = 0 , 7 do
	Factory.AddPawn(root,player1,x,white_y,object_layer_index)
	Factory.AddPawn(root,player2,x,black_y,object_layer_index)
end	
	Factory.AddRook  (root,player1,0,0,object_layer_index)
	Factory.AddKnight(root,player1,1,0,object_layer_index)
	Factory.AddBishop(root,player1,2,0,object_layer_index)
	Factory.AddQueen (root,player1,3,0,object_layer_index)
	Factory.AddKing  (root,player1,4,0,object_layer_index)
	Factory.AddBishop(root,player1,5,0,object_layer_index)
	Factory.AddKnight(root,player1,6,0,object_layer_index)
	Factory.AddRook  (root,player1,7,0,object_layer_index)
	
	Factory.AddRook  (root,player2,0,7,object_layer_index)
	Factory.AddKnight(root,player2,1,7,object_layer_index)
	Factory.AddBishop(root,player2,2,7,object_layer_index)
	Factory.AddQueen (root,player2,3,7,object_layer_index)
	Factory.AddKing  (root,player2,4,7,object_layer_index)
	Factory.AddBishop(root,player2,5,7,object_layer_index)
	Factory.AddKnight(root,player2,6,7,object_layer_index)
	Factory.AddRook  (root,player2,7,7,object_layer_index)
	
end
print('OK')
Table.AddUnits = AddUnits
return Table