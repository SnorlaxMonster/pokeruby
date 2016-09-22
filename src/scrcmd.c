#include "global.h"
#include "script.h"
#include "rng.h"
#include "palette.h"
#include "rtc.h"
#include "pokemon.h"
#include "fieldmap.h"
#include "main.h"
#include "decoration.h"

extern void killram(void);
extern u16 *GetVarPointer(u16);
extern u16 VarGet(u16);
extern void sub_8126160(u8);
extern u8 sub_80A9424(u16, u16);
extern u8 sub_80A9538(u16, u16);
extern u8 sub_80A9344(u16, u16);
extern u8 sub_80A92D4(u16, u16);
extern u8 sub_80A9670(u16);
extern u8 sub_80A9760(u16, u16);
extern u8 sub_80A9718(u16, u16);
extern u8 IsThereStorageSpaceForDecoration(u8);
extern s8 sub_81340A8(u8);
extern u8 sub_8134074(u8);
extern u8 sub_8133FE4(u8);
extern void FlagSet(u16);
extern void FlagReset(u16);
extern u8 FlagGet(u16);
extern void sav12_xor_increment(u8);
extern void sub_8081594(u8);
extern void sub_8053CE4(u32);
extern void fade_screen(u8, u8);
extern void InTrainerHill(void);
extern void sub_80806B4(u32);
extern void sub_80806E4(void);
extern void sub_808073C(void);
extern void activate_per_step_callback(u8);
extern void sub_8053D14(u16);
extern void warp1_set(s8, s8, s8, s8, s8);
extern void sub_8080E88(void);
extern void player_avatar_init_params_reset(void);
extern void sp13E_warp_to_last_warp(void);
extern void sub_8080EF0(void);
extern void sp13F_fall_to_last_warp(void);
extern void sub_8053720(s16, s16);
extern void PlayerGetDestCoords(u16 *, u16 *);
extern void sub_8080F68(void);
extern void saved_warp2_set_2(s8, s8, s8, s8, s8, s8);
extern void sub_8053690(s8, s8, s8, s8, s8);
extern void sub_80536E4(s8, s8, s8, s8, s8);
extern void sub_805363C(s8, s8, s8, s8, s8);
extern void audio_play(u16);
extern bool8 task_is_not_running_overworld_fanfare(void);
extern bool8 mplay_has_finished_maybe(void);
extern void fanfare_play(u16);
extern void sav1_set_battle_music_maybe(u16);
extern void sub_8053F84(void);
extern void sub_8053FB0(u16);
extern void sub_8074FB8(u8);
extern bool8 sub_8074FD0(void);
extern void sub_8074FF8(u8);
extern u8 exec_movement(u8, u8, u8, void *);
extern bool8 sub_80A212C(u8, u8, u8);
extern void RemoveFieldObjectByLocalIdAndMap(u8, u8, u8);
extern u8 show_sprite(u8, u8, u8);
extern void sub_805C0F8(u8, u8, u8, s16, s16);
extern void update_saveblock1_field_object_coords(u8, s16, s16);
extern void sub_805C78C(u8, u8, u8);
extern void npc_by_local_id_and_map_set_field_1_bit_x20(u8, u8, u8, u8);
extern void sub_805BCF0(u8, u8, u8, u8);
extern void sub_805BD48(u8, u8, u8);
extern u8 player_get_direction_lower_nybble(void);
extern u8 FieldObjectFaceOppositeDirection(void *, u8);
extern void FieldObjectTurnByLocalIdAndMap(u8, u8, u8, u8);
extern void update_saveblock1_field_object_movement_behavior(u8, u8);
extern u8 sub_805B410(u8, u8, s16, s16, u8, u8);
extern void sub_8064990(u8, u8);
extern bool32 is_c1_link_related_active(void);
extern void sub_8064D20(void);
extern bool8 sub_8064CFC(void);
extern void sub_8064DD8(void);
extern bool8 sub_8064DB4(void);
extern void textbox_close(void);
extern u8 GetFieldObjectIdByLocalIdAndMap(u8, u8, u8);
extern u8 FieldObjectClearAnimIfSpecialAnimFinished(void *);
extern void sub_80A2178(void);
extern void sub_806451C(void);
extern bool8 box_related_two__2(u8 *);
extern bool8 box_related_two__3(u8 *);
extern bool8 sub_8064C84(void);
extern bool8 yes_no_box(u8, u8);
extern bool8 sub_80B5054(u8, u8, u8, u8);
extern bool8 sub_80B50B0(u8, u8, u8, u8, u8);
extern bool8 sub_80B5578(u8, u8, u8, u8, u8);
extern bool8 Multichoice(u8, u8, u8, u8);
extern bool8 sub_80B58C4(u16, u8, u8);
extern void *picbox_close(void);
extern void sub_8106630(u32);
extern void sub_80C4F10(void);
extern u8 sub_810F87C(void);
extern void itemid_copy_name(u16, u8 *);
extern u8 sub_80BF0B8(u32);
extern void sub_80B79B8(u32 *, u32);
extern sub_80B79E0(u32 *, u32);
extern bool8 IsEnoughMoney(u32, u32);
extern void sub_80B7C14(u32, u8, u8);
extern void RemoveMoneyLabelObject(u8, u8);
extern void sub_80B7BEC(u32, u8, u8);
extern void sub_811A72C(u32, u8, u8);
extern void sub_811A770(u8, u8);
extern void sub_811A704(u32, u8, u8);
extern void *sub_80823C8(u8 *);
extern void sub_80825E4(void);
extern u8 *sub_80826E8(void);
extern u8 *sub_8082700(void);
extern u8 trainer_flag_check(u16);
extern void trainer_flag_set(u16);
extern void trainer_flag_clear(u16);
extern void sub_80C54D0(u16, u8, u16);
extern void sub_8081B3C(void);
extern void CreatePokemartMenu(void *);
extern void CreateDecorationShop1Menu(void *);
extern void CreateDecorationShop2Menu(void *);
extern void sub_81018A0(u8, void *);
extern void PlantBerryTree(u8, u8, u8, u8);
extern bool8 GetPriceReduction(u8);
extern void sub_80F99CC(void);
extern void sub_80C48C8(void);
extern void sub_80C4940(void);
extern void sub_80C4980(u8);
extern u32 FieldEffectStart(u8);
extern bool8 FieldEffectActiveListContains(u8);
extern void sub_8053588(u8);
extern void sub_8075178(u16, u8);
extern bool8 sub_8075374(void);
extern void MapGridSetMetatileIdAt(u32, u32, u16);
extern u16 sub_8058790(u32, u32);
extern bool8 task_overworld_door_add_if_role_69_for_opening_door_at(u32, u32);
extern bool8 sub_805870C(u32, u32);
extern bool8 sub_805877C(void);
extern void sub_80586B4(u32, u32);
extern void sub_80586E0(u32, u32);
extern void sub_810E7AC(u8, u8, u8, u8);
extern void sub_810E824(void);
extern u16 GetCoins(void);
extern bool8 sub_811A840(u16);
extern bool8 sub_811A898(u16);
extern u8 sub_80C5374(u16, u8, u16, u32, u32, u8);
extern u8 sub_80C53F8(u16);
extern void sub_80C5530(u8, u16, u8);
extern bool8 pokemon_has_move(struct Pokemon *, u16);
extern void c2_exit_to_overworld_1_continue_scripts_restart_music(void);

