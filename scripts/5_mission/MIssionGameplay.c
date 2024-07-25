modded class MissionGameplay
{
	override void OnInit()
	{
		super.OnInit();
		
		if(!GetGame().IsMultiplayer() && !GetGame().IsClient())
		{
			//Print("[ES] Kliens");
			ElectricitySystem ES = new ElectricitySystem();
		}
	}
}