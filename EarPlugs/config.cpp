class CfgPatches
{
  class EarPlugs //This should match the class in the CfgMods section
  {
    requiredAddons[]={}; //This is the mods required to load before this one since this mod doesn't need any other mods you can leave this blank
  };
};

class CfgMods
{
  class EarPlugs
  {
    name="Super Cool Ear Plugs Mod"; // The name for your mod will also show in the keybinds menu
    type="mod";
    dependencies[]={"Mission"}; //The list of dependencies for which modules you will be modding for this example we are only modding the Mission module
    inputs="EarPlugs\data\inputs.xml"; //This it path to the inputs.xml for defining your keybinds more to follow on this part
    class defs
    {
      class missionScriptModule
      {
        files[]=
        {
          "EarPlugs/scripts/5_Mission" //This must be the path to the folder in which your scripts are contained for the specificed module
        };
      };
    };
  };
};