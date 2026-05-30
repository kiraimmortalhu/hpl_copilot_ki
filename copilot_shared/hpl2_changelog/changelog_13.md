# HPL2 1.3 Update

## Summary

The 1.3 update was the largest scripting update released for
Amnesia: The Dark Descent.

For modders it introduced:

* New scripting functions.
* Additional enemy types and functionality.
* Position manipulation functions.
* String conversion and math utility functions.
* Improved prop attachment functionality.
* Additional entity manipulation functionality.

Most functions documented under:

* copilot_hpl2/updates_13/

originate from this patch.

## Historical Context

This update was released after the release of
Amnesia: A Machine for Pigs had already occured.

A Machine for Pigs uses a separate HPL2 branch and
should not be treated as equivalent to HPL2 1.3.

Some functionality overlaps between the two branches,
but they are not API-compatible.

See:

* copilot_hpl2/core_amfp
* copilot_hpl2/updates_13

for their respective implementations.

## Modding Additions

### Enemy Support

Added:

* Enemy_ManPig entity type.
* Enemy teleportation functions.
* Enemy state query functions.
* Enemy sanity control functions.

### Player Support

Added:

* Player position manipulation.
* Player jump force multiplier.
* Fall damage control.
* Darkness effect control.
* Insanity event control.

### Entity Support

Added:

* Entity replacement.
* Entity visibility control.
* Entity placement.
* Entity position manipulation.
* Body mass control.

### Utility Functions

Added:

* String conversion functions.
* Mathematical utility functions.

### Prop Support

AttachPropToProp replaces
AddAttachedPropToProp.

The new implementation fixes an issue where
the Z rotation parameter was incorrectly used
as the Z position.

The old function remains available but produces
warning messages.

## Engine Improvements

Added:

* FBX support.
* Collada support from 3ds Max exports.
* Full gamepad support.

## Debugging Improvements

Added:

* F2 quick map reload.
* F3 fast-forward mode.
* In-game error and warning display.

## Notable Bug Fixes

Fixed:

* Attached prop destruction crashes.
* Animation step-event editor issues.
* bone_pile_human2.dae editor crash.

## Guidance For Copilot

When TARGET_ENGINE is HPL2_13 or newer:

- Consider update functions from copilot_hpl2/updates_13.
- Prefer AttachPropToProp over AddAttachedPropToProp.
- Position manipulation functions are available.
- Enemy teleportation functions are available.
- Mathematical utility functions are available.

When TARGET_ENGINE is HPL2_12:

- Do not suggest update functions from copilot_hpl2/updates_13.

When TARGET_ENGINE is HPL2_AMFP:

- Do not assume HPL2 1.3 functionality exists.
- Use documentation from copilot_hpl2/core_amfp instead.