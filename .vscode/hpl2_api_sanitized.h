#ifndef HPL2_API_SANITIZED_H
#define HPL2_API_SANITIZED_H


/*
  Merged HPL2 API docs and sanitized prototypes.
  This header contains all documentation comments from `hpl2_api.h` and
  provides C-compatible prototypes (no AngelScript annotations like `&in`)
  so the C/C++ language server shows correct parameter lists and hover docs.
*/

/* Ensure standard C boolean macros are available when parsing as C. */
#if !defined(__cplusplus)
# include <stdbool.h>
# include <stddef.h>
#else
/* In C++ `bool`, `true`, and `false` are built-in. */
# include <cstddef>
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Trick the C++ parser into ignoring AngelScript keywords
#define in
#define out
#define inout
#define cast

// If AngelScript uses 'string', tell C++ to treat it as a char pointer or a dummy struct
typedef const char* string;


/**
 * @brief The function that runs when the map is loaded for the first time.
 */
void OnStart(void);

/**
 * @brief The function that runs whenever the player enters a map.
 */
void OnEnter(void);

/**
 * @brief The function that runs when the player leaves a map.
 */
void OnLeave(void);

/**
 * @brief This function is found in the global.hps file and the inventory.hps file, and is run when the game is first started by the player (ie via "Start New Game").
 */
void OnGameStart(void);

/**
 * @brief Requires version 1.5
 *
 * This function is executed for every game update or "tick". Can be used for
 * rapid-firing updates instead of looping timers. Keep in mind that this can
 * affect game performance if not used with care.
 *
 * @param afStep - Time elapsed in seconds since the last frame. Multiply speeds,
 *                 distances etc. by this argument to avoid framerate
 *                 dependence issues (for example: if you move something in
 *                 this function with constant speed, it will move faster on
 *                 computers which run the game with high FPS and slower on
 *                 computers with low FPS).
 */
void OnUpdate(float afStep);

/**
 * @brief Generates a random float.
 * @param afMin
 * @param afMax
 */
float RandFloat(float afMin, float afMax);

/**
 * @brief Generates a random int. Note: the maximum value is inclusive  - the RandInt() function may return this value.
 * @param alMin
 * @param alMax
 */
int RandInt(int alMin, int alMax);

/**
 * @brief Checks whether a string contains the specified string. Example: searching for "hello" in "hello world" would return true.
 * @param asString
 * @param asSubString
 */
bool StringContains(string &in asString, string &in asSubString);

/**
 * @brief Returns the substring in a string. Example: in the string "frictional games rocks", using 4 as alStart  and 6 as alCount  would return "tional".
 * @param asString
 * @param alStart
 * @param alCount
 */
const char* StringSub(string &in asString, int alStart, int alCount);

/**
 * @brief Requires version 1.3
 *
 * If possible, returns an integer converted from a string, else returns 0.
 *
 * @param asString - String to convert.
 */
int StringToInt(string &in asString);

/**
 * @brief Requires version 1.3
 *
 * If possible, returns a float converted from a string, else returns 0.
 *
 * @param asString - String to convert.
 */
float StringToFloat(string &in asString);

/**
 * @brief Requires version 1.3
 *
 * If possible, returns a boolean converted from a string, else returns false.
 *
 * @param asString - String to convert.
 */
bool StringToBool(string &in asString);

/**
 * @brief Requires version 1.3
 *
 * Returns the sine of the specified value.
 *
 * @param afX - Value to operate.
 */
float MathSin(float afX);

/**
 * @brief Requires version 1.3
 *
 * Returns the cosine of the specified value.
 *
 * @param afX - Value to operate.
 */
float MathCos(float afX);

/**
 * @brief Requires version 1.3
 *
 * Returns the tangent of the specified value.
 *
 * @param afX - Value to operate.
 */
float MathTan(float afX);

/**
 * @brief Requires version 1.3
 *
 * Returns the arc sine of the specified value.
 *
 * @param afX - Value to operate.
 */
float MathAsin(float afX);

/**
 * @brief Requires version 1.3
 *
 * Returns the arc cosine of the specified value.
 *
 * @param afX - Value to operate.
 */
float MathAcos(float afX);

/**
 * @brief Requires version 1.3
 *
 * Returns the arc tangent of the specified value.
 *
 * @param afX - Value to operate.
 */
float MathAtan(float afX);

/**
 * @brief Requires version 1.3
 *
 * Calculates and returns the arc tangent of the specified values.
 *
 * @param afX - First value to operate.
 * @param afY - Second value to operate.
 */
float MathAtan2(float afX, float afY);

/**
 * @brief Requires version 1.3
 *
 * Returns the square root of the specified value.
 *
 * @param afX - Value to operate.
 */
float MathSqrt(float afX);

/**
 * @brief Requires version 1.3
 *
 * Returns the value of afBase raised to the power of afExp.
 *
 * @param afBase - The base value.
 * @param afExp  - Value to calculate the base with.
 */
float MathPow(float afBase, float afExp);

/**
 * @brief Requires version 1.3
 *
 * Returns the lowest value.
 *
 * @param afA - First value.
 * @param afB - Second value.
 */
float MathMin(float afA, float afB);

/**
 * @brief Requires version 1.3
 *
 * Returns the highest value.
 *
 * @param afA - First value.
 * @param afB - Second value.
 */
float MathMax(float afA, float afB);

/**
 * @brief Requires version 1.3
 *
 * Returns afX clamped between afMin and afMax. If afX < afMin, returns afMin, and
 * if afX > afMax, returns afMax.
 *
 * @param afX   - The value to clamp.
 * @param afMin - The minimum value to clamp afX with.
 * @param afMax - The maximum value to clamp afX with.
 */
float MathClamp(float afX, float afMin, float afMax);

/**
 * @brief Requires version 1.3
 *
 * Returns the absolute value.
 *
 * @param afX - Value to operate.
 */
float MathAbs(float afX);

/**
 * @brief Prints a string to the log file (hpl.log).
 * @param asString
 */
void Print(string &in asString);

/**
 * @brief Prints a line of text to the debug console at the bottom left of the screen. Debug mode must be enabled for the console messages to be visible.
 * @param asString
 * @param abCheckForDuplicates
 */
void AddDebugMessage(string &in asString, bool abCheckForDuplicates);

/**
 * @brief Prints an entry to the ProgLog (progression log). ProgLog is a file created in Documents/Amnesia/main (or an FC folder if one is being used). It logs certain events, such us opening the menu or picking up the lantern, as well as the player's state (Health, Sanity, Oil, Tinderboxes, Coins), for the purpose of documenting a tester's playstyle.  This function allows to log custom messages.The messages in the ProgLog file are sorted by time elapsed since a map was loaded.
 * @param asLevel
 * @param asMessage
 */
void ProgLog(string &in asLevel, string &in asMessage);

/**
 * @brief Checks whether the debug mode is enabled. See "Setting up Development Environment" to setup debug mode on your own computer.
 */
int ScriptDebugOn(void);

/**
 * @brief Sets a local integer variable for the current script file.
 *
 * Local variables are scoped to the script file and are not saved to disk.
 * Use these for temporary counters or state that does not need to persist
 * across map loads.
 *
 * @param asName - Name of the local variable to set.
 * @param alVal  - Integer value to assign to the variable.
 */
void SetLocalVarInt(string &in asName, int alVal);

/**
 * @brief Sets a local float variable for the current script file.
 *
 * @param asName - Name of the local variable to set.
 * @param afVal  - Float value to assign to the variable.
 */
void SetLocalVarFloat(string &in asName, float afVal);

/**
 * @brief Sets a local string variable for the current script file.
 *
 * @param asName - Name of the local variable to set.
 * @param asVal  - String value to assign to the variable.
 */
void SetLocalVarString(string &in asName, string &in asVal);

/**
 * @brief Adds to a local integer variable for the current script file.
 *
 * Local variables are scoped to the script file and are not saved to disk.
 * Use these for temporary counters or state that does not need to persist
 * across map loads.
 *
 * @param asName - Name of the local variable to modify.
 * @param alVal  - Integer value to add to the variable.
 */
