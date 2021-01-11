//We are creating a new class named EarPlugsWidget
class EarPlugsWidget
{			
	//We are declaring a ImageWidget variable so we can reference it when neasary
	ref ImageWidget			m_icon;
	
	//To make sure we can remove the call que if its active we will have a bool called call 
	bool 								m_callqueueactive = false;
	
	
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
		if (m_callqueueactive){
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
		
	 	// If the call queue is currently active then remove it so we don't clear it away too quickly
		if (m_callqueueactive){
	 		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.HideIcon);
		}
		
		//Setting the Call Queue to be active so we know its currently running
 		m_callqueueactive = true;
		
		//Creating a call Queue to hide the Icon 1500 mili(1.5 Seconds) after it is loaded
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.HideIcon, 1500);
		
	}
	
	//This is the function we will use to clear the image off the screen.
	void HideIcon(){
		
		// Setting the call queue as completed (no longer active)
		m_callqueueactive = false;
		
		//Hiding the icon off the screen
		m_icon.Show(false);
	}
	
}