typedef u16 (*SpecialFunc)(void);
typedef void (*NativeFunc)(void);

extern struct Pokemon gPlayerParty[6]; // 0x3004360
extern struct Pokemon gEnemyParty[6]; // 0x30045C0

extern u32 gUnknown_0202E8AC;
extern u32 gUnknown_0202E8B0;
extern u16 gUnknown_0202E8B4;
extern u16 gUnknown_0202E8B6;
extern u16 gUnknown_0202E8B8;
extern u16 gUnknown_0202E8BA;
extern u16 gUnknown_0202E8BC;
extern u16 gUnknown_0202E8C4;
extern u16 gUnknown_0202E8C6;
extern u16 gUnknown_0202E8C8;
extern u16 gUnknown_0202E8CC;

extern u16 gScriptResult;

extern u32 gUnknown_0202FF84[];

extern u16 gUnknown_0203869C;

extern SpecialFunc gSpecials[];
extern u8 *gStdScripts[];
extern u8 *gStdScripts_End[];

extern u8 gSpeciesNames[][11];
extern u8 gMoveNames[][13];

extern u8 gUnknown_083762DC[6][3];
extern u8 * const gUnknown_083762F0[];
extern u8 * const gUnknown_083CE048[];
extern struct Decoration gDecorations[];

bool8 ScrCmd_snop(struct ScriptContext *ctx)
{
    return FALSE;
}

bool8 ScrCmd_snop1(struct ScriptContext *ctx)
{
    return FALSE;
}

bool8 ScrCmd_end(struct ScriptContext *ctx)
{
    script_stop(ctx);
    return FALSE;
}

bool8 ScrCmd_jumpasm(struct ScriptContext *ctx)
{
    u32 addr = script_read_word(ctx);
    script_setup_asm_script(ctx, (void *)addr);
    return TRUE;
}

bool8 ScrCmd_special(struct ScriptContext *ctx)
{
    u16 index = script_read_halfword(ctx);
    gSpecials[index]();
    return FALSE;
}

bool8 ScrCmd_specialval(struct ScriptContext *ctx)
{
    u16 *var = GetVarPointer(script_read_halfword(ctx));
    *var = gSpecials[script_read_halfword(ctx)]();
    return FALSE;
}

bool8 ScrCmd_callasm(struct ScriptContext *ctx)
{
    NativeFunc func = (NativeFunc)script_read_word(ctx);
    func();
    return FALSE;
}

