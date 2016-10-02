#include "global.h"
#include "fieldmap.h"
#include "script.h"
#include "songs.h"
#include "sound.h"
#include "rng.h"
#include "main.h"
#include "palette.h"

#ifdef SAPPHIRE
#define LEGENDARY_MUSIC BGM_OOAME  // Heavy Rain
#else
#define LEGENDARY_MUSIC BGM_HIDERI // Drought
#endif

struct UnkWarpStruct
{
    s8 mapGroup;
    s8 mapNum;
    s16 x, y;
};

struct UnkTVStruct
{
    u32 tv_field_0;
    u32 tv_field_4;
};

struct UnkPlayerStruct
{
    u8 player_field_0;
    u8 player_field_1;
};

struct UnkInputStruct
{
    u8 input_field_0;
    u8 input_field_1;
    u8 input_field_2;
    u8 input_field_3;
};

extern struct WarpData gUnknown_020297F0;
extern struct WarpData gUnknown_020297F8;
extern struct WarpData gUnknown_02029800;
extern struct WarpData gUnknown_02029808;
extern struct UnkPlayerStruct gUnknown_02029810;
extern u16 gUnknown_02029814;
extern u8 gUnknown_02029816;

extern void (*gUnknown_03000584)(void);

extern void (*gUnknown_0300485C)(void);

extern struct UnkTVStruct gUnknown_03004870;

extern u8 gUnknown_0819FC74[];
extern u8 gUnknown_0819FC9F[];

extern struct MapData * const gMapAttributes[];
extern struct MapHeader * const * const gMapGroups[];
extern const struct WarpData gDummyWarpData;
extern s32 gUnknown_0839ACE8;

extern struct UnkWarpStruct *sub_80FA8CC(u8);
extern u16 VarGet(u16);
extern u8 FlagGet(u16);
extern u8 sav1_get_weather_probably(void);
extern void PlayerGetDestCoords(u16 *, u16 *);
extern u8 sub_810D32C(void);
extern u16 wild_pokemon_rand_for_map(u8 *);
extern void sub_80C76A0(void);
extern void sub_8080B60(void);
extern void sub_810CC80(void);
extern void sub_8080AC4(void);
extern void sub_8080A3C(void);
extern void atk17_seteffectuser(void);
extern void sub_80809B0(void);
extern void sub_8080990(void);
extern u8 sub_80BBB24(void);

void sub_8053050(void);
void warp_in(void);
void sub_8053570(void);
u8 sav1_map_get_light_level(void);
u8 get_map_light_level_by_bank_and_number(s8, s8);
bool8 is_light_level_1_2_3_5_or_6(u8);
void sub_805363C(s8, s8, s8, s8, s8);
void sub_807D874(u8);
void sub_8082BD0(u16, u16);
void player_avatar_init_params_reset(void);
u8 TestPlayerAvatarFlags(u8);
u8 player_get_direction_lower_nybble(void);
u8 sub_8053B00(struct UnkPlayerStruct *playerStruct, u16, u8);
u8 sub_8053B60(struct UnkPlayerStruct *playerStruct, u8, u16, u8);
u8 MetatileBehavior_IsSurfableWaterOrUnderwater(u8);
bool8 sub_8056F24(u8);
bool8 sub_8056F08(u8);
bool8 sub_8056EAC(u8);
bool8 MetatileBehavior_IsSouthArrowWarp(u8);
bool8 MetatileBehavior_IsNorthArrowWarp(u8);
bool8 MetatileBehavior_IsWestArrowWarp(u8);
bool8 MetatileBehavior_IsEastArrowWarp(u8);
bool8 MetatileBehavior_IsLadder(u8);
u16 cur_mapdata_block_role_at_screen_center_acc_to_sav1(void);
bool32 sub_8053C44(void);
void sub_8053C98(void);
void sav1_reset_battle_music_maybe(void);
void sub_8053F0C(void);
u8 is_light_level_8_or_9(u8);
void sub_8054164(void);
u16 sub_8085514();
u16 wild_pokemon_rand_for_map(u8 *);
void sub_8055354(void);
void c2_overworld(void);
void CB2_LoadMap2(void);
void c2_80567AC(void);
void sub_8055390(void);
void c2_exit_to_overworld_2_link(void);
void c2_exit_to_overworld_2_local(void);
void FieldClearVBlankHBlankCallbacks(void);
void SetFieldVBlankCallback(void);
void VBlankCB_Field(void);

void sub_8052F5C(void)
{
    ScriptContext2_RunNewScript(gUnknown_0819FC74);
    gSaveBlock1.money /= 2;
    sp000_heal_pokemon();
    sub_8053050();
    sub_8053570();
    warp_in();
}

void flag_var_implications_of_teleport_(void)
{
    player_avatar_init_params_reset();
    FlagReset(2091);
    FlagReset(2093);
    FlagReset(2092);
    FlagReset(2089);
    FlagReset(2088);
}

