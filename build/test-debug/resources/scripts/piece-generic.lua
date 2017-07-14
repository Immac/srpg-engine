local Table = {}

local function AddPiece(root,owner,x,y,z,name,texture_path)
  print("Adding " .. name .. " for: " .. owner .. " at x: " .. x .. " y:" .. y )
  local piece_name = name .. #root+1
  local s2dge = piece_name .. ".S2DGE"
  local tilepos = piece_name .. ".TILEPOS"
  local sss = piece_name .. ".SSS"
  local sprite = {}

  root[#root+1] = { Name = piece_name,
    Id=piece_name,
    Systems = {
      "S2DGE","TILEPOS","SSS"
    },
    Statistics = {
      {"x",x},
      {"y",y},
      {"z",z},
      {"height",64},
      {"width",64},
      {"alpha",255},
      {"red",255},
      {"green",255},
      {"blue",255},
      {"textured",1}
    },
    Dictionary = {
      {"owner",owner}
    },
    Properties = {
      {"S2DGE",s2dge},
      {"TILEPOS",tilepos},
      {"SSS",sss},
      {"sound_effects",piece_name .. ".sound_effects"}
    }
  }

  root[#root+1] = { Name = piece_name..".sound_effects",
    Dictionary = {
      {"select","resources/sound/sfx/generic-select.wav"}
    }
  }

  root[#root+1] = {	Name = s2dge,
    Statistics = {
      {"x",x},
      {"y",y},
      {"z",z},
      {"height",64},
      {"width",64},
      {"alpha",255},
      {"red",255},
      {"green",255},
      {"blue",255},
      {"textured",1}
    },
    Dictionary = {
      {"texture",texture_path}
    }
  }

  root[#root+1] = {	Name = tilepos,
    Statistics = {
      {"x",x},
      {"y",y},
      {"z",z},
      {"x-offset",0},
      {"y-offset",0},
      {"facing",0},
      {"is-selected",0}
    }
  }

  root[#root+1] = {	Name = sss,

  }
end
print("OK")
Table.AddPiece = AddPiece
return Table