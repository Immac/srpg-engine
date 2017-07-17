local Table = {}
local base_tile_name = "tile";
local tile_location = "resources/tile-"
local tile_is_white = true;
local extension = ".png";
local tile_rows = 8;
local tile_lines = 8;

local function AddTiles(root)
  print("Adding tiles.")
  for i=0, tile_lines - 1 do
    for j=0, tile_rows - 1 do
      root[#root+1] = {	Name="WhiteTile" .. i .. j,
        Id="WhiteTile",
        Systems = {
          "S2DGE","TILEPOS"
        },
        Statistics = {
        },
        Dictionary = {
        },
        Properties = {
          {"S2DGE","WhiteTile.S2DGE" .. i .. j},
          {"TILEPOS","WhiteTile.TILEPOS" .. i .. j}
        }
      }

      local tile_color;
      if tile_is_white then
        tile_color = "white"
      else
        tile_color = "black"
      end

      local texture_path = tile_location .. tile_color .. extension;
      root[#root+1] = {	Name = "WhiteTile.S2DGE"..i..j,
        Statistics = {
          {"x",j},
          {"y",i},
          {"display_x",i},
          {"display_y",j},
          {"z",1},
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
      tile_is_white = not tile_is_white

      root[#root+1] = {	Name = "WhiteTile.TILEPOS" .. i .. j,
        Statistics = {
          {"x",j},
          {"y",i},
          {"z",1}
        }
      }
    end
    if tile_rows % 2 == 0 then
      tile_is_white = not tile_is_white
    end
  end

end

Table.AddTiles = AddTiles

return Table