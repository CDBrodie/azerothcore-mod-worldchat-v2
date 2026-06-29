#ifndef AZEROTHCORE_MODULES_WORLDCHAT_H
#define AZEROTHCORE_MODULES_WORLDCHAT_H

#include <array>
#include <deque>
#include <string>
#include <string_view>
#include <unordered_map>
#include <ctime>

#include "Channel.h"
#include "Chat.h"
#include "CommandScript.h"
#include "PlayerScript.h"
#include "SharedDefines.h"
#include "WorldScript.h"

namespace WC
{
    namespace ChatColor
    {
        constexpr std::string_view WORLD = "|cff55ccff";
        constexpr std::string_view ANNOUNCE = "|cffffcc00";
        constexpr std::string_view TEXT = "|cffcccccc";
        constexpr std::string_view GREEN = "|cff00cc00";
        constexpr std::string_view RED = "|cffff0000";
        constexpr std::string_view YELLOW = "|cffffff00";
        constexpr std::string_view GREY = "|cff999999";
    }

    constexpr std::array<std::string_view, MAX_CLASSES> ClassColor =
    {
        "",
        "|cffC79C6E", "|cffF58CBA", "|cffABD473", "|cffFFF569",
        "|cffFFFFFF", "|cffC41F3B", "|cff0070DE", "|cff40C7EB",
        "|cff8787ED", "", "|cffFF7D0A",
    };

    constexpr std::string_view GMIcon = "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:13:26:0:-2|t";

    struct PlayerState
    {
        bool receiveEnabled = true;
        bool worldMode = false;
        time_t muteUntil = 0;
        std::deque<time_t> recentMessages;
    };

    struct Config
    {
        bool enabled = true;
        bool crossFaction = true;
        bool announce = false;
        bool loginState = true;
        uint8 minimumLevel = 10;
        uint32 floodWindowSeconds = 10;
        uint32 floodWarnCount = 3;
        uint32 floodMuteCount = 5;
        uint32 floodMuteSeconds = 60;
        std::string channelName = "world";
        std::string tag = "[World]";
        std::unordered_map<uint32, PlayerState> playerStates;
    };

    class WorldChat_Config : public WorldScript
    {
    public:
        WorldChat_Config() : WorldScript("WorldChat_Config", { WORLDHOOK_ON_BEFORE_CONFIG_LOAD }) {}
        void OnBeforeConfigLoad(bool reload) override;
    };

    class WorldChat_Announce : public PlayerScript
    {
    public:
        WorldChat_Announce()
            : PlayerScript("WorldChat_Announce",
            {
                PLAYERHOOK_ON_LOGIN,
                PLAYERHOOK_CAN_PLAYER_USE_CHAT,
                PLAYERHOOK_CAN_PLAYER_USE_CHANNEL_CHAT
            }) {}

        void OnPlayerLogin(Player* player) override;
        bool OnPlayerCanUseChat(Player* player, uint32 type, uint32 lang, std::string& msg) override;
        bool OnPlayerCanUseChat(Player* player, uint32 type, uint32 lang, std::string& msg, Channel* channel) override;
    };

    class WorldChat : public CommandScript
    {
    public:
        WorldChat() : CommandScript("WorldChat") {}

        static bool HandleWorldChatCommand(ChatHandler* handler, const char* msg);
        static bool HandleWorldChatOnCommand(ChatHandler* handler);
        static bool HandleWorldChatOffCommand(ChatHandler* handler);
        static bool HandleWorldChatStatusCommand(ChatHandler* handler);
        static bool HandleWorldChatAnnounceCommand(ChatHandler* handler, const char* msg);
        static bool HandleWorldChatHordeCommand(ChatHandler* handler, const char* msg);
        static bool HandleWorldChatAllianceCommand(ChatHandler* handler, const char* msg);

        Acore::ChatCommands::ChatCommandTable GetCommands() const override;
    };

    void SendWorldMessage(Player const& sender, std::string const& msg, int team);
    void SendWorldAnnouncement(std::string const& msg);
}

#endif