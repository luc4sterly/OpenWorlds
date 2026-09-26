// 10003a10 FUN_10003a10 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10003a10(undefined4 *param_1,undefined4 param_2,int param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined4 extraout_ECX;
  undefined4 uVar5;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  longlong lVar12;
  
  uVar10 = 0;
  _DAT_10036090 = 0;
  DAT_10036094 = 0;
  _DAT_10036098 = 0;
  _DAT_1003609c = 0;
  _DAT_100360a4 = 0x10;
  DAT_100360a8 = 0x10;
  DAT_100360ac = 0;
  DAT_100360b0 = 0;
  puVar4 = &DAT_1003a030;
  _DAT_100360b4 = 0;
  DAT_100360b8 = 0;
  _DAT_100360bc = 0;
  do {
    uVar6 = 0;
    puVar8 = puVar4;
    do {
      uVar1 = 0;
      uVar9 = 0;
      do {
        uVar1 = uVar1 * 2;
        if ((byte)(&DAT_10036188)[uVar6 + uVar9] <= uVar10) {
          uVar1 = uVar1 | 1;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < 0x10);
      uVar6 = uVar6 + 0x10;
      uVar1 = uVar1 | uVar1 << 0x10;
      *puVar8 = uVar1;
      puVar8[0x10] = uVar1;
      puVar8 = puVar8 + 1;
    } while (uVar6 < 0x100);
    puVar4 = puVar4 + 0x20;
    uVar10 = uVar10 + 1;
  } while (puVar4 < &DAT_10042030);
  DAT_10036054 = param_2;
  iVar2 = FUN_10009290(param_1,param_2,param_3,param_4);
  if (iVar2 == 0) {
    return 0;
  }
  DAT_10038a48 = 0;
  iVar2 = 0x80;
  _DAT_10038a28 = 0;
  DAT_10038a24 = 0;
  _DAT_10038a20 = 0x80;
  DAT_10038a2c = 0;
  DAT_10038a30 = 0;
  DAT_10038a3c = 0;
  DAT_10038a40 = 0;
  DAT_10038a50 = 0;
  DAT_10038a34 = 200;
  DAT_10038a38 = 10;
  DAT_10038a44 = 0x14;
  do {
    DAT_10038a48 = DAT_10038a48 + 1;
    iVar2 = iVar2 / 2;
  } while (0 < iVar2);
  iVar7 = 0;
  FUN_10003d50((int *)&DAT_10038a98,0x10);
  uVar5 = extraout_ECX;
  iVar2 = 0;
  do {
    iVar11 = iVar2 + 4;
    iVar3 = -1 - iVar7;
    iVar7 = iVar7 + 1;
    *(int *)((int)&DAT_10039c20 + iVar2) = iVar3 * 0x1000000;
    FUN_10029bc2(uVar5);
    lVar12 = __ftol();
    *(int *)((int)&DAT_10042040 + iVar2) = (int)lVar12 << 0x18;
    FUN_10029bc2(extraout_ECX_00);
    lVar12 = __ftol();
    *(int *)((int)&DAT_10039820 + iVar2) = (int)lVar12 << 0x18;
    uVar5 = extraout_ECX_01;
    iVar2 = iVar11;
  } while (iVar11 < 0x400);
  DAT_1003a020 = &DAT_10039c20;
  param_1[6] = &LAB_100041e0;
  param_1[7] = FUN_10005e30;
  param_1[0x91] = &LAB_10005eb0;
  param_1[0x9b] = &DAT_10006190;
  param_1[0xd] = &LAB_10006bf0;
  param_1[0xa3] = FUN_10006ba0;
  param_1[0x98] = FUN_10006dc0;
  param_1[10] = FUN_10006200;
  param_1[0xa5] = FUN_10006c10;
  param_1[0xa6] = &LAB_10006c60;
  param_1[0xa7] = &LAB_10006c80;
  param_1[0xa8] = &LAB_10006ce0;
  param_1[0xa9] = &LAB_10006d90;
  param_1[0xa1] = FUN_100036e0;
  param_1[0xa2] = FUN_100073b0;
  param_1[3] = DAT_10036138;
  param_1[4] = DAT_10036138;
  param_1[0xaa] = DAT_10036140;
  uVar5 = DAT_10036140;
  param_1[0x90] = &LAB_100061a0;
  param_1[0x92] = &LAB_10004010;
  DAT_100360c0 = param_1[0x96];
  param_1[0xab] = uVar5;
  param_1[0xe] = &LAB_10007020;
  param_1[0x99] = FUN_100072e0;
  param_1[0x9a] = &LAB_10007350;
  param_1[0x96] = &LAB_10008e30;
  DAT_100360c4 = param_1[0x97];
  param_1[0x97] = &LAB_10007680;
  DAT_100360c8 = param_1[8];
  param_1[8] = FUN_10008fc0;
  param_1[9] = &DAT_10006ec0;
  param_1[0xb] = FUN_10003da0;
  _DAT_10042030 = FUN_10003da0;
  iVar2 = FUN_10003e30((int)param_1,DAT_100360cc);
  if (iVar2 == 0) {
    return 0;
  }
  param_1[0x9d] = 0;
  param_1[0x9f] = &LAB_100061e0;
  FUN_10023a40();
  return 1;
}


