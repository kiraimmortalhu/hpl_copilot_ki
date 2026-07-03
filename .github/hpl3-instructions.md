# HPL3 Copilot Instructions

## 1. Mod Root Abstraction

This project is installed as part of a mod inside the game directory.

The mod folder name is NOT fixed and must never be assumed.

Copilot must always refer to the current workspace root as:

<MOD_ROOT>

All paths in this repository are relative to `<MOD_ROOT>`.

---

## 2. Scope

These instructions apply ONLY when:

copilot_shared/project_config.cfg contains:
`TARGET_ENGINE=HPL3`

If this condition is not met, following instructions MUST be ignored.

---

## 3. Engine Root Resolution (HPL3 Only)

When `TARGET_ENGINE=HPL3` is true, the engine is located outside the mod workspace.

Copilot must resolve the engine root as:

<ENGINE_ROOT> = <MOD_ROOT>/../../..


This applies regardless of the host game (e.g. SOMA, Amnesia Rebirth or Amnesia The Bunker).

No game-specific names may be assumed or hardcoded.

---

## 4. External Engine Resources

When in HPL3 mode, engine resources are located at:

| Resource Type | Location |
|--------------|----------|
| Engine scripts | `<ENGINE_ROOT>/scripts/` |
| Example maps with usage of those scripts | `<ENGINE_ROOT>/maps/` |

---

## 5. Mod Resources (HPL3)

All relevant mod-specific content remains inside:

- `<MOD_ROOT>/`
  - maps
  - scripts (if present)
  - entry.hpc (mod configuration file, not a script)

Other mod folders should also not contain hps files.

---

## 6. Engine Isolation Rule

When `TARGET_ENGINE=HPL3`:

- NEVER use `copilot_hpl2/`
- NEVER assume HPL2 structure applies
- ONLY use HPL3 rules and external engine resolution
- NEVER duplicate engine files into `<MOD_ROOT>`

---

## 7. Path Handling Rule

All references must be resolved using:

- `<MOD_ROOT>` for mod content
- `<ENGINE_ROOT>` for engine content

No absolute paths
No game-name assumptions
No fixed folder names

---

## 8. Purpose

These instructions ensure Copilot correctly understands that:

- HPL3 mods are overlays on an external engine
- The engine is shared across multiple Frictional Games titles
- The mod folder is install-location dependent
- All engine access must be resolved via relative traversal