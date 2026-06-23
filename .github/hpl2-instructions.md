# HPL2-specific rules

## Repository Structure additions

### copilot_hpl2/

Contains:

* API stubs
* Documentation
* Examples
* Engine-specific references

Update folders contain functionality introduced in official patches.

### custom_story_settings.cfg

Indicates that the repository root is the active HPL2 custom story.

If missing, do not assume repository structure is invalid.

---

## Project Target values for HPL2

Valid values:

* HPL2_12
* HPL2_13
* HPL2_14
* HPL2_15
* HPL2_AMFP

If missing, invalid, or undefined:

* Ask the user which target engine is being used.
* Do not assume compatibility.
* Do not suggest version-specific functionality.

Treat HPL2_AMFP as a separate engine branch.

Do not combine HPL2_AMFP documentation with HPL2_13, HPL2_14, or HPL2_15 documentation.

---

### Compatibility Rules

If no valid target is configured:

* Assume HPL2_12 compatibility
* Do not use update documentation
* Ask the user to specify a target engine

Important:

* HPL2_AMFP is a separate engine branch
* HPL2_AMFP must never be combined with HPL2 1.3, 1.4, or 1.5 update documentation

## Documentation Source Selection

The selected TARGET_ENGINE determines which documentation may be used.

Only use documentation assigned to the active target.

Never combine APIs from excluded documentation folders.

### HPL2_12

Use:

* copilot_hpl2/core

Do not use:

* core_amfp
* updates_13
* updates_14
* updates_15

### HPL2_AMFP

Use:

* core
* core_amfp

Do not use:

* updates_13
* updates_14
* updates_15

### HPL2_13

Use:

* core
* updates_13

### HPL2_14

Use:

* core
* updates_13
* updates_14

### HPL2_15

Use:

* core
* updates_13
* updates_14
* updates_15

Do not use:

* core_amfp

---

## HPL2 1.5 Script Organization

Only when:

TARGET_ENGINE = HPL2_15

* `#include "file.hps"` may be used
* Includes must appear before script code
* Multiple script files may be combined this way
* Suggest modular script organization when appropriate

For all other engine versions:

* Assume a single level script
* Do not suggest include-based script organization

---

## Preferred Scripting Patterns

Prefer:

* Callback-driven logic
* AddTimer usage
* Event sequencing
* Entity-based interactions
* Small focused functions
* Readable gameplay code

Avoid:

* Unity APIs
* Unreal APIs
* Godot APIs
* Generic C# architectures
* Overengineered systems
* Framework-heavy solutions

---

## Examples and Grounding

Example folders may contain:

* Original game scripting examples
* Puzzle logic
* Enemy behavior
* Sanity events
* Gameplay interactions
* Level scripting patterns

Treat these examples as behavioral references for generated code.

When documentation and examples disagree, prefer official API documentation.

---