void AddLocalVarInt(string &in asName, int alVal);

/**
 * @brief Returns the value of a local integer variable for the current script file.
 *
 * @param asName - Name of the local variable to read.
 */
int GetLocalVarInt(string &in asName);

/**
 * @brief Adds to a local float variable for the current script file.
 *
 * @param asName - Name of the local variable to modify.
 * @param afVal  - Float value to add to the variable.
 */
void AddLocalVarFloat(string &in asName, float afVal);

/**
 * @brief Returns the value of a local float variable for the current script file.
 *
 * @param asName - Name of the local variable to read.
 */
float GetLocalVarFloat(string &in asName);

/**
 * @brief Adds to a local string variable for the current script file.
 *
 * @param asName - Name of the local variable to modify.
 * @param asVal  - String to append.
 */
void AddLocalVarString(string &in asName, string &in asVal);

/**
 * @brief Returns the value of a local string variable for the current script file.
 *
 * @param asName - Name of the local variable to read.
 */
string GetLocalVarString(string &in asName);

/**
 * @brief Sets a global integer variable accessible across maps and script files.
 *
 * Global variables persist across maps and are useful for tracking
 * player progress or state that must survive map transitions.
 *
 * @param asName - Name of the global variable to set.
 * @param alVal  - Integer value to assign to the variable.
 */
void SetGlobalVarInt(string &in asName, int alVal);

/**
 * @brief Sets a global float variable accessible across maps and script files.
 *
 * @param asName - Name of the global variable to set.
 * @param afVal  - Float value to assign to the variable.
 */
void SetGlobalVarFloat(string &in asName, float afVal);

/**
 * @brief Sets a global string variable accessible across maps and script files.
 *
 * @param asName - Name of the global variable to set.
 * @param asVal  - String value to assign to the variable.
 */
void SetGlobalVarString(string &in asName, string &in asVal);

/**
 * @brief Adds to a global integer variable accessible across maps and script files.
 *
 * Global variables persist across maps and are useful for tracking player
 * progress or state that must survive map transitions.
 *
 * @param asName - Name of the global variable to modify.
 * @param alVal  - Integer value to add to the variable.
 */
void AddGlobalVarInt(string &in asName, int alVal);

/**
 * @brief Returns the value of a global integer variable.
 *
 * @param asName - Name of the global variable to read.
 */
int GetGlobalVarInt(string &in asName);

/**
 * @brief Adds to a global float variable accessible across maps and script files.
 *
 * @param asName - Name of the global variable to modify.
 * @param afVal  - Float value to add to the variable.
 */
void AddGlobalVarFloat(string &in asName, float afVal);

/**
 * @brief Returns the value of a global float variable.
 *
 * @param asName - Name of the global variable to read.
 */
float GetGlobalVarFloat(string &in asName);

/**
 * @brief Adds to a global string variable accessible across maps and script files.
 *
 * @param asName - Name of the global variable to modify.
 * @param asVal  - String to append.
 */
void AddGlobalVarString(string &in asName, string &in asVal);

/**
 * @brief Returns the value of a global string variable.
 *
 * @param asName - Name of the global variable to read.
 */
string GetGlobalVarString(string &in asName);

/**
 * @brief Preloads a particle system.
 * @param asPSFile
 */
void PreloadParticleSystem(string &in asPSFile);

/**
 * @brief Creates a particle system on an entity.
 * @param asPSName internal name
 * @param asPSFile 
 * @param asEntity
 * @param abSavePS
 */
void CreateParticleSystemAtEntity(string &in asPSName, string &in asPSFile, string &in asEntity, bool abSavePS);

/**
 * @brief Creates a particle system on an entity, extended method with more options. 
 * @param asPSName internal name
 * @param asPSFile the particle system to use + extension .ps
 * @param asEntity the entity to create the particle system at
 * @param abSavePS determines whether a particle system should "remember" its shown/hidden state, so that this state can be restored when the player revisits the level
 * @param afR red value
 * @param afG green value
 * @param afB blue value
 * @param afA alpha value
 * @param abFadeAtDistance determines whether a particle system fades from a certain distance on
 * @param afFadeMinEnd minimum distance at which the particle system stops fading
 * @param afFadeMinStart minimum distance at which the particle system starts fading
 * @param afFadeMaxStart maximum distance at which the particle system starts fading
 * @param afFadeMaxEnd maximum distance at which the particle system stops fading
 * 
 */
void CreateParticleSystemAtEntityExt(string &in asPSName, string &in asPSFile, string &in asEntity, bool abSavePS, float afR, float afG, float afB, float afA, bool abFadeAtDistance, float afFadeMinEnd, float afFadeMinStart, float afFadeMaxStart, float afFadeMaxEnd);

/**
 * @brief Destroys a particle system.
 * @param asName
 */
void DestroyParticleSystem(string &in asName);

/**
 * @brief Preloads a sound.
 * @param asSoundFile
 */
void PreloadSound(string &in asSoundFile);

/**
 * @brief Plays a sound, not using 3D.
 * @param asSoundFile
 * @param afVolume
 */
void PlayGuiSound(string &in asSoundFile, float afVolume);

/**
 * @brief Creates a sound at an entity.
 * @param asSoundName
 * @param asSoundFile
 * @param asEntity
 * @param afFadeTime
 * @param abSaveSound
 */
void PlaySoundAtEntity(string &in asSoundName, string &in asSoundFile, string &in asEntity, float afFadeTime, bool abSaveSound);

/**
 * @brief Fades in a sound.
 * @param asSoundName
 * @param afFadeTime
 * @param abPlayStart
 */
void FadeInSound(string &in asSoundName, float afFadeTime, bool abPlayStart);

/**
 * @brief Fades out a sound.
 * @param asSoundName
 * @param afFadeTime
 */
void StopSound(string &in asSoundName, float afFadeTime);

/**
 * @brief Adds a voice and an additional sound effect to be played.
 *
 * It is okay to call this many times to queue multiple voices. The
 * EffectVoiceOverCallback is not called until ALL voices have finished.
 *
 * @param asVoiceFile  - The voice file to play.
 * @param asEffectFile - Additional sound effect file to play alongside the voice.
 * @param asTextCat    - The category in the .lang file, usually "Voice".
 * @param asTextEntry  - The text entry in the .lang file.
 * @param abUsePosition- Play the voice in 3D (true) or as GUI sound (false).
 * @param asPosEntity  - Entity at which the voice/sound is played.
 * @param afMinDistance- Minimum distance the voice is heard.
 * @param afMaxDistance- Maximum distance the voice is heard.
 */
void AddEffectVoice(string &in asVoiceFile, string &in asEffectFile, string &in asTextCat, string &in asTextEntry, bool abUsePosition, string &in asPosEntity, float afMinDistance, float afMaxDistance);

/**
 * @brief Plays music.
 * @param asMusicFile
 * @param abLoop
 * @param afVolume
 * @param afFadeTime
 * @param alPrio
 * @param abResume
 */
void PlayMusic(string &in asMusicFile, bool abLoop, float afVolume, float afFadeTime, int alPrio, bool abResume);

/**
 * @brief Stops music.
 * @param afFadeTime
 * @param alPrio
 */
void StopMusic(float afFadeTime, int alPrio);

/**
 * @brief Stops all voices and calls the EffectVoiceOverCallback.
 * @param afFadeOutTime
 */
void StopAllEffectVoices(float afFadeOutTime);

/**
 * @brief Checks whether EffectVoices are still active.
 */
bool GetEffectVoiceActive(void);

/**
 * @brief Sets the function to be called when the EffectVoices are finished. Callback syntax: void MyFunc()
 * @param asFunc
 */
void SetEffectVoiceOverCallback(string &in asFunc);

/**
 * @brief Influences the global sound volume, that means everything you can hear from the world. This does not affect music of GUI sounds.
 * @param afDestVolume
 * @param afTime
 */