void new_game(void)
{
    player_avatar_init_params_reset();
    FlagReset(2091);
    FlagReset(2093);
    FlagReset(2092);
    FlagReset(2089);
    FlagReset(2088);
    ScriptContext2_RunNewScript(gUnknown_0819FC9F);
}

void sub_8053014(void)
{
    player_avatar_init_params_reset();
    FlagReset(2091);
    FlagReset(2093);
    FlagReset(2092);
    FlagReset(2089);
    FlagReset(2088);
}

void sub_8053050(void)
{
    player_avatar_init_params_reset();
    FlagReset(2091);
    FlagReset(2093);
    FlagReset(2092);
    FlagReset(2089);
    FlagReset(2088);
}

void sub_805308C(void)
{
    FlagReset(2092);
    sub_8054164();
    wild_pokemon_reroll();
    mapnumbers_history_shift_sav1_0_2_4_out();
    sub_8134348();
}

void sub_80530AC(void)
{
    s32 i;
    for (i = 0; i < NUM_GAME_STATS; i++)
        gSaveBlock1.gameStats[i] = 0;
}

void sav12_xor_increment(u8 index)
{
    if (index < NUM_GAME_STATS)
    {
        if (gSaveBlock1.gameStats[index] < 0xFFFFFF)
            gSaveBlock1.gameStats[index]++;
        else
            gSaveBlock1.gameStats[index] = 0xFFFFFF;
    }
}

u32 sub_8053108(u8 index)
{
    if (index >= NUM_GAME_STATS)
        return 0;

    return gSaveBlock1.gameStats[index];
}

void sav12_xor_set(u8 index, u32 value)
{
    if (index < NUM_GAME_STATS)
        gSaveBlock1.gameStats[index] = value;
}

void sub_8053154(void)
{
    CpuFill32(0, gSaveBlock1.mapObjectTemplates, sizeof(gSaveBlock1.mapObjectTemplates));
    CpuCopy32(gMapHeader.events->mapObjects,
              gSaveBlock1.mapObjectTemplates,
              gMapHeader.events->mapObjectCount * sizeof(struct MapObjectTemplate));
}

void sub_8053198(void)
{
    struct MapObjectTemplate *mapObjectTemplates = gSaveBlock1.mapObjectTemplates;
    s32 i;
    for (i = 0; i < 64; i++)
        mapObjectTemplates[i].script = gMapHeader.events->mapObjects[i].script;
}

void update_saveblock1_field_object_coords(u8 localId, s16 x, s16 y)
{
    s32 i;
    for (i = 0; i < 64; i++)
    {
        struct MapObjectTemplate *mapObjectTemplate = &gSaveBlock1.mapObjectTemplates[i];
        if (mapObjectTemplate->localId == localId)
        {
            mapObjectTemplate->x = x;
            mapObjectTemplate->y = y;
            break;
        }
    }
}

void update_saveblock1_field_object_movement_behavior(u8 localId, u8 movementType)
{
    s32 i = 0;
    struct MapObjectTemplate *mapObjectTemplate = gSaveBlock1.mapObjectTemplates;
    do
    {
        if (mapObjectTemplate->localId == localId)
        {
            mapObjectTemplate->movementType = movementType;
            break;
        }
        mapObjectTemplate++;
        i++;
    } while (i < 64);
}

void mapdata_load_assets_to_gpu_and_full_redraw(void)
{
    move_tilemap_camera_to_upper_left_corner();
    copy_map_tileset1_tileset2_to_vram(gMapHeader.mapData);
    apply_map_tileset1_tileset2_palette(gMapHeader.mapData);
    DrawWholeMapView();
    cur_mapheader_run_tileset_funcs_after_some_cpuset();
}

struct MapData *get_mapdata_header(void)
{
    u16 mapDataId = gSaveBlock1.mapDataId;
    if (mapDataId)
        return gMapAttributes[mapDataId - 1];
    return NULL;
}

void warp_shift(void)
{
    gUnknown_020297F0 = gSaveBlock1.location;
    gSaveBlock1.location = gUnknown_020297F8;
    gUnknown_02029800 = gDummyWarpData;
    gUnknown_02029808 = gDummyWarpData;
}

void warp_set(struct WarpData *warp, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    warp->mapGroup = mapGroup;
    warp->mapNum = mapNum;
    warp->warpId = warpId;
    warp->x = x;
    warp->y = y;
}

bool32 warp_data_is_not_neg_1(struct WarpData *warp)
{
    if (warp->mapGroup != -1)
        return FALSE;
    if (warp->mapNum != -1)
        return FALSE;
    if (warp->warpId != -1)
        return FALSE;
    if (warp->x != -1)
        return FALSE;
    if (warp->y != -1)
        return FALSE;
    return TRUE;
}

struct MapHeader * const get_mapheader_by_bank_and_number(u16 mapGroup, u16 mapNum)
{
    return gMapGroups[mapGroup][mapNum];
}

