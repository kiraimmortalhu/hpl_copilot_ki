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
 * @param afStep
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
int StringContains(string &in asString, string &in asSubString);

/**
 * @brief Returns the substring in a string. Example: in the string "frictional games rocks", using 4 as alStart  and 6 as alCount  would return "tional".
 * @param asString
 * @param alStart
 * @param alCount
 */
const char* StringSub(string &in asString, int alStart, int alCount);

/**
 * @brief Requires version 1.3
 * @param asString
 */
int StringToInt(string &in asString);

/**
 * @brief Requires version 1.3
 * @param asString
 */
float StringToFloat(string &in asString);

/**
 * @brief Requires version 1.3
 * @param asString
 */
int StringToBool(string &in asString);

/**
 * @brief Requires version 1.3
 * @param afX
 */
float MathSin(float afX);

/**
 * @brief Requires version 1.3
 * @param afX
 */
float MathCos(float afX);

/**
 * @brief Requires version 1.3
 * @param afX
 */
float MathTan(float afX);

/**
 * @brief Requires version 1.3
 * @param afX
 */
float MathAsin(float afX);

/**
 * @brief Requires version 1.3
 * @param afX
 */
float MathAcos(float afX);

/**
 * @brief Requires version 1.3
 * @param afX
 */
float MathAtan(float afX);

/**
 * @brief Requires version 1.3
 * @param afX
 * @param afY
 */
float MathAtan2(float afX, float afY);

/**
 * @brief Requires version 1.3
 * @param afX
 */
float MathSqrt(float afX);

/**
 * @brief Requires version 1.3
 * @param afBase
 * @param afExp
 */
float MathPow(float afBase, float afExp);

/**
 * @brief Requires version 1.3
 * @param afA
 * @param afB
 */
float MathMin(float afA, float afB);

/**
 * @brief Requires version 1.3
 * @param afA
 * @param afB
 */
float MathMax(float afA, float afB);

/**
 * @brief Requires version 1.3
 * @param afX
 * @param afMin
 * @param afMax
 */
float MathClamp(float afX, float afMin, float afMax);

/**
 * @brief Requires version 1.3
 * @param afX
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
 * @brief No description provided.
 * @param asName
 * @param alVal
 */
void SetLocalVarInt(string &in asName, int alVal);

/**
 * @brief No description provided.
 * @param asName
 * @param afVal
 */
void SetLocalVarFloat(string &in asName, float afVal);

/**
 * @brief No description provided.
 * @param asName
 * @param asVal
 */
void SetLocalVarString(string &in asName, string &in asVal);

/**
 * @brief No description provided.
 * @param asName
 * @param alVal
 */
void SetGlobalVarInt(string &in asName, int alVal);

/**
 * @brief No description provided.
 * @param asName
 * @param afVal
 */
void SetGlobalVarFloat(string &in asName, float afVal);

/**
 * @brief No description provided.
 * @param asName
 * @param asVal
 */
void SetGlobalVarString(string &in asName, string &in asVal);

/**
 * @brief Preloads a particle system.
 * @param asPSFile
 */
void PreloadParticleSystem(string &in asPSFile);

/**
 * @brief Creates a particle system on an entity.
 * @param asPSName - internal name
 * @param asPSFile
 * @param asEntity
 * @param abSavePS
 */
void CreateParticleSystemAtEntity(string &in asPSName, string &in asPSFile, string &in asEntity, bool abSavePS);

/**
 * @brief Creates a particle system on an entity, extended method with more options. 
 * @param asPSName - internal name
 * @param asPSFile - 
 * @param asEntity
 * @param abSavePS
 */
void CreateParticleSystemAtEntityExt(string &in asPSName, string &in asPSFile, string &in asEntity, bool abSavePS,
float afR, float afG, float afB, float afA, bool abFadeAtDistance, float afFadeMinEnd, float afFadeMinStart,
float afFadeMaxStart, float afFadeMaxEnd);

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
int GetEffectVoiceActive(void);

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
int GetFlashbackIsActive(void);

/**
 * @brief Continuously spawn regular particle systems (.ps) around the player. Particles created by this script carry over from map to map.
 * @param asSPSFile
 */
void StartPlayerSpawnPS(string &in asSPSFile);

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
 * @param abX
 */
void SetInDarknessEffectsActive(bool abX);

