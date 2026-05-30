# HPL2 1.5 Update

## Summary

The 1.5 update primarily focused on
modding workflow improvements and Steam
integration.

Unlike 1.3, relatively few scripting
features were added.

However, 1.5 introduced several features
that significantly changed how large mods
can be structured.

Major additions include:

* Full Conversion support through Custom Stories.
* Steam Workshop support.
* #include support for .hps files.
* OnUpdate callback.
* ShowScreenImage().
* Various editor and engine improvements.

## Historical Context

Version 1.5 is primarily associated with
the Steam release of Amnesia: The Dark Descent.

Many retail, DRM-free and legacy copies
only support up to version 1.4.

Do not assume 1.5 functionality exists
unless:

TARGET_ENGINE=HPL2_15

is explicitly selected.

## Full Conversion Support

Version 1.5 introduced:

InitCfgFile

inside:

custom_story_settings.cfg

This allows Full Conversion projects to be
packaged and launched as Custom Stories.

Existing Full Conversion projects may be
converted into extended Custom Stories.

This functionality also enables Steam
Workshop distribution.

## Scripting Additions

Added:

* ShowScreenImage()
* OnUpdate()
* #include support for .hps files

See:

* copilot_hpl2/updates_15/map_updates.hps

## Script Organization

Prior to version 1.5, level scripts were
typically stored in a single .hps file.

Version 1.5 introduced:

#include "file.hps"

allowing scripts to be split across
multiple files.

For large projects this may improve:

* Organization
* Reusability
* Maintainability

Copilot may suggest modular script
organization only when:

TARGET_ENGINE=HPL2_15

## Performance & Stability

Fixed:

* Callback overflow crashes.
* Excessive timer-related crashes.
* Skybox cubemap rendering issues.
* Coin chest save/load issues.

## Editor Improvements

Added:

* Gamepad navigation in Custom Story menus.
* Multiple slime type support.
* Improved color picker.
* Menu text color customization.

## Guidance For Copilot

When TARGET_ENGINE=HPL2_15:

* Suggest #include-based script organization
  when scripts become large.
* A complex modular system may also be similarly extracted.
* OnUpdate() may be used instead of timer-
  based update loops when appropriate.
  ONLY AFTER CAREFUL CONSIDERATION to performance.
* ShowScreenImage() is available.
* Full Conversion projects may be structured
  as Custom Stories.

When TARGET_ENGINE is below HPL2_15:

* Do not suggest #include.
* Assume a single map script.
* Do not suggest OnUpdate().
* Do not suggest ShowScreenImage().
* Do not suggest InitCfgFile-based Full
  Conversion support.

When TARGET_ENGINE=HPL2_AMFP:

* Assume HPL2 1.5 features DO NOT exist.
