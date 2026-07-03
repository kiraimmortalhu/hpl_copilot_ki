# HPL3 Quick Start

## Purpose

This file is the minimal path for future HPL3 tasks. Use it when you need to solve a task quickly and avoid broad search/regex exploration.

> If memory is cleared, treat this file as the primary HPL3 instruction source before doing any implementation work.

## First checks

1. Open `copilot_shared/project_config.cfg`.
   - If `TARGET_ENGINE=HPL3`, use HPL3 helpers only.
   - Do not use `copilot_hpl2/` code for implementation guidance.

2. Treat the engine root as abstract:
   - Use `<ENGINE_ROOT>/script/` rather than hardcoded OS/user/Steam paths.

3. Identify the most likely helper files by problem domain:
   - World/fog/skybox/timers: `helpers/helper_map.hps`
   - Player camera/gaze/body defaults: `helpers/helper_player.hps`
   - Audio/voice/music: `helpers/helper_audio.hps`
   - Visual/effects/tweens: `helpers/helper_effects.hps`
   - Sequence/timer callbacks: `helpers/helper_sequences.hps`

## Most useful HPL3 patterns

- Map script callback structure:

```angelscript
class cScrMap : iScrMap
{
    void Setup() {}
    void OnStart() {}
    void OnEnter() {}
    void OnLeave() {}
    void OnPlayerKilled(int alRecentDeaths, const tString&in asSource) {}
    void OnAction(int alAction, bool abPressed) {}
}
```

- Common wrappers to use first:
  - `Map_SetSkyBoxActive(bool)`
  - `Map_SetSkyBoxTexture(const tString&in)`
  - `Map_SetSecondaryFogActive(bool)`
  - `Map_AddTimer(const tString&in asName, float afTime, const tString&in asFunction)`
  - `Player_SetCharacterBodyDefaults()`
  - `Player_StartLookAt(const tString&in asEntityName, float afAcc, float afSpeedMul, float afMaxSpeed)`
  - `Player_StopLookAt(float afDeacc)`
  - `Player_MoveHeadPos(const cVector3f&in avPos, float afAcc, float afSpeed, float afSlowDownDist)`

- Timer callback signature:

```angelscript
void MyTimerCallback(const tString&in asTimer)
{
    // stop look-at or restore state
}
```

## Fast search strategy

- Open `helper_map.hps` first for any environment or timer task.
- Open `helper_player.hps` first for any player/camera task.
- If the wrapper name is not present, search inside the same helper file for the engine call it delegates to.
- Avoid searching the entire engine tree unless the helper file does not contain the function.

## What saved time here

- Most tasks were solved from two files: `helper_map.hps` and `helper_player.hps`.
- The direct map lifecycle callback pattern is stable across HPL3 map scripts.
- This guide is intentionally narrow so that the next implementation does not start with broad regex hunts.
