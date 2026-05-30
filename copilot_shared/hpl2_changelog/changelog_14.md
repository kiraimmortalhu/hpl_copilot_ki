# HPL2 1.4 Update

## Summary

The 1.4 update introduced:

* Hard Mode.
* Steam achievements.
* Additional debugging functionality.

Unlike the 1.3 update, version 1.4 did not
significantly expand the scripting API.

Only one script function was introduced:

* UnlockAchievement()

## Historical Context

Version 1.4 is the final official update
available for most non-Steam installations.

For many retail, DRM-free and legacy copies,
1.4 is the newest available version.

Version 1.5 is primarily distributed through
the Steam release and should not be assumed
to exist unless explicitly selected as the
TARGET_ENGINE.

## Hard Mode Support

The update introduced Hard Mode support.

Projects targeting HPL2_14 or newer may use
Hard Mode functionality exposed through the
game configuration files.
It is perfectly compatible with mods.

main_init.cfg introduced one additional variable in this section:

<Variables
 GameName = "Amnesia - The Dark Descent -"
 AllowHardMode = "true"
/>

AllowHardMode controls whether Hard Mode can
be selected by the player upon starting new game.

## Achievement Support

The update introduced Steam achievements.

Scripts may unlock ending achievements using:

UnlockAchievement()

Only specific achievement identifiers are valid.
There is barely if any use cases of this for mods.

See:

* copilot_hpl2/updates_14/achievements.hps

## Debugging Improvements

Added:

* Free camera mode when the Debug Menu is loaded.

## Guidance For Copilot

When TARGET_ENGINE is HPL2_14:

* HPL2 1.3 functionality remains available.
* Achievement functionality is available.
* Hard Mode configuration may be available.
* Do not assume HPL2 1.5 functionality exists.

When TARGET_ENGINE is HPL2_15:

* HPL2 1.4 functionality remains available.

When TARGET_ENGINE is HPL2_12 or HPL2_13:

* Do not suggest UnlockAchievement().
* Do not assume Hard Mode support exists.

When TARGET_ENGINE is HPL2_AMFP:

* Assume 1.4 functionality DOESN'T exist.
