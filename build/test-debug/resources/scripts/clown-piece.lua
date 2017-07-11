local Table = {}

local function AddClownPiece(root)
print("Adding units.")
	root[#root+1] = {	Name="Clownpiece",
	Id="Clownpiece",
	Systems = {
	"S2DGE","TILEPOS"
	},
	Statistics = {
	},
	Dictionary = {
	},
	Properties = {
		{"S2DGE","Clownpiece.S2DGE"},
		{"TILEPOS","Clownpiece.TILEPOS"}
	}
}

root[#root+1] = {	Name = "Clownpiece.S2DGE",
	Statistics = {
		{"x",0},
		{"y",0},
		{"z",3},
		{"height",64},
		{"width",64},
		{"alpha",255},
		{"red",255},
		{"green",255},
		{"blue",255},
		{"textured",1}
	},
	Dictionary = {
		{"texture","resources/clownpiece-1.png"}
	}
}

root[#root+1] = {	Name = "Clownpiece.TILEPOS",
	Statistics = {
		{"x",4},
		{"y",4},
		{"z",2},
		{"x-offset",11},
		{"y-offset",5}
	}
}
end

Table.AddClownPiece = AddClownPiece
return Table