Root = {}

local chess_board_tiles = require("resources.scripts.chess-board-tiles")
chess_board_tiles.AddTiles(Root)
local chess_board_units = require("resources.scripts.chess-board-units")
chess_board_units.AddUnits(Root)
local clown_piece = require("resources.scripts.clown-piece")
--clown_piece.AddClownPiece(Root)

Root[#Root+1] = {	Name="Cursor",
	Id="Cursor",
	Systems = {
	"S2DGE","TILEPOS"
	},
	Properties = {
		{"S2DGE","Cursor.S2DGE"},
		{"TILEPOS","Cursor.TILEPOS"}
	}
}

Root[#Root+1] = {	Name = "Cursor.S2DGE",
	Statistics = {
		{"textured",1}
	},
	Dictionary = {
		{"texture","resources/cursor.png"}
	}
}	
	
Root[#Root+1] = {	Name = "Cursor.TILEPOS",
	Statistics = {
		{"x",0},
		{"y",0},
		{"z",1000},
		{"x-offset",0},
		{"y-offset",0}
	}
}