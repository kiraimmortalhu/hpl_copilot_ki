# HPL3 Search Heuristics

## Quick flow for future HPL3 tasks

1. Confirm the active engine:
   - Open `copilot_shared/project_config.cfg`
   - If `TARGET_ENGINE=HPL3`, use HPL3 resources only.

2. Prefer helper wrappers in the engine root:
   - ` <ENGINE_ROOT>/script/helpers/helper_map.hps `
   - ` <ENGINE_ROOT>/script/helpers/helper_player.hps `
   - ` <ENGINE_ROOT>/script/helpers/helper_audio.hps `
   - ` <ENGINE_ROOT>/script/helpers/helper_effects.hps `
   - ` <ENGINE_ROOT>/script/helpers/helper_sequences.hps `

3. Use broad categories first, then find exact wrappers:
   - world/fog/skybox/timer logic -> `helper_map.hps`
   - player camera/body/look logic -> `helper_player.hps`
   - audio/music -> `helper_audio.hps`
   - effect/tween/fade behavior -> `helper_effects.hps`
   - scripted sequences and callbacks -> `helper_sequences.hps`

4. Search efficiently, not exhaustively:
   - Start from the helper file that matches the problem domain.
   - Look for the wrapper name or the engine method it delegates to.
   - If needed, search once for the exact wrapper name.

## Useful wrapper patterns

- Player camera/body:
  - `Player_SetCharacterBodyDefaults()`
  - `Player_StartLookAt(asEntityName, afAcc, afSpeedMul, afMaxSpeed)`
  - `Player_StopLookAt(afDeacc)`
  - `Player_MoveHeadPos(avPos, afAcc, afSpeed, afSlowDownDist)`

- Map world state:
  - `Map_SetSkyBoxActive(bool)`
  - `Map_SetSkyBoxTexture(const tString&in)`
  - `Map_SetFogActive(bool)`
  - `Map_SetSecondaryFogActive(bool)`
  - `Map_AddTimer(const tString&in, float afTime, const tString&in asFunction)`
  - `Map_RemoveTimer(const tString&in)`

## Typical `cScrMap` callback structure

Use the following pattern in map scripts:

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

## What to avoid

- Do not start with raw terminal grep over the entire engine.
- Do not use `copilot_hpl2/` files when `TARGET_ENGINE=HPL3`.
- Do not hardcode external user or Steam paths.
- Do not assume HPL2 helper names and HPL3 helper names are the same.

## Notes for future Copilot usage

- If the user asks for camera/looking behavior, head to `helper_player.hps` first.
- If the user asks for fog/skybox/timers, head to `helper_map.hps` first.
- If the user asks for death/respawn scene state, `OnPlayerKilled()` is a reliable HPL3 callback to inspect.

## Best-case future process

- Confirm engine target
- Pick helper file by functional domain
- Read the relevant wrapper section
- Implement using the wrapper names
- Only then search for missing underlying engine calls