void FadeGlobalSoundVolume(float afDestVolume, float afTime);

/**
 * @brief Influences the global sound speed.
 * @param afDestSpeed
 * @param afTime
 */
void FadeGlobalSoundSpeed(float afDestSpeed, float afTime);

/**
 * @brief Enables/disables lights.
 * @param asLightName
 * @param abVisible
 */
void SetLightVisible(string &in asLightName, bool abVisible);

/**
 * @brief Changes the properties of a light.
 * @param asLightName
 * @param afR
 * @param afG
 * @param afB
 * @param afA
 * @param afRadius
 * @param afTime
 */
void FadeLightTo(string &in asLightName, float afR, float afG, float afB, float afA, float afRadius, float afTime);

/**
 * @brief Activates flickering on a light.
 * @param asLightName
 * @param abActive
 */
void SetLightFlickerActive(string &in asLightName, bool abActive);

/**
 * @brief Starts the end credits screen.
 * @param asMusic
 * @param abLoopMusic
 * @param asTextCat
 * @param asTextEntry
 * @param alEndNum
 */
void StartCredits(string &in asMusic, bool abLoopMusic, string &in asTextCat, string &in asTextEntry, int alEndNum);

/**
 * @brief Shows the demo end screen. The background and UI elements are defined in demo.cfg, with the text using the entries in the "Demo" category of the .lang file.
 */
void StartDemoEnd(void);

/**
 * @brief Creates an auto save file.
 */
void AutoSave(void);

/**
 * @brief Sets a checkpoint at which the player will respawn in case he dies. Callback syntax: void MyFunc(string &in asName, int alCount) Count is 0 on the first checkpoint load!
 * @param asName
 * @param asStartPos
 * @param asCallback
 * @param asDeathHintCat
 * @param asDeathHintEntry
 */
void CheckPoint(string &in asName, string &in asStartPos, string &in asCallback, string &in asDeathHintCat, string &in asDeathHintEntry);

/**
 * @brief Loads another map after a 1.5 second fade out.
 * @param asMapName
 * @param asStartPos
 * @param asStartSound
 * @param asEndSound
 */
void ChangeMap(string &in asMapName, string &in asStartPos, string &in asStartSound, string &in asEndSound);

/**
 * @brief Clears the "history" of the save, useful to do when you know the player will not be able to go back anymore. Makes the next save much smaller in size.
 */
void ClearSavedMaps(void);

/**
 * @brief This caches all current textures and models and they are not released until destroy is called. If there is already cached data it is destroyed. Create caches to enable faster loading when going back to a map. Destroy the cache if you know the player won't go back to that map.
 */
void CreateDataCache(void);

/**
 * @brief Sets the map name shown in save file names. If none is set NULL is assumed.
 * @param asNameEntry
 */
void SetMapDisplayNameEntry(string &in asNameEntry);

/**
 * @brief Enables/Disables the skybox.
 * @param abActive
 */
void SetSkyBoxActive(bool abActive);

/**
 * @brief Sets the texture of the skybox.
 * @param asTexture
 */
void SetSkyBoxTexture(string &in asTexture);

/**
 * @brief Sets the solid color of the skybox rather than a texture.
 * @param afR
 * @param afG
 * @param afB
 * @param afA
 */
void SetSkyBoxColor(float afR, float afG, float afB, float afA);

/**
 * @brief Enables/Disables the global fog.
 * @param abActive
 */
void SetFogActive(bool abActive);

/**
 * @brief Sets the color to use for the global fog.
 * @param afR
 * @param afG
 * @param afB
 * @param afA
 */
void SetFogColor(float afR, float afG, float afB, float afA);

/**
 * @brief Sets the properties for the global fog.
 * @param afStart
 * @param afEnd
 * @param afFalloffExp
 * @param abCulling
 */
void SetFogProperties(float afStart, float afEnd, float afFalloffExp, bool abCulling);

/**
 * @brief Determines which loading screen will be shown when changing maps.
 * @param asTextCat
 * @param asTextEntry
 * @param alRandomNum
 * @param asImageFile
 */
void SetupLoadScreen(string &in asTextCat, string &in asTextEntry, int alRandomNum, string &in asImageFile);

/**
 * @brief Unlocks the specified achievement. Only able to be used for the ending achievements.
 * @param asName
 */
void UnlockAchievement(string &in asName);

/**
 * @brief Creates a timer which calls a function when it expires. Callback syntax: void MyFunc(string &in asTimer)
 * @param asName
 * @param afTime
 * @param asFunction
 */
void AddTimer(string &in asName, float afTime, string &in asFunction);

/**
 * @brief Removes a timer, no matter how much time is left.
 * @param asName
 */
void RemoveTimer(string &in asName);

/**
 * @brief Returns the time left on a timer.
 * @param asName
 */
float GetTimerTimeLeft(string &in asName);

/**
 * @brief Fades the screen to black.
 * @param afTime
 */
void FadeOut(float afTime);

/**
 * @brief Fades the screen back to normal.
 * @param afTime
 */
void FadeIn(float afTime);

/**
 * @brief Applies the image trail effect to the screen.
 * @param afAmount
 * @param afSpeed
 */
void FadeImageTrailTo(float afAmount, float afSpeed);

/**
 * @brief Makes the screen go dark red.
 * @param afAmount
 * @param afSpeed
 */
void FadeSepiaColorTo(float afAmount, float afSpeed);

/**
 * @brief Applies radial blur effects to the screen.
 * @param afSize
 * @param afSpeed
 */
void FadeRadialBlurTo(float afSize, float afSpeed);

/**
 * @brief Determines at which distance the radial blur effects appear.
 * @param afStartDist
 */
void SetRadialBlurStartDist(float afStartDist);

/**
 * @brief Fades the screen to white.
 * @param afFadeIn
 * @param afWhite
 * @param afFadeOut
 */
void StartEffectFlash(float afFadeIn, float afWhite, float afFadeOut);

/**
 * @brief Fades the screen to white and shows a text message.
 * @param asTextCat
 * @param asTextEntry
 * @param asSound
 */
void StartEffectEmotionFlash(string &in asTextCat, string &in asTextEntry, string &in asSound);

/**
 * @brief Checks whether a flashback is still in effect.
 */
bool GetFlashbackIsActive(void);

/**
 * @brief Continuously spawn regular particle systems (.ps) around the player. Particles created by this script carry over from map to map.
 * @param asSPSFile
 */
void StartPlayerSpawnPS(string &in asSPSFile);

/**
 * @brief Stops the player SPS started with StartPlayerSpawnPS.
 */
void StopPlayerSpawnPS(void);

/**
 * @brief Shakes the screen.
 * @param afAmount
 * @param afTime
 * @param afFadeInTime
 * @param afFadeOutTime
 */
void StartScreenShake(float afAmount, float afTime, float afFadeInTime, float afFadeOutTime);

/**
 * @brief Requires version 1.3
 *
 * Enables/disables the sanity drain and night vision effects while in the
 * darkness.
 *
 * @param abX - Enable/disable effects.
 */
void SetInDarknessEffectsActive(bool abX);

/**
 * @brief Requires version 1.5
 *
 * Displays an image file directly onto the screen. See ShowScreenImage()
 * in the tutorials section for more information.
 *
 * @param asImageName - The image file to render (.jpg, .png, .tga, .dds)
 * @param afX         - The X position of the image
 * @param afY         - The Y position of the image
 * @param afScale     - The size of the image in pixels (not scale), or original
 *                     image size if negative
 * @param abUseRelativeCoordinates - Whether X and Y are relative to the
 *                                  screen resoltion, or pixel co-ordinates if not
 * @param afDuration  - The duration that the image is displayed for
 * @param afFadeIn    - The time, in seconds, to fade in the image
 * @param afFadeOut   - The time, in seconds, to fade out the image
 */
