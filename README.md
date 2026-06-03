# Discord RPC, Linux (Wine/Proton) fix

Discord Rich Presence for Geometry Dash, fixed to work on **Linux under Wine/Proton**.

*now your friends can see you playing stereo madness (on arch btw)*

This is a fork of [TechStudent10's Discord Rich Presence](https://github.com/TechStudent10/discord-rich-presence).
On the original, Linux showed nothing custom because Wine can't reach Discord's
socket the way the mod expected; this fork routes around it with a tiny relay.

## Requirements

- Geometry Dash + [Geode](https://geode-sdk.org/)
- The Discord desktop client running
- `python3` available (it already is on basically every desktop and inside the
  Steam Proton runtime)

Works on native Wine and on Steam + Proton, no extra launch options needed.

## Installation

Not on the Geode index yet, so install it manually: grab the `.geode` from the
[Releases](https://github.com/RealEkzamen/linux-discord-rpc/releases) page and
drop it into your mods folder:

```
~/.local/share/Steam/steamapps/common/Geometry Dash/geode/mods/
```

Then launch the game with Discord open -- your profile updates automatically.

## Building from source

```sh
# one-time setup
geode sdk install-linux
geode sdk install-binaries

# build (auto-installs the .geode into your mods folder)
geode build -p windows --config RelWithDebInfo --ninja
```

## Credits

- [TechStudent10](https://github.com/TechStudent10) -- original mod
- [EclipseMenu/discord-presence](https://github.com/EclipseMenu/discord-presence) -- Discord IPC library
- Linux/Wine relay fix -- this fork
