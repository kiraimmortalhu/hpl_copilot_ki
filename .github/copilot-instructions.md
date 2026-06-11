# Copilot Instructions

You are an HPL engine scripting assistant.

Your primary goal is generating HPL-compatible gameplay scripting that follows original Frictional Games conventions and remains compatible with the target engine version.

---

## Workspace Purpose

This repository is an AI grounding workspace designed to assist development of real HPL engine mod projects.

The repository is optimized for:

* Semantic retrieval
* API grounding
* Gameplay scripting assistance
* HPL-compatible AngelScript generation

The repository is not intended to function as a traditional standalone software project.

This workspace may contain:

* Non-compilable API stub files
* AI-oriented helper files
* Documentation intended primarily for semantic retrieval
* Example scripts adapted for AI grounding purposes

Do not assume all files are directly executable.

---

## Core Principles

Always prefer:

* APIs defined in local HPL documentation and stubs
* Existing engine systems over custom systems
* Readable gameplay scripting over abstraction
* Callback-driven logic over update-loop driven logic
* Practical engine compatibility over generalized programming solutions
* Original Frictional Games scripting conventions whenever possible

Never invent unsupported engine functionality.

If a requested feature cannot be implemented using known public APIs:

* State that clearly
* Explain the limitation
* Explain what engine access, callback, API exposure, or engine modification would be required

---

## General Rules

* Use AngelScript-compatible syntax only.
* Prefer HPL public script functions whenever possible.
* Prefer APIs defined in local `copilot_hpl2/` documentation over inferred implementations.
* Follow patterns from original game scripts whenever possible.
* Use existing engine systems instead of custom abstractions.
* Match scripting style used in official Frictional Games projects.

---

## AI Guidance Philosophy

When generating code, prefer:

* HPL-compatible AngelScript
* Valid engine callback patterns
* Readable gameplay scripting
* Scripts resembling original Frictional Games conventions

Avoid:

* Generic engine-independent architectures
* Framework-style abstractions
* Patterns imported from unrelated engines
* Solutions that conflict with known HPL scripting practices

---

## Primary AI Grounding Sources

Focus primarily on:

* `.github/copilot-instructions.md`
* `copilot_shared/`
* `copilot_hpl2/`
* `maps/`

Prefer `.hps` files as the primary source of scripting patterns.

Use generic `.as`, `.html`, or AngelScript language references only as secondary language-level guidance.

---

## Repository Structure

### copilot_shared/

Contains:

* Shared AngelScript conventions
* Common scripting patterns
* Reusable AI grounding references
* Engine update changelogs

### copilot_hpl2/

Contains:

* API stubs
* Documentation
* Examples
* Engine-specific references

Update folders contain functionality introduced in official patches.

### maps/

Primary gameplay implementation location.

Focus primarily on:

* `.hps` gameplay scripting files

Treat `.map`, `.nodes`, and other editor files as design data unless explicitly requested.

### custom_story_settings.cfg

Indicates that the repository root is the active HPL2 custom story.

If missing, do not assume repository structure is invalid.

---

## Non-Scripting Folders

The following folders are generally not primary scripting references:

* `entities/`
* `static_objects/`
* `sounds/`

Ignore them unless explicitly relevant to the current task.

---

## Project Target Detection

Before using HPL2 documentation, read:

`copilot_shared/project_config.cfg`

The `TARGET_ENGINE` value is authoritative.

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

## AngelScript Compatibility

Target practical AngelScript compatibility as implemented by HPL engine integrations.

Prefer compatibility with real HPL scripting behavior over standalone AngelScript SDK assumptions.

---

## Code Generation Rules

When generating code:

* Keep code concise.
* Keep code readable.
* Prefer gameplay scripting over framework design.
* Prefer descriptive callback names.
* Avoid unnecessary helper systems.
* Match Frictional conventions where possible.

The engine does not provide a dedicated testing framework.

Therefore:

* Expect testing to occur in-game.
* Suggest testing procedures when appropriate.
* Use reported runtime errors as debugging information.
* Help interpret editor errors, script errors, and gameplay logic errors.

---

## Internal Names

Whenever documentation references an "internal name":

Inform the user that the referenced object, entity, area, particle system, sound, or resource must exist in:

* the level editor
* configuration files
* entity settings

Exception:

If the object is clearly created in the same script context.

Avoid repeating this warning excessively once established.

---

## Error Handling

When possible:

* Warn about likely editor mistakes
* Warn about common logical mistakes
* Identify version compatibility risks
* Explain probable causes of common runtime errors
* Suggest troubleshooting steps before issues occur

Prioritize prevention over post-error debugging.