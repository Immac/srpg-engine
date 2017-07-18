Root = {}


local main_scene = require("resources.scripts.scenes.main-screen.main-scene")
local chess_scene = require("resources.scripts.scenes.chess.chess-scene")


local cursor_level = 400;
local util = require("resources.scripts.util.util")

--[[local chess_board_tiles = require("resources.scripts.chess-board-tiles")
chess_board_tiles.AddTiles(Root)
local chess_board_units = require("resources.scripts.chess-board-units")
chess_board_units.AddUnits(Root)
local clown_piece = require("resources.scripts.clown-piece")
local menu = require("resources.scripts.mechanics.menu")
--]]
--clown_piece.AddClownPiece(Root)

Root[#Root+1] = {	Name="Cursor",
  Id="Cursor",
  Systems = {
    "S2DGE","TILEPOS"
  },
  Properties = {
    {"graphics","cursor.graphics"},
    {"S2DGE","Cursor.S2DGE"},
    {"TILEPOS","Cursor.TILEPOS"}
  }
}

Root[#Root+1] = {	Name="cursor.graphics",
  Properties = {
    {"position","cursor.position"},
    {"size","cursor.size"}
  },
  Dictionary = {
    {"texture" ,"resources/cursor.png"}
    }
}


Root[#Root+1] = {	Name="cursor.position",
    Statistics = {
    {"x",0},
    {"y",0},
    {"z",cursor_level},
    {"x-offset",0},
    {"y-offset",0}
  }
}

Root[#Root+1] = {	Name="cursor.size",
    Statistics = {
    {"width",64},
    {"height",64}
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
    {"graphics","highlight.graphics"},
    {"S2DGE","Highlight.S2DGE"},
    {"TILEPOS","Highlight.TILEPOS"}
  }
}

Root[#Root+1] = {	Name="highlight.graphics",
  Properties = {
    {"position","highlight.position"},
    {"size","highlight.size"}
  },
  Dictionary = {
    {"texture" ,"resources/highlight.png"}
    }
}


Root[#Root+1] = {	Name="highlight.position",
    Statistics = {
    {"x",0},
    {"y",0},
    {"z",cursor_level},
    {"x-offset",0},
    {"y-offset",0}
  }
}

Root[#Root+1] = {	Name="highlight.size",
    Statistics = {
    {"width",64},
    {"height",64}
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
    {"x",0},
    {"y",0},
    {"z",cursor_level},
    {"x-offset",0},
    {"y-offset",0}
  }
}



util.concat_table(Root,main_scene)
--[[
local inspect = require("resources.scripts.lib.inspect")
print(inspect.inspect(Root))
--]]