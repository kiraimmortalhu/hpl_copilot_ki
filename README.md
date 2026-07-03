# HPL Copilot

HPL Copilot is an AI-grounding workspace designed to improve AI-assisted scripting for Frictional Games' HPL engine titles. It was created mainly for the possibility of the following:
* Provide more accurate answers, that reflect the code quality of the original game. A certain improvement upon saved ChatGPT contexts of asking prompts in an online GUI from a barely known scripting language such as HPL
* Be as beginner friendly as possible, installing only a lightweight IDE shell to use Copilot with. In the future with updates, it might get some additional automations that do not consume Copilot resources - courtesy of already having this local setup.
* Having an offline workspace with all necessary information preexistent inside. Internet connection is still required to get AI assisted answers!
* FREE PLAN COMPATIBILITY

Rather than relying solely on general AI knowledge, the workspace provides structured documentation, API references, scripting examples, and compatibility guidance that AI assistants such as GitHub Copilot can use as retrieval sources.
The goal is to improve the quality, accuracy, and engine compatibility of AI-assisted scripting workflows, specifically inside HPL.

IMPORTANT NOTE: HPL Copilot MIGHT work with other Agent AIs as well - such as Codex that one our testers have tried - integrated similarly into the VS code environment. The AI descriptor and example files are universally structured for such models to work with. Feel free to try, and let me know how it went! 

---

## Features

The repository provides:

* Verified HPL API documentation
* AngelScript references (using only the basics from 2.19.2 SDK)
* Engine-specific scripting practices
* Original game scripting examples
* Version compatibility guidance
* AI grounding resources

This helps AI assistants:

* Generate authentic HPL scripts
* Avoid hallucinated solutions from the internet/other engines
* Respect engine version differences
* Use verified function signatures
* Follow established scripting conventions

NOTE: AI can - still and always will - make mistakes. 
It is the author's intention to improve the tool from user feedback.

---

## Supported Engines

### HPL2

Used by:

* Amnesia: The Dark Descent
* Amnesia: Justine
* Amnesia: A Machine for Pigs

#### HPL3 (currently in beta)

Used by:

* SOMA
* Amnesia: Rebirth
* Amnesia: The Bunker

---

## Requirements

You will need:

* Visual Studio Code
* GitHub Copilot for VS Code
* The game, editor suite installed, your mod set up
* About 1 GB of additional space for the tools

Downloads:

