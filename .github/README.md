# Workspace routing notes

Read this file before using engine-specific guidance.

- The authoritative engine selection is in copilot_shared/project_config.cfg.
- Use the guidance set that matches TARGET_ENGINE.
- If TARGET_ENGINE refers to an HPL2 target, use .github/hpl2-instructions.md and the HPL2 documentation set.
- If TARGET_ENGINE refers to HPL3, use .github/hpl3-instructions.md and the HPL3 engine resources.
- If TARGET_ENGINE is missing or invalid, ask the user before using version-specific APIs; if no clarification is available, fall back to HPL2 (1.2 patch) guidance.