bool8 ScrCmd_waitstate(struct ScriptContext *ctx)
{
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_jump(struct ScriptContext *ctx)
{
    u8 *ptr = (u8 *)script_read_word(ctx);
    script_jump(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_return(struct ScriptContext *ctx)
{
    script_return(ctx);
    return FALSE;
}

bool8 ScrCmd_call(struct ScriptContext *ctx)
{

    u8 *ptr = (u8 *)script_read_word(ctx);
    script_call(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_jumpif(struct ScriptContext *ctx)
{
    u8 condition = *(ctx->scriptPtr++);
    u8 *ptr = (u8 *)script_read_word(ctx);
    if (gUnknown_083762DC[condition][ctx->comparisonResult] == 1)
        script_jump(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_callif(struct ScriptContext *ctx)
{
    u8 condition = *(ctx->scriptPtr++);
    u8 *ptr = (u8 *)script_read_word(ctx);
    if (gUnknown_083762DC[condition][ctx->comparisonResult] == 1)
        script_call(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_setvaddress(struct ScriptContext *ctx)
{
    u32 addr1 = (u32)ctx->scriptPtr - 1;
    u32 addr2 = script_read_word(ctx);
    gUnknown_0202E8B0 = addr2 - addr1;
    return FALSE;
}

bool8 ScrCmd_vjump(struct ScriptContext *ctx)
{
    u32 addr = script_read_word(ctx);
    script_jump(ctx, (u8 *)(addr - gUnknown_0202E8B0));
    return FALSE;
}

bool8 ScrCmd_vcall(struct ScriptContext *ctx)
{
    u32 addr = script_read_word(ctx);
    script_call(ctx, (u8 *)(addr - gUnknown_0202E8B0));
    return FALSE;
}

bool8 ScrCmd_if5(struct ScriptContext *ctx)
{
    u8 condition = *(ctx->scriptPtr++);
    u8 *ptr = (u8 *)(script_read_word(ctx) - gUnknown_0202E8B0);
    if (gUnknown_083762DC[condition][ctx->comparisonResult] == 1)
        script_jump(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_if6(struct ScriptContext *ctx)
{
    u8 condition = *(ctx->scriptPtr++);
    u8 *ptr = (u8 *)(script_read_word(ctx) - gUnknown_0202E8B0);
    if (gUnknown_083762DC[condition][ctx->comparisonResult] == 1)
        script_call(ctx, ptr);
    return FALSE;
}

bool8 ScrCmd_jumpstd(struct ScriptContext *ctx)
{
    u8 index = *(ctx->scriptPtr++);
    u8 **ptr = &gStdScripts[index];
    if (ptr < gStdScripts_End)
        script_jump(ctx, *ptr);
    return FALSE;
}

bool8 ScrCmd_callstd(struct ScriptContext *ctx)
{
    u8 index = *(ctx->scriptPtr++);
    u8 **ptr = &gStdScripts[index];
    if (ptr < gStdScripts_End)
        script_call(ctx, *ptr);
    return FALSE;
}

bool8 ScrCmd_jumpstdif(struct ScriptContext *ctx)
{
    u8 condition = *(ctx->scriptPtr++);
    u8 index = *(ctx->scriptPtr++);
    if (gUnknown_083762DC[condition][ctx->comparisonResult] == 1)
    {
        u8 **ptr = &gStdScripts[index];
        if (ptr < gStdScripts_End)
            script_jump(ctx, *ptr);
    }
    return FALSE;
}

bool8 ScrCmd_callstdif(struct ScriptContext *ctx)
{
    u8 condition = *(ctx->scriptPtr++);
    u8 index = *(ctx->scriptPtr++);
    if (gUnknown_083762DC[condition][ctx->comparisonResult] == 1)
    {
        u8 **ptr = &gStdScripts[index];
        if (ptr < gStdScripts_End)
            script_call(ctx, *ptr);
    }
    return FALSE;
}

bool8 ScrCmd_jumpram(struct ScriptContext *ctx)
{
    script_jump(ctx, (u8 *)gUnknown_0202E8AC);
    return FALSE;
}

bool8 ScrCmd_die(struct ScriptContext *ctx)
{
    killram();
    script_stop(ctx);
    return TRUE;
}

bool8 ScrCmd_setbyte(struct ScriptContext *ctx)
{
    u8 value = *(ctx->scriptPtr++);
    sub_8126160(value);
    return FALSE;
}

bool8 ScrCmd_loadptr(struct ScriptContext *ctx)
{
    u8 index = *(ctx->scriptPtr++);
    ctx->data[index] = script_read_word(ctx);
    return FALSE;
}

bool8 ScrCmd_loadbytefrompointer(struct ScriptContext *ctx)
{
    u8 index = *(ctx->scriptPtr++);
    ctx->data[index] = *(u8 *)script_read_word(ctx);
    return FALSE;
}

bool8 ScrCmd_writebytetooffset(struct ScriptContext *ctx)
{
    u8 value = *(ctx->scriptPtr++);
    *(u8 *)script_read_word(ctx) = value;
    return FALSE;
}

bool8 ScrCmd_setbufferbyte(struct ScriptContext *ctx)
{
    u8 index = *(ctx->scriptPtr++);
    ctx->data[index] = *(ctx->scriptPtr++);
    return FALSE;
}

bool8 ScrCmd_setptrbyte(struct ScriptContext *ctx)
{
    u8 index = *(ctx->scriptPtr++);
    *(u8 *)script_read_word(ctx) = ctx->data[index];
    return FALSE;
}

bool8 ScrCmd_copybuffers(struct ScriptContext *ctx)
{
    u8 destIndex = *(ctx->scriptPtr++);
    u8 srcIndex = *(ctx->scriptPtr++);
    ctx->data[destIndex] = ctx->data[srcIndex];
    return FALSE;
}

bool8 ScrCmd_copybyte(struct ScriptContext *ctx)
{
    u8 *ptr = (u8 *)script_read_word(ctx);
    *ptr = *(u8 *)script_read_word(ctx);
    return FALSE;
}

bool8 ScrCmd_setvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(script_read_halfword(ctx));
    *ptr = script_read_halfword(ctx);
    return FALSE;
}

bool8 ScrCmd_copyvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(script_read_halfword(ctx));
    *ptr = *GetVarPointer(script_read_halfword(ctx));
    return FALSE;
}

bool8 ScrCmd_setorcopyvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(script_read_halfword(ctx));
    *ptr = VarGet(script_read_halfword(ctx));
    return FALSE;
}

u8 compare_012(u16 a1, u16 a2)
{
    if (a1 < a2)
        return 0;

    if (a1 == a2)
        return 1;

    return 2;
}

bool8 ScrCmd_comparebuffers(struct ScriptContext *ctx)
{
    u8 value1 = ctx->data[*(ctx->scriptPtr++)];
    u8 value2 = ctx->data[*(ctx->scriptPtr++)];
    ctx->comparisonResult = compare_012(value1, value2);
    return FALSE;
}

bool8 ScrCmd_comparebuffertobyte(struct ScriptContext *ctx)
{
    u8 value1 = ctx->data[*(ctx->scriptPtr++)];
    u8 value2 = *(ctx->scriptPtr++);
    ctx->comparisonResult = compare_012(value1, value2);
    return FALSE;
}

bool8 ScrCmd_comparebuffertoptrbyte(struct ScriptContext *ctx)
{
    u8 value1 = ctx->data[*(ctx->scriptPtr++)];
    u8 value2 = *(u8 *)script_read_word(ctx);
    ctx->comparisonResult = compare_012(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compareptrbytetobuffer(struct ScriptContext *ctx)
{
    u8 value1 = *(u8 *)script_read_word(ctx);
    u8 value2 = ctx->data[*(ctx->scriptPtr++)];
    ctx->comparisonResult = compare_012(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compareptrbytetobyte(struct ScriptContext *ctx)
{
    u8 value1 = *(u8 *)script_read_word(ctx);
    u8 value2 = *(ctx->scriptPtr++);
    ctx->comparisonResult = compare_012(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compareptrbytes(struct ScriptContext *ctx)
{
    u8 value1 = *(u8 *)script_read_word(ctx);
    u8 value2 = *(u8 *)script_read_word(ctx);
    ctx->comparisonResult = compare_012(value1, value2);
    return FALSE;
}

bool8 ScrCmd_compare(struct ScriptContext *ctx)
{
    u16 value1 = *GetVarPointer(script_read_halfword(ctx));
    u16 value2 = script_read_halfword(ctx);
    ctx->comparisonResult = compare_012(value1, value2);
    return FALSE;
}

bool8 ScrCmd_comparevars(struct ScriptContext *ctx)
{
    u16 *ptr1 = GetVarPointer(script_read_halfword(ctx));
    u16 *ptr2 = GetVarPointer(script_read_halfword(ctx));
    ctx->comparisonResult = compare_012(*ptr1, *ptr2);
    return FALSE;
}

bool8 ScrCmd_addvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(script_read_halfword(ctx));
    *ptr += script_read_halfword(ctx);
    return FALSE;
}

bool8 ScrCmd_subvar(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(script_read_halfword(ctx));
    *ptr -= VarGet(script_read_halfword(ctx));
    return FALSE;
}

bool8 ScrCmd_random(struct ScriptContext *ctx)
{
    u16 max = VarGet(script_read_halfword(ctx));
    gScriptResult = Random() % max;
    return FALSE;
}

bool8 ScrCmd_additem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(script_read_halfword(ctx));
    u32 quantity = VarGet(script_read_halfword(ctx));
    gScriptResult = sub_80A9424(itemId, (u8)quantity);
    return FALSE;
}

bool8 ScrCmd_removeitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(script_read_halfword(ctx));
    u32 quantity = VarGet(script_read_halfword(ctx));
    gScriptResult = sub_80A9538(itemId, (u8)quantity);
    return FALSE;
}

bool8 ScrCmd_checkitemspace(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(script_read_halfword(ctx));
    u32 quantity = VarGet(script_read_halfword(ctx));
    gScriptResult = sub_80A9344(itemId, (u8)quantity);
    return FALSE;
}

bool8 ScrCmd_checkitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(script_read_halfword(ctx));
    u32 quantity = VarGet(script_read_halfword(ctx));
    gScriptResult = sub_80A92D4(itemId, (u8)quantity);
    return FALSE;
}

bool8 ScrCmd_checkitemtype(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(script_read_halfword(ctx));
    gScriptResult = sub_80A9670(itemId);
    return FALSE;
}

bool8 ScrCmd_addpcitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(script_read_halfword(ctx));
    u16 quantity = VarGet(script_read_halfword(ctx));
    gScriptResult = sub_80A9760(itemId, quantity);
    return FALSE;
}

bool8 ScrCmd_checkpcitem(struct ScriptContext *ctx)
{
    u16 itemId = VarGet(script_read_halfword(ctx));
    u16 quantity = VarGet(script_read_halfword(ctx));
    gScriptResult = sub_80A9718(itemId, quantity);
    return FALSE;
}

bool8 ScrCmd_adddecor(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(script_read_halfword(ctx));
    gScriptResult = IsThereStorageSpaceForDecoration(decorId);
    return FALSE;
}

bool8 ScrCmd_removedecor(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(script_read_halfword(ctx));
    gScriptResult = sub_81340A8(decorId);
    return FALSE;
}

bool8 ScrCmd_checkdecor(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(script_read_halfword(ctx));
    gScriptResult = sub_8134074(decorId);
    return FALSE;
}

bool8 ScrCmd_testdecor(struct ScriptContext *ctx)
{
    u32 decorId = VarGet(script_read_halfword(ctx));
    gScriptResult = sub_8133FE4(decorId);
    return FALSE;
}

bool8 ScrCmd_setflag(struct ScriptContext *ctx)
{
    FlagSet(script_read_halfword(ctx));
    return FALSE;
}

bool8 ScrCmd_clearflag(struct ScriptContext *ctx)
{
    FlagReset(script_read_halfword(ctx));
    return FALSE;
}

bool8 ScrCmd_checkflag(struct ScriptContext *ctx)
{
    ctx->comparisonResult = FlagGet(script_read_halfword(ctx));
    return FALSE;
}

bool8 ScrCmd_inccounter(struct ScriptContext *ctx)
{
    sav12_xor_increment(*(ctx->scriptPtr++));
    return FALSE;
}

bool8 ScrCmd_lighten(struct ScriptContext *ctx)
{
    sub_8081594(*(ctx->scriptPtr++));
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_darken(struct ScriptContext *ctx)
{
    u16 value = VarGet(script_read_halfword(ctx));
    sub_8053CE4(value);
    return FALSE;
}

bool8 sub_8066248(void)
{
    if (!gPaletteFade.active)
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_fadescreen(struct ScriptContext *ctx)
{
    fade_screen(*(ctx->scriptPtr++), 0);
    script_setup_asm_script(ctx, sub_8066248);
    return TRUE;
}

bool8 ScrCmd_fadescreendelay(struct ScriptContext *ctx)
{
    u8 val1 = *(ctx->scriptPtr++);
    u8 val2 = *(ctx->scriptPtr++);
    fade_screen(val1, val2);
    script_setup_asm_script(ctx, sub_8066248);
    return TRUE;
}

bool8 s28_pause_asm()
{
    gUnknown_0202E8B4--;

    if (gUnknown_0202E8B4 == 0)
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_pause(struct ScriptContext *ctx)
{
    gUnknown_0202E8B4 = script_read_halfword(ctx);
    script_setup_asm_script(ctx, s28_pause_asm);
    return TRUE;
}

bool8 ScrCmd_compareflags(struct ScriptContext *ctx)
{
    u8 hour = VarGet(script_read_halfword(ctx));
    u8 minute = VarGet(script_read_halfword(ctx));
    RtcInitLocalTimeOffset(hour, minute);
    return FALSE;
}

bool8 ScrCmd_checkdailyflags(struct ScriptContext *ctx)
{
    InTrainerHill();
    return FALSE;
}

bool8 ScrCmd_resetvars(struct ScriptContext *ctx)
{
    RtcCalcLocalTime();
    gUnknown_0202E8C4 = gLocalTime.hours;
    gUnknown_0202E8C6 = gLocalTime.minutes;
    gUnknown_0202E8C8 = gLocalTime.seconds;
    return FALSE;
}

bool8 ScrCmd_setweather(struct ScriptContext *ctx)
{
    u16 value = VarGet(script_read_halfword(ctx));
    sub_80806B4(value);
    return FALSE;
}

bool8 ScrCmd_resetweather(struct ScriptContext *ctx)
{
    sub_80806E4();
    return FALSE;
}

bool8 ScrCmd_doweather(struct ScriptContext *ctx)
{
    sub_808073C();
    return FALSE;
}

bool8 ScrCmd_tileeffect(struct ScriptContext *ctx)
{
    activate_per_step_callback(*(ctx->scriptPtr++));
    return FALSE;
}

bool8 ScrCmd_setmapfooter(struct ScriptContext *ctx)
{
    u16 value = VarGet(script_read_halfword(ctx));
    sub_8053D14(value);
    return FALSE;
}

bool8 ScrCmd_warp(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u16 v4 = VarGet(script_read_halfword(ctx));
    s8 v5 = VarGet(script_read_halfword(ctx));
    warp1_set(v1, v2, v3, v4, v5);
    sub_8080E88();
    player_avatar_init_params_reset();
    return TRUE;
}

bool8 ScrCmd_warpmuted(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u16 v4 = VarGet(script_read_halfword(ctx));
    s8 v5 = VarGet(script_read_halfword(ctx));
    warp1_set(v1, v2, v3, v4, v5);
    sp13E_warp_to_last_warp();
    player_avatar_init_params_reset();
    return TRUE;
}

bool8 ScrCmd_warpwalk(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u16 v4 = VarGet(script_read_halfword(ctx));
    s8 v5 = VarGet(script_read_halfword(ctx));
    warp1_set(v1, v2, v3, v4, v5);
    sub_8080EF0();
    player_avatar_init_params_reset();
    return TRUE;
}

bool8 ScrCmd_warphole(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u16 x;
    u16 y;

    PlayerGetDestCoords(&x, &y);

    if (v1 == 0xFF && v2 == 0xFF)
        sub_8053720(x - 7, y - 7);
    else
        warp1_set(v1, v2, -1, x - 7, y - 7);

    sp13F_fall_to_last_warp();
    player_avatar_init_params_reset();
    return TRUE;
}

bool8 ScrCmd_warpteleport(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u16 v4 = VarGet(script_read_halfword(ctx));
    s8 v5 = VarGet(script_read_halfword(ctx));
    warp1_set(v1, v2, v3, v4, v5);
    sub_8080F68();
    player_avatar_init_params_reset();
    return TRUE;
}

bool8 ScrCmd_warp3(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u16 v4 = VarGet(script_read_halfword(ctx));
    s8 v5 = VarGet(script_read_halfword(ctx));
    warp1_set(v1, v2, v3, v4, v5);
    return FALSE;
}

bool8 ScrCmd_warpplace(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u16 v4 = VarGet(script_read_halfword(ctx));
    s8 v5 = VarGet(script_read_halfword(ctx));
    saved_warp2_set_2(0, v1, v2, v3, v4, v5);
    return FALSE;
}

bool8 ScrCmd_warp4(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u16 v4 = VarGet(script_read_halfword(ctx));
    s8 v5 = VarGet(script_read_halfword(ctx));
    sub_8053690(v1, v2, v3, v4, v5);
    return FALSE;
}

bool8 ScrCmd_warp5(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u16 v4 = VarGet(script_read_halfword(ctx));
    s8 v5 = VarGet(script_read_halfword(ctx));
    sub_80536E4(v1, v2, v3, v4, v5);
    return FALSE;
}

bool8 ScrCmd_warp6(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u16 v4 = VarGet(script_read_halfword(ctx));
    s8 v5 = VarGet(script_read_halfword(ctx));
    sub_805363C(v1, v2, v3, v4, v5);
    return FALSE;
}

bool8 ScrCmd_getplayerxy(struct ScriptContext *ctx)
{
    u16 *ptr1 = GetVarPointer(script_read_halfword(ctx));
    u16 *ptr2 = GetVarPointer(script_read_halfword(ctx));
    *ptr1 = gSaveBlock1.pos.x;
    *ptr2 = gSaveBlock1.pos.y;
    return FALSE;
}

bool8 ScrCmd_countpokemon(struct ScriptContext *ctx)
{
    gScriptResult = CalculatePlayerPartyCount();
    return FALSE;
}

bool8 ScrCmd_playsfx(struct ScriptContext *ctx)
{
    audio_play(script_read_halfword(ctx));
    return FALSE;
}

bool8 s30_music_check_asm()
{
    if (!mplay_has_finished_maybe())
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_checksound(struct ScriptContext *ctx)
{
    script_setup_asm_script(ctx, s30_music_check_asm);
    return TRUE;
}

bool8 ScrCmd_fanfare(struct ScriptContext *ctx)
{
    fanfare_play(script_read_halfword(ctx));
    return FALSE;
}

bool8 s32_fanfare_wait_asm()
{
    return task_is_not_running_overworld_fanfare();
}

bool8 ScrCmd_waitfanfare(struct ScriptContext *ctx)
{
    script_setup_asm_script(ctx, s32_fanfare_wait_asm);
    return TRUE;
}

bool8 ScrCmd_playmusic(struct ScriptContext *ctx)
{
    u16 songId = script_read_halfword(ctx);
    bool8 val = *(ctx->scriptPtr++);
    if (val == TRUE)
        sav1_set_battle_music_maybe(songId);
    current_map_music_set(songId);
    return FALSE;
}

bool8 ScrCmd_playmusicbattle(struct ScriptContext *ctx)
{
    sav1_set_battle_music_maybe(script_read_halfword(ctx));
    return FALSE;
}

bool8 ScrCmd_fadedefault(struct ScriptContext *ctx)
{
    sub_8053F84();
    return FALSE;
}

bool8 ScrCmd_fademusic(struct ScriptContext *ctx)
{
    sub_8053FB0(script_read_halfword(ctx));
    return FALSE;
}

bool8 ScrCmd_fadeout(struct ScriptContext *ctx)
{
    u8 val = *(ctx->scriptPtr++);
    if (val)
        sub_8074FB8(4 * val);
    else
        sub_8074FB8(4);
    script_setup_asm_script(ctx, sub_8074FD0);
    return TRUE;
}

bool8 ScrCmd_fadein(struct ScriptContext *ctx)
{
    u8 val = *(ctx->scriptPtr++);
    if (val)
        sub_8074FF8(4 * val);
    else
        sub_8074FF8(4);
    return FALSE;
}

bool8 ScrCmd_move(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    void *v2 = (void *)script_read_word(ctx);
    exec_movement(v1, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup, v2);
    gUnknown_0202E8B6 = v1;
    return FALSE;
}

bool8 ScrCmd_movecoords(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    void *v2 = (void *)script_read_word(ctx);
    u8 v3 = *(ctx->scriptPtr++);
    u8 v4 = *(ctx->scriptPtr++);
    exec_movement(v1, v4, v3, v2);
    gUnknown_0202E8B6 = v1;
    return FALSE;
}

bool8 s51a_0806B288(void)
{
    return sub_80A212C(gUnknown_0202E8B6, gUnknown_0202E8BA, gUnknown_0202E8B8);
}

bool8 ScrCmd_waitmove(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    if (v1)
        gUnknown_0202E8B6 = v1;
    gUnknown_0202E8B8 = gSaveBlock1.location.mapGroup;
    gUnknown_0202E8BA = gSaveBlock1.location.mapNum;
    script_setup_asm_script(ctx, s51a_0806B288);
    return TRUE;
}

bool8 ScrCmd_waitmovexy(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    u8 v2;
    u8 v3;

    if (v1)
        gUnknown_0202E8B6 = v1;

    v2 = *(ctx->scriptPtr++);
    v3 = *(ctx->scriptPtr++);
    gUnknown_0202E8B8 = v2;
    gUnknown_0202E8BA = v3;
    script_setup_asm_script(ctx, s51a_0806B288);
    return TRUE;
}

bool8 ScrCmd_disappear(struct ScriptContext *ctx)
{
    u16 objectId = VarGet(script_read_halfword(ctx));
    RemoveFieldObjectByLocalIdAndMap(objectId, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup);
    return FALSE;
}

bool8 ScrCmd_disappearxy(struct ScriptContext *ctx)
{
    u16 objectId = VarGet(script_read_halfword(ctx));
    u8 mapGroup = *(ctx->scriptPtr++);
    u8 mapNum = *(ctx->scriptPtr++);
    RemoveFieldObjectByLocalIdAndMap(objectId, mapNum, mapGroup);
    return FALSE;
}

bool8 ScrCmd_reappear(struct ScriptContext *ctx)
{
    u16 objectId = VarGet(script_read_halfword(ctx));
    show_sprite(objectId, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup);
    return FALSE;
}

bool8 ScrCmd_reappearxy(struct ScriptContext *ctx)
{
    u16 objectId = VarGet(script_read_halfword(ctx));
    u8 mapGroup = *(ctx->scriptPtr++);
    u8 mapNum = *(ctx->scriptPtr++);
    show_sprite(objectId, mapNum, mapGroup);
    return FALSE;
}

bool8 ScrCmd_movesprite(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    u16 v2 = VarGet(script_read_halfword(ctx));
    u32 v3 = VarGet(script_read_halfword(ctx));
    sub_805C0F8(v1, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup, v2, v3);
    return FALSE;
}

bool8 ScrCmd_movespriteperm(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    u16 v2 = VarGet(script_read_halfword(ctx));
    u32 v3 = VarGet(script_read_halfword(ctx));
    update_saveblock1_field_object_coords(v1, v2, v3);
    return FALSE;
}

bool8 ScrCmd_moveoffscreen(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    sub_805C78C(v1, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup);
    return FALSE;
}

bool8 ScrCmd_spritevisible(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    npc_by_local_id_and_map_set_field_1_bit_x20(v1, v3, v2, 0);
    return FALSE;
}

bool8 ScrCmd_spriteinvisible(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    npc_by_local_id_and_map_set_field_1_bit_x20(v1, v3, v2, 1);
    return FALSE;
}

bool8 ScrCmd_spritelevelup(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u8 v4 = *(ctx->scriptPtr++);
    sub_805BCF0(v1, v3, v2, v4 + 83);
    return FALSE;
}

bool8 ScrCmd_restorespritelevel(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    sub_805BD48(v1, v3, v2);
    return FALSE;
}

bool8 ScrCmd_faceplayer(struct ScriptContext *ctx)
{
    struct MapObject *objects = gMapObjects;
    struct MapObject *object = &objects[gSelectedMapObject];
    if (object->active)
    {
        u8 dir = player_get_direction_lower_nybble();
        FieldObjectFaceOppositeDirection(object, dir);
    }
    return FALSE;
}

bool8 ScrCmd_spriteface(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    u8 v2 = *(ctx->scriptPtr++);
    FieldObjectTurnByLocalIdAndMap(v1, gSaveBlock1.location.mapNum, gSaveBlock1.location.mapGroup, v2);
    return FALSE;
}

bool8 ScrCmd_spritebehave(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    u8 v2 = *(ctx->scriptPtr++);
    update_saveblock1_field_object_movement_behavior(v1, v2);
    return FALSE;
}

bool8 ScrCmd_createvsprite(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u16 v3 = VarGet(script_read_halfword(ctx));
    u32 v4 = VarGet(script_read_halfword(ctx));
    u8 v5 = *(ctx->scriptPtr++);
    u8 v6 = *(ctx->scriptPtr++);
    sub_805B410(v1, v2, v3, v4, v5, v6);
    return FALSE;
}

bool8 ScrCmd_vspriteface(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    sub_8064990(v1, v2);
    return FALSE;
}

bool8 ScrCmd_lockall(struct ScriptContext *ctx)
{
    if (is_c1_link_related_active())
    {
        return FALSE;
    }
    else
    {
        sub_8064D20();
        script_setup_asm_script(ctx, sub_8064CFC);
        return TRUE;
    }
}

bool8 ScrCmd_lock(struct ScriptContext *ctx)
{
    if (is_c1_link_related_active())
    {
        return FALSE;
    }
    else
    {
        if (gMapObjects[gSelectedMapObject].active)
        {
            sub_8064DD8();
            script_setup_asm_script(ctx, sub_8064DB4);
        }
        else
        {
            sub_8064D20();
            script_setup_asm_script(ctx, sub_8064CFC);
        }

        return TRUE;
    }
}

bool8 ScrCmd_releaseall(struct ScriptContext *ctx)
{
    u8 objectId;

    textbox_close();
    objectId = GetFieldObjectIdByLocalIdAndMap(0xFF, 0, 0);
    FieldObjectClearAnimIfSpecialAnimFinished(&gMapObjects[objectId]);
    sub_80A2178();
    sub_806451C();
    return FALSE;
}

bool8 ScrCmd_release(struct ScriptContext *ctx)
{
    u8 objectId;

    textbox_close();
    if (gMapObjects[gSelectedMapObject].active)
        FieldObjectClearAnimIfSpecialAnimFinished(&gMapObjects[gSelectedMapObject]);
    objectId = GetFieldObjectIdByLocalIdAndMap(0xFF, 0, 0);
    FieldObjectClearAnimIfSpecialAnimFinished(&gMapObjects[objectId]);
    sub_80A2178();
    sub_806451C();
    return FALSE;
}

bool8 ScrCmd_message(struct ScriptContext *ctx)
{
    u8 *msg = (u8 *)script_read_word(ctx);
    if (!msg)
        msg = (u8 *)ctx->data[0];
    box_related_two__2(msg);
    return FALSE;
}

bool8 ScrCmd_message2(struct ScriptContext *ctx)
{
    u8 *msg = (u8 *)script_read_word(ctx);
    if (!msg)
        msg = (u8 *)ctx->data[0];
    box_related_two__3(msg);
    return FALSE;
}

bool8 ScrCmd_waittext(struct ScriptContext *ctx)
{
    script_setup_asm_script(ctx, sub_8064C84);
    return TRUE;
}

bool8 ScrCmd_closebutton(struct ScriptContext *ctx)
{
    textbox_close();
    return FALSE;
}

bool8 sub_80670C0()
{
    if (gMain.newKeys & A_BUTTON)
        return TRUE;
    if (gMain.newKeys & B_BUTTON)
        return TRUE;
    return FALSE;
}

bool8 ScrCmd_waitbutton(struct ScriptContext *ctx)
{
    script_setup_asm_script(ctx, sub_80670C0);
    return TRUE;
}

bool8 ScrCmd_yesnobox(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    if (yes_no_box(v1, v2) == 1)
    {
        sub_80655F0();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_multichoice(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u8 v4 = *(ctx->scriptPtr++);
    if (sub_80B5054(v1, v2, v3, v4) == 1)
    {
        sub_80655F0();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_multichoicedef(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u8 v4 = *(ctx->scriptPtr++);
    u8 v5 = *(ctx->scriptPtr++);
    if (sub_80B50B0(v1, v2, v3, v5, v4) == 1)
    {
        sub_80655F0();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_showbox(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u8 v4 = *(ctx->scriptPtr++);
    MenuDrawTextWindow(v1, v2, v3, v4);
    return FALSE;
}

bool8 ScrCmd_multichoicerow(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u8 v4 = *(ctx->scriptPtr++);
    u8 v5 = *(ctx->scriptPtr++);
    if (sub_80B5578(v1, v2, v3, v5, v4) == 1)
    {
        sub_80655F0();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_hidebox(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u8 v4 = *(ctx->scriptPtr++);
    MenuZeroFillWindowRect(v1, v2, v3, v4);
    return FALSE;
}

bool8 ScrCmd_clearbox(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u8 v4 = *(ctx->scriptPtr++);
    if (Multichoice(v1, v2, v3, v4) == 1)
    {
        sub_80655F0();
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ScrCmd_showpokepic(struct ScriptContext *ctx)
{
    u16 v1 = VarGet(script_read_halfword(ctx));
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    sub_80B58C4(v1, v2, v3);
    return FALSE;
}

bool8 ScrCmd_hidepokepic(struct ScriptContext *ctx)
{
    void *func = picbox_close();
    if (!func)
        return FALSE;

    script_setup_asm_script(ctx, func);
    return TRUE;
}

bool8 ScrCmd_showcontestwinner(struct ScriptContext *ctx)
{
    u8 v1 = *(ctx->scriptPtr++);
    if (v1)
        sub_8106630(v1);
    sub_80C4F10();
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_braillemsg(struct ScriptContext *ctx)
{
    u8 *ptr = (u8 *)script_read_word(ctx);
    u8 v2 = ptr[0];
    u8 v3 = ptr[1];
    u8 v4 = ptr[2];
    u8 v5 = ptr[3];
    u8 v6 = ptr[4];
    u8 v7 = ptr[5];
    StringBraille(gStringVar4, ptr + 6);
    MenuDrawTextWindow(v2, v3, v4, v5);
    MenuPrint(gStringVar4, v6, v7);
    return FALSE;
}

bool8 ScrCmd_vtext(struct ScriptContext *ctx)
{
    u32 v1 = script_read_word(ctx);
    box_related_two__2((u8 *)(v1 - gUnknown_0202E8B0));
    return FALSE;
}

bool8 ScrCmd_bufferpoke(struct ScriptContext *ctx)
{
    u8 stringVarIndex = *(ctx->scriptPtr++);
    u16 species = VarGet(script_read_halfword(ctx));
    StringCopy(gUnknown_083762F0[stringVarIndex], &gSpeciesNames[species]);
    return FALSE;
}

bool8 ScrCmd_bufferfirstpoke(struct ScriptContext *ctx)
{
    u8 stringVarIndex = *(ctx->scriptPtr++);
    u8 *dest = gUnknown_083762F0[stringVarIndex];
    u8 partyIndex = sub_810F87C();
    u32 species = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES, NULL);
    StringCopy(dest, &gSpeciesNames[species]);
    return FALSE;
}

bool8 ScrCmd_bufferpartypoke(struct ScriptContext *ctx)
{
    u8 stringVarIndex = *(ctx->scriptPtr++);
    u16 partyIndex = VarGet(script_read_halfword(ctx));
    GetMonData(&gPlayerParty[partyIndex], MON_DATA_NICKNAME, gUnknown_083762F0[stringVarIndex]);
    StringGetEnd10(gUnknown_083762F0[stringVarIndex]);
    return FALSE;
}

bool8 ScrCmd_bufferitem(struct ScriptContext *ctx)
{
    u8 stringVarIndex = *(ctx->scriptPtr++);
    u16 itemId = VarGet(script_read_halfword(ctx));
    itemid_copy_name(itemId, gUnknown_083762F0[stringVarIndex]);
    return FALSE;
}

bool8 ScrCmd_bufferdecor(struct ScriptContext *ctx)
{
    u8 stringVarIndex = *(ctx->scriptPtr++);
    u16 decorId = VarGet(script_read_halfword(ctx));
    StringCopy(gUnknown_083762F0[stringVarIndex], gDecorations[decorId].name);
    return FALSE;
}

bool8 ScrCmd_bufferattack(struct ScriptContext *ctx)
{
    u8 stringVarIndex = *(ctx->scriptPtr++);
    u16 moveId = VarGet(script_read_halfword(ctx));
    StringCopy(gUnknown_083762F0[stringVarIndex], &gMoveNames[moveId]);
    return FALSE;
}

bool8 ScrCmd_buffernum(struct ScriptContext *ctx)
{
    u8 stringVarIndex = *(ctx->scriptPtr++);
    u16 v1 = VarGet(script_read_halfword(ctx));
    u8 v2 = sub_80BF0B8(v1);
    ConvertIntToDecimalStringN(gUnknown_083762F0[stringVarIndex], v1, 0, v2);
    return FALSE;
}

bool8 ScrCmd_bufferstd(struct ScriptContext *ctx)
{
    u8 stringVarIndex = *(ctx->scriptPtr++);
    u16 index = VarGet(script_read_halfword(ctx));
    StringCopy(gUnknown_083762F0[stringVarIndex], gUnknown_083CE048[index]);
    return FALSE;
}

bool8 ScrCmd_buffertext(struct ScriptContext *ctx)
{
    u8 stringVarIndex = *(ctx->scriptPtr++);
    u8 *text = (u8 *)script_read_word(ctx);
    StringCopy(gUnknown_083762F0[stringVarIndex], text);
    return FALSE;
}

bool8 ScrCmd_vloadptr(struct ScriptContext *ctx)
{
    u8 *ptr = (u8 *)(script_read_word(ctx) - gUnknown_0202E8B0);
    StringExpandPlaceholders(gStringVar4, ptr);
    return FALSE;
}

bool8 ScrCmd_vbuffer(struct ScriptContext *ctx)
{
    u8 stringVarIndex = *(ctx->scriptPtr++);
    u32 addr = script_read_word(ctx);
    u8 *src = (u8 *)(addr - gUnknown_0202E8B0);
    u8 *dest = gUnknown_083762F0[stringVarIndex];
    StringCopy(dest, src);
    return FALSE;
}

bool8 ScrCmd_givepokemon(struct ScriptContext *ctx)
{
    u16 v3 = VarGet(script_read_halfword(ctx));
    u8 v5 = *(ctx->scriptPtr++);
    u16 v7 = VarGet(script_read_halfword(ctx));
    u32 v8 = script_read_word(ctx);
    u32 v9 = script_read_word(ctx);
    u8 v10 = *(ctx->scriptPtr++);
    gScriptResult = sub_80C5374(v3, v5, v7, v8, v9, v10);
    return FALSE;
}

bool8 ScrCmd_giveegg(struct ScriptContext *ctx)
{
    u16 value = VarGet(script_read_halfword(ctx));
    gScriptResult = sub_80C53F8(value);
    return FALSE;
}

bool8 ScrCmd_setpokemove(struct ScriptContext *ctx)
{
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u16 v4 = script_read_halfword(ctx);
    sub_80C5530(v2, v4, v3);
    return FALSE;
}

bool8 ScrCmd_checkattack(struct ScriptContext *ctx)
{
    u8 i;
    u16 moveId = script_read_halfword(ctx);
    gScriptResult = 6;
    for (i = 0; i < 6; i++)
    {
        register u8 *dummy asm("r2");
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
        if (!species)
            break;
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, dummy) && pokemon_has_move(&gPlayerParty[i], moveId) == TRUE)
        {
            gScriptResult = i;
            gUnknown_0202E8CC = species;
            break;
        }
    }
    return FALSE;
}

bool8 ScrCmd_givemoney(struct ScriptContext *ctx)
{
    u32 amount = script_read_word(ctx);
    u8 ignore = *(ctx->scriptPtr++);
    if (!ignore)
        sub_80B79B8(&gSaveBlock1.money, amount);
    return FALSE;
}

bool8 ScrCmd_paymoney(struct ScriptContext *ctx)
{
    u32 amount = script_read_word(ctx);
    u8 ignore = *(ctx->scriptPtr++);
    if (!ignore)
        sub_80B79E0(&gSaveBlock1.money, amount);
    return FALSE;
}

bool8 ScrCmd_checkmoney(struct ScriptContext *ctx)
{
    u32 amount = script_read_word(ctx);
    u8 ignore = *(ctx->scriptPtr++);
    if (!ignore)
        gScriptResult = IsEnoughMoney(gSaveBlock1.money, amount);
    return FALSE;
}

bool8 ScrCmd_showmoney(struct ScriptContext *ctx)
{
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u8 ignore = *(ctx->scriptPtr++);
    if (!ignore)
        sub_80B7C14(gSaveBlock1.money, v2, v3);
    return FALSE;
}

bool8 ScrCmd_hidemoney(struct ScriptContext *ctx)
{
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    RemoveMoneyLabelObject(v2, v3);
    return FALSE;
}

bool8 ScrCmd_updatemoney(struct ScriptContext *ctx)
{
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u8 ignore = *(ctx->scriptPtr++);
    if (!ignore)
        sub_80B7BEC(gSaveBlock1.money, v2, v3);
    return FALSE;
}

bool8 ScrCmd_showcoins(struct ScriptContext *ctx)
{
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    sub_811A72C(gSaveBlock1.coins, v2, v3);
    return FALSE;
}

bool8 ScrCmd_hidecoins(struct ScriptContext *ctx)
{
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    sub_811A770(v2, v3);
    return FALSE;
}

bool8 ScrCmd_updatecoins(struct ScriptContext *ctx)
{
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    sub_811A704(gSaveBlock1.coins, v2, v3);
    return FALSE;
}

bool8 ScrCmd_trainerbattle(struct ScriptContext *ctx)
{
    ctx->scriptPtr = sub_80823C8(ctx->scriptPtr);
    return FALSE;
}

bool8 ScrCmd_reptrainerbattle(struct ScriptContext *ctx)
{
    sub_80825E4();
    return TRUE;
}

bool8 ScrCmd_endtrainerbattle(struct ScriptContext *ctx)
{
    ctx->scriptPtr = sub_80826E8();
    return FALSE;
}

bool8 ScrCmd_endtrainerbattle2(struct ScriptContext *ctx)
{
    ctx->scriptPtr = sub_8082700();
    return FALSE;
}

bool8 ScrCmd_checktrainerflag(struct ScriptContext *ctx)
{
    u16 index = VarGet(script_read_halfword(ctx));
    ctx->comparisonResult = trainer_flag_check(index);
    return FALSE;
}

bool8 ScrCmd_cleartrainerflag(struct ScriptContext *ctx)
{
    u16 index = VarGet(script_read_halfword(ctx));
    trainer_flag_set(index);
    return FALSE;
}

bool8 ScrCmd_settrainerflag(struct ScriptContext *ctx)
{
    u16 index = VarGet(script_read_halfword(ctx));
    trainer_flag_clear(index);
    return FALSE;
}

bool8 ScrCmd_setwildbattle(struct ScriptContext *ctx)
{
    u16 v2 = script_read_halfword(ctx);
    u8 v4 = *(ctx->scriptPtr++);
    u16 v5 = script_read_halfword(ctx);
    sub_80C54D0(v2, v4, v5);
    return FALSE;
}

bool8 ScrCmd_dowildbattle(struct ScriptContext *ctx)
{
    sub_8081B3C();
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_pokemart(struct ScriptContext *ctx)
{
    void *ptr = (void *)script_read_word(ctx);
    CreatePokemartMenu(ptr);
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_pokemartdecor(struct ScriptContext *ctx)
{
    void *ptr = (void *)script_read_word(ctx);
    CreateDecorationShop1Menu(ptr);
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_pokemartbp(struct ScriptContext *ctx)
{
    void *ptr = (void *)script_read_word(ctx);
    CreateDecorationShop2Menu(ptr);
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_pokecasino(struct ScriptContext *ctx)
{
    u8 v2 = VarGet(script_read_halfword(ctx));
    sub_81018A0(v2, c2_exit_to_overworld_1_continue_scripts_restart_music);
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_event_8a(struct ScriptContext *ctx)
{
    u8 v2 = *(ctx->scriptPtr++);
    u8 v3 = *(ctx->scriptPtr++);
    u8 v4 = *(ctx->scriptPtr++);
    if (!v3)
        PlantBerryTree(v2, 0, v4, 0);
    else
        PlantBerryTree(v2, v3, v4, 0);
    return FALSE;
}

bool8 ScrCmd_event_96(struct ScriptContext *ctx)
{
    u16 value = VarGet(script_read_halfword(ctx));
    gScriptResult = GetPriceReduction(value);
    return FALSE;
}

bool8 ScrCmd_choosecontestpkmn(struct ScriptContext *ctx)
{
    sub_80F99CC();
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_startcontest(struct ScriptContext *ctx)
{
    sub_80C48C8();
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_showcontestresults(struct ScriptContext *ctx)
{
    sub_80C4940();
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_contestlinktransfer(struct ScriptContext *ctx)
{
    sub_80C4980(gUnknown_0203869C);
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_doanimation(struct ScriptContext *ctx)
{
    u16 effectId = VarGet(script_read_halfword(ctx));
    gUnknown_0202E8BC = effectId;
    FieldEffectStart(gUnknown_0202E8BC);
    return FALSE;
}

bool8 ScrCmd_setanimation(struct ScriptContext *ctx)
{
    u8 v2 = *(ctx->scriptPtr++);
    gUnknown_0202FF84[v2] = (s16)VarGet(script_read_halfword(ctx));
    return FALSE;
}

bool8 sub_8067B48()
{
    if (!FieldEffectActiveListContains(gUnknown_0202E8BC))
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_checkanimation(struct ScriptContext *ctx)
{
    gUnknown_0202E8BC = VarGet(script_read_halfword(ctx));
    script_setup_asm_script(ctx, sub_8067B48);
    return TRUE;
}

bool8 ScrCmd_sethealplace(struct ScriptContext *ctx)
{
    u16 v2 = VarGet(script_read_halfword(ctx));
    sub_8053588(v2);
    return FALSE;
}

bool8 ScrCmd_checkgender(struct ScriptContext *ctx)
{
    gScriptResult = gSaveBlock2.playerGender;
    return FALSE;
}

bool8 ScrCmd_pokecry(struct ScriptContext *ctx)
{
    u16 v3 = VarGet(script_read_halfword(ctx));
    u16 v5 = VarGet(script_read_halfword(ctx));
    sub_8075178(v3, v5);
    return FALSE;
}

bool8 ScrCmd_waitpokecry(struct ScriptContext *ctx)
{
    script_setup_asm_script(ctx, sub_8075374);
    return TRUE;
}

bool8 ScrCmd_setmaptile(struct ScriptContext *ctx)
{
    u16 v3 = VarGet(script_read_halfword(ctx));
    u16 v5 = VarGet(script_read_halfword(ctx));
    u16 v7 = VarGet(script_read_halfword(ctx));
    u16 v8 = VarGet(script_read_halfword(ctx));
    v3 += 7;
    v5 += 7;
    if (!v8)
        MapGridSetMetatileIdAt(v3, v5, v7);
    else
        MapGridSetMetatileIdAt(v3, v5, v7 | 0xC00);
    return FALSE;
}

bool8 ScrCmd_setdooropened(struct ScriptContext *ctx)
{
    u16 v3 = VarGet(script_read_halfword(ctx));
    u16 v4 = VarGet(script_read_halfword(ctx));
    u16 v7;
    v3 += 7;
    v4 += 7;
    v7 = sub_8058790(v3, v4);
    audio_play(v7);
    task_overworld_door_add_if_role_69_for_opening_door_at(v3, v4);
    return FALSE;
}

bool8 ScrCmd_setdoorclosed(struct ScriptContext *ctx)
{
    u16 v3 = VarGet(script_read_halfword(ctx));
    u16 v5 = VarGet(script_read_halfword(ctx));
    v3 += 7;
    v5 += 7;
    sub_805870C(v3, v5);
    return FALSE;
}

bool8 sub_8067D2C()
{
    if (!sub_805877C())
        return TRUE;
    else
        return FALSE;
}

bool8 ScrCmd_doorchange(struct ScriptContext *ctx)
{
    script_setup_asm_script(ctx, sub_8067D2C);
    return TRUE;
}

bool8 ScrCmd_setdooropened2(struct ScriptContext *ctx)
{
    u16 v3 = VarGet(script_read_halfword(ctx));
    u16 v5 = VarGet(script_read_halfword(ctx));
    v3 += 7;
    v5 += 7;
    sub_80586B4(v3, v5);
    return FALSE;
}

bool8 ScrCmd_setdoorclosed2(struct ScriptContext *ctx)
{
    u16 v3 = VarGet(script_read_halfword(ctx));
    u16 v5 = VarGet(script_read_halfword(ctx));
    v3 += 7;
    v5 += 7;
    sub_80586E0(v3, v5);
    return FALSE;
}

bool8 ScrCmd_event_b1(struct ScriptContext *ctx)
{
    u8 v3 = *(ctx->scriptPtr++);
    u16 v5 = VarGet(script_read_halfword(ctx));
    u16 v7 = VarGet(script_read_halfword(ctx));
    u16 v9 = VarGet(script_read_halfword(ctx));
    sub_810E7AC(v3, v5, v7, v9);
    return FALSE;
}

bool8 ScrCmd_event_b2(struct ScriptContext *ctx)
{
    sub_810E824();
    sub_80655F0();
    return TRUE;
}

bool8 ScrCmd_checkcoins(struct ScriptContext *ctx)
{
    u16 *ptr = GetVarPointer(script_read_halfword(ctx));
    *ptr = GetCoins();
    return FALSE;
}

bool8 ScrCmd_givecoins(struct ScriptContext *ctx)
{
    u16 v2 = VarGet(script_read_halfword(ctx));
    if (sub_811A840(v2) == TRUE)
        gScriptResult = 0;
    else
        gScriptResult = 1;

    return FALSE;
}

bool8 ScrCmd_removecoins(struct ScriptContext *ctx)
{
    u16 v2 = VarGet(script_read_halfword(ctx));
    if (sub_811A898(v2) == TRUE)
        gScriptResult = 0;
    else
        gScriptResult = 1;

    return FALSE;
}