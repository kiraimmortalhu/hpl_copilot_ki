# HPL3 Quick Reference

## Purpose

This folder contains internal guidance for Copilot when working in an HPL3 project.
It is not a full function reference. Instead, it records the main file structure, class/callback patterns, and search heuristics needed to solve tasks quickly.

## When to use this guide

1. Check `copilot_shared/project_config.cfg` first.
2. If `TARGET_ENGINE=HPL3`, do not use `copilot_hpl2/` for implementation guidance.
3. Use this guide to find relevant HPL3 helper files and core patterns in the external engine scripts.

## Key concepts

- HPL3 uses wrapper helpers in the engine scripts rather than local repo docs.
- The main engine script root is ` <ENGINE_ROOT>/script/ `.
- Helper files are typically under `script/helpers/`.
- Map scripts in the mod use `class cScrMap : iScrMap` and implement callbacks such as:
  - `Setup()`
  - `OnStart()`
  - `OnEnter()`
  - `OnLeave()`
  - `OnPlayerKilled(int alRecentDeaths, const tString&in asSource)`
  - `OnAction(int alAction, bool abPressed)`

## Main HPL3 helper categories we rely on

- `helpers/helper_map.hps`
  - world-level state, skybox/fog control, timers, environment particles
  - key wrappers: `Map_SetSkyBoxActive`, `Map_SetSkyBoxTexture`, `Map_SetSecondaryFogActive`, `Map_AddTimer`

- `helpers/helper_player.hps`
  - player properties, camera control, movement and body helpers
  - key wrappers: `Player_SetCharacterBodyDefaults`, `Player_StartLookAt`, `Player_StopLookAt`, `Player_MoveHeadPos`

- `helpers/helper_audio.hps`
  - map audio helpers and voice playback wrappers.

- `helpers/helper_effects.hps`
  - camera shake, visual FX, effect wrappers.

- `helpers/helper_sequences.hps`
  - sequence and timer callback helpers for scripts.

## Practical pattern notes

- For map lifecycle logic, prefer `OnStart()` when initialization should only run once.
- Use `OnEnter()` for state enforcement on every entry.
- Timers use `Map_AddTimer(name, seconds, functionName)`.
- Timer callback signature is usually `void CallbackName(const tString&in asTimer)`.
- Use helper wrappers instead of raw engine API when available.

## Abstraction guidance

- Keep instructions engine-agnostic by using abstract names like `<ENGINE_ROOT>/script/`.
- Avoid hardcoded install paths such as `common/SOMA`.
- If a helper exists, use the wrapper name rather than the underlying engine function.
- If the wrapper does not exist, search for the underlying call pattern in engine `player/` or `map/` scripts.

## What was missing compared to `copilot_hpl2`

- No local `copilot_hpl3/` reference folder in the project.
- No repo-level HPL3 helper summary of `Map_*` and `Player_*` wrappers.
- No quick bridge from the HPL3 engine file structure to the common gameplay patterns.
- No documented `class cScrMap` callback set for the HPL3 project.

## Outcome

This file is the starting point for future HPL3 tasks. It is intentionally narrow: enough to direct the next search and avoid repeated exploratory commands.

## Quick Start

For the fastest HPL3 workflow, see `copilot_hpl3/quick_start.md`.