struct MapHeader * const warp1_get_mapheader(void)
{
    return get_mapheader_by_bank_and_number(gUnknown_020297F8.mapGroup, gUnknown_020297F8.mapNum);
}

void set_current_map_header_from_sav1_save_old_name(void)
{
    struct MapHeader *dest = &gMapHeader;
    struct MapHeader *src = get_mapheader_by_bank_and_number(gSaveBlock1.location.mapGroup, gSaveBlock1.location.mapNum);
    *dest = *src;
    gSaveBlock1.mapDataId = dest->mapDataId;
    dest->mapData = get_mapdata_header();
}

void sub_805338C(void)
{
    struct MapHeader *dest = &gMapHeader;
    struct MapHeader *src = get_mapheader_by_bank_and_number(gSaveBlock1.location.mapGroup, gSaveBlock1.location.mapNum);
    *dest = *src;
    dest->mapData = get_mapdata_header();
}

void sub_80533CC(void)
{
    if (gSaveBlock1.location.warpId >= 0 && gSaveBlock1.location.warpId < gMapHeader.events->warpCount)
    {
        gSaveBlock1.pos.x = gMapHeader.events->warps[gSaveBlock1.location.warpId].x;
        gSaveBlock1.pos.y = gMapHeader.events->warps[gSaveBlock1.location.warpId].y;
    }
    else if (gSaveBlock1.location.x >= 0 && gSaveBlock1.location.y >= 0)
    {
        gSaveBlock1.pos.x = gSaveBlock1.location.x;
        gSaveBlock1.pos.y = gSaveBlock1.location.y;
    }
    else
    {
        gSaveBlock1.pos.x = gMapHeader.mapData->width / 2;
        gSaveBlock1.pos.y = gMapHeader.mapData->height / 2;
    }
}

void warp_in(void)
{
    warp_shift();
    set_current_map_header_from_sav1_save_old_name();
    sub_80533CC();
}

void warp1_set(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    warp_set(&gUnknown_020297F8, mapGroup, mapNum, warpId, x, y);
}

void warp1_set_2(s8 mapGroup, s8 mapNum, s8 warpId)
{
    warp1_set(mapGroup, mapNum, warpId, -1, -1);
}

void saved_warp2_set(int unused, s8 mapGroup, s8 mapNum, s8 warpId)
{
    warp_set(&gSaveBlock1.warp2, mapGroup, mapNum, warpId, gSaveBlock1.pos.x, gSaveBlock1.pos.y);
}

void saved_warp2_set_2(int unused, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    warp_set(&gSaveBlock1.warp2, mapGroup, mapNum, warpId, x, y);
}

void copy_saved_warp2_bank_and_enter_x_to_warp1(void)
{
    gUnknown_020297F8 = gSaveBlock1.warp2;
}

void sub_8053538(u8 a1)
{
    struct UnkWarpStruct *warp = sub_80FA8CC(a1);
    if (warp)
        warp1_set(warp->mapGroup, warp->mapNum, -1, warp->x, warp->y);
}

void sub_8053570(void)
{
    gUnknown_020297F8 = gSaveBlock1.warp3;
}

void sub_8053588(u8 a1)
{
    struct UnkWarpStruct *warp = sub_80FA8CC(a1);
    if (warp)
        warp_set(&gSaveBlock1.warp3, warp->mapGroup, warp->mapNum, -1, warp->x, warp->y);
}

void sub_80535C4(u16 a1, u16 a2)
{
    u8 v4 = sav1_map_get_light_level();
    u8 v5 = get_map_light_level_by_bank_and_number(gUnknown_020297F8.mapGroup, gUnknown_020297F8.mapNum);
    if (is_light_level_1_2_3_5_or_6(v4) && is_light_level_1_2_3_5_or_6(v5) != TRUE)
        sub_805363C(gSaveBlock1.location.mapGroup, gSaveBlock1.location.mapNum, -1, a1 - 7, a2 - 6);
}

void sub_805363C(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    warp_set(&gSaveBlock1.warp4, mapGroup, mapNum, warpId, x, y);
}

void sub_8053678(void)
{
    gUnknown_020297F8 = gSaveBlock1.warp4;
}

void sub_8053690(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    warp_set(&gUnknown_02029800, mapGroup, mapNum, warpId, x, y);
}

void warp1_set_to_warp2(void)
{
    gUnknown_020297F8 = gUnknown_02029800;
}

void sub_80536E4(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    warp_set(&gUnknown_02029808, mapGroup, mapNum, warpId, x, y);
}

void sub_8053720(s16 x, s16 y)
{
    if (warp_data_is_not_neg_1(&gUnknown_02029808) == TRUE)
    {
        gUnknown_020297F8 = gUnknown_020297F0;
    }
    else
    {
        warp1_set(gUnknown_02029808.mapGroup, gUnknown_02029808.mapNum, -1, x, y);
    }
}

