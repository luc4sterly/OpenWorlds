// 1000b7b0 FUN_1000b7b0 [Global]
// program: rwdlmd21.dll

uint * FUN_1000b7b0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint uVar7;
  
  uVar5 = DAT_10087248;
  iVar4 = DAT_10087244;
  uVar1 = *DAT_10089de0;
  uVar2 = DAT_10089de0[1];
  uVar3 = DAT_10089de0[2];
  if (((*(uint *)(DAT_10089de0[0xb1] + 0x78) & 0x1000) == 0) &&
     (((*param_1 != 0 || (param_1[1] != 0)) || (param_1[2] != 0)))) {
    return (uint *)0x0;
  }
  puVar6 = (uint *)(*(code *)DAT_10089de0[0xd3])(400);
  if (puVar6 == (uint *)0x0) {
    return (uint *)0x0;
  }
  *puVar6 = 0;
  puVar6[1] = 0;
  if (DAT_10089b7c == 8) {
    uVar7 = (*(code *)DAT_10089de0[0xd3])(0x2100);
    *puVar6 = uVar7;
    if (uVar7 == 0) {
      (*(code *)DAT_10089de0[0xd6])(puVar6);
      return (uint *)0x0;
    }
    DAT_10087248 = (uVar7 & 0xffffff00) + 0x100;
    uVar7 = (*(code *)DAT_10089de0[0xd3])(0x1320);
    puVar6[1] = uVar7;
    if (uVar7 == 0) {
      (*(code *)DAT_10089de0[0xd6])(*puVar6);
      (*(code *)DAT_10089de0[0xd6])(puVar6);
      return (uint *)0x0;
    }
    DAT_10087244 = (uVar7 & 0xffffff00) + 0x100;
  }
  else {
    if ((DAT_10089b7c < 0xf) || (0x10 < DAT_10089b7c)) {
      return (uint *)0x0;
    }
    uVar7 = (*(code *)DAT_10089de0[0xd3])(0xd00);
    *puVar6 = uVar7;
    if (uVar7 == 0) {
      (*(code *)DAT_10089de0[0xd6])(puVar6);
      return (uint *)0x0;
    }
    DAT_10087248 = (uVar7 & 0xffffff00) + 0x100;
  }
  uVar7 = *param_1;
  puVar6[2] = uVar7;
  *DAT_10089de0 = uVar7;
  uVar7 = param_1[1];
  puVar6[3] = uVar7;
  DAT_10089de0[1] = uVar7;
  uVar7 = param_1[2];
  puVar6[4] = uVar7;
  DAT_10089de0[2] = uVar7;
  FUN_10009430();
  DAT_10087244 = iVar4;
  DAT_10087248 = uVar5;
  *DAT_10089de0 = uVar1;
  DAT_10089de0[1] = uVar2;
  DAT_10089de0[2] = uVar3;
  return puVar6;
}


