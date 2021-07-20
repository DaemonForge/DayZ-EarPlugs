//Use the modded key word to tell the compiler you are modding the class
modded class MissionGameplay
{   
	
	// This is our global varible for keeping track of which state the ear plugs are in and we are initializing it with 0 cause its full volume
	int m_EarPlugsState = 0;

	// Creating a reference variable for the earplugs widget and creating it when the game loads
	autoptr EarPlugsWidget m_earplugswidget = new EarPlugsWidget;
	
	// You also need to use the override keyword to override the function, it needs to match exactly as it is from the base class you are overriding including the variable name
	override void OnUpdate(float timeslice)
	{        
		// Using the super.function ensures that the function is called across other mods as well as the vanilla code
		super.OnUpdate(timeslice); 
		
		// We are using the GetGame().GetInput().LocalPress("KeyBind") to detect if our keybind is pressed This must match exactly as it is writen in the inputs.xml we did above
		// The current Menu must be null and the key bind must be pressed and Using the && means both these coniton met before it will work, 
		if ( GetGame().GetInput().LocalPress("UAEarPlugsToggle") && GetGame().GetUIManager().GetMenu() == NULL ) 
		{
			
			//Send message to chat everytime keybind is pressed
			//GetGame().Chat("EarPlugs Toggle is Pressed");
						
			//If the EarPlugs are currently disabled we will then enable them
			if (m_EarPlugsState == 0) {  // If we are at state 0 we go to state 1 which is 45% volume
				
				//incerment the EarPlugsState
				m_EarPlugsState++;
				
				// set the volume to 0.45 (45%) over a period of 1 second
				GetGame().GetSoundScene().SetSoundVolume(0.45,1);	
			
				//Calling our Function to change the icon
				m_earplugswidget.SetIcon("EarPlugs\\data\\volume_mid.edds");
				
			} else if (m_EarPlugsState == 1) { //If we are in current state 1 we go to state 2 wich is 8% volume
				
				//incerment the EarPlugsState
				m_EarPlugsState++;
				
				// set the volume to 0.08 (8%) over a period of 1 second
				GetGame().GetSoundScene().SetSoundVolume(0.08,1);	
			
				//Calling our Function to change the icon
				m_earplugswidget.SetIcon("EarPlugs\\data\\volume_low.edds");
				
			} else if (m_EarPlugsState == 2) {  //If current state is 2 then we go to state state 3 which is full mute
				
				//incerment the EarPlugsState
				m_EarPlugsState++;
				
				// Set the volume to 0 (0%) over a period of 1 second
				GetGame().GetSoundScene().SetSoundVolume(0,1);	
			
				//Calling our Function to change the icon
				m_earplugswidget.SetIcon("EarPlugs\\data\\volume_off.edds");
				
			}  else if (m_EarPlugsState >= 3) {  //If we are current in state 3 then we go back to state 0 which is full volume
			    
				//Set the m_EarPlugsState back to 0
				m_EarPlugsState = 0;
				
				// to set the volume to 1 (100%) over a period of 1 second
				GetGame().GetSoundScene().SetSoundVolume(1,1);
				
				//Calling our Function to change the icon
				m_earplugswidget.SetIcon("EarPlugs\\data\\volume_full.edds");
				
			}
			
		}
		
	}
	
}