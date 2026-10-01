// 0044d810 FUN_0044d810 [Global]
// program: gamma.dll

byte * __cdecl FUN_0044d810(int param_1,byte *param_2)

{
  byte bVar1;
  LPVOID pvVar2;
  uint uVar3;
  LPVOID pvVar4;
  int iVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte local_2c [32];
  
  puVar6 = &DAT_0049e128;
  pbVar7 = local_2c;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined4 *)pbVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    pbVar7 = (byte *)((int)pbVar7 + 4);
  }
  if (param_1 != 0) {
    pvVar2 = FUN_00453ed0();
    *(int *)((int)pvVar2 + 0x10) = param_1;
  }
  while( true ) {
    bVar1 = *param_2;
    if (bVar1 == 0) break;
    local_2c[(int)(uint)bVar1 >> 3] = local_2c[(int)(uint)bVar1 >> 3] | (byte)(1 << (bVar1 & 7));
    param_2 = param_2 + 1;
  }
  pvVar2 = FUN_00453ed0();
  pbVar7 = *(byte **)((int)pvVar2 + 0x10);
  do {
    pbVar8 = pbVar7;
    uVar3 = (uint)*pbVar8;
    if (uVar3 == 0) break;
    pbVar7 = pbVar8 + 1;
  } while ((1 << (*pbVar8 & 7) & (uint)local_2c[(int)uVar3 >> 3]) != 0);
  pbVar7 = pbVar8 + 1;
  if (uVar3 == 0) {
    pvVar2 = FUN_00453ed0();
    pvVar4 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar4 + 0x10) = *(undefined4 *)((int)pvVar2 + 0xc);
    return (byte *)0x0;
  }
  do {
    pbVar9 = pbVar7;
    uVar3 = (uint)*pbVar9;
    if (uVar3 == 0) break;
    pbVar7 = pbVar9 + 1;
  } while ((1 << (*pbVar9 & 7) & (uint)local_2c[(int)uVar3 >> 3]) == 0);
  if (uVar3 == 0) {
    pvVar2 = FUN_00453ed0();
    pvVar4 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar4 + 0x10) = *(undefined4 *)((int)pvVar2 + 0xc);
  }
  else {
    pvVar2 = FUN_00453ed0();
    *(byte **)((int)pvVar2 + 0x10) = pbVar9 + 1;
    *pbVar9 = 0;
  }
  return pbVar8;
}


