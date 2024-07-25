class Z_Lamp_Base extends BuildingSuper
{
	void SetLamps()
	{
		string memPoint1 = "sound_rainobjectinner0spotmetal1_1";
		string memPoint2 = "sound_rainobjectinner0spotmetal1_2";
		string memPoint3 = "sound_rainobjectinner0spotmetal1_3";
		if(MemoryPointExists(memPoint1))
		{
			Z_StreetLamp z_lamp1A = Z_StreetLamp.Cast(GetGame().CreateObject("Z_StreetLamp", vector.Zero));
			z_lamp1A.AttachOnMemPoint(this,memPoint1);
			Print("[ES] memPoint1 Found on <" + this.GetType() + "> Attaching Lamp[]");
		};
		if(MemoryPointExists(memPoint2))
		{
			Z_StreetLamp z_lamp2B = Z_StreetLamp.Cast(GetGame().CreateObject("Z_StreetLamp", vector.Zero));
			z_lamp2B.AttachOnMemPoint(this,memPoint2);
			Print("[ES] memPoint2 Found on <" + this.GetType() + "> Attaching Lamp[]");
		};
		if(MemoryPointExists(memPoint3))
		{
			Z_StreetLamp z_lamp3C = Z_StreetLamp.Cast(GetGame().CreateObject("Z_StreetLamp", vector.Zero));
			z_lamp3C.AttachOnMemPoint(this,memPoint3);
			Print("[ES] memPoint2 Found on <" + this.GetType() + "> Attaching Lamp[]");
		};
	}
	void RaisePole()
	{
		vector pos = this.GetPosition();
		vector YPos = pos + "0 2.40 0";
		this.SetPosition(YPos);
		Print("[ES] Raising Pole <" + this.GetType() + "> to <" + this.GetPosition() + "> --[]");
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.SetLamps, 20, false);
	}
	void Z_Lamp_Base()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.SetLamps, 70, false);
	}
}
class Z_Lamp_City1: Z_Lamp_Base
{
};
class Z_Lamp_City2: Z_Lamp_Base
{
};
class Z_Lamp_City3: Z_Lamp_Base
{
};