class CfgPatches
{
	class ElectricitySystem
	{
		units[] = {
			"Z_Lamp",
			"Z_Lamp_City1",
			"Z_Lamp_City2",
			"Z_Lamp_City3"
		};
		weapons[] = {};
		requiredVersion=0.1;
		requiredAddons[]= {
			"DZ_Data",
			"DZ_Scripts",
			"ShowMEInfo",
			"DZ_Structures_Residential",
			"DZ_Structures_Rail",
			"DZ_Structures_Military",
			"DZ_Structures_Specific"
		};
	};
};
class CfgMods
{
	class ElectricitySystem
	{
		type = "mod";
		dependencies[]={
			"Game",
			"World",
			"Mission"
		};
		class defs{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"ElectricitySystem/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {
					"ElectricitySystem/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"ElectricitySystem/scripts/5_mission"
				};
			}
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class HouseNoDestruct;
	class Z_Generator: Inventory_Base
	{
		scope = 1;
		displayName = "Generator";
		model = "ElectricitySystem\models\generator\generator.p3d";
		attachments[]=
		{
			"SparkPlug"
		};
		soundImpactType="metal";
		fuelTankCapacity=100000;
		carveNavmesh=1;
		physLayer="item_large";
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyStorageMax=75000;
			energyUsagePerSecond=5;
			energyAtSpawn=0;
		};
		class AnimationSources
		{
			class sparkplug
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class fuel_tank
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class sparkplug_installed
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class dial_fuel
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};		
	};
	class Z_EMeter: Inventory_Base
	{
		scope = 1;
		displayName = "Electricity Meter";
		model = "ElectricitySystem\models\emeter\emeter.p3d";
	};
	class Z_StreetLamp: Inventory_Base
	{
		scope = 2;
		storageCategory = 10;
		model = "\dz\gear\consumables\Stone.p3d";
		hiddenSelections[]={
			"zbytek"
		};
		forceFarBuble = "true";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1;
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {2.5,2.5,2,0};
				brightness = 2.5;
				radius = 30;
				dayLight = 0;
			};
		};
	};
	class Z_InteriorLamp: Z_StreetLamp
	{
		scope = 2;
		class PointLights
		{
			class PointLight
			{
				color[] = {2.5,2.5,2,0};
				brightness = 1.25;
				radius = 30;
				dayLight = 0;
			};
		};
	};
	class Z_Switch: Inventory_Base
	{
		scope = 2;
		displayName = "Light Switch";
		model = "ElectricitySystem\models\switches\switch01.p3d"
		hiddenSelections[] = {
			"switchOn", 
			"switchOff"
		};
		hiddenSelectionsTextures[] = { 
			"ElectricitySystem\models\switches\switch01.paa",
			"ElectricitySystem\models\switches\switch01.paa"
		};
		class AnimationSources
		{
			class switchOn
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class switchOff
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};

	class Z_Lamp_Base: HouseNoDestruct
	{
		scope = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
		};
	};
	class Z_Lamp_City1: Z_Lamp_Base
	{
		scope = 2;
		model = "\DZ\Structures\residential\misc\lamp_city1.p3d";
	};
	class Z_Lamp_City2: Z_Lamp_Base
	{
		scope = 2;
		model = "\DZ\Structures\residential\misc\lamp_city2.p3d";
	};
	class Z_Lamp_City3: Z_Lamp_Base
	{
		scope = 2;
		model = "\DZ\Structures\residential\misc\lamp_city3.p3d";
	};
	
	class Land_House_2B01: HouseNoDestruct
	{
		class ElectricSystem
		{
			EMeter[] = {
				"-3.05429699999877 -2.301579 -4.97433599999931"
			};
			Lamps[]=
			{
				"-1.35429699999986 -1.875989 2.82566400000087",
				/*"-1.15429699999913 -1.574439 -3.79433599999993",
				"1.14570300000014 1.490611 -0.814335999999457",
				"-1.2542969999995 1.302111 2.97566400000051"*/
			};			
			Switches[] = {
				"2.89746100000048 -2.816888 0.788086000000476"
			};
			SwitchesOri[] = {
				"-90 0 0"
			};
		};
	};
};
class CfgNonAIVehicles
{
	class StaticObject;
	class Static_Pole_Base: StaticObject
	{
		scope = 0;
	};
	class Static_Lamp_City1: Static_Pole_Base
	{
		scope = 2;
		model = "\DZ\Structures\residential\misc\lamp_city1.p3d";
	}
	class Static_Lamp_City2: Static_Pole_Base
	{
		scope = 2;
		model = "\DZ\Structures\residential\misc\lamp_city2.p3d";
	}
	class Static_Lamp_City3: Static_Pole_Base
	{
		scope = 2;
		model = "\DZ\Structures\residential\misc\lamp_city3.p3d";
	}
};