void sub_8053778(void)
{
    gUnknown_020297F8 = gSaveBlock1.warp1;
}

void unref_sub_8053790(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    warp_set(&gSaveBlock1.warp1, mapGroup, mapNum, warpId, x, y);
}

void sub_80537CC(u8 a1)
{
    struct UnkWarpStruct *warp = sub_80FA8CC(a1);
    if (warp)
        warp_set(&gSaveBlock1.warp1, warp->mapGroup, warp->mapNum, -1, warp->x, warp->y);
}

void gpu_sync_bg_hide(void)
{
    gSaveBlock1.warp1 = gSaveBlock1.warp2;
}

struct MapConnection *sub_8053818(u8 dir)
{
    s32 i;
    s32 count = gMapHeader.connections->count;
    struct MapConnection *connection = gMapHeader.connections->connections;

    if (connection == NULL)
        return NULL;

    i = 0;

    while (i < count)
    {
        if (connection->direction == dir)
            return connection;
        i++;
        connection++;
    }

    return NULL;
}

bool8 sub_8053850(u8 dir, u16 x, u16 y)
{
    struct MapConnection *connection = sub_8053818(dir);
    if (connection)
    {
        warp1_set(connection->mapGroup, connection->mapNum, -1, x, y);
    }
    else
    {
        mapheader_run_script_with_tag_x6();
        if (warp_data_is_not_neg_1(&gUnknown_02029800))
            return FALSE;
        warp1_set_to_warp2();
    }
    return TRUE;
}

bool8 sub_80538B0(u16 x, u16 y)
{
    return sub_8053850(CONNECTION_EMERGE, x, y);
}

bool8 sub_80538D0(u16 x, u16 y)
{
    return sub_8053850(CONNECTION_DIVE, x, y);
}

void sub_80538F0(u8 mapGroup, u8 mapNum)
{
    s32 i;
    warp1_set(mapGroup, mapNum, -1, -1, -1);
    sub_8053F0C();
    warp_shift();
    set_current_map_header_from_sav1_save_old_name();
    sub_8053154();
    sub_806906C();
    wild_pokemon_reroll();
    prev_quest_postbuffer_cursor_backup_reset();
    sub_8082BD0(mapGroup, mapNum);
    InTrainerHill();
    sub_80806E4();
    sub_8054164();
    sub_8053C98();
    sav1_reset_battle_music_maybe();
    mapheader_run_script_with_tag_x3();
    not_trainer_hill_battle_pyramid();
    sub_8056D38(gMapHeader.mapData);
    apply_map_tileset2_palette(gMapHeader.mapData);
    for (i = 6; i < 12; i++)
        sub_807D874(i);
    sub_8072ED0();
    mapnumbers_history_shift_sav1_0_2_4_out();
    sub_8134394();
    sub_808073C();
    wild_encounter_reset_coro_args();
    mapheader_run_script_with_tag_x5();
    AddMapNamePopUpWindowTask();
}

void sub_8053994(u32 a1)
{
    bool8 v2;
    bool8 v3;

    set_current_map_header_from_sav1_save_old_name();
    sub_8053154();
    v2 = is_light_level_1_2_3_5_or_6(gMapHeader.light);
    v3 = is_light_level_8_or_9(gMapHeader.light);
    sub_806906C();
    wild_pokemon_reroll();
    prev_quest_postbuffer_cursor_backup_reset();
    sub_8082BD0(gSaveBlock1.location.mapGroup, gSaveBlock1.location.mapNum);
    if (a1 != 1)
        InTrainerHill();
    sub_80806E4();
    sub_8054164();
    if (v2)
        FlagReset(2088);
    sub_8053C98();
    sav1_reset_battle_music_maybe();
    mapheader_run_script_with_tag_x3();
    mapnumbers_history_shift_sav1_0_2_4_out();
    sub_8134348();
    not_trainer_hill_battle_pyramid();
    if (a1 != 1 && v3)
    {
        UpdateTVScreensOnMap(gUnknown_03004870.tv_field_0, gUnknown_03004870.tv_field_4);
        sub_80BBCCC(1);
    }
}

void player_avatar_init_params_reset(void)
{
    gUnknown_02029810.player_field_1 = 1;
    gUnknown_02029810.player_field_0 = 1;
}

void walkrun_find_lowest_active_bit_in_bitfield(void)
{
    gUnknown_02029810.player_field_1 = player_get_direction_lower_nybble();

    if (TestPlayerAvatarFlags(2))
        gUnknown_02029810.player_field_0 = 2;
    else if (TestPlayerAvatarFlags(4))
        gUnknown_02029810.player_field_0 = 4;
    else if (TestPlayerAvatarFlags(8))
        gUnknown_02029810.player_field_0 = 8;
    else if (TestPlayerAvatarFlags(0x10))
        gUnknown_02029810.player_field_0 = 16;
    else
        gUnknown_02029810.player_field_0 = 1;
}

