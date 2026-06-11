# HPL Copilot

HPL Copilot is an AI-grounding workspace designed to improve AI-assisted scripting for Frictional Games' HPL engine titles.

Rather than relying solely on general AI knowledge, the workspace provides structured documentation, API references, scripting examples, and compatibility guidance that AI assistants such as GitHub Copilot can use as retrieval sources.

The goal is to improve the quality, accuracy, and engine compatibility of AI-assisted scripting workflows.

---

## Features

The repository provides:

* Verified HPL API documentation
* AngelScript references
* Engine-specific scripting documentation
* Original game scripting examples
* Version compatibility guidance
* AI grounding resources

This helps AI assistants:

* Generate authentic HPL scripts
* Avoid hallucinated APIs
* Respect engine version differences
* Use verified function signatures
* Follow established scripting conventions

---

## Supported Engines

### HPL2

Used by:

* Amnesia: The Dark Descent
* Amnesia: Justine
* Amnesia: A Machine for Pigs

### Currently NOT Supported

#### HPL3

Used by:

* SOMA
* Amnesia: Rebirth
* Amnesia: The Bunker

---

## Requirements

Before using this workspace, you should already be familiar with:

* Basic HPL2 mod creation
* The HPL2 Editor Suite
* Script debugging and testing
* General mod folder structure

Tutorials:

* HPL2 Tutorials: *(link coming soon)*

You will also need:

* Visual Studio Code
* GitHub Copilot

Downloads:

* VSCode: *(link coming soon)*
* GitHub Copilot: *(link coming soon)*

---

## Repository Structure

The intended workspace root is your actual mod project, represented by "my_mod".

Example:

```text
my_mod/
├── .github/
│   └── copilot-instructions.md
│
├── shared/
├── hpl2/
│
├── maps/
├── entities/
├── custom_story_settings.cfg
│
└── README.md
```

### Folder Purpose

* `.github/` - Copilot workspace instructions
* `shared/` - Configuration files and changelogs
* `hpl2/` - HPL2 documentation and version-specific references

* `maps/` - Gameplay scripts and mod implementation files

The workspace is designed so that the engine documentation exists alongside your real mod project rather than inside a separate SDK.

---

## Engine Configuration

The most important configuration file is:

```text
shared/project_config.cfg
```

Example:

```text
TARGET_ENGINE=HPL2_15
```

Supported values:

```text
HPL2_12
HPL2_13
HPL2_14
HPL2_15
HPL2_AMFP
```

This value determines which documentation and APIs Copilot should consider valid.

---

## Documentation Structure

### Core Documentation

Located in:

```text
hpl2/core/
```

Contains verified baseline HPL2 functionality.

Examples:

* Player functions
* Entity functions
* Enemy functions
* Map functions
* Audio functions
* Visual effects
* Math helpers
* Debug utilities

### Update Documentation

Version-specific additions are separated into:

```text
hpl2/updates_13/
hpl2/updates_14/
hpl2/updates_15/
```

This separation improves retrieval quality and version awareness.

### Changelogs

Historical engine information is stored in:

```text
shared/changelogs/
```

These files contain:

* Patch summaries
* Historical context
* Compatibility notes
* Copilot guidance

---

## Documentation Philosophy

The workspace intentionally documents only verified functionality.

Sources include:

* Official HPL2 documentation
* Verified engine script references
* Official Frictional documentation

If functionality cannot be verified:

* It should not be documented
* Omission is preferred over speculation

The project intentionally avoids inventing:

* Helper functions
* Convenience wrappers
* SDK abstractions
* Custom engine APIs

Accuracy is prioritized over completeness.

---

## Using GitHub Copilot

After opening your mod project in VSCode:

1. Verify `TARGET_ENGINE` in `project_config.cfg`
2. Open or create scripts inside `maps/`
3. Use GitHub Copilot normally
4. Test and debug with the HPL2 tools
5. Update documentation when verified behavior is discovered

Copilot should automatically use the workspace documentation to provide more accurate suggestions.

---

## Project Goals

### Present

* Build high-quality HPL API documentation
* Improve AI-assisted scripting accuracy
* Preserve original Frictional scripting conventions
* Reduce hallucinated engine APIs
* Create reusable scripting references
* Provide reliable version compatibility guidance
* Remain usable even with GitHub Copilot Free Tier

### Future

* Support additional generations of the HPL engine
* Add HPL3 support
* Improve AI-assisted configuration editing
* Improve troubleshooting assistance
* Improve script generation quality
* Expand documentation coverage

---

## Installation

Installation instructions and release packages will be documented here in the future.
