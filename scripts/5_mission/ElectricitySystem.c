class ElectricitySystem
{
	void ElectricitySystem()
	{
		//Print("[ES] Running; Spawning Generator");
		Z_Generator g = SpawnObject("Z_Generator", "13373.3 6.98359 5437.52", "90.3896 0.0 0.0");
		//Print("[ES] GEN Spawned " + g.GetPosition() + "");
		
	}
}