struct UnkPlayerStruct *sub_8053AA8(void)
{
    struct UnkPlayerStruct playerStruct;
    u8 light = sav1_map_get_light_level();
    u16 v2 = cur_mapdata_block_role_at_screen_center_acc_to_sav1();
    u8 v4 = sub_8053B00(&gUnknown_02029810, v2, light);
    playerStruct.player_field_0 = v4;
    playerStruct.player_field_1 = sub_8053B60(&gUnknown_02029810, v4, v2, light);
    gUnknown_02029810 = playerStruct;
    return &gUnknown_02029810;
}

u8 sub_8053B00(struct UnkPlayerStruct *playerStruct, u16 a2, u8 a3)
{
    if (a3 != 8 && FlagGet(2093))
        return 1;
    if (a3 == 5)
        return 16;
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(a2) == 1)
        return 8;
    if (sub_8053C44() != 1)
        return 1;
    if (playerStruct->player_field_0 == 2)
        return 2;
    if (playerStruct->player_field_0 != 4)
        return 1;
    return 4;
}

u8 sub_8053B60(struct UnkPlayerStruct *playerStruct, u8 a2, u16 a3, u8 a4)
{
    if (FlagGet(2093) && a4 == 6)
        return 4;
    if (sub_8056F24(a3) == TRUE)
        return 2;
    if (sub_8056F08(a3) == TRUE || sub_8056EAC(a3) == TRUE)
        return 1;
    if (MetatileBehavior_IsSouthArrowWarp(a3) == TRUE)
        return 2;
    if (MetatileBehavior_IsNorthArrowWarp(a3) == TRUE)
        return 1;
    if (MetatileBehavior_IsWestArrowWarp(a3) == TRUE)
        return 4;
    if (MetatileBehavior_IsEastArrowWarp(a3) == TRUE)
        return 3;
    if ((playerStruct->player_field_0 == 16 && a2 == 8)
     || (playerStruct->player_field_0 == 8 && a2 == 16))
        return playerStruct->player_field_1;
    if (MetatileBehavior_IsLadder(a3) == TRUE)
        return playerStruct->player_field_1;
    return 1;
}

u16 cur_mapdata_block_role_at_screen_center_acc_to_sav1(void)
{
    return MapGridGetMetatileBehaviorAt(gSaveBlock1.pos.x + 7, gSaveBlock1.pos.y + 7);
}

bool32 sub_8053C44(void)
{
    if (gSaveBlock1.location.mapGroup == 29 && (gSaveBlock1.location.mapNum == 11 || gSaveBlock1.location.mapNum == 12))
        return TRUE;
    if (gMapHeader.light == 8)
        return FALSE;
    if (gMapHeader.light == 9)
        return FALSE;
    if (gMapHeader.light == 5)
        return FALSE;
    if (gSaveBlock1.location.mapGroup == 24 && gSaveBlock1.location.mapNum == 36)
        return FALSE;
    if (gSaveBlock1.location.mapGroup == 24 && gSaveBlock1.location.mapNum == 42)
        return FALSE;
    return TRUE;
}

void sub_8053C98(void)
{
    if (!gMapHeader.cave)
        gSaveBlock1.flashUsed = 0;
    else if (FlagGet(2088))
        gSaveBlock1.flashUsed = 1;
    else
        gSaveBlock1.flashUsed = gUnknown_0839ACE8;
}

void sub_8053CE4(s32 a1)
{
    if (a1 < 0 || a1 > gUnknown_0839ACE8)
        a1 = 0;
    gSaveBlock1.flashUsed = a1;
}

u8 sav1_get_flash_used_on_map()
{
    return gSaveBlock1.flashUsed;
}

void sub_8053D14(u16 mapDataId)
{
    gSaveBlock1.mapDataId = mapDataId;
    gMapHeader.mapData = get_mapdata_header();
}

bool16 sub_8053D30(struct WarpData *warp)
{
    if (!FlagGet(2090))
        return FALSE;
    if (warp->mapGroup != 0)
        return FALSE;
    switch (warp->mapNum)
    {
    case 5:
    case 6:
    case 7:
    case 8:
        return TRUE;
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
        return TRUE;
    }
    return FALSE;
}

bool16 sub_8053D6C(struct WarpData *warp)
{
    if (VarGet(16563))
        return FALSE;
    if (warp->mapGroup != 32)
        return FALSE;
    if (warp->mapNum == 0 || warp->mapNum == 1)
        return TRUE;
    return FALSE;
}

u16 sub_8053D9C(struct WarpData *warp)
{
    if (sub_8053D30(warp) == TRUE)
        return LEGENDARY_MUSIC;
    else if (sub_8053D6C(warp) == TRUE)
        return BGM_TOZAN;
    else
        return get_mapheader_by_bank_and_number(warp->mapGroup, warp->mapNum)->music;
}

