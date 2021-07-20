//We are creating a new class named EarPlugsWidget and Exending Managed so there is memory clean up.
class EarPlugsWidget extends Managed 
{			
	//We are declaring a ImageWidget variable so we can reference it when neasary
	autoptr ImageWidget			m_icon;
	
	//To make sure we can remove the call que if its active we will have a bool called call 
	float						m_iconalpha = 0;
	
	//When an object of the class is instantiate(created) then we need to create the widget
	void EarPlugsWidget()
	{
		// we are creating the widget using the layout we created, as well as setting it to the ref variable
		m_icon 	= ImageWidget.Cast(GetGame().GetWorkspace().CreateWidgets( "EarPlugs/data/earplugs.layout" ));
		
		//Setting the icon to be hidden by default
		m_icon.Show(false);
		
		// you could set the default image path in the layout but just going to set it here to show you how
		// m_icon.LoadImageFile( 0, "EarPlugs\\data\\volume_up.edds" );
		
	}

	//When an object of the object is destroyed this class is called
	void ~EarPlugsWidget()
	{
		//first we make sure the image is hidden
		m_icon.Show(false);
		
		//If the call Queue is currently active remove it to prevent null pointer errors
		if (m_iconalpha != 0){
	 		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.HideIcon);
		}
		
		//Then delete the reference to the icon widget
		delete m_icon;
	}

	//This is the function we will calling to change the image for the icon
	void SetIcon(string imagePath)
	{
		
		//This set the image to the image path provided in the function call
		m_icon.LoadImageFile( 0, imagePath );
		
		//Since it will now be hidden we need to show it as well
		m_icon.Show(true);
		
		
		//Setting the new alpha to be 1 reseting it so the icon shows up
 		m_iconalpha = 1;
		//Set the icons Alpha back to full
		m_icon.SetAlpha(m_iconalpha);
		
		//Creating a call Queue to hide the Icon in a loop slowly reduce the alpha till its 0
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.HideIcon, 20, true);
		
	}
	
	//This is the function we will use to fade the icon off the screen
	void HideIcon(){
		
		//If the alpha is over 90% reduce it at a slower rate should make it apear more solid for longers
		if (m_iconalpha > 0.90){
			m_iconalpha = m_iconalpha - 0.0035;
		} else { //else reduce it at its normal rate to have the fade affect
			m_iconalpha = m_iconalpha - 0.022;
		}
		
		
		if (m_iconalpha <= 0){
			//Hiding the icon off the screen
			m_icon.Show(false);
			
			// Set Alpha to 0 to make sure we know that the call queue has stopped running
			m_iconalpha = 0;
			
			//remove the call from the Queue
	 		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.HideIcon);
		}
		
		//Setting the icons alpha
		m_icon.SetAlpha(m_iconalpha);
	}
	
	
	
}