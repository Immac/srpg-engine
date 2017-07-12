Root = {
	{
		Name = "Config",
		Properties = {
			{"S2DGE.Config","S2DGE.Config"},
			{"Core.Config","Core.Config"}
		}
	},
	{
		Name = "Core.Config",
		Systems = {
			"Core"
		},
		Properties = {
			{"SystemList","SystemList"}
		},
		Dictionary = {
			{"game_object_database_filepath","resources/scripts/game-objects.lua"}
		},
		Tags = {
			"config"
		}
	},
	{
		Name = "SystemList",
		Tags = {
			"S2DGE",
			"SPS"
		}
	},
	{
		Name = "S2DGE.Config",
		Systems = {
			"S2DGE"
		},
		Tags = {
			"config"
		},
		Properties = {
			{"Video","Video"}
		},
		Statistics = {
			{"vsync",0},
			{"frame_limit",60},
			{"step_update_time_in_ms",16}
		},
		Dictionary = {
			{"window_title","Title :D"}
		}
	},
	{
		Name = "Video",
		Statistics = {
					{"width",1280},
					{"height",720},
				}
	},
	{
		Name="TILEPOS.Config",
		Systems = {
			"TILEPOS"
		},
		Tags = {
			"config"
		},
		Statistics = {
			{"tile_size",64},
		},
		Dictionary = {
			{"dummy","dummy"}
		}
	}
}