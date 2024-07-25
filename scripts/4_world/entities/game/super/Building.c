modded class House : BuildingBase
{
	ref array<string> positions;
	ref array<string> e_positions;
	ref array<string> s_positions;
	ref array<string> s_orientations;
	ref array<Z_Switch> switches = new array<Z_Switch>;
	ref array<Z_InteriorLamp> lamps = new array<Z_InteriorLamp>;

	void initElectric(vector housePos, string houseName)
	{
		this.initSwitches(housePos, houseName);
		this.initEMeter(housePos,houseName);
	}
	void initSwitches(vector housePos, string houseName)
	{
		string cfgPath = "cfgVehicles " + houseName + " ElectricSystem Switches";
		string oriPath = "cfgVehicles " + houseName + " ElectricSystem SwitchesOri";
		if(GetGame().ConfigIsExisting(cfgPath) && GetGame().ConfigIsExisting(oriPath))
		{
			s_positions = new array<string>;
			s_orientations = new array<string>;
			GetGame().ConfigGetTextArray(cfgPath, s_positions);
			GetGame().ConfigGetTextArray(oriPath, s_orientations);
			for(int i = 0; i < s_positions.Count(); i++)
			{
				vector pos = s_positions[i].ToVector();
				vector ori = s_orientations[i].ToVector();
				Z_Switch sw = AddItem(this,pos,ori,"Z_Switch");
				this.getLinkedLamp(housePos, houseName, sw, i);				
				switches.Insert(sw);
			}
		}else{
			Print("[ES] Not found the config: " + cfgPath);
		}
	}
	void getLinkedLamp(vector housePos, string houseName, Z_Switch sw, int index)
	{
		string cfgPath = "cfgVehicles " + houseName + " ElectricSystem Lamps";
		if(GetGame().ConfigIsExisting(cfgPath)){
			positions = new array<string>;
			GetGame().ConfigGetTextArray(cfgPath, positions);
			vector pos = positions[index].ToVector();
			Z_InteriorLamp lamp = AddItem(this,pos,vector.Zero,"Z_InteriorLamp");
			sw.initLamp(lamp, index);
			lamps.Insert(lamp);			
		}else{
			Print("[ES] Not found the config: " + cfgPath);
		};
	}
	void initEMeter(vector housePos, string houseName)
	{
		string cfgPath = "cfgVehicles " + houseName + " ElectricSystem EMeter";
		if(GetGame().ConfigIsExisting(cfgPath)){
			e_positions = new array<string>;
			GetGame().ConfigGetTextArray(cfgPath, e_positions);
			for ( int j = 0; j < e_positions.Count(); j++ )			
			{
				vector pos = e_positions[j].ToVector();
				vector WorldPos = housePos + pos;
				AddItem(this, pos, "0.0 0.0 0.0", "Z_EMeter");
			};
		}else{
			Print("[ES] Not found the config: " + cfgPath);
		};
	}
	Object AddItem(Object parent, vector offset, vector orientation, string point)
	{
		Print("[ADDITEM]: " + point + "; pos: " + offset + "; ori: " + orientation + "; parent: " + parent.ClassName());
		Object light = GetGame().CreateObject(point, vector.Zero);
		light.SetPosition(offset);
		light.SetOrientation(orientation);
		parent.AddChild(light, -1, false);
		light.Update();
		return light;
	}
	array<Z_InteriorLamp> getLamps()
	{
		return this.lamps;
	}
}
modded class Land_House_2B01: House
{
}