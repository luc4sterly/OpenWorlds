// 1002baf0 FUN_1002baf0 [Global]
// programa: RWL21.DLL

uint * FUN_1002baf0(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  
  puVar1 = (uint *)param_1[6];
  if ((*param_1 & 8) == 0) {
    FUN_1002bbd0(param_1);
  }
  else if (param_1 == (uint *)0x0) {
    FUN_1000cba0(0x65);
  }
  else if (puVar1 == (uint *)0x0) {
    FUN_1000cba0(0x65);
  }
  else {
    puVar2 = (uint *)puVar1[2];
    puVar5 = puVar2;
    puVar4 = puVar2;
    while ((puVar3 = puVar5, puVar3 != (uint *)0x0 && (param_1 != puVar3))) {
      puVar4 = puVar3;
      puVar5 = (uint *)puVar3[4];
    }
    if (puVar3 != (uint *)0x0) {
      if (puVar2 == puVar3) {
        puVar1[2] = puVar3[4];
      }
      else {
        puVar4[4] = puVar3[4];
      }
      *(uint **)(puVar1[3] + puVar1[7] * 4) = param_1;
      puVar1[7] = puVar1[7] + 1;
      *param_1 = *param_1 & 0xfffffffe;
    }
  }
  uVar6 = puVar1[7];
  do {
    uVar7 = uVar6 - 1;
    if ((int)uVar6 < 1) goto LAB_1002bb91;
    uVar6 = uVar7;
  } while (*(uint **)(puVar1[3] + uVar7 * 4) != param_1);
  uVar6 = puVar1[7] - 1;
  puVar1[7] = uVar6;
  *(undefined4 *)(puVar1[3] + uVar7 * 4) = *(undefined4 *)(puVar1[3] + uVar6 * 4);
LAB_1002bb91:
  *puVar1 = *puVar1 | 1;
  uVar6 = puVar1[8] - 1;
  puVar1[8] = uVar6;
  if (uVar6 != 0) {
    uVar6 = (**(code **)(PTR_DAT_1005b69c + 0x354))(puVar1[3],uVar6 * 4);
    puVar1[3] = uVar6;
  }
  param_1[6] = 0;
  return param_1;
}


