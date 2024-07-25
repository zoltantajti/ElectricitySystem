modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		
		if(GetGame().IsMultiplayer() && !GetGame().IsClient())
		{
			//Print("[ES] Szerver");
			ElectricitySystem ES = new ElectricitySystem();
		}
	}
	
	
}