u16 sav1_map_get_music(void)
{
    u16 music;

    if (gSaveBlock1.location.mapGroup == 0
     && gSaveBlock1.location.mapNum == 26
     && sav1_get_weather_probably() == 8)
        return BGM_ASHROAD;

    music = sub_8053D9C(&gSaveBlock1.location);
    if (music != 0x7FFF)
    {
        return music;
    }
    else
    {
        if (gSaveBlock1.pos.x < 24)
            return BGM_DOORO_X1;
        else
            return BGM_GRANROAD;
    }
}

u16 warp1_target_get_music(void)
{
    u16 music = sub_8053D9C(&gUnknown_020297F8);
    if (music != 0x7FFF)
    {
        return music;
    }
    else
    {
        if (gSaveBlock1.location.mapGroup == 0 && gSaveBlock1.location.mapNum == 2)
            return BGM_DOORO_X1;
        else
            return BGM_GRANROAD;
    }
}

void call_map_music_set_to_zero(void)
{
    ResetMapMusic();
}

void sub_8053E90(void)
{
    u16 music = sav1_map_get_music();

    if (music != LEGENDARY_MUSIC)
    {
        if (gSaveBlock1.battleMusic)
            music = gSaveBlock1.battleMusic;
        else if (sav1_map_get_light_level() == 5)
            music = BGM_DEEPDEEP;
        else if (TestPlayerAvatarFlags(8))
            music = BGM_NAMINORI;
    }

    if (music != GetCurrentMapMusic())
        PlayNewMapMusic(music);
}

void sav1_set_battle_music_maybe(u16 songNum)
{
    gSaveBlock1.battleMusic = songNum;
}

void sav1_reset_battle_music_maybe(void)
{
    gSaveBlock1.battleMusic = 0;
}

void sub_8053F0C(void)
{
    if (FlagGet(16385) != TRUE)
    {
        u16 newMusic = warp1_target_get_music();
        u16 currentMusic = GetCurrentMapMusic();
        if (newMusic != LEGENDARY_MUSIC)
        {
            if (currentMusic == BGM_DEEPDEEP || currentMusic == BGM_NAMINORI)
                return;
            if (TestPlayerAvatarFlags(8))
                newMusic = BGM_NAMINORI;
        }
        if (newMusic != currentMusic)
        {
            if (TestPlayerAvatarFlags(6))
                FadeOutAndFadeInNewMapMusic(newMusic, 4, 4);
            else
                FadeOutAndPlayNewMapMusic(newMusic, 8);
        }
    }
}

void sub_8053F84(void)
{
    u16 currentMusic = GetCurrentMapMusic();
    if (currentMusic != sav1_map_get_music())
        FadeOutAndPlayNewMapMusic(sav1_map_get_music(), 8);
}

void sub_8053FB0(u16 music)
{
    u16 currentMusic = GetCurrentMapMusic();
    if (currentMusic != music && currentMusic != LEGENDARY_MUSIC)
        FadeOutAndPlayNewMapMusic(music, 8);
}

u8 is_warp1_light_level_8_or_9(void)
{
    struct MapHeader *mapHeader = warp1_get_mapheader();
    if (is_light_level_8_or_9(mapHeader->light) == TRUE)
        return 2;
    else
        return 4;
}

void sub_8053FF8(void)
{
    u16 music = warp1_target_get_music();
    if (FlagGet(16385) != TRUE && music != GetCurrentMapMusic())
    {
        u8 speed = is_warp1_light_level_8_or_9();
        FadeOutMapMusic(speed);
    }
}

bool8 sub_8054034(void)
{
    return IsNotWaitingForBGMStop();
}

void sub_8054044(void)
{
    FadeOutMapMusic(4);
}

void sub_8054050(void)
{
    s16 x, y;
    PlayerGetDestCoords((u16 *)&x, (u16 *)&y);
    if (gUnknown_02029816 != 1
     || MetatileBehavior_IsSurfableWaterOrUnderwater(MapGridGetMetatileBehaviorAt(x, y)))
    {
        s8 pan = (Random() % 88) + 212;
        s8 volume = (Random() % 30) + 50;
        PlayCry2(gUnknown_02029814, pan, volume, 1);
    }
}

void sub_80540D0(s16 *a1, u16 *a2)
{
    switch (*a1)
    {
    case 0:
        if (!gUnknown_02029814)
            *a1 = 4;
        else
            *a1 = 1;
        break;
    case 1:
        *a2 = (Random() % 2400) + 1200;
        *a1 = 3;
        break;
    case 2:
        *a2 = (Random() % 1200) + 1200;
        *a1 = 3;
        break;
    case 3:
        (*a2)--;
        if (*a2 == 0)
        {
            sub_8054050();
            *a1 = 2;
        }
        break;
    case 4:
        break;
    }
}