void ShowScreenImage(string &in asImageName, float afX, float afY, float afScale, bool abUseRelativeCoordinates, float afDuration, float afFadeIn, float afFadeOut);

/**
 * @brief Determines which InsanitySets are enabled.
 * @param asSet
 * @param abX
 */
void SetInsanitySetEnabled(string &in asSet, bool abX);

/**
 * @brief Requires version 1.3
 *
 * Starts a specified insanity event.
 *
 * @param asEventName - Insanity event to play.
 */
void StartInsanityEvent(string &in asEventName);

/**
 * @brief Starts a random insanity event from the available sets.
 */
void StartRandomInsanityEvent(void);

/**
 * @brief Requires version 1.3
 *
 * Stops the currently playing insanity event.
 */
void StopCurrentInsanityEvent(void);

/**
 * @brief Not useful at all due to having a return type of void when it should be bool. Checks whether an insanity event is currently in effect. 
 *
 */
void InsanityEventIsActive(void);

/**
 * @brief Enabled/Disable player controlled movement.
 * @param abActive
 */
void SetPlayerActive(bool abActive);

/**
 * @brief Resets the player's state, forcing them to stop interacting with objects. It also clears the inventory item to be used (as if it was double-clicked on in the inventory again) and dismounts the player from ladders.
 */
void ChangePlayerStateToNormal(void);

/**
 * @brief Forces the player to crouch.
 * @param abCrouch
 */
void SetPlayerCrouching(bool abCrouch);

/**
 * @brief Pushes the player into a certain direction. Note that you need values above ~2000 to see any effects.
 * @param afX amount along the X-axis
 * @param afY amount along the Y-axis
 * @param afZ amount along the Z-axis
 * @param abUseLocalCoords If true, axes are based on where the player is facing, not the world. 
 */
void AddPlayerBodyForce(float afX, float afY, float afZ, bool abUseLocalCoords);

/**
 * @brief Enables/Disables the icons when a player has something in focus.
 * @param abX
 */
void ShowPlayerCrossHairIcons(bool abX);

/**
 * @brief Modifies the sanity of the player.
 * @param afSanity
 */
void SetPlayerSanity(float afSanity);

/**
 * @brief Modifies the health of the player.
 * @param afHealth
 */
void SetPlayerHealth(float afHealth);

/**
 * @brief Modifies the lamp oil of the player.
 * @param afOil Lamp oil amount to set
 */
void SetPlayerLampOil(float afOil);

/**
 * @brief Adds sanity to the player. Give it a negative number to decrease the sanity of the player.
 * @param afSanity Sanity to add
 */
void AddPlayerSanity(float afSanity);

/**
 * @brief Returns the sanity of the player.
 * @return Player's sanity
 */
float GetPlayerSanity(void);

/**
 * @brief Adds health to the player. Give it a negative number to decrease the health of the player.
 * @param afHealth Health to add
 */
void AddPlayerHealth(float afHealth);

/**
 * @brief Returns the health of the player.
 * @return Player's health
 */
float GetPlayerHealth(void);

/**
 * @brief Adds lamp oil to the player. Give it a negative number to decrease the lamp oil of the player.
 * @param afSanity Oil to add
 */
void AddPlayerLampOil(float afOil);

/**
 * @brief Returns the lamp oil of the player.
 * @return Player's lamp oil
 */
float GetPlayerLampOil(void);

/**
 * @brief Returns the current speed of the player.
 */
float GetPlayerSpeed(void);
float GetPlayerYSpeed(void);

/**
 * @brief Enables/Disables sanity drain from darkness.
 * @param abX 
 */
void SetSanityDrainDisabled(bool abX);

/**
 * @brief Boosts the player's sanity by a large amount depending on the current sanity.
 */
void GiveSanityBoost(void);

/**
 * @brief Boosts the player's sanity by a small amount depending on the current sanity.
 */
void GiveSanityBoostSmall(void);

/**
 * @brief Reduces the sanity of the player.
 * @param afAmount
 * @param abUseEffect
 */
void GiveSanityDamage(float afAmount, bool abUseEffect);

/**
 * @brief Reduces the health of the player.
 * @param afAmount
 * @param asType
 * @param abSpinHead
 * @param abLethal
 */
void GivePlayerDamage(float afAmount, string &in asType, bool abSpinHead, bool abLethal);

/**
 * @brief Changes the field of view of the player. A shorter FOV will create a zoom effect.
 * @param afX
 * @param afSpeed
 */
void FadePlayerFOVMulTo(float afX, float afSpeed);

/**
 * @brief Changes the aspect ratio of the player. Basically stretches or narrows the screen horizontally.
 * @param afX
 * @param afSpeed
 */
void FadePlayerAspectMulTo(float afX, float afSpeed);

/**
 * @brief Rotates the position of the camera on the player's body.
 * @param afX
 * @param afSpeedMul
 * @param afMaxSpeed
 */
void FadePlayerRollTo(float afX, float afSpeedMul, float afMaxSpeed);

/**
 * @brief Requires version 1.2
 * @param afAmount
 */
void MovePlayerForward(float afAmount);

/**
 * @brief Changes the position of the camera on the player's body.
 * @param afX
 * @param afY
 * @param afZ
 * @param afSpeed
 * @param afSlowDownDist
 */
void MovePlayerHeadPos(float afX, float afY, float afZ, float afSpeed, float afSlowDownDist);

/**
 * @brief Forces the player to look at a certain entity until StopPlayerLookAt is used.
 * @param asEntityName
 * @param afSpeedMul
 * @param afMaxSpeed
 * @param asAtTargetCallback
 */
void StartPlayerLookAt(string &in asEntityName, float afSpeedMul, float afMaxSpeed, string &in asAtTargetCallback);

/**
 * @brief Stops any existing player lookAt from StartPlayerLookAt.
 */
void StopPlayerLookAt(void);

/**
 * @brief Changes the player's move speed. Default is 1.
 * @param afMul
 */
void SetPlayerMoveSpeedMul(float afMul);

/**
 * @brief Changes the player's run speed. Default is 1.
 * @param afMul
 */
void SetPlayerRunSpeedMul(float afMul);

/**
 * @brief Changes the player's look speed. Default is 1.
 * @param afMul
 */
void SetPlayerLookSpeedMul(float afMul);

/**
 * @brief Requires version 1.3
 * @param afMul
 */
void SetPlayerJumpForceMul(float afMul);

/**
 * @brief Enables/Disables the player's ability to jump.
 * @param abX
 */
void SetPlayerJumpDisabled(bool abX);

/**
 * @brief Enables/Disables the player's ability to crouch.
 * @param abX
 */
void SetPlayerCrouchDisabled(bool abX);

/**
 * @brief Instantly teleports the player to the target StartPos.
 * @param asStartPosName
 */
void TeleportPlayer(string &in asStartPosName);

/**
 * @brief Makes the player use his lantern.
 * @param abX
 * @param abUseEffects
 */
void SetLanternActive(bool abX, bool abUseEffects);

/**
 * @brief Checks whether the player is currently using the lantern.
 */
bool GetLanternActive(void);

/**
 * @brief Enables/Disables the player's ability to use the lantern.
 * @param abX
 */
void SetLanternDisabled(bool abX);

/**
 * @brief Sets the function to call when the player uses the lantern. Callback syntax: MyFunc(bool abLit)
 * @param asCallback
 */
void SetLanternLitCallback(string &in asCallback);

/**
 * @brief Displays a message on the screen.
 * @param asTextCategory
 * @param asTextEntry
 * @param afTime
 */
void SetMessage(string &in asTextCategory, string &in asTextEntry, float afTime);

/**
 * @brief Sets the message that appears when the player dies.
 * @param asTextCategory
 * @param asTextEntry
 */
void SetDeathHint(string &in asTextCategory, string &in asTextEntry);

/**
 * @brief Disables the death sound when the player dies. This must be called directly before player is killed! The variable as soon as player dies too.
 */
void DisableDeathStartSound(void);

/**
 * @brief Requires version 1.2
 * @param asSound
 */