/**
 * @brief Requires version 1.5
 * @param asImageName
 * @param afX
 * @param afY
 * @param afScale
 * @param abUseRelativeCoordinates
 * @param afDuration
 * @param afFadeIn
 * @param afFadeOut
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
 * @param asEventName
 */
void StartInsanityEvent(string &in asEventName);

/**
 * @brief Starts a random insanity event from the available sets.
 */
void StartRandomInsanityEvent(void);

/**
 * @brief Requires version 1.3
 */
void StopCurrentInsanityEvent(void);

/**
 * @brief Checks whether an insanity event is currently in effect.Not useful at all due to having a return type of void when it should be bool.
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
 * @param afX
 * @param afY
 * @param afZ
 * @param abUseLocalCoords
 */
void AddPlayerBodyForce(float afX, float afY, float afZ, bool abUseLocalCoords);

/**
 * @brief Enables/Disables the icons when a player has something in focus.
 * @param abX
 */
void ShowPlayerCrossHairIcons(bool abX);

/**
 * @brief Modifies/returns the sanity of the player.
 * @param afSanity
 */
void SetPlayerSanity(float afSanity);

/**
 * @brief Modifies/returns the health of the player.
 * @param afHealth
 */
void SetPlayerHealth(float afHealth);

/**
 * @brief Modifies/returns the lamp oil of the player.
 * @param afOil
 */
void SetPlayerLampOil(float afOil);

/**
 * @brief Returns the current speed of the player.
 */
float GetPlayerSpeed(void);

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
 * @brief Changes the player's move/run/look speed. Default is 1.
 * @param afMul
 */
void SetPlayerMoveSpeedMul(float afMul);

/**
 * @brief Requires version 1.3
 * @param afMul
 */
void SetPlayerJumpForceMul(float afMul);

/**
 * @brief Enables/Disables the player's ability to jump/crouch.
 * @param abX
 */
void SetPlayerJumpDisabled(bool abX);

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
int GetLanternActive(void);

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
 * @brief Requires version 1.3
 * @param abX
 */
void SetPlayerFallDamageDisabled(bool abX);

/**
 * @brief Requires version 1.3
 * @param afX
 * @param afY
 * @param afZ
 */
void SetPlayerPos(float afX, float afY, float afZ);

/**
 * @brief Requires version 1.3
 */
float GetPlayerPosX(void);

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
 * @param asName
 * @param asNameAndTextEntry
 */
void AddQuest(string &in asName, string &in asNameAndTextEntry);

/**
 * @brief Completes a quest. If the quest has not been added, it's marked as complete anyway, preventing it from being added.
 * @param asName
 * @param asNameAndTextEntry
 */
void CompleteQuest(string &in asName, string &in asNameAndTextEntry);

/**
 * @brief Checks whether a quest is completed/added.
 * @param asName
 */
int QuestIsCompleted(string &in asName);

/**
 * @brief Sets the number of quests in the map. Obsolete; formerly used to calculate a completion percentage when looking at a level door.
 * @param alNumberOfQuests
 */
void SetNumberOfQuestsInMap(int alNumberOfQuests);

/**
 * @brief Displays a hint on the player's screen.
 * @param asName
 * @param asMessageCat
 * @param asMessageEntry
 * @param afTimeShown
 */
void GiveHint(string &in asName, string &in asMessageCat, string &in asMessageEntry, float afTimeShown);

/**
 * @brief Blocking a hint prevents it from being shown. Blocked hints are included in savefiles, so they should persist between levels. Unblocking a hint allows it to be shown.
 * @param asName
 */
void BlockHint(string &in asName);

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
int GetEntityExists(string &in asName);

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
int GetEntitiesCollide(string &in asEntityA, string &in asEntityB);

/**
 * @brief Requires version 1.3
 * @param asName
 * @param afMass
 */
void SetBodyMass(string &in asName, float afMass);

/**
 * @brief Requires version 1.3
 * @param asName
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
int GetPropIsInteractedWith(string &in asName);

/**
 * @brief Rotates the prop up to a set speed.
 * @param asName
 * @param afAcc
 * @param afGoalSpeed
 * @param afAxisX
 * @param afAxisY
 * @param afAxisZ
 * @param abResetSpeed
 * @param asOffsetArea
 */
void RotatePropToSpeed(string &in asName, float afAcc, float afGoalSpeed, float afAxisX, float afAxisY, float afAxisZ, bool abResetSpeed, string &in asOffsetArea);

