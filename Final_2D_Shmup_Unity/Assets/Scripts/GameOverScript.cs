using UnityEngine;
using System.Collections;

/// <summary>
/// Start or quit the game
/// </summary>
public class GameOverScript : MonoBehaviour
{
	/// <summary>
	/// The retry button and back button skins
	/// </summary>
	private GUISkin retryBtn;
	private GUISkin backBtn;

	void Start()
	{
		//call this during start to load the resource for the button(s) you wish to create skins for
		retryBtn = Resources.Load ("RetryButton_Skin") as GUISkin;
		backBtn = Resources.Load ("Back_Button_GUI") as GUISkin;
	}

	void OnGUI()
	{
		//change the next gui function called
		GUI.skin = retryBtn;

		const int buttonWidth = 120;
		const int buttonHeight = 60;

		//retry
		if (
			GUI.Button(
			// Center in X, 1/3 of the height in Y
			new Rect(
			Screen.width / 2 - (buttonWidth / 2),
			(Screen.height / 2) - (buttonHeight / 2),
			buttonWidth,
			buttonHeight
			),
			""
			)
			)			
		{
			// Reload the level
			Application.LoadLevel("Stage1");
		}

		GUI.skin = backBtn;

		//back to menu
		if (
			GUI.Button(
			// Center in X, 2/3 of the height in Y
			new Rect(
			Screen.width / 2 - (buttonWidth / 2),
			(Screen.height) - (buttonHeight * 2),
			buttonWidth,
			buttonHeight
			),
			""
			)
			)
		{
			// Reload the level
			Application.LoadLevel("title_menu");
		}
	}
}