void SetPlayerPermaDeathSound(string &in asSound);

/**
 * @brief Enables/disables the player's ability to take fall damage.
 *
 * Requires version 1.3
 *
 * @param abX - true to disable fall damage, false to enable
 */
void SetPlayerFallDamageDisabled(bool abX);

/**
 * @brief Sets the player's position within the level.
 *
 * Requires version 1.3
 *
 * @param afX - X co-ordinate position.
 * @param afY - Y co-ordinate position.
 * @param afZ - Z co-ordinate position.
 */
void SetPlayerPos(float afX, float afY, float afZ);

/**
 * @brief Returns the player's position within the level on the X axis.
 *
 * Requires version 1.3
 */
float GetPlayerPosX(void);

/**
 * @brief Returns the player's position within the level on the Y axis.
 *
 * Requires version 1.3
 */
float GetPlayerPosY(void);

/**
 * @brief Returns the player's position within the level on the Z axis.
 *
 * Requires version 1.3
 */
float GetPlayerPosZ(void);

/**
 * @brief Adds a note to the player's journal.
 * @param asNameAndTextEntry
 * @param asImage
 */
void AddNote(string &in asNameAndTextEntry, string &in asImage);

/**
 * @brief Adds a diary to the player's journal.
 * @param asNameAndTextEntry
 * @param asImage
 */
void AddDiary(string &in asNameAndTextEntry, string &in asImage);

/**
 * @brief Only called in the pickup diary callback! If true the journal displays the entry else not.
 * @param abOpenJournal 
 */
void ReturnOpenJournal(bool abOpenJournal);

/**
 * @brief Adds a quest to the player's journal under mementos. Completed quests cannot be readded.
 * @param asName the internal name of the quest
 * @param asNameAndTextEntry entry in the .lang file. Must start with " Quest_<texthere>_Text ”, and be in category “Journal”!
 */
void AddQuest(string &in asName, string &in asNameAndTextEntry);

/**
 * @brief Completes a quest. If the quest has not been added, it's marked as complete anyway, preventing it from being added.
 * @param asName the internal name of the quest
 * @param asNameAndTextEntry entry in the .lang file. Must start with " Quest_<texthere>_Text ”, and be in category “Journal”!
 */
void CompleteQuest(string &in asName, string &in asNameAndTextEntry);

/**
 * @brief Checks whether a quest is completed.
 * @param asName the internal name of the quest
 */
bool QuestIsCompleted(string &in asName);

/**
 * @brief Checks whether a quest is added.
 * @param asName the internal name of the quest
 */
bool QuestIsAdded(string &in asName);

/**
 * @brief Sets the number of quests in the map. Obsolete; formerly used to calculate a completion percentage when looking at a level door.
 * @param alNumberOfQuests Amount of quests
 */
void SetNumberOfQuestsInMap(int alNumberOfQuests);

/**
 * @brief Displays a hint on the player's screen.
 * @param asName the internal name
 * @param asMessageCat the category in the .lang file, usually "Hints"
 * @param asMessageEntry the entry in the .lang file
 * @param afTimeShown time in seconds until the message disappears. If time is <= 0 then the life time is calculated based on string length.
 */
void GiveHint(string &in asName, string &in asMessageCat, string &in asMessageEntry, float afTimeShown);

/**
 * @brief Blocking a hint prevents it from being shown. Blocked hints are included in savefiles, so they should persist between levels. Unblocking a hint allows it to be shown.
 * @param asName the internal name. Basic game hints use the same name as their respective lang entries, with the exception of "numbered" hints. For example, EntityGrab blocks the EntityGrab01 and EntityGrab02 entries.
 */
void BlockHint(string &in asName);

/**
 * @brief Unblocks a hint to allow it to be shown again.
 * @param asName the internal name. Basic game hints use the same name as their respective lang entries, with the exception of "numbered" hints. For example, EntityGrab blocks the EntityGrab01 and EntityGrab02 entries.
 */
void UnBlockHint(string &in asName);

/**
 * @brief Removes the hint from the list of already shown hints, allowing it to appear again.
 * @param asName
 */
void RemoveHint(string &in asName);

/**
 * @brief Exits the inventory by force.
 */
void ExitInventory(void);

/**
 * @brief Disables the player's ability to open his inventory.
 * @param abX
 */
void SetInventoryDisabled(bool abX);

/**
 * @brief Adds a message on the inventory screen. Used for feedback messages when failing to combine items.
 * @param asTextCategory
 * @param asTextEntry
 * @param afTime
 */
void SetInventoryMessage(string &in asTextCategory, string &in asTextEntry, float afTime);

/**
 * @brief Adds an item to the inventory of the player. Note that the item does not have to exist as entity in the world to be able to do this.
 * @param asName
 * @param asType
 * @param asSubTypeName
 * @param asImageName
 * @param afAmount
 */
void GiveItem(string &in asName, string &in asType, string &in asSubTypeName, string &in asImageName, float afAmount);

/**
 * @brief Removes an item from the player's inventory.
 * @param asName
 */
void RemoveItem(string &in asName);

/**
 * @brief Checks whether the player has an item in his inventory.
 * @param asName
 */
int HasItem(string &in asName);

/**
 * @brief Adds a single item to the player's inventory. This is meant to be used for debug mostly as it creates the actual item and then destroys it.
 * @param asName
 * @param asFileName
 */
void GiveItemFromFile(string &in asName, string &in asFileName);

/**
 * @brief Allows the player to combine items in his inventory. Callback syntax: void MyFunc(string &in asItemA, string &in asItemB)
 * @param asName
 * @param asItemA
 * @param asItemB
 * @param asFunction
 * @param abAutoRemove
 */
void AddCombineCallback(string &in asName, string &in asItemA, string &in asItemB, string &in asFunction, bool abAutoRemove);

/**
 * @brief Removes a combine callback.
 * @param asName
 */
void RemoveCombineCallback(string &in asName);

/**
 * @brief Allows the player to use items on the world. Callback syntax: void MyFunc(string &in asItem, string &in asEntity)
 * @param asName
 * @param asItem
 * @param asEntity
 * @param asFunction
 * @param abAutoDestroy
 */
void AddUseItemCallback(string &in asName, string &in asItem, string &in asEntity, string &in asFunction, bool abAutoDestroy);

/**
 * @brief Removes an item callback.
 * @param asName
 */
void RemoveUseItemCallback(string &in asName);

/**
 * @brief Activates/deactivates an entity.
 * @param asName
 * @param abActive
 */
void SetEntityActive(string &in asName, bool abActive);

/**
 * @brief Requires version 1.3
 * @param asName
 * @param abVisible
 */
void SetEntityVisible(string &in asName, bool abVisible);

/**
 * @brief Checks whether an entity exists.
 * @param asName
 */
bool GetEntityExists(string &in asName);

/**
 * @brief Changes the crosshair that is used when focusing an entity.
 * @param asName
 * @param asCrossHair
 */
void SetEntityCustomFocusCrossHair(string &in asName, string &in asCrossHair);

/**
 * @brief Creates an entity at an area. When creating an enemy though, it cannot chase properly along PathNodes (using for example ShowEnemyPlayerPosition).
 * @param asEntityName
 * @param asEntityFile
 * @param asAreaName
 * @param abFullGameSave
 */
void CreateEntityAtArea(string &in asEntityName, string &in asEntityFile, string &in asAreaName, bool abFullGameSave);

/**
 * @brief Requires version 1.3
 * @param asName
 * @param asBodyName
 * @param asNewEntityName
 * @param asNewEntityFile
 * @param abFullGameSave
 */
void ReplaceEntity(string &in asName, string &in asBodyName, string &in asNewEntityName, string &in asNewEntityFile, bool abFullGameSave);

/**
 * @brief Requires version 1.3
 * @param asName
 * @param asTargetEntity
 * @param asTargetBodyName
 * @param abUseRotation
 */
