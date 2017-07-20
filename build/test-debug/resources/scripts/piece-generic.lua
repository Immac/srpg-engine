local Table = {}

local function AddPiece(root,owner,x,y,z,name,texture_path,facing)
  print("Adding " .. name .. " for: " .. owner .. " at x: " .. x .. " y:" .. y )
  local piece_name = name .. #root+1
  local s2dge = piece_name .. ".S2DGE"
  local tile_position_system = piece_name .. ".TILEPOS"
  local simple_sound_system = piece_name .. ".SSS"
  local simple_action_system = piece_name .. ".SAS"
  local actions = piece_name .. ".actions"
  
  
  local sprite = {}
-- PIECE --
  root[#root+1] = { Name = piece_name,
    Id=piece_name,
    Systems = {
      "S2DGE","TILEPOS","SSS","SAS"
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
      {"textured",1},
      {"has-moved",0}
    },
    Dictionary = {
      {"owner",owner},
      {"facing",facing},
    },
    Properties = {
      {"S2DGE",s2dge},
      {"TILEPOS",tile_position_system},
      {"SSS",simple_sound_system},
      {"SAS",simple_action_system},
      {"sound_effects",piece_name .. ".sound_effects"},
      {"actions",piece_name..".actions"},
    },
    Tags = {
      "piece"
    }
  }
  -- ACTIONS --
  root[#root+1] = { Name = piece_name..".actions",
    Properties = {
      {"move",piece_name.."move"}
      }
    }
-- MOVEMENT --
  root[#root+1] = { Name = piece_name.."move",
      Properties = {
        {"statistics",piece_name..".move_stats"}
      },
      Statistics = {
        {"exclude_specific",1},
        {"target_specific",0},
        {"target_position",1}
        },
      Dictionary = {
        {"range",name.."_movement_range"},
        {"target_type",""},
        {"target_exclude","piece"},
        {"direct_object","self"}
      },
    }
    -- STATS AFFECTED BY MOVE --
    root[#root+1] = { Name = piece_name..".move_stats",
    Tags = {
      }
  }
    
-- SFX --
  root[#root+1] = { Name = piece_name..".sound_effects",
    Dictionary = {
      {"select","resources/sound/sfx/generic-select.wav"}
    }
  }


-- S2DGE --
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

-- TILEPOS --
  root[#root+1] = {	Name = tile_position_system,
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

-- SSS --
  root[#root+1] = {	Name = simple_sound_system,

  }

-- SAS -- 
  root[#root+1] = {	Name = simple_action_system,

  }
end
print("OK")
Table.AddPiece = AddPiece
return Table