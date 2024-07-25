#define DEBUG

class Z_Generator extends PowerGeneratorBase {
	static int EffectRadius = 1000;
	static int Lamps = 0;
	ref array<Object> streetLamps = new array<Object>();
	ref array<Object> interiorLamps = new array<Object>();
	bool PowerOutput = false;
	vector Position = "0 0 0";
	
	override void EOnInit(IEntity other, int extra)
	{
		super.EOnInit(other,extra);
		
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.searchLamps, 70, false);

		#ifdef DEBUG
		EntityAI entity;
		if (Class.CastTo(entity, this))
		{
			entity.GetInventory().CreateInInventory("SparkPlug");
		};		
		SetFuel(GetMaxFuel());
		#endif

		if(GetGame().IsServer())
        {
            SetSynchDirty();
        };
	}
	
	void searchLamps()
	{
		this.Position = this.GetPosition();
		array<Object> subObjects = new array<Object>;
		GetGame().GetObjectsAtPosition(this.Position, this.EffectRadius, subObjects, NULL);
		foreach(Object item: subObjects)
		{
			if(item.ClassName() == "Static_Lamp_City1")
			{
				this.Lamps++;
				streetLamps.Insert(ObjToObj(item, "Z_StreetLamp", "0.0 0.0 0.0"));
			};
			if(item.ClassName() == "Land_House_2B01")
			{
				House house;
				Class.CastTo(house,item);
				house.initElectric(item.GetPosition(), item.ClassName());
			};
		};
		Print("[ES] " + Lamps + " lamp found");
	}
	
	void InteractionWithItems(bool state)
	{
		PowerOutput = state;
		foreach(Object item: this.streetLamps)
		{
			Z_StreetLamp light;
			if(Class.CastTo(light, item))
			{
				light.setElectricity(state);
			};
		}
		foreach(Object iitem: this.interiorLamps)
		{
			Z_InteriorLamp ilight;
			if(Class.CastTo(ilight, iitem))
			{
				ilight.setElectricity(state);
				ilight.TryTurnOn();
			};
		}
	}
	
	override bool CanPutIntoHands(EntityAI player)
	{
		return false;
	}
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionPullOutPlug);
		AddAction(ActionTurnOnPowerGenerator);
		AddAction(ActionTurnOffPowerGenerator);
	}
	
	override bool CanAddFuel(ItemBase container)
	{
		return super.CanAddFuel(container);
	}
	
	override void OnWorkStart() {
		super.OnWorkStart();
		this.InteractionWithItems(true);
	}
	
	override void OnWork(float consumed_energy) {
		super.OnWork(consumed_energy);
	}
	
	override void OnWorkStop() {
		super.OnWorkStop();
		this.InteractionWithItems(false);
	}
}