void PlaceEntityAtEntity(string &in asName, string &in asTargetEntity, string &in asTargetBodyName, bool abUseRotation);

/**
 * @brief Requires version 1.3
 * @param asName
 * @param afX
 * @param afY
 * @param afZ
 */
void SetEntityPos(string &in asName, float afX, float afY, float afZ);

/**
 * @brief Requires version 1.3
 * @param asName
 */
float GetEntityPosX(string &in asName);

/**
 * @brief Calls a function when the player looks at a certain entity. Callback syntax: void MyFunc(string &in asEntity, int alState) alState: 1 = looking, -1 = not looking
 * @param asName
 * @param asCallback
 * @param abRemoveWhenLookedAt
 */
void SetEntityPlayerLookAtCallback(string &in asName, string &in asCallback, bool abRemoveWhenLookedAt);

/**
 * @brief Calls a function when the player interacts with a certain entity. Callback syntax: void MyFunc(string &in asEntity)
 * @param asName
 * @param asCallback
 * @param abRemoveOnInteraction
 */
void SetEntityPlayerInteractCallback(string &in asName, string &in asCallback, bool abRemoveOnInteraction);

/**
 * @brief Calls a function when certain events occur with an entity. Callback syntax: void MyFunc(string &in asEntity, string &in asType)
 * @param asName
 * @param asCallback
 */
void SetEntityCallbackFunc(string &in asName, string &in asCallback);

/**
 * @brief A callback called when ever the connection state changes (button being switched on, lever switched, etc). Callback syntax: void Func(string &in asEntity, int alState) alState: -1 = off, 0 = between, 1 = on
 * @param asName
 * @param asCallback
 */
void SetEntityConnectionStateChangeCallback(string &in asName, string &in asCallback);

/**
 * @brief Disallows interaction with an entity.
 * @param asName
 * @param abDisabled
 */
void SetEntityInteractionDisabled(string &in asName, bool abDisabled);

/**
 * @brief Breaks a joint. Do not use this on joints in SwingDoors, Levers, Wheels, etc. where the joint is part of an interaction. That will make the game crash. 
 * @param asName 
 */

void BreakJoint(string &in asName);

/**
 * @brief Calls a function when two entities collide. Callback syntax: void MyFunc(string &in asParent, string &in asChild, int alState) alState: 1 = enter, -1 = leave
 * @param asParentName
 * @param asChildName
 * @param asFunction
 * @param abDeleteOnCollide
 * @param alStates
 */
void AddEntityCollideCallback(string &in asParentName, string &in asChildName, string &in asFunction, bool abDeleteOnCollide, int alStates);

/**
 * @brief Removes an EntityCollideCallback. Asterix (*) not supported in asChildName.
 * @param asParentName
 * @param asChildName
 */
void RemoveEntityCollideCallback(string &in asParentName, string &in asChildName);

/**
 * @brief Checks whether two entities collide. This function does NOT support asterix (*) or "Player"!
 * @param asEntityA
 * @param asEntityB
 */
bool GetEntitiesCollide(string &in asEntityA, string &in asEntityB);

/**
 * @brief Requires version 1.3. Sets the mass of an entity's body. 
 * @param asName Name of the body of an entity. The body name of an entity is EntityName_BodyName.
 * @param afMass The mass to set.
 */
void SetBodyMass(string &in asName, float afMass);

/**
 * @brief Requires version 1.3. Gets the mass of an entity's body. 
 * @param asName Name of the body of an entity. The body name of an entity is EntityName_BodyName.
 */
float GetBodyMass(string &in asName);

/**
 * @brief Turns the texture illumination, billboards, particles, light flicker, and sounds of a prop on or off.
 * @param asName
 * @param abActive
 * @param abFadeAndPlaySounds
 */
void SetPropEffectActive(string &in asName, bool abActive, bool abFadeAndPlaySounds);

/**
 * @brief Activates/deactivates a prop.
 * @param asName
 * @param abActive
 * @param afFadeTime
 */
void SetPropActiveAndFade(string &in asName, bool abActive, float afFadeTime);

/**
 * @brief Activates/deactivates the physics of a prop, setting the mass to 0. Setting as true will make entities static in midair.
 * @param asName
 * @param abX
 */
void SetPropStaticPhysics(string &in asName, bool abX);

/**
 * @brief Checks whether a prop is interacted with.
 * @param asName
 */
bool GetPropIsInteractedWith(string &in asName);

/**
 * @brief Rotates the prop up to a set speed.
 * @param asName internal name
 * @param afAcc acceleration
 * @param afGoalSpeed desired speed
 * @param afAxisX rotation around X axis
 * @param afAxisY rotation around Y axis
 * @param afAxisZ rotation around Z axis
 * @param abResetSpeed determines whether the speed is resetted after goal speed is reached
 * @param asOffsetArea the area to rotate around, if empty, then the center of the body is used Note: The entity you want to rotate MUST be a "StaticObject" entity!
 */
void RotatePropToSpeed(string &in asName, float afAcc, float afGoalSpeed, float afAxisX, float afAxisY, float afAxisZ, bool abResetSpeed, string &in asOffsetArea);

/**
 * @brief Stops all movement of a prop.
 * @param asName
 */
void StopPropMovement(string &in asName);

/**
 * @brief --- OUTDATED after 1.3!!! Use AttachPropToProp in 1.3 instead.---
 *        Attaches a prop to another prop. 
 *        Note: for the purposes of AddEntityCollideCallback, attached props will not call the callback function if they collide with a "static_object" or a "StaticProp" entity type! 
 * @param asPropName the prop to attach another prop at
 * @param asAttachName internal name of the prop that gets attached
 * @param asAttachFile the prop that gets attached extension .ent
 * @param afPosX X position of the attach from the prop
 * @param afPosY Y position of the attach from the prop
 * @param afPosZ Z position of the attach from the prop
 * @param afRotX rotation around X axis of the attach
 * @param afRotY rotation around Y axis of the attach
 * @param afRotZ rotation around ZX axis of the attach
 */
void AddAttachedPropToProp(string &in asPropName, string &in asAttachName, string &in asAttachFile, float afPosX, float afPosY, float afPosZ, float afRotX, float afRotY, float afRotZ);

/**
 * @brief Requires version 1.3.
 *        Attaches a prop to another prop. Fixed version of AddAttachedPropToProp. 
 *        Note: for the purposes of AddEntityCollideCallback, attached props will not call the callback function if they collide with a "static_object" or a "StaticProp" entity type! 
 * @param asPropName the prop to attach another prop at
 * @param asAttachName internal name of the prop that gets attached
 * @param asAttachFile the prop that gets attached extension .ent
 * @param afPosX X position of the attach from the prop
 * @param afPosY Y position of the attach from the prop
 * @param afPosZ Z position of the attach from the prop
 * @param afRotX rotation around X axis of the attach
 * @param afRotY rotation around Y axis of the attach
 * @param afRotZ rotation around ZX axis of the attach
 */
void AttachPropToProp(string &in asPropName, string &in asAttachName, string &in asAttachFile, float afPosX, float afPosY, float afPosZ, float afRotX, float afRotY, float afRotZ);

/**
 * @brief Detaches a prop from a prop.
 * @param asPropName
 * @param asAttachName
 */
void RemoveAttachedPropFromProp(string &in asPropName, string &in asAttachName);

/**
 * @brief Modifies the health of a prop.
 * @param asName
 * @param afHealth
 */
void SetPropHealth(string &in asName, float afHealth);

/**
 * @brief Modifies the health of a prop.
 * @param asName
 * @param afHealth
 */
void AddPropHealth(string &in asName, float afHealth);

/**
 * @brief Returns the health of a prop.
 * @param asName
 * @return The health of the prop
 */
float GetPropHealth(string &in asName);

/**
 * @brief Resets a prop's state to the original one when the map was loaded.
 * @param asName
 */
void ResetProp(string &in asName);

