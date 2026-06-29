# Enhanced World Chat

A modern, feature-rich World Chat module for AzerothCore.

Enhanced World Chat is a redesigned version of the original `mod-world-chat` by Ouizzy/Wizzymore. It keeps the simplicity of the original module while adding persistent World Chat mode, saved player preferences, flood protection, Blizzard-style hyperlinks, and configurable moderation tools.

## Features

- Cross-faction global chat
- `.world <message>` command
- Persistent World Chat Mode using `.world`
- `.world on`, `.world off`, and `.world status`
- Saved player settings between logins
- Blizzard-style hyperlink support for items, spells, achievements, quests, professions, and more
- Clean Blizzard-style formatting
- GM announcement command
- Horde-only and Alliance-only staff broadcasts
- Minimum level requirement
- Built-in flood protection
- Optional `/join World` channel support
- Fully configurable through `WorldChat.conf`

## Commands

### Player Commands

```text
.world <message>
```

Send a World Chat message.

```text
.world
```

Toggle persistent World Chat Mode.

```text
.world on
```

Show World Chat.

```text
.world off
```

Hide World Chat.

```text
.world status
```

Display current World Chat settings.

### Staff Commands

```text
.worldgm <message>
```

Broadcast a server-wide announcement.

```text
.worldh <message>
```

Send a Horde-only World Chat message.

```text
.worlda <message>
```

Send an Alliance-only World Chat message.

## Persistent World Chat Mode

Typing:

```text
.world
```

toggles World Chat Mode.

When enabled, normal `/say` messages are redirected to World Chat until the player toggles it off again.

## Hyperlink Support

Enhanced World Chat preserves normal WoW chat hyperlinks.

Players can shift-click items, spells, achievements, quests, professions, and other supported links directly into World Chat.

Example:

```text
.world WTS [Betrayer of Humanity]
```

## Flood Protection

Enhanced World Chat includes configurable anti-spam protection.

```ini
WorldChat.Flood.WindowSeconds = 10
WorldChat.Flood.WarnCount = 3
WorldChat.Flood.MuteCount = 5
WorldChat.Flood.MuteSeconds = 60
```

## Configuration

```ini
WorldChat.Enable = 1
WorldChat.CrossFaction = 1
WorldChat.Announce = 0
WorldChat.ChannelName = "world"
WorldChat.OnLogin.State = 1
WorldChat.Tag = "[World]"

WorldChat.MinimumLevel = 10

WorldChat.Flood.WindowSeconds = 10
WorldChat.Flood.WarnCount = 3
WorldChat.Flood.MuteCount = 5
WorldChat.Flood.MuteSeconds = 60
```

## Installation

1. Copy the module into the AzerothCore `modules` directory.
2. Re-run CMake.
3. Compile the server.
4. Import the character database SQL from:

```text
sql/characters/base/
```

5. Copy `WorldChat.conf.dist` into your server configuration directory.
6. Restart the server.

## Credits

Enhanced World Chat is based on the original `mod-world-chat` project created by Ouizzy/Wizzymore.

This version expands the original concept with persistent player preferences, persistent World Chat mode, improved formatting, hyperlink support, flood protection, and configurable moderation tools.

Special thanks to the AzerothCore community for the foundation that made this module possible.

## Planned Features

- Ignore list integration
- Optional chat history
- Optional Discord relay support
- Optional chat logging database
- Localized system messages
- Broadcast API for other modules
