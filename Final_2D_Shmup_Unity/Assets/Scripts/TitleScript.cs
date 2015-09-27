using UnityEngine;
using System.Collections;

/// <summary>
/// Title screen script
/// </summary>
public class TitleScript : MonoBehaviour
{
	/// <summary>
	/// The next button skin
	/// </summary>
	private GUISkin nextBtn;
	private GUISkin backBtn;

	void Start()
	{
		//call this during start to load the resource for the button(s) you wish to create skins for
		nextBtn = Resources.Load ("Next_Button_GUI") as GUISkin;
		backBtn = Resources.Load ("Back_Button_GUI") as GUISkin;
	}

	void OnGUI()
	{
		//change the next gui function called
		GUI.skin = nextBtn;

		const int buttonWidth = 120;
		const int buttonHeight = 60;
		
		// Determine the button's place on screen
		// Center in X, 2/3 of the height in Y
		Rect buttonRect1 = new Rect(
			Screen.width / 2 - (buttonWidth / 2),
			(Screen.height) - (buttonHeight * 4),
			buttonWidth,
			buttonHeight
			);
		
		// next button
		if(GUI.Button(buttonRect1,""))
		{
			// On Click, load the first level.
			// "Stage1" is the name of the first scene we created.
			Application.LoadLevel("help_menu");
		}

		GUI.skin = backBtn;
		Rect buttonRect2 = new Rect(
			Screen.width / 2 - (buttonWidth / 2),
			(Screen.height) - (buttonHeight * 2),
			buttonWidth,
			buttonHeight
			);
		
		// next button
		if(GUI.Button(buttonRect2,""))
		{
			// On Click, load the first level.
			// "Stage1" is the name of the first scene we created.
			Application.Quit();
		}
	}
}