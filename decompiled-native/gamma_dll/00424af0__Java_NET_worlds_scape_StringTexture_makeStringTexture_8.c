// 00424af0 _Java_NET_worlds_scape_StringTexture_makeStringTexture@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_StringTexture_makeStringTexture_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  HDC hdc;
  UINT UVar9;
  HBITMAP ho;
  undefined4 extraout_EDX;
  DWORD local_34;
  byte *local_24;
  int local_18;
  int local_14;
  
                    /* 0x24af0  297  _Java_NET_worlds_scape_StringTexture_makeStringTexture@8 */
  local_34 = 0;
  iVar1 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049d208);
  if (iVar1 == 0) {
    FUN_0044d5a0(s_Error_getting_array_object_field_004719e4);
    return;
  }
  pWVar2 = (LPCWSTR)(**(code **)(*param_1 + 0x2e4))(param_1,iVar1,0);
  if (pWVar2 == (LPCWSTR)0x0) {
    FUN_0044d5a0(s_Error_getting_character_array_el_00471a1c);
    return;
  }
  uVar3 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049d20c);
  pbVar4 = (byte *)(**(code **)(*param_1 + 0x2a4))(param_1,uVar3,0);
  iVar5 = FUN_0044d760(pbVar4,(byte *)s_Kanji_00471a48,5);
  local_24 = pbVar4;
  if (iVar5 == 0) {
    local_24 = &DAT_00471a50;
    local_34 = 0x80;
  }
  uVar6 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049d210);
  uVar7 = FUN_00414240(param_1,uVar6,DAT_0049d224);
  uVar6 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049d214);
  uVar8 = FUN_00414240(param_1,uVar6,DAT_0049d224);
  hdc = CreateCompatibleDC((HDC)0x0);
  if (hdc == (HDC)0x0) {
    FUN_00402800(s_nStringTexture_004718d0,0xfe);
  }
  local_18 = 0;
  local_14 = 0;
  UVar9 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d21c);
  iVar5 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d218);
  ho = FUN_00424870(param_1,((int)uVar7 >> 8 & 0xffU) << 8 | (int)uVar7 >> 0x10 & 0xffU |
                            (uVar7 & 0xff) << 0x10,
                    ((int)uVar8 >> 8 & 0xffU) << 8 | (int)uVar8 >> 0x10 & 0xffU |
                    (uVar8 & 0xff) << 0x10,hdc,iVar5,(LPCSTR)local_24,pWVar2,&local_18,&local_14,
                    local_34,UVar9);
  iVar5 = FUN_004222b0(local_14,extraout_EDX,ho,local_18,local_14,-1,(char *)0x0,0);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049d220,iVar5);
  DeleteObject(ho);
  DeleteDC(hdc);
  (**(code **)(*param_1 + 0x2a8))(param_1,uVar3,pbVar4);
  (**(code **)(*param_1 + 0x304))(param_1,iVar1,pWVar2,0);
  return;
}


