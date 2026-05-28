# HPL Copilot

HPL Copilot is an AI-grounding workspace designed to improve AI-assisted scripting for Frictional Games' HPL engine titles.

The repository provides:

* Public API stubs
* AngelScript references
* Engine-specific scripting rules
* Original game scripting examples
* Prompting and grounding instructions for AI coding assistants

The goal is to help tools such as GitHub Copilot generate:

* HPL-compatible AngelScript
* Valid engine callback patterns
* Readable gameplay scripting
* Scripts that resemble original Frictional Games code conventions

---

## Repository Purpose

This repository is NOT intended to function as a traditional software project.

Instead, it acts as:

* An AI grounding environment
* A semantic scripting knowledge base
* A collection of engine-specific examples and references

The repository prioritizes practical HPL engine compatibility over generic AngelScript solutions.

The AI grounding infrastructure is intended to live alongside real HPL mod project files.

The files in this repository primarily exist to provide context to AI coding assistants.

---

## AI Guidance Philosophy

The repository is designed to encourage AI assistants to:

* Prefer HPL public API functions whenever possible
* Follow original Frictional Games scripting conventions
* Use callback-driven gameplay scripting
* Use existing engine systems instead of custom abstractions
* Generate concise and readable AngelScript code
* Avoid unrelated game engine APIs and patterns

---

## Core Principles

- Prefer APIs defined in local hpl2/api/ stubs over inferred implementations
- Prefer existing engine systems over custom systems
- Prefer readable gameplay scripting over abstraction
- Prefer callbacks over update loops
- Prefer practical solutions over generalized frameworks

---

## Supported Engines

### HPL2

Used by:

* Amnesia: The Dark Descent
* Amnesia: Justine
* Amnesia: A Machine for Pigs

Focus:

* Public script function APIs
* AngelScript 2.2x-compatible syntax
* Original Amnesia scripting patterns

---

## Repository Structure

```text
my_mod/
├── .github/
│   └── copilot-instructions.md
├── shared/
├── hpl2/
│   ├── api/
│   ├── docs/
│   ├── examples/
│   └── templates/
├── maps/
├── custom_story_settings.cfg
└── README.md
```

* `README.md`
  Primary repository overview, AI guidance philosophy, and workspace structure.

* `.github/copilot-instructions.md`
  Repository-level Copilot behavior instructions and scripting constraints.

* `shared/`
  Shared AngelScript conventions, scripting patterns, and reusable AI grounding references.

* `hpl2/`
  HPL2-specific AI grounding infrastructure, including API stubs, examples, templates, and engine documentation.

* `maps/`
  Primary gameplay scripting location containing real HPL map scripts and implementation logic. Gameplay scripting files are primarily .hps files. Other map-related file types such as .map, .nodes, and similar files are generally editor or design data and are not primary scripting references.

* `custom_story_settings.cfg`
  Mod configuration file indicating that `my_mod/` is the root directory of the active HPL2 custom story project.

Other folders and files may exist as part of the actual mod structure, but are generally not primary scripting or AI grounding references unless directly relevant to the current task.


---

## Preferred Scripting Patterns

### Preferred

* Callback-driven logic
* Timers and event sequencing
* Entity-based interactions
* Readable gameplay scripting
* Small focused functions

### Avoid

* Unity APIs
* Unreal Engine APIs
* Godot APIs
* Gameplay architectures designed for compiled engines rather than scripting environments
* Overengineered systems
* Complex abstractions unnecessary for HPL scripting or a script language like it

---

## Examples and Grounding

The `examples/` directories contain:

* Original game scripting examples
* Puzzle scripting patterns
* Enemy behaviors
* Sanity events
* Level scripting logic
* Gameplay interaction examples

These examples are intended to serve as behavioral references for AI-assisted scripting.

---

## AngelScript Compatibility

The repository targets AngelScript syntax and conventions compatible with HPL engine integrations.

The primary focus is practical compatibility with existing HPL scripting patterns rather than exact standalone AngelScript SDK behavior.

---

## Short-Term Goals

### HPL3 compatibility

Used by:

* SOMA
* Amnesia: Rebirth
* Amnesia: The Bunker

Focus:

* Updated engine APIs
* Newer gameplay systems
* HPL3-specific scripting conventions

---

## Long-Term Goals

* Build high-quality HPL API stub libraries
* Improve AI-assisted scripting quality
* Preserve original HPL scripting conventions
* Reduce hallucinated non-HPL APIs
* Create reusable scripting references and templates
* Support multiple generations of the HPL engine

---

## Important Notes

This repository may contain:

* Non-compilable stub files
* AI-oriented helper files
* Documentation intended primarily for semantic retrieval
* Example scripts adapted for AI grounding purposes

The repository is optimized for AI context and scripting assistance rather than direct execution.
