# Agent routing instructions

This repository is an HPL mod workspace. Before using engine-specific scripting guidance, read the following files in order:

1. .github/copilot-instructions.md
2. copilot_shared/project_config.cfg
3. The engine-specific instructions that match TARGET_ENGINE:
   - .github/hpl2-instructions.md for HPL2 targets
   - .github/hpl3-instructions.md for HPL3 targets
4. AGENTS.md (this file)

The active engine is determined by TARGET_ENGINE in copilot_shared/project_config.cfg and must be treated as authoritative.

## Engine routing rules

- Use the guidance set that matches TARGET_ENGINE.
- Do not use HPL2 or HPL3 references as implementation guidance unless they match the active target engine.
- If TARGET_ENGINE is missing, invalid, or ambiguous, ask the user before using version-specific APIs.
- If clarification is not available, fall back to HPL2 (1.2 patch) guidance rather than assuming HPL3.
- Prefer mod-local content such as maps/, entities/, and entry.hpc for implementation context when relevant to the active engine.
