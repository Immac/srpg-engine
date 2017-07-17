Root = {}
--[[local inspect = require("resources.scripts.lib.inspect")
--]]
local cursor_level = 400;
local util = require("resources.scripts.mechanics.util")
local chess_board_tiles = require("resources.scripts.chess-board-tiles")
chess_board_tiles.AddTiles(Root)
local chess_board_units = require("resources.scripts.chess-board-units")
chess_board_units.AddUnits(Root)
local clown_piece = require("resources.scripts.clown-piece")
local menu = require("resources.scripts.mechanics.menu")

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
    {"z",cursor_level},
    {"x-offset",0},
    {"y-offset",0}
  }
}
Root[#Root+1] = {	Name="Highlight",
  Id="Highlight",
  Systems = {
    "S2DGE","TILEPOS"
  },
  Properties = {
    {"S2DGE","Highlight.S2DGE"},
    {"TILEPOS","Highlight.TILEPOS"}
  }
}

Root[#Root+1] = {	Name = "Highlight.S2DGE",
  Statistics = {
    {"textured",1}
  },
  Dictionary = {
    {"texture","resources/highlight.png"}
  }
}	

Root[#Root+1] = {	Name = "Highlight.TILEPOS",
  Statistics = {
    {"x",-1},
    {"y",-1},
    {"z",cursor_level},
    {"x-offset",0},
    {"y-offset",0}
  }
}

util.concatenate_table(Root,menu)
--[[print(inspect.inspect(Root))
]]