[VSCode](https://https://code.visualstudio.com/Download)

[GitHub Copilot](https://marketplace.visualstudio.com/items?itemName=GitHub.copilot-chat)

Before using this workspace, you should already be familiar with:

* Basic HPL mod creation, for the specific game you're modding
* The HPL Editor Suite in particular
* General mod folder structure
* Basic HPL scripting practices
* Testing - and DEBUGGING - in game

It is advised but not mandatory to have:
* Experience with AI tool prompts and agents - helps making better use of your monthly quota
* Git basics knowledge
* Ability to use Git bash / Github Desktop for your own project management
* Amnesia Remodded Editor tools for HPL2 (for advanced custom assets management)
[DOWNLOAD](https://www.moddb.com/mods/amnesia-remodded/downloads)

Useful tutorials:

* Visual Studio Copilot setup: 
[Youtube](https://https://code.visualstudio.com/Download)
* HPL2 Tutorials:
[by Mudbill](https://www.youtube.com/watch?v=X_Aet9ndh_Y)
* HPL3 Tutorials:
[SOMA, by Draugemalf](https://www.youtube.com/watch?v=lR-4OlG4uuc&list=PLwJXvfVZGcJljQs1G-rAnipVf5SeuXawX)
[Rebirth, by Draugemalf](https://www.youtube.com/watch?v=-jFnEk7peTE&list=PL4KkjlmOwLwwMVqedCNpi6caUxhgyf8Qr)

---

## Repository Structure

The intended workspace root is your actual mod project, represented by "my_mod".

Example:

```text
"my_mod"/
├── .github/
│
├── copilot_shared/
├── copilot_hpl2/
│
├── maps/
├── entities/
├── "project configuration"
│
└── README.md
```

### Folder Purposes

* `"my_mod"` - Your mod project's root folder, usually the name of your mod.

* `.github/` - Copilot workspace instructions
* `.vscode/` - Helps VScode recognize .hps files / wip autocomplete setup
* `copilot_shared/` - Configuration files and changelogs
* `copilot_hpl2/` - HPL2 documentation and version-specific references

* `maps/` - Gameplay scripts and mod implementation files
* `"project configuration"` - The filename and format differs between engines. Contains the info necessary for the mod to show up in game.
    * `"custom_story_settings.cfg"`- HPL2 configuration file
    * `"entry.hpc"`- HPL3 configuration file

The workspace is designed so that the engine documentation exists alongside your real mod project rather than inside a separate SDK.

---

## Installation

### 1. Install Visual Studio Code

* Download and install Visual Studio Code.

[Youtube](https://www.youtube.com/watch?v=wU7IQLIOwoo)

* If you have not already done so, create a GitHub account and sign up for GitHub Copilot.

[Github](https://github.com/settings/copilot/features)

---

### 2. Set Up GitHub Copilot

Install the GitHub Copilot extension inside VSCode and complete the sign-in process.

Before continuing, verify that Copilot is functioning correctly by opening a text file and confirming that Copilot suggestions appear.

Tutorial:

* GitHub Copilot Setup Guide: https://youtu.be/wxaxlIlN7BA

---

### 3. Confirm the HPL Editor Suite is working

Ensure that the editors are installed and functioning correctly.

This workspace is intended for users who already know how to:

* Create HPL2/3 mods
* Use the Level Editor
* Create and edit scripts (for which VS code can now be used)
* Test and debug projects

---

### 4. Download the HPL Copilot Workspace

On the project's GitHub page:
https://github.com/kiraimmortalhu/hpl_copilot_ki

(Near the top of the repository page)

1. Click the green **Code** button.
2. Select **Download ZIP**.
3. Save the ZIP file somewhere convenient.

You should end up with a file such as:

```text
hpl_copilot_ki-master.zip
```

---

### 5. Locate Your Mod Folder

Find the root folder of the mod or custom story you want to work on.

Common locations include:

```text
Amnesia The Dark Descent\custom_stories\MyCustomStory\
```

or

```text
SOMA\mods\MyMod\
```

The folder should already contain your project files such as:

```text
maps/
entities/
configuration (custom_story_settings.cfg or entry.hpc)
```

and/or similar project-specific content.

---

### 6. Extract the Workspace Files

Extract:

```text
hpl_copilot_ki-master.zip
```

After extraction you will usually see a folder named:

```text
hpl_copilot_ki-master
```

Open that folder.

Inside you should see folders similar to:

```text
.github/
.vscode/
copilot_shared/
copilot_hpl2/
README.md
```

Copy the **contents** of `hpl_copilot_ki-master` directly into your project's root folder.

**Important:**

Do NOT copy the entire `hpl_copilot_ki-master` folder into your mod.

This is a very common mistake.

❌ Incorrect:

```text
MyCustomStory/
└── hpl_copilot_ki-master/
    ├── .github/
    ├── .vscode/
    ├── copilot_shared/
    └── copilot_hpl2/
```

✔ Correct:

```text
MyCustomStory/
├── .github/
├── .vscode/
├── copilot_shared/
├── copilot_hpl2/
├── maps/
├── entities/
└── and so on...
```

The Copilot folders should sit alongside your existing project files.

---

### 7. Open the Project in VSCode

Launch Visual Studio Code.

Select:

```text
File → Open Folder...
```

Choose your mod's root folder.

Example:

```text
.../Amnesia The Dark Descent/custom_stories/MyCustomStory/
or
.../SOMA/mods/MyCustomStory/
.../Amnesia Rebirth/mods/MyCustomStory/
.../Amnesia The Bunker/mods/MyCustomStory/
```

Do NOT open only the `maps` folder.

Do NOT open only the Copilot folders.

Open the project's ROOT folder that contains everything your mod uses.

---

### 8. Start Working

VSCode can now be used much like a traditional text editor such as Notepad++.

Common shortcuts include:

* CTRL + S — Save file
* CTRL + F — Find text
* CTRL + H — Find and replace
* CTRL + Z — Undo
* CTRL + SHIFT + F — Search entire project

Your gameplay scripts - to work correctly with the game even - will typically remain inside:

```text
maps/
```

and other normal HPL project folders.

### 9. Do the Engine Configuration from the next section

### 9.5 [Optional] Add the copilot files to your project's .gitignore

If you are familiar with Git basics and you use github or any similar platform to track your project, 
you should add the following lines to the root folder gitignore:

```text
*/.github
*/.vscode
*/copilot_hpl2
*/copilot_shared
*README.md
```

### Important

You should normally edit only your own project files.

Avoid modifying, unless - and as previously - prompted:

```text
.github/
copilot_shared/
copilot_hpl2/
```

Unless you intentionally want to customize or extend the Copilot workspace.
These folders provide the documentation and configuration that help GitHub Copilot understand HPL2 scripting correctly.
Modifying them unnecessarily may reduce suggestion quality or cause version compatibility issues.

### In addition, for fellow developers

I do not accept any direct contribution / pull requests initiated by people not on my Contributors list.
You are however free to fork this repository and edit/redistribute it in any way you please.

---

## Engine Configuration

The most important configuration file is:

```text
copilot_shared/project_config.cfg
```

Before using Copilot you should set "TARGET_ENGINE"
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

HPL3
```

This value determines which documentation and APIs Copilot should consider valid.
12 is treated as default, while AMFP should be considered work in progress.
HPL3 works in a slightly different way, so it is VERY IMPORTANT to set it as so.

---

## Using GitHub Copilot

After opening your mod project in VSCode:

1. Verify `TARGET_ENGINE` in `project_config.cfg`
2. Open or create scripts inside `maps/`
3. Use GitHub Copilot normally
4. Test and debug with the HPL tools

Copilot should automatically use the workspace documentation to provide more accurate suggestions.


---

## HPL2 Documentation Structure

### Core Documentation

Located in:

```text
copilot_hpl2/core/
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
copilot_hpl2/updates_13/
copilot_hpl2/updates_14/
copilot_hpl2/updates_15/
```

This separation improves retrieval quality and version awareness.

### Changelogs

Historical engine information is stored in:

```text
copilot_shared/changelogs/
```

These files contain:

* Patch summaries
* Historical context
* Compatibility notes
* Copilot guidance

## HPL3 Documentation

HPL3 comes with "its own documentation".
Copilot uses the specific game' root folder "maps" and "scripts" folders
to accurately suggest SOMA/Rebirth/Bunker specific code conventions.

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

* Improve support for AMFP and HPL3
* Improve AI-assisted configuration editing
* Improve troubleshooting assistance
* Improve script generation quality
* Expand documentation coverage