/**
 * @brief Makes the prop play an animation and calls a function when it stops. Callback syntax: void MyFunc(string &in asProp)
 * @param asProp
 * @param asAnimation
 * @param afFadeTime
 * @param abLoop
 * @param asCallback
 */
void PlayPropAnimation(string &in asProp, string &in asAnimation, float afFadeTime, bool abLoop, string &in asCallback);

/**
 * @brief These functions push objects. Note that rather high values are needed when applying forces  (on the order of ~100 (weak) to ~10000 (strong)), but not impulses (values less than 10 can be appropriate). Forces are external influences, and will have different effect depending on the mass of the object they are being applied to; impulses disregard mass, and can cause objects to break, as if hit. A "Body" is a physics-related helper object, to which a force or an impulse can be applied. Entities can consist of several bodies, interconnected in various ways (you can create/examine bodies in the model editor).
 * @param asName
 * @param afX
 * @param afY
 * @param afZ
 * @param asCoordSystem
 */
void AddPropForce(string &in asName, float afX, float afY, float afZ, string &in asCoordSystem);

/**
 * @brief These functions push objects. Note that rather high values are needed when applying forces  (on the order of ~100 (weak) to ~10000 (strong)), but not impulses (values less than 10 can be appropriate). Forces are external influences, and will have different effect depending on the mass of the object they are being applied to; impulses disregard mass, and can cause objects to break, as if hit. A "Body" is a physics-related helper object, to which a force or an impulse can be applied. Entities can consist of several bodies, interconnected in various ways (you can create/examine bodies in the model editor).
 * @param asName
 * @param afX
 * @param afY
 * @param afZ
 * @param asCoordSystem
 */
void AddPropImpulse(string &in asName, float afX, float afY, float afZ, string &in asCoordSystem);

/**
 * @brief These functions push objects. Note that rather high values are needed when applying forces  (on the order of ~100 (weak) to ~10000 (strong)), but not impulses (values less than 10 can be appropriate). Forces are external influences, and will have different effect depending on the mass of the object they are being applied to; impulses disregard mass, and can cause objects to break, as if hit. A "Body" is a physics-related helper object, to which a force or an impulse can be applied. Entities can consist of several bodies, interconnected in various ways (you can create/examine bodies in the model editor).
 * @param asName
 * @param afX
 * @param afY
 * @param afZ
 * @param asCoordSystem
 */
void AddBodyForce(string &in asName, float afX, float afY, float afZ, string &in asCoordSystem);

/**
 * @brief These functions push objects. Note that rather high values are needed when applying forces  (on the order of ~100 (weak) to ~10000 (strong)), but not impulses (values less than 10 can be appropriate). Forces are external influences, and will have different effect depending on the mass of the object they are being applied to; impulses disregard mass, and can cause objects to break, as if hit. A "Body" is a physics-related helper object, to which a force or an impulse can be applied. Entities can consist of several bodies, interconnected in various ways (you can create/examine bodies in the model editor).
 * @param asName
 * @param afX
 * @param afY
 * @param afZ
 * @param asCoordSystem
 */
void AddBodyImpulse(string &in asName, float afX, float afY, float afZ, string &in asCoordSystem);

/**
 * @brief Connects a prop with the movement of a rope (i.e. turn a wheel to move a rope). For Levers, the rope only moves when the Lever is at the min, max, or middle.
 * @param asName
 * @param asPropName
 * @param asRopeName
 * @param abInteractOnly
 * @param afSpeedMul
 * @param afToMinSpeed
 * @param afToMaxSpeed
 * @param abInvert
 * @param alStatesUsed
 */
void InteractConnectPropWithRope(string &in asName, string &in asPropName, string &in asRopeName, bool abInteractOnly, float afSpeedMul, float afToMinSpeed, float afToMaxSpeed, bool abInvert, int alStatesUsed);

/**
 * @brief This one should only be used if there must be an exact correspondence to prop "amount" and the MoveObject open amount. It is best used for Wheel-door connections, where the MoveObject moves continuously along with the Wheel. For Levers, the MoveObject only moves when the Lever is at the min, max, or middle.
 * @param asName
 * @param asPropName
 * @param asMoveObjectName
 * @param abInteractOnly
 * @param abInvert
 * @param alStatesUsed
 */
void InteractConnectPropWithMoveObject(string &in asName, string &in asPropName, string &in asMoveObjectName, bool abInteractOnly, bool abInvert, int alStatesUsed);

/**
 * @brief Connects two entities together so that changing the state of the main entity changes the state of the connected entity.
 * @param asName
 * @param asMainEntity
 * @param asConnectEntity
 * @param abInvertStateSent
 * @param alStatesUsed
 * @param asCallbackFunc
 */
void ConnectEntities(string &in asName, string &in asMainEntity, string &in asConnectEntity, bool abInvertStateSent, int alStatesUsed, string &in asCallbackFunc);

/**
 * @brief Turns a lamp on or off.
 * @param asName
 * @param abLit
 * @param abEffects
 */
void SetLampLit(string &in asName, bool abLit, bool abEffects);

/**
 * @brief Locks a SwingDoor.
 * @param asName
 * @param abLocked
 * @param abEffects
 */
void SetSwingDoorLocked(string &in asName, bool abLocked, bool abEffects);

/**
 * @brief Closes a SwingDoor.
 * @param asName
 * @param abClosed
 * @param abEffects
 */
void SetSwingDoorClosed(string &in asName, bool abClosed, bool abEffects);

/**
 * @brief Checks whether a swing door is locked.
 * @param asName
 */
bool GetSwingDoorLocked(string &in asName);

/**
 * @brief Checks whether a swing door is closed.
 * @param asName
 */
bool GetSwingDoorClosed(string &in asName);

/**
 * @brief Deactivates the "auto-close" when a door is nearly closed.
 * @param asName
 * @param abDisableAutoClose
 */
void SetSwingDoorDisableAutoClose(string &in asName, bool abDisableAutoClose);

/**
 * @brief Returns an integer depending on how far the door is opened. -1 = angle is close to 0°, 1 = angle is 70% or higher of max, 0 = inbetween -1 and 1.
 * @param asName
 */
int GetSwingDoorState(string &in asName);

/**
 * @brief Locks a level door. Note that level doors are NOT swing doors.
 * @param asName
 * @param abLocked
 */
void SetLevelDoorLocked(string &in asName, bool abLocked);

/**
 * @brief Determines which sound is played when interacting with a locked level door.
 * @param asName
 * @param asSound
 */
void SetLevelDoorLockedSound(string &in asName, string &in asSound);

/**
 * @brief Displays a message when interacting with a locked level door.
 * @param asName
 * @param asTextCat
 * @param asTextEntry
 */
void SetLevelDoorLockedText(string &in asName, string &in asTextCat, string &in asTextEntry);

/**
 * @brief Moves an object to a certain state.
 * @param asName
 * @param afState
 */
void SetMoveObjectState(string &in asName, float afState);

/**
 * @brief Moves an object to a certain state, extended method.
 * @param asName
 * @param afState
 * @param afAcc
 * @param afMaxSpeed
 * @param afSlowdownDist
 * @param abResetSpeed
 */
void SetMoveObjectStateExt(string &in asName, float afState, float afAcc, float afMaxSpeed, float afSlowdownDist, bool abResetSpeed);

/**
 * @brief Makes an object stuck in a certain state.
 * @param asName
 * @param alState
 */
void SetPropObjectStuckState(string &in asName, int alState);

/**
 * @brief Makes an wheel stuck in a certain state.
 * @param asName
 * @param alState
 */
void SetWheelStuckState(string &in asName, int alState, bool abEffects);

/**
 * @brief Makes an lever stuck in a certain state.
 * @param asName
 * @param alState
 */
void SetLeverStuckState(string &in asName, int alState, bool abEffects);

/**
 * @brief Moves a wheel to a certain angle.
 * @param asName
 * @param afAngle
 * @param abAutoMove
 */
void SetWheelAngle(string &in asName, float afAngle, bool abAutoMove);