void sub_8054164(void)
{
    if ((gSaveBlock1.location.mapGroup == 0 && gSaveBlock1.location.mapNum == 45) && !sub_810D32C())
    {
        gUnknown_02029816 = 1;
        gUnknown_02029814 = sub_8085514();
    }
    else
    {
        gUnknown_02029814 = wild_pokemon_rand_for_map(&gUnknown_02029816);
    }
}

u8 get_map_light_level_by_bank_and_number(s8 mapGroup, s8 mapNum)
{
    return get_mapheader_by_bank_and_number(mapGroup, mapNum)->light;
}

u8 get_map_light_level_from_warp(struct WarpData *warp)
{
    return get_map_light_level_by_bank_and_number(warp->mapGroup, warp->mapNum);
}

u8 sav1_map_get_light_level(void)
{
    return get_map_light_level_from_warp(&gSaveBlock1.location);
}

u8 get_map_light_from_warp0(void)
{
    return get_map_light_level_from_warp(&gUnknown_020297F0);
}

bool8 is_light_level_1_2_3_5_or_6(u8 a1)
{
    if (a1 == 3 || a1 == 1 || a1 == 5 || a1 == 2 || a1 == 6)
        return TRUE;
    else
        return FALSE;
}

bool8 is_light_level_1_2_3_or_6(u8 a1)
{
    if (a1 == 3 || a1 == 1 || a1 == 6 || a1 == 2)
        return TRUE;
    else
        return FALSE;
}

bool8 is_light_level_8_or_9(u8 a1)
{
    if (a1 == 8 || a1 == 9)
        return TRUE;
    else
        return FALSE;
}

u8 unref_sub_8054260(void)
{
    return get_mapheader_by_bank_and_number(gSaveBlock1.warp2.mapGroup, gSaveBlock1.warp2.mapNum)->name;
}

u8 sav1_map_get_name(void)
{
    return get_mapheader_by_bank_and_number(gSaveBlock1.location.mapGroup, gSaveBlock1.location.mapNum)->name;
}

u8 sav1_map_get_battletype(void)
{
    return get_mapheader_by_bank_and_number(gSaveBlock1.location.mapGroup, gSaveBlock1.location.mapNum)->battleType;
}

void ResetSafariZoneFlag_(void)
{
    ResetSafariZoneFlag();
}

bool32 is_c1_link_related_active(void)
{
    if (gMain.callback1 == sub_8055354)
        return TRUE;
    else
        return FALSE;
}

void c1_overworld_normal(u16 newKeys, u16 heldKeys)
{
    struct UnkInputStruct inputStruct;
    sub_8059204();
    sub_8067EEC(&inputStruct);
    process_overworld_input(&inputStruct, newKeys, heldKeys);
    if (!ScriptContext2_IsEnabled())
    {
        if (sub_8068024(&inputStruct) == 1)
        {
            ScriptContext2_Enable();
            HideMapNamePopUpWindow();
        }
        else
        {
            player_step(inputStruct.input_field_2, newKeys, heldKeys);
        }
    }
}

void c1_overworld(void)
{
    if (gMain.callback2 == c2_overworld)
        c1_overworld_normal(gMain.newKeys, gMain.heldKeys);
}

void c2_overworld_basic(void)
{
    ScriptContext2_RunScript();
    RunTasks();
    AnimateSprites();
    CameraUpdate();
    UpdateCameraPanning();
    BuildOamBuffer();
    UpdatePaletteFade();
    sub_8072EDC();
}

void sub_8054398(void)
{
    c2_overworld_basic();
}

void c2_overworld(void)
{
    int fading = (gPaletteFade.active != 0);
    if (fading)
        SetVBlankCallback(NULL);
    c2_overworld_basic();
    if (fading)
        SetFieldVBlankCallback();
}

void set_callback1(MainCallback cb)
{
    gMain.callback1 = cb;
}

void sub_80543DC(void (*a1)(void))
{
    gUnknown_03000584 = a1;
}

void sub_80543E8(void)
{
    if (gUnknown_0300485C)
        gUnknown_0300485C();
    else
        mapldr_default();
    gUnknown_0300485C = NULL;
}

void CB2_NewGame(void)
{
    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    ResetSafariZoneFlag_();
    NewGameInitData();
    player_avatar_init_params_reset();
    PlayTimeCounter_Start();
    ScriptContext1_Init();
    ScriptContext2_Disable();
    gUnknown_0300485C = sub_80C76A0;
    do_load_map_stuff_loop(&gMain.state);
    SetFieldVBlankCallback();
    set_callback1(c1_overworld);
    SetMainCallback2(c2_overworld);
}

void c2_whiteout(void)
{
    u8 val;
    gMain.state++;
    if (gMain.state >= 120)
    {
        FieldClearVBlankHBlankCallbacks();
        StopMapMusic();
        ResetSafariZoneFlag_();
        sub_8052F5C();
        player_avatar_init_params_reset();
        ScriptContext1_Init();
        ScriptContext2_Disable();
        gUnknown_0300485C = sub_8080B60;
        val = 0;
        do_load_map_stuff_loop(&val);
        SetFieldVBlankCallback();
        set_callback1(c1_overworld);
        SetMainCallback2(c2_overworld);
    }
}

