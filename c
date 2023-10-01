local grmt = getrawmetatable(game)
local backupindex = grmt.__index
setreadonly(grmt, false)

local grmt = getrawmetatable(game)
local backupindex = grmt.__index
setreadonly(grmt, false)
local properties = {
	"Hit"
}

local SelectedPart = GetClosestBodyPart()
Trollster_CONSTRUCTORS.Data.Silent_Target = ClosestPlrFromMouse()

grmt.__index = newcclosure(function(self, v)
	if getgenv().Euleon.Silent.Enabled and Mouse and table.find(properties, v) then

		Prey = ClosestPlrFromMouse()

		if Prey then			
			local endpoint = PredictionictTargets2(Prey, getgenv().Euleon.Silent.Prediction)

			return (tostring(v) == "Hit" and endpoint + VelocityCheck())

		end
	end
	return backupindex(self, v)

end)
