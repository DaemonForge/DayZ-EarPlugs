//Use the modded key word to tell the compiler you are modding the class
modded class MissionGameplay
{   
	// This is our global varible for keeping track of which state the ear plugs are in and we are initializing it with false cause they will start false
	bool m_IsEarPlugsEnabled = false;

	// Creating a reference variable for the earplugs widget and creating it when the game loads
	ref EarPlugsWidget m_earplugswidget = new EarPlugsWidget;
	
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
			
            //Running in Offline Mod we need to use this method to send a message to chat so we know if the key bind has been pressed
            //this.m_Chat.Add( new ChatMessageEventParams( CCSystem, "", "EarPlugs Toggle is Pressed", "" ) );
			
			//If the EarPlugs are currently disabled we will then enable them
			if (m_IsEarPlugsEnabled == false){ 
			    //Set the m_IsEarPlugsEnabled to be enabled
				m_IsEarPlugsEnabled = true;
				
				// we are using the  GetGame().GetSoundScene().SetSoundVolume(float vol, float time); to set the volume back to 0.1 (10%) over a period of 1 second
				GetGame().GetSoundScene().SetSoundVolume(0.1,1);
				
				//Calling our Function to change the icon
				m_earplugswidget.SetIcon("EarPlugs\\data\\volume_mute.edds");
				
				//Send message to chat
				//GetGame().Chat("EarPlugs are now Enabled");
				//Running in Offline Mod we need to use this method to send a message to chat so we know if the key bind has been pressed
				//this.m_Chat.Add( new ChatMessageEventParams( CCSystem, "", "EarPlugs are now Enabled", "" ) );
				
			} else { // else (meaning the are enabled) we will disable them
				
				//Set the m_IsEarPlugsEnabled to be disabled
				m_IsEarPlugsEnabled = false;
				
				// we are using the  GetGame().GetSoundScene().SetSoundVolume(float vol, float time); to set the volume back to 1 (100%) over a period of 1 second
				GetGame().GetSoundScene().SetSoundVolume(1,1);	
				
			
				//Calling our Function to change the icon
				m_earplugswidget.SetIcon("EarPlugs\\data\\volume_up.edds");
				
				
				//Send message to chat
				//GetGame().Chat("EarPlugs are now Disabled");
				//Running in Offline Mod we need to use this method to send a message to chat so we know if the key bind has been pressed
				//this.m_Chat.Add( new ChatMessageEventParams( CCSystem, "", "EarPlugs are now Disabled", "" ) );
			}
		}
	}
}