void CB2_LoadMap(void)
{
    FieldClearVBlankHBlankCallbacks();
    ScriptContext1_Init();
    ScriptContext2_Disable();
    set_callback1(NULL);
    SetMainCallback2(sub_810CC80);
    gMain.field_8 = CB2_LoadMap2;
}

void CB2_LoadMap2(void)
{
    do_load_map_stuff_loop(&gMain.state);
    SetFieldVBlankCallback();
    set_callback1(c1_overworld);
    SetMainCallback2(c2_overworld);
}

void sub_8054534(void)
{
    if (!gMain.state)
    {
        FieldClearVBlankHBlankCallbacks();
        ScriptContext1_Init();
        ScriptContext2_Disable();
        set_callback1(NULL);
    }
    if (sub_805493C(&gMain.state, 1))
    {
        SetFieldVBlankCallback();
        set_callback1(c1_overworld);
        SetMainCallback2(c2_overworld);
    }
}

void sub_8054588(void)
{
    FieldClearVBlankHBlankCallbacks();
    gUnknown_0300485C = sub_8080AC4;
    SetMainCallback2(c2_80567AC);
}

void c2_80567AC(void)
{
    if (sub_805483C(&gMain.state))
    {
        SetFieldVBlankCallback();
        set_callback1(sub_8055354);
        sub_80543DC(sub_8055390);
        SetMainCallback2(c2_overworld);
    }
}

void c2_exit_to_overworld_2_switch(void)
{
    if (is_c1_link_related_active() == TRUE)
    {
        SetMainCallback2(c2_exit_to_overworld_2_link);
    }
    else
    {
        FieldClearVBlankHBlankCallbacks();
        SetMainCallback2(c2_exit_to_overworld_2_local);
    }
}

void c2_exit_to_overworld_2_local(void)
{
    if (sub_8054A4C(&gMain.state))
    {
        SetFieldVBlankCallback();
        SetMainCallback2(c2_overworld);
    }
}

void c2_exit_to_overworld_2_link(void)
{
    if (!sub_8055870() && sub_8054A9C(&gMain.state))
        SetMainCallback2(c2_overworld);
}

void sub_805465C(void)
{
    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    sub_8054F70();
    set_callback1(sub_8055354);
    sub_80543DC(sub_8055390);
    gUnknown_0300485C = sub_8080A3C;
    ScriptContext1_Init();
    ScriptContext2_Disable();
    c2_exit_to_overworld_2_switch();
}

void sub_805469C(void)
{
    FieldClearVBlankHBlankCallbacks();
    gUnknown_0300485C = atk17_seteffectuser;
    c2_exit_to_overworld_2_switch();
}

void sub_80546B8(void)
{
    FieldClearVBlankHBlankCallbacks();
    gUnknown_0300485C = sub_80809B0;
    c2_exit_to_overworld_2_switch();
}

void c2_exit_to_overworld_1_continue_scripts_restart_music(void)
{
    FieldClearVBlankHBlankCallbacks();
    gUnknown_0300485C = sub_8080990;
    c2_exit_to_overworld_2_switch();
}

void sub_80546F0(void)
{
    FieldClearVBlankHBlankCallbacks();
    gUnknown_0300485C = sub_8080B60;
    c2_exit_to_overworld_2_switch();
}

void sub_805470C(void)
{
    if (gMapHeader.flags == 1 && sub_80BBB24() == 1)
        AddMapNamePopUpWindowTask();
    sub_8080B60();
}

void CB2_ContinueSavedGame(void)
{
    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    ResetSafariZoneFlag_();
    sub_805338C();
    sub_8053198();
    sub_806451C();
    InTrainerHill();
    sub_805308C();
    sub_8055FC0();
    PlayTimeCounter_Start();
    ScriptContext1_Init();
    ScriptContext2_Disable();
    if (sub_80479F8() == 1)
    {
        sub_8047A04();
        sub_8053778();
        warp_in();
        SetMainCallback2(CB2_LoadMap);
    }
    else
    {
        gUnknown_0300485C = sub_805470C;
        set_callback1(c1_overworld);
        c2_exit_to_overworld_2_switch();
    }
}

void FieldClearVBlankHBlankCallbacks(void)
{
    u16 savedIme = REG_IME;
    REG_IME = 0;
    REG_IE &= ~INTR_FLAG_HBLANK;
    REG_IE |= INTR_FLAG_VBLANK;
    REG_IME = savedIme;
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

void SetFieldVBlankCallback(void)
{
    SetVBlankCallback(VBlankCB_Field);
}

void VBlankCB_Field(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    sub_8089668();
    sub_8057A58();
    TransferPlttBuffer();
    sub_8072E74();
}