/**
 * @brief Allows the player to make a wheel unstuck when interacted with.
 * @param asName
 * @param abX
 */
void SetWheelInteractionDisablesStuck(string &in asName, bool abX);

/**
 * @brief Allows the player to make a lever unstuck when interacted with.
 * @param asName
 * @param abX
 */
void SetLeverInteractionDisablesStuck(string &in asName, bool abX);

/**
 * @brief Returns the state of the lever. 0 = not stuck, 1 = at max, -1 = at min
 * @param asName
 */
int GetLeverState(string &in asName);

/**
 * @brief Makes a MultiSlider stuck in a certain state.
 * @param asName
 * @param alStuckState
 * @param abEffects
 */
void SetMultiSliderStuckState(string &in asName, int alStuckState, bool abEffects);

/**
 * @brief Calls a function when state changes. Callback syntax: void MyFunc(string &in asEntity, int alState)
 * @param asName
 * @param asCallback
 */
void SetMultiSliderCallback(string &in asName, string &in asCallback);

/**
 * @brief Sets a Button's switched state.
 *
 * @param asName - internal name of the button
 * @param abSwitchedOn - true = switched on, false = switched off
 * @param abEffects - whether to play associated effects/sounds
 */
void SetButtonSwitchedOn(string &in asName, bool abSwitchedOn, bool abEffects);

/**
 * @brief Allows entities to stick to a StickyArea.
 * @param abX
 */
void SetAllowStickyAreaAttachment(bool abX);

/**
 * @brief Attaches a prop to a StickyArea.
 * @param asAreaName
 * @param asProp
 */
void AttachPropToStickyArea(string &in asAreaName, string &in asProp);

/**
 * @brief Attaches a body to a StickyArea.
 * @param asAreaName
 * @param asProp
 */
void AttachBodyToStickyArea(string &in asAreaName, string &in asBody);

/**
 * @brief Detaches everything from a StickyArea.
 * @param asAreaName
 */
void DetachFromStickyArea(string &in asAreaName);

/**
 * @brief Wakes/sleeps a NPC.
 * @param asName
 * @param abAwake
 * @param abEffects
 */
void SetNPCAwake(string &in asName, bool abAwake, bool abEffects);

/**
 * @brief Sets a NPC's head to follow the player's movements.
 * @param asName
 * @param abX
 */
void SetNPCFollowPlayer(string &in asName, bool abX);

/**
 * @brief Disables an enemy.
 * @param asName
 * @param abDisabled
 */
void SetEnemyDisabled(string &in asName, bool abDisabled);

/**
 * @brief Makes an enemy a hallucination. Hallucinations fade to smoke when they get near the player.
 * @param asName
 * @param abX
 */
void SetEnemyIsHallucination(string &in asName, bool abX);

/**
 * @brief Instantly fades an enemy to smoke.
 * @param asName
 * @param abPlaySound
 */
void FadeEnemyToSmoke(string &in asName, bool abPlaySound);

/**
 * @brief Makes the enemy run to the player, no matter where he is.
 * @param asName
 */
void ShowEnemyPlayerPosition(string &in asName);

/**
 * @brief Requires version 1.3
 *
 * Gives the specified enemy the player's current position and makes it search
 * the area.
 *
 * @param asName - Internal name of the enemy.
 */
void AlertEnemyOfPlayerPresence(string &in asName);

/**
 * @brief Enables or disables enemy triggers. If disabled, enemy will not react to player or attack.
 * @param asName
 * @param abX
 */
void SetEnemyDisableTriggers(string &in asName, bool abX);

/**
 * @brief Adds a patrol node to the enemy's path.
 * @param asName
 * @param asNodeName
 * @param afWaitTime
 * @param asAnimation
 */
void AddEnemyPatrolNode(string &in asName, string &in asNodeName, float afWaitTime, string &in asAnimation);

/**
 * @brief Clears the current path of patrol nodes of the enemy.
 * @param asEnemyName
 */
void ClearEnemyPatrolNodes(string &in asEnemyName);

/**
 * @brief Requires version 1.3
 *
 * Enables/disables whether an enemy activates the player's sanity drain when
 * stared at.
 *
 * @param asName - Internal name of the enemy.
 * @param abX   - Enabled/disabled.
 */
void SetEnemySanityDecreaseActive(string &in asName, bool abX);

/**
 * @brief Requires version 1.3
 *
 * Teleports an enemy to a specific PathNode.
 *
 * @param asEnemyName - Internal name of the enemy
 * @param asNodeName  - Internal name of the node to teleport to
 * @param abChangeY   - Whether the Y position of the node will be used when teleporting the enemy
 */
void TeleportEnemyToNode(string &in asEnemyName, string &in asNodeName, bool abChangeY);

/**
 * @brief Requires version 1.3
 *
 * Teleports an enemy to a specific entity.
 *
 * @param asEnemyName   - Internal name of the enemy
 * @param asTargetEntity - Internal name of the entity to teleport to
 * @param asTargetBody   - Internal name of the entity's body name to teleport to. If empty, the first body will be used (might be unstable, recommended to input a body anyway)
 * @param abChangeY      - Whether the Y position of the entity will be used when teleporting the enemy
 */
void TeleportEnemyToEntity(string &in asEnemyName, string &in asTargetEntity, string &in asTargetBody, bool abChangeY);

/**
 * @brief Requires version 1.3
 *
 * Changes the pose a specified ManPig.
 *
 * @param asName     - Internal name of the enemy
 * @param asPoseType - Name of the ManPig pose to use. Can be "Biped" or "Quadruped"
 */
void ChangeManPigPose(string &in asName, string &in asPoseType);

/**
 * @brief Requires version 1.3
 *
 * Enables/disables whether a specified Tesla ManPig should fade the player's
 * view in and out.
 *
 * @param asName - Internal name of the enemy
 * @param abX    - Enabled/disabled
 */
void SetTeslaPigFadeDisabled(string &in asName, bool abX);

/**
 * @brief Requires version 1.3
 *
 * Enables/disables whether a specified Tesla ManPig should play the proximity
 * sounds.
 *
 * @param asName - Internal name of the enemy
 * @param abX    - Enabled/disabled
 */
void SetTeslaPigSoundDisabled(string &in asName, bool abX);

/**
 * @brief Requires version 1.3
 *
 * Enables/disables whether a specified Tesla ManPig should be easier to
 * escape from when hunted. If not disabled, easy escape is activated if the
 * player is more than 12.35 meters away, the enemy can't see the player, and
 * the player has less than 75 health. When this occurs, the enemy is forced
 * to stop hunting and wait for half a second.
 *
 * @param asName - Internal name of the enemy
 * @param abX    - Enabled/disabled
 */
void SetTeslaPigEasyEscapeDisabled(string &in asName, bool abX);

/**
 * @brief Requires version 1.3
 *
 * Forces a Tesla ManPig to be visible for a short time.
 *
 * @param asName - Internal name of the enemy
 */
void ForceTeslaPigSighting(string &in asName);

/**
 * @brief Requires version 1.3
 * @param asName
 */
/**
 * @brief Requires version 1.3
 * @brief Returns the name of the current state a specified enemy is in.
 *
 * @param asName - Internal name of the enemy whose state name should be returned.
 * @return A string containing the state's name.
 *
 * Possible common state names (may vary by enemy type):
 *  - Idle
 *  - Wait
 *  - Patrol
 *  - Investigate
 *  - Alert
 *  - Search
 *  - Hurt
 *  - Hunt
 *  - HuntPause
 *  - HuntWander
 *  - AttackMeleeShort
 *  - AttackMeleeLong
 *  - BreakDoor
 *  - Dead
 *
 * Waterlurker-only states:
 *  - GoHome
 *  - Eat
 *
 * ManPig-only states:
 *  - Flee
 *  - Stalk
 *  - Track
 *
 * Unused states:
 *  - AttackRange
 */
string GetEnemyStateName(string &in asName);

#ifdef __cplusplus
}
#endif

#endif // HPL2_API_SANITIZED_H
