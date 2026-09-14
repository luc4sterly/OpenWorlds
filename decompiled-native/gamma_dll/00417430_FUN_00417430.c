// 00417430 FUN_00417430 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00417430(undefined4 *param_1)

{
  int iVar1;
  uint *puVar2;
  char *pcVar3;
  int *local_208;
  undefined4 local_204;
  uint local_200;
  undefined1 local_1fc [4];
  uint local_1f8;
  undefined1 local_1f4 [4];
  uint local_1f0 [95];
  uint local_74 [19];
  uint local_28;
  int local_20;
  
  iVar1 = (**(code **)*param_1)(param_1,&DAT_00466f5c,&local_208);
  if (iVar1 < 0) {
    FUN_0043c8f0((byte *)s_IDS_NO_DIRECTDRAW_2_004701f0);
    FUN_0044d5a0(&DAT_00470204);
    return 0;
  }
  puVar2 = local_1f0;
  for (iVar1 = 0x5f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_1f0[0] = 0x17c;
  iVar1 = (**(code **)(*local_208 + 0x2c))(local_208,local_1f0,0);
  if (iVar1 < 0) {
    FUN_0043c8f0((byte *)s_IDS_GETCAPS_FAILED_00470208);
    FUN_0044d5a0(&DAT_00470204);
    (**(code **)(*local_208 + 8))(local_208);
    return 0;
  }
  if ((local_1f0[2] & 0x80000) == 0) {
    FUN_0043c8f0((byte *)s_IDS_3D_HARDWARE_REJECTED_0047021c);
    FUN_0044d5a0(&DAT_00470204);
    (**(code **)(*local_208 + 8))(local_208);
    return 0;
  }
  if ((local_1f0[2] & 0x200) != 0) {
    FUN_0043c8f0((byte *)s_IDS_NON_LOCAL_VIDEO_00470238);
    FUN_0044d5a0(&DAT_00470204);
  }
  local_204 = 0x1000;
  iVar1 = (**(code **)(*local_208 + 0x5c))(local_208,&local_204,&local_200,local_1fc);
  if (iVar1 < 0) {
    (**(code **)(*local_208 + 8))(local_208);
    return 0;
  }
  local_204 = 0x4000;
  iVar1 = (**(code **)(*local_208 + 0x5c))(local_208,&local_204,&local_1f8,local_1f4);
  if (iVar1 < 0) {
    (**(code **)(*local_208 + 8))();
    return 0;
  }
  FUN_0043c8f0((byte *)(s_P_IDS_CARD_REPORTS1_00470256 + 2));
  FUN_0044d5a0(s__s__5_2f_0047026c);
  FUN_0043c8f0((byte *)s_IDS_CARD_REPORTS2_00470278);
  FUN_0044d5a0(s__s__5_2f_0047028c);
  FUN_0043c8f0((byte *)s_IDS_CARD_REPORTS3_00470298);
  FUN_0044d5a0(&DAT_004702ac);
  if ((byte)((double)local_200 < _DAT_004702b8 |
            (byte)((ushort)((ushort)(NAN((double)local_200) || NAN(_DAT_004702b8)) << 10) >> 8)) ==
      1) {
    FUN_0043c8f0((byte *)(s__IDS_3D_CARD_MINIMUM1_004702c7 + 1));
    FUN_0044d5a0(s__s__5_2f_0047026c);
    FUN_0043c8f0((byte *)s_IDS_3D_CARD_MINIMUM2_004702e0);
    FUN_0044d5a0(&DAT_004702ac);
    return 0;
  }
  puVar2 = local_74;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_74[0] = 0x6c;
  iVar1 = (**(code **)(*local_208 + 0x30))(local_208,local_74);
  if (iVar1 < 0) {
    (**(code **)(*local_208 + 8))();
    return 0;
  }
  if ((local_74[1] & 0x1000) == 0) {
    pcVar3 = s_IDS_PIXEL_FORMATS_NOT_00470310;
  }
  else {
    if ((local_28 & 0x40) != 0) goto LAB_0041775f;
    pcVar3 = s_IDS_INVALID_COLOR_DEPTH_004702f8;
  }
  FUN_0043c8f0((byte *)pcVar3);
  FUN_0044d5a0(&DAT_00470204);
  local_20 = 0x20;
LAB_0041775f:
  FUN_0043c8f0((byte *)s_IDS_SCREEN_DEPTH1_00470328);
  FUN_0044d5a0(s__s__5_2f_0047026c);
  FUN_0043c8f0((byte *)s_IDS_SCREEN_DEPTH2_0047033c);
  FUN_0044d5a0(&DAT_004702ac);
  if ((local_20 >> 3) * local_74[3] * local_74[2] + local_74[3] * local_74[2] * 2 <= local_1f8) {
    FUN_0043c8f0((byte *)s_IDS_VRAM_TO_SPARE1_0047036c);
    FUN_0044d5a0(s__s__5_2f_0047026c);
    FUN_0043c8f0((byte *)s_IDS_VRAM_TO_SPARE2_00470380);
    FUN_0044d5a0(&DAT_004702ac);
    (**(code **)(*local_208 + 8))();
    return 1;
  }
  FUN_0043c8f0((byte *)s_IDS_USING_SOFTWARE_RENDERER_00470350);
  FUN_0044d5a0(&DAT_00470204);
  return 0;
}