/**
 * @brief Stops all movement of a prop.
 * @param asName
 */
void StopPropMovement(string &in asName);

/**
 * @brief Attaches a prop to another prop.
 * @param asPropName
 * @param asAttachName
 * @param asAttachFile
 * @param afPosX
 * @param afPosY
 * @param afPosZ
 * @param afRotX
 * @param afRotY
 * @param afRotZ
 */
void AddAttachedPropToProp(string &in asPropName, string &in asAttachName, string &in asAttachFile, float afPosX, float afPosY, float afPosZ, float afRotX, float afRotY, float afRotZ);

/**
 * @brief Requires version 1.3
 * @param asPropName
 * @param asAttachName
 * @param asAttachFile
 * @param afPosX
 * @param afPosY
 * @param afPosZ
 * @param afRotX
 * @param afRotY
 * @param afRotZ
 */
void AttachPropToProp(string &in asPropName, string &in asAttachName, string &in asAttachFile, float afPosX, float afPosY, float afPosZ, float afRotX, float afRotY, float afRotZ);

/**
 * @brief Detaches a prop from a prop.
 * @param asPropName
 * @param asAttachName
 */
void RemoveAttachedPropFromProp(string &in asPropName, string &in asAttachName);

/**
 * @brief Modifies/returns the health of a prop.
 * @param asName
 * @param afHealth
 */
void SetPropHealth(string &in asName, float afHealth);

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
 * @brief Checks whether a swing door is locked/closed.
 * @param asName
 */
int GetSwingDoorLocked(string &in asName);

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
 * @brief Makes an object/wheel/lever stuck in a certain state.
 * @param asName
 * @param alState
 */
void SetPropObjectStuckState(string &in asName, int alState);

/**
 * @brief Moves a wheel to a certain angle.
 * @param asName
 * @param afAngle
 * @param abAutoMove
 */
void SetWheelAngle(string &in asName, float afAngle, bool abAutoMove);

/**
 * @brief Allows the player to make a wheel/lever unstuck when interacted with.
 * @param asName
 * @param abX
 */
void SetWheelInteractionDisablesStuck(string &in asName, bool abX);

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
 * @brief No description provided.
 * @param asName
 * @param abSwitchedOn
 * @param abEffects
 */
void SetButtonSwitchedOn(string &in asName, bool abSwitchedOn, bool abEffects);

/**
 * @brief Allows entities to stick to a StickyArea.
 * @param abX
 */
void SetAllowStickyAreaAttachment(bool abX);

/**
 * @brief Attaches a prop/body to a StickyArea.
 * @param asAreaName
 * @param asProp
 */
void AttachPropToStickyArea(string &in asAreaName, string &in asProp);

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
 * @param asName
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
 * @param asName
 * @param abX
 */
void SetEnemySanityDecreaseActive(string &in asName, bool abX);

/**
 * @brief Requires version 1.3
 * @param asEnemyName
 * @param asNodeName
 * @param abChangeY
 */
void TeleportEnemyToNode(string &in asEnemyName, string &in asNodeName, bool abChangeY);

/**
 * @brief Requires version 1.3
 * @param asEnemyName
 * @param asTargetEntity
 * @param asTargetBody
 * @param abChangeY
 */
void TeleportEnemyToEntity(string &in asEnemyName, string &in asTargetEntity, string &in asTargetBody, bool abChangeY);

/**
 * @brief Requires version 1.3
 * @param asName
 * @param asPoseType
 */
void ChangeManPigPose(string &in asName, string &in asPoseType);

/**
 * @brief Requires version 1.3
 * @param asName
 * @param abX
 */
void SetTeslaPigFadeDisabled(string &in asName, bool abX);

/**
 * @brief Requires version 1.3
 * @param asName
 * @param abX
 */
void SetTeslaPigSoundDisabled(string &in asName, bool abX);

/**
 * @brief Requires version 1.3
 * @param asName
 * @param abX
 */
void SetTeslaPigEasyEscapeDisabled(string &in asName, bool abX);

/**
 * @brief Requires version 1.3
 * @param asName
 */
void ForceTeslaPigSighting(string &in asName);

/**
 * @brief Requires version 1.3
 * @param asName
 */
const char* GetEnemyStateName(string &in asName);

#ifdef __cplusplus
}
#endif

#endif // HPL2_API_SANITIZED_H
